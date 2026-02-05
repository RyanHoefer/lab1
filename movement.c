/*
 * movement.c
 *
 *  Created on: Feb 4, 2026
 *      Author: rhoefer
 */
#include "movement.h"
#include "open_interface.h"
#include <stdlib.h>
#include <stdbool.h>


void main(){

    oi_t *sensor_data = oi_alloc();
    oi_init(sensor_data);
    int i;

    double distanceToGo = 2000.0;
    bool leftBumperPressed = false;
    bool rightBumperPressed = false;

    while (distanceToGo > 0.0) {
        oi_update(sensor_data);
        while (sensor_data -> bumpLeft == 0 && sensor_data -> bumpRight == 0) {
            oi_update(sensor_data);
            move_forward(sensor_data, 10);
            distanceToGo -= sensor_data -> distance;
        }
        if (sensor_data -> bumpLeft > 0 || sensor_data -> bumpRight > 0) {
            if (sensor_data -> bumpLeft > 0) {
                move_backwards(sensor_data, 150);
            }
        }
    }
    /*
    for (i = 0; i < 4; i++) {
        move_forward(sensor_data,500.0);
        turn_right(sensor_data, 63.5);
    }
    */

    oi_free(sensor_data);

}


double move_forward(oi_t *sensor_data, double distance_mm){
    double totalDistanceTraveled = 0.0;
    oi_setWheels(250,250);
    while(totalDistanceTraveled <= distance_mm){
        oi_update(sensor_data);
        totalDistanceTraveled += sensor_data -> distance;
    }
    oi_setWheels(0,0);


    return totalDistanceTraveled;
}

double move_backwards(oi_t *sensor_data, double distance_mm){
    double totalDistanceTraveled = 0.0;
    oi_setWheels(-250,-250);
    while(totalDistanceTraveled <= distance_mm){
        oi_update(sensor_data);
        totalDistanceTraveled += abs(sensor_data -> distance);
    }
    oi_setWheels(0,0);


    return totalDistanceTraveled;
}

void turn_right(oi_t *sensor_data, double degrees){

double current_angle = 0.0;
double desired_angle = degrees;

oi_setWheels(-100,100); //right wheel in reverse and left wheel forward

    while (current_angle <= desired_angle) { // iterate untill the desired angle is reached
           oi_update(sensor_data);
           current_angle += abs(sensor_data -> angle); // update current angle, the angle value in the struct, is the change in angle since the last check
    }
    oi_setWheels(0,0);
}

void turn_left(oi_t *sensor_data, double degrees){

double current_angle = 0.0;
double desired_angle = degrees;

oi_setWheels(100,-100); //right wheel in reverse and left wheel forward

    while (current_angle <= desired_angle) { // iterate untill the desired angle is reached
           oi_update(sensor_data);
           current_angle += abs(sensor_data -> angle); // update current angle, the angle value in the struct, is the change in angle since the last check
    }
    oi_setWheels(0,0);
}

void bumpTrigger() {
    move_backwards(sensor_data, 150.0);
}


