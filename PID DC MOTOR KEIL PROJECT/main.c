
#include <MKL25Z4.H>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Delay.h"
#include "Defines.h"
#include "PID.h"
#include "DAC.h"
#include "ADC.h"



 


int main(){
	 
                        	//Read Signal >> ADC CODE

    float Angle(void);
			      
             float n ;   //read 
             float Current_angle ; //angle by rad 
						
             ADC0->SC1[0]=0x00 ; //start conversion 

      while (!(ADC0->SC1[0]& ADC_SC1_COCO_MASK))

             n=(float)  ADC0->R[0] ;

             Current_angle =(n*2*3.14)/(3.3);   //rad 
      return Current_angle;
			
		   
			
			

                            // PID CODE
	
	
    float desired_angle = 90;
    int encoder = 0, pwm = 0;  //just for initialization/checking (input voltage)

    while(1){
            Current_angle = encoder;   //depending on the digital value from ADC
            pwm = (PID(desired_angle, Current_angle)/4)*255;  //for example
            delay_ms(dt);
            }
		
						
						
						                // DAC CODE
						
			float DAC_INPUT (void);
				{
	
	       
	      // the DAC expects a number in the range 0 to 4095 in units of VREF/4096
	             desired_angle = desired_angle * (3.3/4096) ;
	
	      while(1){

	                DAC0->DAT[0].DATL = DAC_DATL_DATA0(desired_angle) ;                 /* write low byte */
                  DAC0->DAT[0].DATH = DAC_DATH_DATA1(desired_angle > 8);             /* write high byte */
		
		
	              }	 
	      }
						
						
						
						
		
}
