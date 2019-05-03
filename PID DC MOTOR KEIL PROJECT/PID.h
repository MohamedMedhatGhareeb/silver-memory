#include "Defines.h"
#include <stdlib.h>



float PID(float setpoint,float actual_position){
    float pre_error = 0, integral = 0;
    float error, derivative, output;

    error = setpoint - actual_position;
    if(abs(error) > epsilon){
       integral = integral + error*dt;
       }
    derivative = (error - pre_error)/dt;
    output = kp*error + ki*integral + kd*derivative;

    if(output > MAX){
                     output = MAX;
                    }
    else if(output < MIN){
                          output = MIN;
                          }

    pre_error = error;
    return output;
												}