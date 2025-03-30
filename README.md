# Digital Inputs
C library for digital inputs(buttons, switches)

A Lightweight C based library for be used with arduino Stm32CubeHAL or any other framework that support a milisecond time stamp.
Debouncing, short press, long press and double press are built in and accessed through the structure.

Config the library with "digitalInput.h" header
	1.Define the input numbers you have with "INPUT_COUNT".
	2.Initiate digital_inputs[INPUT_COUNT] using the digital_input_t structure.
	3.Define the input level(this library allows independently configuring input levels per each input).
