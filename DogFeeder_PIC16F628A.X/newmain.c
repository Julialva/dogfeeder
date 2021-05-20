/*
 * File:   newmain.c
 * Author: 18.00522-5
 *
 * Created on 19 de Maio de 2021, 20:50
 */

// PIC16F628A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 4000000
#define LED PORTAbits.RA0
#define PSHB PORTAbits.RA1
#define SERVO PORTAbits.RA2
#define T 1
void servo_turn();
void servo_center();
void pisca();
void main(void) {
    CMCON = 0x07;
    TRISA = 0b000000010;
    while(1)
    {
        if(PSHB==1){
            servo_turn();
            LED = 1;
            pisca(100,5);
            servo_center();
            
        }
        else {
            servo_center();
            LED = 0;   
        }
     
    }
}
void pisca(int time,int x)
{
    for(int j=0;j<x;j++){
        LED =1;
        for (int i=0;i<time;i++){
        __delay_ms(T);   
        }
        LED =0;
        for (int i=0;i<time;i++){
        __delay_ms(T);   
        }
    }
}
void servo_center()
{
    SERVO = 0;
    __delay_us(18500);
    SERVO = 1;
    __delay_us(1500); //PULSO DE 1,5MS coloca SERVO EM 90 graus
}
void servo_turn() // ABRE COMPORTA
{
    SERVO = 0;
    __delay_us(18000);
    SERVO = 1;
    __delay_us(1000); //PULSO DE 1MS coloca SERVO EM 0 graus
}