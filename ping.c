/*
 * ping.c
 *
 *  Created on: Apr 1, 2026
 *      Author: rhoefer
 */


/**
 * Driver for ping sensor
 * @file ping.c
 * @author
 */

#include "ping.h"
#include "Timer.h"

// Global shared variables
// Use extern declarations in the header file

volatile uint32_t g_start_time = 0;
volatile uint32_t g_end_time = 0;
volatile enum{LOW, HIGH, DONE} g_state = LOW; // State of ping echo pulse

void ping_init (void){
    SYSCTL_RCGCGPIO_R |= 0x02;
    SYSCTL_RCGCTIMER_R |= 0x8;

    GPIO_PORTB_DEN_R |= 0x8; //  enable PB3 as digital pin
    //GPIO_PORTB_DIR_R |= 0x8; //
    GPIO_PORTB_AFSEL_R |= 0x8; // make PB3 analog function
    GPIO_PORTB_AMSEL_R |= 0x8; // enable analog functionality on PB4
    GPIO_PORTB_PCTL_R |= 0x7000;// set 7 to the mux value for the timer

    TIMER3_CTL_R  &= ~0x100;// disable the register
    TIMER3_CFG_R  = 0x4;
    TIMER3_TBMR_R |= 0x7;
    TIMER3_CTL_R  |= 0xC00;
    TIMER3_TBILR_R = 65535;
    TIMER3_TBPR_R = 0xFF;//
    TIMER3_ICR_R |= 0x400; // set capture mode interrupt
    TIMER3_IMR_R |= 0x400;// same thing here





    IntRegister(INT_TIMER3B, TIMER3B_Handler);

    IntMasterEnable();

    // Configure and enable the timer
    TIMER3_CTL_R |= 0xD;//
}

void ping_trigger (void){
    g_state = LOW;
    // Disable timer and disable timer interrupt
    //TIMER3_CTL_R &= ~0xD00;
    //TIMER3_IMR_R &= ~0x600 ;
    // Disable alternate function (disconnect timer from port pin)
    GPIO_PORTB_AFSEL_R &= ~0x8;
    GPIO_PORTB_AMSEL_R &= ~0x8;

    GPIO_PORTB_DEN_R |= 0x8;
    GPIO_PORTB_DIR_R |= 0x8;

    // YOUR CODE HERE FOR PING TRIGGER/START PULSE
    GPIO_PORTB_DATA_R &= ~(0x8);
    timer_waitMicros(2);
    GPIO_PORTB_DATA_R |= 0x8;
    timer_waitMicros(2);
    GPIO_PORTB_DATA_R &= ~(0x8);



    // Clear an interrupt that may have been erroneously triggered
    //TIMER3_ICR_R |= 0xF00;
    // Re-enable alternate function, timer interrupt, and timer
    GPIO_PORTB_AFSEL_R |= 0x8;
    GPIO_PORTB_AMSEL_R |= 0x8;
    //TIMER3_IMR_R |= 0x600;
    //TIMER3_CTL_R |= 0xD00;
}

void TIMER3B_Handler(void){

  // YOUR CODE HERE
  // As needed, go back to review your interrupt handler code for the UART lab.
  // What are the first lines of code in the ISR? Regardless of the device, interrupt handling
  // includes checking the source of the interrupt and clearing the interrupt status bit.
  // Checking the source: test the MIS bit in the MIS register (is the ISR executing
  // because the input capture event happened and interrupts were enabled for that event?
  // Clearing the interrupt: set the ICR bit (so that same event doesn't trigger another interrupt)
  // The rest of the code in the ISR depends on actions needed when the event happens.

}

float ping_getDistance (void){

    return 0.0;

}

