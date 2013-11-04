#ifndef _ADC_h_
#define _ADC_h_


typedef struct {
	uint8_t	samples;
	uint8_t	uref;
	uint8_t	channel;
	float		minValueIs;
	float		maxValueIs;
	uint8_t	blocking;
	void		(*handler) (void);
	uint8_t	conversation_done;
} type_ADC_CHANNEL;

void ADC_INIT (type_ADC_CHANNEL *device, uint8_t isFirstADC);
float ADC_MEASURE (type_ADC_CHANNEL *device);

type_ADC_CHANNEL *device_Last;
uint8_t ADC_is_used;

	
	

/** Datasheet Atmel Atmega32 : Page 2 : Figure 1 **/
#define 	ADC_PORT	PORTA
#define		ADC_PIN		PINA
#define		ADC_DDR		DDRA

/** Datasheet Atmel Atmega32 : Page 214 : Table 83 **/
#define		ADC_REF_AREF	(1<<0)
#define		ADC_REF_AVCC	(1<< REFS0)
#define		ADC_REF_2V56	((1<< REFS0) | (1<< REFS1))

#define		ADC_MAXVALUE	1023

#define 	True 	1
#define		False	0



#endif
