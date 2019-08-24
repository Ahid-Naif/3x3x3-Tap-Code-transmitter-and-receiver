#include "Decoder.h"

void setup()
{
    Serial.begin(115200);
    Decoder tapCode('D', 3, 30);
    for (;;)
    {
        tapCode.decodeMessage();
    }
}

void loop()
{
   
}