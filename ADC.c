// !- TODO -! //
// implement non-blocking measurement
 
#include <avr/io.h>
#include "ADC.h"

void ADC_INIT (type_ADC_CHANNEL *device, uint8_t isFirstADC)			// Es werden nur die Randbedingungen geschaffen, die Initialisierung
																		// des ADC an sich erfolgt in der Auslesen-Funktion
{

	/** Pinkonfiguration vornehmen **/
	ADC_DDR  &= ~(1<< device->channel);									// Entsprechender Pin -> Eingang
	ADC_PORT &= ~(1<< device->channel);									// Entsprechender Pin -> (eventuell aktivierte) Pullups deaktivieren

	// ISR aktivieren
	
	if(isFirstADC)
	{
		device_Last = 0;
		ADC_is_used = False;
		ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1);					// ADC einschalten + Prescaler=64
	}
}

float ADC_MEASURE (type_ADC_CHANNEL *device)
{
	if(ADC_is_used)
		return 0;
	ADC_is_used = True;
	if(device_Last != device)											// ADC muss für anderen Kanal umconfiguriert werden
	{
		// initititit
		ADMUX = (device->channel) | (device->uref);
		
		
	}

	float temp = 0;
	if(device->blocking)
	{
		
		for(uint8_t samples=0; samples < device->samples; samples++)
		{
			ADCSRA |= (1<<ADSC);										// ADC starten
			while(ADCSRA & (1<< ADSC));
			temp += ADCW;
		}
		temp /= (device->samples);
		
		temp = (temp/ADC_MAXVALUE)*((device->maxValueIs)-(device->minValueIs))+(device->minValueIs);
		
		
	}
	else
	{
		
		
	}
	
	

	device_Last = device;
	ADC_is_used = False;
	return temp;
}
