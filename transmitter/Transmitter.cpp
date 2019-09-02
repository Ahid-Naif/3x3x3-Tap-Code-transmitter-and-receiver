#include "Transmitter.h"

// Port Number
// Period
Transmitter::Transmitter(short pinNumber, int period) :_pinNumber(pinNumber), _period(period)
{
	pinMode(_pinNumber, OUTPUT);
}

void Transmitter::SendMessage(String text)
{

	for (size_t i = 0; i < text.length(); i++)
	{
		String data = getEncodings(text[i]);

		for (size_t j = 0; j < data.length(); j++)
		{
			int value = (int)data[j] - 48;
			digitalWrite(_pinNumber, value);	// start bit
			delay(_period);						// period
		}
	}

}

String Transmitter::getEncodings(char letter)
{

	switch (letter)
	{
	case 'A':
	case 'a':
		return "1001001000";
	case 'B':
	case 'b':
		return "100100101000";
	case 'C':
	case 'c':
		return "10010010101000";
	case 'D':
	case 'd':
		return "100101001000";
	case 'E':
	case 'e':
		return "10010100101000";
	case 'F':
	case 'f':
		return "1001010010101000";
	case 'G':
	case 'g':
		return "10010101001000";
	case 'H':
	case 'h':
		return "1001010100101000";
	case 'I':
	case 'i':
		return "100101010010101000";
	case 'J':
	case 'j':
		return "101001001000";
	case 'K':
	case 'k':
		return "10100100101000";
	case 'L':
	case 'l':
		return "1010010010101000";
	case 'M':
	case 'm':
		return "10100101001000";
	case 'N':
	case 'n':
		return "1010010100101000";
	case 'O':
	case 'o':
		return "101001010010101000";
	case 'P':
	case 'p':
		return "1010010101001000";
	case 'Q':
	case 'q':
		return "101001010100101000";
	case 'R':
	case 'r':
		return "10100101010010101000";
	case 'S':
	case 's':
		return "10101001001000";
	case 'T':
	case 't':
		return "1010100100101000";
	case 'U':
	case 'u':
		return "101010010010101000";
	case 'V':
	case 'v':
		return "1010100101001000";
	case 'W':
	case 'w':
		return "101010010100101000";
	case 'X':
	case 'x':
		return "10101001010010101000";
	case 'Y':
	case 'y':
		return "101010010101001000";
	case 'Z':
	case 'z':
		return "10101001010100101000";
	case ' ':
		return "1010100101010010101000";
	default:
		break;
	}
}
