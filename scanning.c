/*
 * scanning.c
 *
 *  Created on: Feb 11, 2026
 *      Author: rhoefer
 */

#include "movement.h"
#include "open_interface.h"
#include <stdlib.h>
#include <stdbool.h>
#include "Timer.h"
#include "lcd.h"
#include "cyBot_uart.h"
#include <stdio.h>
#include "scanning.h"
#include "cyBot_Scan.h"


void main(){
/*
    timer_init(); // Initialize Timer, needed before any LCD screen functions can be called
                      // and enables time functions (e.g. timer_waitMillis)

    lcd_init();   // Initialize the LCD screen.  This also clears the screen.
*/
    cyBOT_init_Scan(0b0111);
    cyBot_uart_init();
    cyBOT_Scan_t* scanner = calloc(0, sizeof(cyBOT_Scan_t));

    //lcd_printf("%c",(char)cyBot_getByte());


   // cyBOT_Scan(90, scanner);

    //sendACharToPuTTY((char)cyBot_getByte());
    cyBOT_Scan(180, scanner);
    scanIntermitently(2, 90, scanner);

}

void sendAStringToPuTTY(char string[]){
    char message[100];
    sprintf(message, "%s", string);
    int i;
    for(i = 0; i < strlen(message); i++){
        cyBot_sendByte(message[i]);
    }

}

void scanIntermitently(int intermitentAngle, int angleDesired, cyBOT_Scan_t* scanner){
    sendAStringToPuTTY("Degrees  PING distance (cm)\n");

    int totalAngle = 0;

    while(totalAngle <= angleDesired){
        char message[100];
        cyBOT_Scan(totalAngle, scanner);
        totalAngle += intermitentAngle;
        float scannerVal = scanner -> sound_dist;
        sprintf(message, "%d \t%f\n", totalAngle, scannerVal);
        sendAStringToPuTTY(message);
    }
}

