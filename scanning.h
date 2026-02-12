/*
 * scanning.h
 *
 *  Created on: Feb 11, 2026
 *      Author: rhoefer
 */

#ifndef SCANNING_H_
#define SCANNING_H_
#include "cyBot_scan.h"

void sendAStringToPuTTY(char string[]);
void scanIntermitently(int intermitentAngle, int angleDesired, cyBOT_Scan_t* scanner);



#endif /* SCANNING_H_ */
