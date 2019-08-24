#include "Decoder.h"
// //////////////// define registers //////////////
volatile unsigned char *pinb = (unsigned char *)0x23;
unsigned char *ddrb = (unsigned char *)0x24;
unsigned char *portb = (unsigned char *)0x25;
volatile unsigned char *pinc = (unsigned char *)0x26;
unsigned char *ddrc = (unsigned char *)0x27;
unsigned char *portc = (unsigned char *)0x28;
volatile unsigned char *pind = (unsigned char *)0x29;
unsigned char *ddrd = (unsigned char *)0x2A;
unsigned char *portd = (unsigned char *)0x2B;

/////////////////// define Constructor //////////
Decoder::Decoder(char port, int pin, unsigned long period) : _portName(port), _pin(pin), _period(period)
{
    this->initialize();
    this->_counter = 0; // counter to keep track of dimensions
}
///////////////// define class methods /////////
void Decoder::decodeMessage()
{
    this->_counter++;
    String Signal = this->receiveMessage();
    this->_message.concat(Signal); // concatenate the signal dimension to the full message
    if (this->_counter == 3)
    {   // if it's the last dimension
        // add "00" which seperate between letters
        // then, clear counter & message variables
        // Finally, print the message to the serial monitor
        this->_message.concat("00");
        this->_counter = 0;
        this->_message = this->decodeLetter(this->_message);
        this->displayMessage(this->_message);
        this->_message = "";
    }
    else
    {
        this->_message.concat('0');
    }
}

String Decoder::receiveMessage()
{
    unsigned char message;
    String Signal;
    bool value = this->checkBit();
    bool previousState = 0;
    while (value == this->checkBit())
    {
        // do nothing if there's no change from the idle state
    }
    message |= 1 << 7;
    previousState = 1;
    this->wait(this->_period * 1.1);

    for (int i = 6; i >= 0; i--)
    {
        if (this->checkBit()) // if bit is HIGH
        {
            message |= 1 << i; // set the bit to HIGH
            previousState = 1;
        }
        else
        {
            // if we have two 0 states after each other
            // it indicates end of dimension
            if (!previousState) 
            {
                Signal = String(message, BIN); // convert into string, but keep it in its binary state
                int index = Signal.indexOf("00", 0);
                // keeps the signal that represents dimension and remove the zeros in the end
                Signal.remove(index + 1, Signal.length() - index);
                break;
            }
            message &= ~(1 << i); // clear bit into LOW
            previousState = 0;
        }
        this->wait(this->_period);
    }
    return Signal;
}

void Decoder::wait(unsigned long delayTime)
{
    unsigned long startTime = millis();
    while ((millis() - startTime) < delayTime)
    {
        // do nothing
    }
}

bool Decoder::checkBit()
{
    switch (this->_portName)
    {
    case 'B':
        return !((1 << this->_pin) & (*pinb));
        break;
    case 'C':
        return !((1 << this->_pin) & (*pinc));
        break;
    case 'D':
        return !((1 << this->_pin) & (*pind));
        break;
    }
}

char Decoder::decodeLetter(String letter)
{
    if (letter == "1001001000")
		return 'A';
	else if (letter == "100100101000")
		return 'B';
	else if (letter == "10010010101000")
		return 'C';
	else if (letter == "100101001000")
		return 'D';
	else if (letter == "10010100101000")
		return 'E';
	else if (letter == "1001010010101000")
		return 'F';
	else if (letter == "10010101001000")
		return 'G';
	else if (letter == "1001010100101000")
		return 'H';
	else if (letter == "100101010010101000")
		return 'I';
	else if (letter == "101001001000")
		return 'J';
	else if (letter == "10100100101000")
		return 'K';
	else if (letter == "1010010010101000")
		return 'L';
	else if (letter == "10100101001000")
		return 'M';
	else if (letter == "1010010100101000")
		return 'N';
	else if (letter == "101001010010101000")
		return 'O';
	else if (letter == "1010010101001000")
		return 'P';
	else if (letter == "101001010100101000")
		return 'Q';
	else if (letter == "10100101010010101000")
		return 'R';
	else if (letter == "10101001001000")
		return 'S';
	else if (letter == "1010100100101000")
		return 'T';
	else if (letter == "101010010010101000")
		return 'U';
	else if (letter == "1010100101001000")
		return 'V';
	else if (letter == "101010010100101000")
		return 'W';
	else if (letter == "10101001010010101000")
		return 'X';
	else if (letter == "101010010101001000")
		return 'Y';
	else if (letter == "10101001010100101000")
		return 'Z';
	else if (letter == "1010100101010010101000")
return ' ';
}

void Decoder::displayMessage(String message)
{
    Serial.print(message);
}

void Decoder::initialize()
{
    switch (this->_portName)
    {
    case 'B':
        *ddrb &= ~(1 << this->_pin); // determine direction of the pin as INPUT
        *portb &= ~(1 << this->_pin);
        break;
    case 'C':
        *ddrc &= ~(1 << this->_pin); // determine direction of the pin as INPUT
        *portc &= ~(1 << this->_pin);
        break;
    case 'D':
        *ddrd &= ~(1 << this->_pin); // determine direction of the pin as INPUT
        *portd &= ~(1 << this->_pin);
        break;
    }
}