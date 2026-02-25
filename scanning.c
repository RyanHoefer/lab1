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

/*
int main(void){
/*
    timer_init(); // Initialize Timer, needed before any LCD screen functions can be called
                      // and enables time functions (e.g. timer_waitMillis)

    lcd_init();   // Initialize the LCD screen.  This also clears the screen.
*/
   // cyBot_uart_init();
   // cyBOT_init_Scan(0b0111);

    //For Calibration
   // right_calibration_value = 269500;
    //left_calibration_value = 1209250;

    //cyBOT_Scan_t* scanner = calloc(1, sizeof(cyBOT_Scan_t));
/*
    int intermittentAngle = 2;
    int angleDesired = 90;
    double distArr[(angleDesired\intermittentAngle) + 1];
*/
/*
    timer_init();
    lcd_init();
    cyBOT_init_Scan(0b0111);
    cyBOT_SERVO_cal();
*/

    //lcd_printf("%c",(char)cyBot_getByte());
    /*
    char message[25];
    int totalAngle = 0;
    float scannerVal = scanner -> sound_dist;
    sprintf(message, "%d\t %f\n\r", totalAngle, scannerVal);
    sendAStringToPuTTY(message);
    */
   // cyBOT_Scan(90, scanner);

    //sendACharToPuTTY((char)cyBot_getByte());
    //cyBOT_Scan(180, scanner);
   //scanIntermitently(2, 180, scanner);


  // return 0;

/*
}
*/
/*
void pointToSmallestObject(double *distances, int intermittentAngle){
    int i;
    double current = distances[0];
    double previous;
    int tracking = 0;
    int totalAngle = 0;
    int objNum = 0;


    typedef struct{
        int angleToCenter;
        double width;
    } object;

    object objArr[10];

    for(i = 1; (i < sizeOf(distances) \ sizeof(distances[0])); i ++){
        previous = distances[i-1];
        current = distances[i];
        totalAngle += intermittentAngle;
        if(((abs(previous - current)) > 10.0) && tracking == 0){
            tracking = 1;
        }
        else if(((abs(previous - current)) > 10.0) && tracking == 1){
            tracking = 0;
            objNum++;
        }

        if(tracking){
            object.width += intermittentAngle;
        }

    }
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
    sendAStringToPuTTY("Degrees  PING distance (cm)\n\r");
    char message[25];
    char message2[100];
    int totalAngle = 0;
    float scannerVal;
    double current = 0;
    double previous = 0;
    int objNum = 0;
    int tracking = 0;
    typedef struct{
            int angleToCenter;
            int width;
            int startAngle;
            int endAngle;
            float distance;
        } object;

    object objArr[10];

    while(totalAngle < angleDesired){



        cyBOT_Scan(totalAngle, scanner);
        totalAngle += intermitentAngle;
        scannerVal = scanner -> sound_dist;
        sprintf(message, "%d\t %f\n\r", totalAngle, scannerVal);
        sendAStringToPuTTY(message);

        previous = current;
        current = scannerVal;

        if (((abs(previous - current)) > 30.0) && tracking == 0 && (scannerVal < 100.0)){
            tracking = 1;

            objArr[objNum].startAngle = totalAngle;
            objArr[objNum].distance = scannerVal;

        }
        else if(((abs(previous - current)) > 30.0) && tracking == 1){
            tracking = 0;
            objArr[objNum].endAngle = totalAngle;
            objArr[objNum].width = objArr[objNum].endAngle - objArr[objNum].startAngle;
            objArr[objNum].angleToCenter = (objArr[objNum].width / 2) + objArr[objNum].startAngle;


            sprintf(message2, "Number: %d, Angle: %d, Distance %f, Width %d \n\r", objNum, objArr[objNum].angleToCenter, objArr[objNum].distance, objArr[objNum].width  );
            objNum++;
            sendAStringToPuTTY(message2);
        }

    }
    int i;
    int smallestWidth = objArr[0].width;
    int currentWidth = 0;
    int smallestObj = 0;
    for(i = 0; i < objNum; i++){
        currentWidth = objArr[i].width;
        if(currentWidth < smallestWidth) {
            smallestWidth = currentWidth;
            smallestObj = i;
        }
    }
    cyBOT_Scan(objArr[smallestObj].angleToCenter, scanner);
}
*/
