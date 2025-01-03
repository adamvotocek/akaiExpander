# Arduino-based potentiometer expander for the Akai APC Mini MK2 
This is a device, that slides on the Akai APC MINI MK2 MIDI controller and adds 9 potentiometers to it as well as a USB port for another device. 
![done](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/doneFull.jpg)
<img src="https://github.com/adamvotocek/akaiExpander/blob/main/pictures/akaiCorner.jpg" alt="akaiCorner" width="460"/> <img src="https://github.com/adamvotocek/akaiExpander/blob/main/pictures/akaiFront.jpg" alt="akaiFront" width="540"/>
<img src="https://github.com/adamvotocek/akaiExpander/blob/main/pictures/akaiBack.jpg" alt="akaiBack" width="700"/>
## Overview
Currently, I am too lazy to make a full schematic (might add it later if anyone gets interested in this project), but this is the overview of what is happening in the device:

The brains of this device is an Arduino Pro Micro board. It senses the potentiometers and sends MIDI signals to the computer, so this is essentialy a standalone MIDI controller that can be used without the APC mini. In order to connect the APC mini and Arduino to the computer through a single USB, there is a custom USB hub on board, which is basically just an SL2.1A chip on a breakout board with a 12MHz crystal and two small 10uF capacitors. This hub can host up to 4 devices so in order to use more of its potential, there is a USB A port on the back of the device for connecting any other USB 2.0 devices. All is housed in a two-part 3D printed case, which is printable on an Ender 3 sized print bed.
## Parts
### Electrical
1x Arduino Pro Micro Board

9x WH148 10k Potentiometers

1x USB breakout connector or a cable that you splice up for the arduino

1x SL2.1A USB hub chip

1x SOP16 breakout board

1x 12Mhz crystal oscillator

2x 10uF capacitors

2x 100uF capacitors (not really needed, but it is good practice to include them)

1x USB-C Female breakout board ([Specifically this one](https://www.aliexpress.com/item/1005008099379510.html))

1x USB-A Breakout Board ([Specifically this one](https://www.aliexpress.com/item/1005007333583184.html))

1x USB-B Right angled cable ([Specifically this one](https://www.aliexpress.com/item/1005004042735579.html))

...a lot of wirezzz (i used multiple colors of 26 AWG stranded wire)
### Mechanical
1x 3D printed case

9x Potentiometer knobs of your choice

10x M3 12mm bolts

10x M3 square nuts

2x M2 8mm bolts

2x M2 nuts

2x 15*2mm rubber feet (optional, [I used these](https://www.aliexpress.com/item/1005005287385986.html))
## How to build
### 1. Upload the code to the Arduino
### 2. USB-C breakout board
Solder long enough leads to the VBUS, GND, D+ and D- terminals of the board. Solder in a 100uF capacitor (be careful of the polarity).
![board](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/usbCBoardUsbBCable.jpg)
### 3. Strip the angled USB-B cable
### 4. Arduino USB connection
Solder long enough leads to the breakout USB connector for your Arduino, or if you decided to sacrifice a cable instead, strip it. 
![connector](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/arduinoUsb.jpg)
### 5. USB-A breakout board
Solder long enough leads to the VBUS, GND, D+ and D- terminals of the board. Solder in a 100uF capacitor (be careful of the polarity).
![usbA](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/usbA.jpg)
### 6. Potentiometers
Screw in the pots.
![pots](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/potentiometersTop.jpg)
![pots](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/potentiometersBottom.jpg)
1. Solder the potentiometers in parallel. 
2. Solder long enough leads to the potentiometers for sensing the divided voltage (yellow, green and blue wires in the picture). These will go to the Arduino's analog inputs.
3. Solder long enough power leads to the potentiometers (red and black wires).
![pots](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/potentiometersSoldered.jpg)
### 7. USB hub
1. Solder the SL2.1A chip to the breakout board in the correct orientation.
2. Solder the 12MHz crystal to XIN and XOUT. The orientation doesn't matter.
![image](https://github.com/user-attachments/assets/ede56a37-1e49-45b2-9344-61f774d03ac2)
3. Solder a 10uF capacitor between VDD33 and GND
4. Solder a 10uF capacitor between VDD18 and GND
5. Solder long enough power leads to VDD5 and GND
6. Solder the USB data leads from the USB-C breakout board to DP and DM.
7. Solder the USB data leads from the Arduino USB, USB-B angled cable and USB-A breakout board to the DPx and DMx terminals.

This is what mine looked like. It looks really messy (mostly because of the hot glue), but it works great.  
![hub](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/usbHubSoldered.jpg)
### 8. Arduino connections
Solder the potentiometer power leads to VCC and GND. Solder the potentiometer sense leads to pins A0, A1, A2, A3, 4 (A6), 6 (A7), 8 (A8), 9 (A9), 10 (A10). Don't forget to plug in the USB.

When I did this I wanted to be able to disconnect the potentiometers from the board, because I thought it would help ease the building process. I first soldered pins onto the Arduino and then crimped dupont connectors onto the sense leads. For the power leads, I used a small molex connector. In hindsight, I should've soldered everything on the board, because the connectors didn't quite fit in the case and the pins on the board had to be bent.
![arduino](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/arduinoSoldered.jpg)
### 9. Solder all the power leads together
At this point, the electronics should look somewhat like this:
![soldered](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/allSoldered.jpg)
### 10. Insulate exposed conductors
I used heatshrink and hot glue (wow so proffesional)
### 11. Insert the nuts, screw in the boards
### 12. Close the case
Insert square nuts in the slots under the screw holes. Stuff everything inside. It helps if you use double sided tape to secure the USB hub and the Arduino to the floor of the case. Screw it all together...aaand you're done! Hope everything works:) 
![done](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/doneFull.jpg)
![done](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/doneBack.jpg)
![done](https://github.com/adamvotocek/akaiExpander/blob/main/pictures/doneCorner.jpg)
