#include "Transmitter.h"

void setup()
{
	Transmitter transmitter(11, 50);

	transmitter.SendMessage("Hello World");

	while (1)
	{

	}
}


void loop()
{

}