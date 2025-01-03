// this is a MIDI controller that has 9 potentiometers, based on the ARDUINO PRO MICRO
// it is meant to expand on the features of akai apc mini mk2

#include <Arduino.h>
#include <MIDIUSB.h>

uint8_t analogPins[9] = {A0, A1, A2, A3, A6, A7, A8, A9, A10};

uint8_t firstCC = 70;

uint8_t potentiometerValues[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t lastPotentiometerValues[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void controlChange(byte channel, byte control, byte value)
{
    midiEventPacket_t event = {0x0B, static_cast<uint8_t>(0xB0 | channel), control, value};
    MidiUSB.sendMIDI(event);
}

void setup() {
    //Serial.begin(115200);
}

void loop()
{
    for (int i = 0; i < 9; i++)
    {
        potentiometerValues[i] = map(analogRead(analogPins[i]), 0, 1023, 0, 127);
        if (potentiometerValues[i] != lastPotentiometerValues[i])
        {
            controlChange(0, firstCC + i, potentiometerValues[i]);
            // Serial.print("CC: ");
            // Serial.print(firstCC + i);
            // Serial.print(" Value: ");
            // Serial.println(potentiometerValues[i]);
            lastPotentiometerValues[i] = potentiometerValues[i];
        }
    }
    MidiUSB.flush();
}
