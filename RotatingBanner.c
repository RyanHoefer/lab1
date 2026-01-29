/// Simple 'Hello, world' program
/**
 * This program prints "Hello, world" to the LCD screen
 * @author Chad Nelson
 * @date 06/26/2012
 *
 * updated: phjones 9/3/2019
 * Description: Added timer_init call, and including Timer.h
 */

#include "Timer.h"
#include "lcd.h"

//Functions
void lcd_rotatingBanner();

void main (void) {

	timer_init(); // Initialize Timer, needed before any LCD screen functions can be called 
	              // and enables time functions (e.g. timer_waitMillis)

	lcd_init();   // Initialize the LCD screen.  This also clears the screen. 


	lcd_rotatingBanner();



	// Print "Hello, world" on the LCD
	//lcd_puts("Hello, world");

	// lcd_puts("Hello, world"); // Replace lcd_printf with lcd_puts
        // step through in debug mode and explain to TA how it works
    
	// NOTE: It is recommended that you use only lcd_init(), lcd_printf(), lcd_putc, and lcd_puts from lcd.h.
       // NOTE: For time functions, see Timer.h

}

void lcd_rotatingBanner () {
    char message[53] = "                    Microcontrollers are lots of fun!";
    char onScreenMessage[20] = "";
    int i = 0;
    int j = 0;
    int k = 0;
    while(true){
        j = k;
        for(i = 0; i < 20; i++){
            onScreenMessage[i % 20] = message[j % 53];
            j++;
        }
      k++;

        lcd_printf("%s", onScreenMessage);
        timer_waitMillis(300);

    }
}
