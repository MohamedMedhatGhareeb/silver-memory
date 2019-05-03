#include <MKL25Z4.H>
#include "Defines.h"




void Init (void){
                                 //enable to clock portA
                  SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK ;

                                 //enable clock to module ADC 
                  SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK ;

	
	
                                //select analog for pin 

                  PORTA->PCR[ADC_POS] &=~ PORT_PCR_MUX_MASK;
                  PORTA->PCR[ADC_POS] |=PORT_PCR_MUX(0);

    ADC0->CFG1 = ADC_CFG1_ADLPC_MASK| ADC_CFG1_ADLSMP_MASK |ADC_CFG1_MODE(3) |ADC_CFG1_ADICLK(0) ;

    ADC0->SC2=ADC_SC2_REFSEL(0);
	
                }
