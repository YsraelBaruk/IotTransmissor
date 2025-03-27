#include <SPI.h>
#include <nRF24L01.H>
#include <RF24.h>

RF24 radio(9, 10);

const byte address[6] = "00601";

void setup()
{
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_LOW);
    radio.stopListening();
}

void loop()
{
    const char text[] = "IoT";
    radio.write(&text, sizeof(text));
    delay(1000);
}