#ifndef transmitter_h
#define transmitter_h

#include <Arduino.h>

class Transmitter
{
public:
	Transmitter(short,int);
	void SendMessage(String);
	
private:
	short _pinNumber;
	int _period;
	String getEncodings(char);
};

#endif