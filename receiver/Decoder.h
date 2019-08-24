#ifndef Decoder_h
#define Decoder_h

#include <Arduino.h>

class Decoder
{
  public:
    // constructor
    Decoder(char, int, unsigned long);
    
    /*
      - This the main function that keeps running in the loop. It does the following:
        1. receives the messages
        2. it decodes the messages
        3. it prints translated messages to the Serial monitor
    */
    void decodeMessage();
    
    /*
      - This function checks the the input pin to check the received bit 1/0
      - It works very similar to digitalRead() function
    */
    bool checkBit();

  private:
    unsigned long _period; // it represents the interval of each bit (1 / frequency)
    char _portName; // the name of the port where the sensor is connected
    int _pin; // number of the pin where the sensor is connected
    int _counter; // this counter keeps track of the number of dimensions.. Tap Code has 3 dimensions
    String _message; // to store received signal

    /*
      This function does all necessary initializations
    */
    void initialize();

    /*
      This function is responsible for receiving chunks of sent signals
      @return:
      message in String type
    */
    String receiveMessage();
    
    /*
      delay function
      @params:
      delay time

      @return:
      void
    */
    void wait(unsigned long);

    /*
      This function is decodes signals 
      or maps them into their repective letters according to tap code
      @params:
      signal in String type

      @return:
      decoded letter in char type
    */
    char decodeLetter(String);

    /*
      prints the message to the serial monitor
    */
    void displayMessage(String);
};

#endif