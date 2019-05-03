#include <MKL25Z4.H>
#include "Defines.h"



void DAC0_init(void)
{
	// Enable clocks
	SIM->SCGC6 |= DAC0_MASK;	// DAC0 clock
	SIM->SCGC5 |= PORTE_MASK;	// PTE clock
	
	// Select Analog For Pin (PTE30)
	PORTE->PCR[DAC_POS] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[DAC_POS] |= PORT_PCR_MUX(0);
	
	// Disable Buffer mode
	DAC0->C1 = 0 ;
	DAC0->C2 = 0 ;
	
	// Enable DAC, Select VDDA as reference voltage
	DAC0->C0 = DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;
}