/*
 Arduino Library for Analog Devices ADXL362 - Micropower 3-axis accelerometer
 go to http://www.analog.com/ADXL362 for datasheet
 
 
 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created June 2012
 by Anne Mahaffey - hosted on http://annem.github.com/ADXL362
 
 Modified May 2013
 by Jonathan Ruiz de Garibay

 */ 

#include "Arduino.h"

#ifndef ADXL362_h
#define ADXL362_h

class ADXL362 {
public:

	ADXL362();
	
	//
	// Basic Device control and readback functions
	//
	void begin(int16_t chipSelectPin = 10); 		
	void beginMeasure(); 
	
	uint8_t readStatus();
	
	int16_t readXData();
	int16_t readYData();
	int16_t readZData();
	void readXYZTData(int16_t &XData, int16_t &YData, int16_t &ZData, int16_t &Temperature);
	int16_t readTemp();
	
	//
	// Activity/Inactivity interrupt functions
	//
	void setupDCActivityInterrupt(int16_t threshold, byte time);	
	void setupDCInactivityInterrupt(int16_t threshold, int16_t time);
    void setupACActivityInterrupt(int16_t threshold, byte time);
	void setupACInactivityInterrupt(int16_t threshold, int16_t time);
	
	void writeIntmap1(uint8_t value);
	void writeIntmap2(uint8_t value);

	// need to add the following functions
	// void mapINT1(
	// void mapINT2
	// void autoSleep
	// void activityInterruptControl
	//		-Activity, Inactivity, Both
	//		- Referenced, Absolute
	//		- Free Fall, Linked Mode, Loop Mode
	
	void checkAllControlRegs();
	
	
	//  Low-level SPI control, to simplify overall coding
	byte SPIreadOneRegister(byte regAddress);
	void SPIwriteOneRegister(byte regAddress, byte regValue);
	int16_t  SPIreadTwoRegisters(byte regAddress);
	void SPIwriteTwoRegisters(byte regAddress, int16_t twoRegValue);

	// Status bits in status register
	static const uint8_t STATUS_ERR_USER_REGS = 0x80;
	static const uint8_t STATUS_AWAKE = 0x40;
	static const uint8_t STATUS_INACT = 0x20;
	static const uint8_t STATUS_ACT = 0x10;
	static const uint8_t STATUS_FIFO_OVERRUN = 0x08;
	static const uint8_t STATUS_FIFO_WATERMARK = 0x04;
	static const uint8_t STATUS_FIFO_READY = 0x02;
	static const uint8_t STATUS_DATA_READ = 0x01;

	// INTMAP1 and INTMAP2
	static const uint8_t INTMAP_INT_LOW = 0x80;
	static const uint8_t INTMAP_AWAKE = 0x40;
	static const uint8_t INTMAP_INACT = 0x20;
	static const uint8_t INTMAP_ACT = 0x10;
	static const uint8_t INTMAP_FIFO_OVERRUN = 0x08;
	static const uint8_t INTMAP_FIFO_WATERMARK = 0x04;
	static const uint8_t INTMAP_FIFO_READY = 0x02;
	static const uint8_t INTMAP_DATA_READY = 0x01;

private:

};

#endif