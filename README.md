avr_ObjAdcLib
=============

This is a more object-orientated ADC-library for AVR Microcontrollers written in C.

This library consits of:

    ADC.h
    ADC.c

and offers:

    - handle infinite number of ADC-channels with no duplicate code (most microcontrollers have only 8)
    - automatic conversion of ADC-value to voltage
    - easily choose:
        - number of samples
        - reference voltage
        - channel

    functions:
        ADC_INIT: Init an ADC-channel
        ADC_MEASURE: Measures the voltage

There are examples in main.c, which show the basics.

Note: The library supports only blocking measurement yet. This means, your program does nothing until the measurement is done.