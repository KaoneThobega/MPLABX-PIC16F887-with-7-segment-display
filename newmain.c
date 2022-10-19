#include <xc.h>
#define _XTAL_FREQ 4000000
#define _Delay 1000

// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)


int index = 0;
const int unsigned look_up_table [] = {
         0b00111111, //0
         0b00000110, //1
         0b01011011, //2
         0b01001111, //3
         0b01100110, //4
         0b01101101, //5
         0b01111101, //6
         0b00000111, //7
         0b01111111,//8
         0b01101111, //9
         0b01110111, //A
         0b01111111, //B
         0b00111001, //C
         0b00111111,//D
         0b01111001, //E
         0b01110001 //F
    };

void portc()
{
    TRISC = 0x00;
    while(1) {
        if (index>15)
            index=0;
        
        else {PORTC=look_up_table[index];
        __delay_ms(1500);
        index++;}
    }
    
}


void main(void) {
    
    portc();
    
     
return;
}


