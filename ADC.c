/*
 * ADC.c
 *
 *  Created on: Jan 31, 2020
 *  Author: LWDC05/ Sarosij
 */
#include "ADC.h"
#include "msp430.h"

void init_ADC()
{
	// Configure ADC10
	ADCCTL0 |= ADCSHT_2 | ADCON;                              // ADCON, S&H=16 ADC clks
	ADCCTL1 |= ADCSHP;                                        // ADCCLK = MODOSC; sampling timer
	ADCCTL2 |= ADCRES;                                        // 10-bit conversion results
	ADCIE |= ADCIE0;                                          // Enable ADC conv complete interrupt
	//ADCMCTL0 |= ADCINCH_2 | ADCSREF_0;                        // A2 ADC input select; Vref=AVCC
	//ADCMCTL0 |= ADCINCH_3 | ADCSREF_0;                        // A3 ADC input select; Vref=AVCC
}

void init_ADC_CH2()
{
	while (ADCCTL1 & 0x0001);			// Wait if ADC core is active
	ADCCTL0 &= ~ADCENC;
	//ADCCTL0 &= ~ADCON;                              // ADCON, S&H=16 ADC clks
	//_delay_cycles(1450000);		//approx 100 msec
	Delay_3ms(33);
	ADCMCTL0 &= ~ADCINCH_15;
	ADCMCTL0 |= ADCINCH_2 | ADCSREF_0;
	//ADCCTL0 |= ADCON;
	//init_ADC();
	//_delay_cycles(1450000);		//approx 100 msec
	Delay_3ms(33);
}

void init_ADC_CH3()
{
	while (ADCCTL1 & 0x0001);			// Wait if ADC core is active
	ADCCTL0 &= ~ADCENC;
	//ADCCTL0 &= ~ADCON;                              // ADCON, S&H=16 ADC clks
	//_delay_cycles(1450000);		//approx 100 msec
	Delay_3ms(33);
	ADCMCTL0 |= ADCINCH_3 | ADCSREF_0;
	//ADCCTL0 |= ADCON;
	//init_ADC();
	//_delay_cycles(1450000);		//approx 100 msec
	Delay_3ms(33);
}

void ADC_OFF()
{
	ADCCTL0 &= ~ADCON;                              // ADCON, S&H=16 ADC clks
	ADCCTL0 &= ~ADCENC;
}

void ADC_ON()
{
	ADCCTL0 |= ADCON;                              // ADCON, S&H=16 ADC clks
}
