#include <xc.h>
#include "Configuration_Header_File.h"

#define Motion_detection PORTAbits.RA0  /* Read PIR sensor's data on this pin */
#define Motion_detection1 PORTAbits.RA1  /* Read PIR sensor's data on this pin */
#define Motion_detection2 PORTAbits.RA2  /* Read PIR sensor's data on this pin */

#define PORT_Dir TRISAbits.RA0          /* define for setting direction */
#define PORT_Dir1 TRISAbits.RA1         /* define for setting direction */
#define PORT_Dir2 TRISAbits.RA2         /* define for setting direction */

#define LED LATD0                       /* connect LED to the PORT pin */
#define LED1 LATD1                     /* connect LED to the PORT pin */
#define LED2 LATD2                    /* connect LED to the PORT pin */

#define LED3 LATD3                       /* connect LED to the PORT pin */
#define LED4 LATD4                     /* connect LED to the PORT pin */
#define LED5 LATD5                    /* connect LED to the PORT pin */

#define LED6 LATC0                       /* connect LED to the PORT pin */
#define LED7 LATC1                     /* connect LED to the PORT pin */
#define LED8 LATC2                    /* connect LED to the PORT pin */

#define LED_Dir TRISDbits.RD0           /* define for setting direction */
#define LED_Dir1 TRISDbits.RD1          /* define for setting direction */
#define LED_Dir2 TRISDbits.RD2          /* define for setting direction */

#define LED_Dir3 TRISDbits.RD3           /* define for setting direction */
#define LED_Dir4 TRISDbits.RD4          /* define for setting direction */
#define LED_Dir5 TRISDbits.RD5          /* define for setting direction */

#define LED_Dir6 TRISCbits.RC0           /* define for setting direction */
#define LED_Dir7 TRISCbits.RC1         /* define for setting direction */
#define LED_Dir8 TRISCbits.RC2          /* define for setting direction */

void MSdelay(unsigned int val);

void main(void) 
{
    ADCON1=0x0F;       /* this makes all pins as a digital I/O pins */ 
    
    TRISD=0x00;         /* this makes all pins as a digital I/O pins */
    TRISE=0x00;         /* this makes all pins as a digital I/O pins */
    TRISC=0x00;         /* this makes all pins as a digital I/O pins */
    
    PORT_Dir = 1;      /* set as input port */
    PORT_Dir1 = 1;      /* set as input port */
    PORT_Dir2 = 1;      /* set as input port */
    
    LED_Dir = 0;       /* set as output port */
    LED_Dir1 = 0;       /* set as output port */
    LED_Dir2 = 0;       /* set as output port */
    LED_Dir3 = 0;       /* set as output port */
    LED_Dir4 = 0;       /* set as output port */
    LED_Dir5 = 0;       /* set as output port */
    LED_Dir6 = 0;       /* set as output port */
    LED_Dir7 = 0;       /* set as output port */
    LED_Dir8 = 0;       /* set as output port */
    
    LED = 0;           /* initially turned OFF LED */
    LED1 = 0;           /* initially turned OFF LED */
    LED2 = 0;           /* initially turned OFF LED */
    
    OSCCON = 0x72;
    
    do
    {
        if(Motion_detection) 
        {
            LED = 0;   /* LED turn ON if any Human motion is detected */ 
            LED1 = 1;   /* LED turn ON if any Human motion is detected */
            LED2 = 0;   /* LED turn ON if any Human motion is detected */
        }
        else {
            LED = 0;   /* LED turn OFF */ 
            LED1 = 0;   /* LED turn OFF */
            LED2 = 1;   /* LED turn OFF */
        }
        if(Motion_detection1)
        {
            LED3 = 0;   /* LED turn ON if any Human motion is detected */ 
            LED4 = 1;   /* LED turn ON if any Human motion is detected */
            LED5 = 0;   /* LED turn ON if any Human motion is detected */
        }
        else {
            LED3 = 0;   /* LED turn OFF */ 
            LED4 = 0;   /* LED turn OFF */
            LED5 = 1;   /* LED turn OFF */
        }
        if(Motion_detection2)
        {
            LED6 = 0;   /* LED turn ON if any Human motion is detected */ 
            LED7 = 1;   /* LED turn ON if any Human motion is detected */
            LED8 = 0;   /* LED turn ON if any Human motion is detected */
        }
        else {
            LED6 = 0;   /* LED turn OFF */ 
            LED7 = 0;   /* LED turn OFF */
            LED8 = 1;   /* LED turn OFF */
        }
    }
    while(1);
}
 
void MSdelay(unsigned int val)
{
     unsigned int i,j;
        for(i=0;i<val;i++)
            for(j=0;j<165;j++);  /*This count Provide delay of 1 ms for 8MHz Frequency */
}