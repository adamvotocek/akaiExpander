// this is a MIDI controller that has 9 potentiometers, based on the ARDUINO PRO MICRO
// it is meant to expand on the features of akai apc mini mk2

// Uncomment this if you want to print the CC values to serial
//#define SERIAL_DEBUG_MODE

#include <Arduino.h>
#include <MIDIUSB.h>


#define NUM_POTS 9
#define FIRST_CC 70

#define MIDI_BOUNCE_THRESHOLD 4 // how many times a value bounces between two values before we pick one and stop bouncing

uint8_t analogPins[NUM_POTS] = {A0, A1, A2, A3, A6, A7, A8, A9, A10};

uint8_t midiValues[NUM_POTS] = {0};
uint8_t lastMidiValues[NUM_POTS] = {0};
uint8_t secondToLastMidiValues[NUM_POTS] = {0};

unsigned long midiBounceCounter[NUM_POTS] = {0};

void controlChange(byte channel, byte control, byte value)
{
    midiEventPacket_t event = {0x0B, static_cast<uint8_t>(0xB0 | channel), control, value};
    MidiUSB.sendMIDI(event);
}

void setup()
{
#ifdef SERIAL_DEBUG_MODE
    Serial.begin(115200);
#endif
}

void loop()
{
    for (int i = 0; i < 9; i++)
    {
        midiValues[i] = map(analogRead(analogPins[i]), 0, 1023, 0, 127);

        if (midiValues[i] != lastMidiValues[i])
        {
            if (midiValues[i] == secondToLastMidiValues[i])
            {
                midiBounceCounter[i]++;
            }
            else
            {
                midiBounceCounter[i] = 0;
            }
            secondToLastMidiValues[i] = lastMidiValues[i];
            lastMidiValues[i] = midiValues[i];

            if (midiBounceCounter[i] <= MIDI_BOUNCE_THRESHOLD)
            {
                controlChange(0, FIRST_CC + i, midiValues[i]);

#ifdef SERIAL_DEBUG_MODE
                Serial.print("CC: ");
                Serial.print(FIRST_CC + i);
                Serial.print(" Value: ");
                Serial.println(midiValues[i]);
#endif
            }
        }
    }
    MidiUSB.flush();
}
