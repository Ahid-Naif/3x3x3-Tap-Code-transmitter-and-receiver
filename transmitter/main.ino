#include "Transmitter.h"

void setup()
{
	Transmitter transmitter(11, 30);

	transmitter.SendMessage("Hello World");

	while (1)
	{

	}
}


void loop()
{

}