#include <Metro.h>
#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("hi!");
    delay(1000);
}
