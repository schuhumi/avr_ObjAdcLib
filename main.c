#include <avr/io.h>
#include "ADC.h"
	
int main (void)
{	
	type_ADC_CHANNEL adcBattVoltage;
	type_ADC_CHANNEL adcNegVoltage;
	
	/// Configure Devices //////////////////////////////////////	
	// ADC for battery voltage configuration 	
		adcBattVoltage.samples	= 10;				// Measures the voltage 10 times and calculates the average
		adcBattVoltage.uref		= ADC_REF_AVCC;		// Voltage reference (see ADC.h for aviable options)
		adcBattVoltage.channel	= 3;				// ADC-channel to measure
		adcBattVoltage.minValueIs = 0;				// A reading of 0 equals 0V
		adcBattVoltage.maxValueIs = 12.5;			// A reading of ADC_MAXVALUE equals 12.5V
		adcBattVoltage.blocking	= True;				// Program stops while measuring. Measurement with interrupts is not supported yet
		
	// ADC for negative voltage configuration 	
		adcNegVoltage.samples	= 10;
		adcNegVoltage.uref		= ADC_REF_AVCC;
		adcNegVoltage.channel	= 2;
		adcNegVoltage.minValueIs = -7.5;
		adcNegVoltage.maxValueIs = 5;
		adcNegVoltage.blocking	= True;
	/// END Configure Devices //////////////////////////////////
	
	/// INIT Devices ///////////////////////////////////////////
	// INIT ADC
		//       &device        , isFirstADC
		ADC_INIT(&adcBattVoltage, True      );
		ADC_INIT(&adcNegVoltage , False     );
	/// END INIT Devices ///////////////////////////////////////
	
	// Example;
	float Batteryvoltage = ADC_MEASURE(&adcBattVoltage);
	float NegativePowerSupply = ADC_MEASURE(&adcNegVoltage);

	while(1);

	return 0;
}
