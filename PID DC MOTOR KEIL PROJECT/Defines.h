
                                        // ADC Defines 


#define ADC0_MASK
#define PORTA_MASK
#define ADC_POS (12)





                                         // PID Defines 

#define epsilon 0.01     //In case of error too small then stop integration
#define dt 100           //100ms loop time
#define kp 21
#define kd 1
#define ki 500
#define MAX 4            //For Current Saturation
#define MIN -4           //arbitrary value





                                       // DAC Defines


 #define DAC0_MASK       			0x8000000u
 #define PORTE_MASK      			0x0002000u
 #define DAC_POS (30)




