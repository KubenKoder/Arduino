*Guides for the DFRobotshop rover kit*

# Rover Control schemes

All examples below assumes that the rover responds to serial commands w,s,a,d. [See code](tank_wasd_keyboard_control/tank_wasd_keyboard_control.ino)

##  USB Control

_Installation guide_

* Download the Arduino software ZIP file, [Choose JUST DOWNLOAD](https://www.arduino.cc/en/Main/Donate)
* Find the downloaded file in your downloads folder.
* Unpack the ZIP file (Høyreklikk og "Pakk ut alle" på ZIP fila i Downloads mappen)
* Run the Arduino program from the folder you unpakked. (Bonus: Right klick and add a shortcut to your desktop for later use.)
* Copy [all this code](https://raw.githubusercontent.com/KubenKoder/Arduino/master/Egna%20exempel/Rover/tank_wasd_keyboard_control/tank_wasd_keyboard_control.ino)
* Empty the Arduino window and Paste in the code you copied
* Plug in the Rover USB cable to your PC
* Unplug the Bluetooth module from the Rover, it interfears with the programming signals. 
* Under the Tools menu in the Arduion program ("Verktøy?"), find and select the Port, it is called a COM number that changes when you plug things in and out.
* Now find the arrrow button that says Upload when you hover over it, press that one and wait a bit.
* The rover is now programmed.

_Steering the rover via the Serial monitor_

![](img/serial.PNG)

*How to open and configure the serial monitor*

You can steer the rover by sending it these letters:

* W = Forward
* S = Reverse
* A = Steer left
* D = Steer right
* Spacebar = Stop

Send commands with the Enter key.

The Rover must be battery powered to run. The switch is ON when toggled towards the center.

## Wireless control
    
### Bluetooth    

There is a [bluetooth module](https://www.robotshop.com/en/dfrobot-serial-bluetooth-module.html#Useful-Links) included in the kit.

* [Android app control](https://www.robotshop.com/community/blog/show/dfrobotshop-rover-tutorial-control-with-android-app-bluetooth)

* Iphone does not have a dedicated app, but we should be able to use something like this [Bluetooth terminal app](https://apps.apple.com/us/app/bluetooth-terminal/id1058693037) and use the same commands as when steering it via USB, see above.

* PC bluetooth. Try pairing it and using termial through Termite above? [or try this one, **untested**](http://www.bluesoleil.com/bssoftware/BSoftware.aspx)

### Wifi control using esp8266 onboard web server

We can build a web interface to control the [DF RobotShop rover](https://www.robotshop.com/en/dfrobotshop-rover-tracked-robot-basic-kit.html).

To accomplice this we will use a ESP8266 Wifi-microcontroller module that is Arduino compatible.

It's a 3.3V volt mircocontroller and the rover is 5V so we need to make sure to not fry it. 

*3.3 V vs 5V Checklist:*

* Supply voltage - CHECK, There is a ams1117 5V to 3.3V Linear Regulator on the NODEMCU dev board. Rover outputs ~5V for the bluetooth module. 
* Input Rx voltage - esp8266 should be 5V input compatible according to tests, see [source](https://hackaday.com/2016/07/28/ask-hackaday-is-the-esp8266-5v-tolerant/) and [source, expressif CEO](https://www.facebook.com/groups/1499045113679103/permalink/1731855033731442/?hc_location=ufi). So we need not worry.
* Output voltage / current draw - Should be ok, Rx input is high impedance and should read >~2V as high. See [source](https://learn.sparkfun.com/tutorials/logic-levels/ttl-logic-levels)

All good, moving on.

We should mod [this example code](../esp8266-nodemcu/HelloServer_LED/HelloServer_LED.ino) to instead send 'w','s','a','d' bytes over serial connected to the TX / RX pins on the rover. Make sure to get the TX -> RX pins to speak to each other and vice versa. (T=transmit and R=recieve.)

We can wire it up and test it with male-female lab cables.

*Telerobotics bonus idea*

If we attach a mobile phone to the rover, we can make a video chat to the phone and see where it drives. 

(Possible extension, use the headset jack to recieve the robot control signals to be able to steer it using computer generated audio signals tied to keystrokes)