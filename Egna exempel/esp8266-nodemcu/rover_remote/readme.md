# Rover Remote

All examples below assumes that the rover responds to serial commands w,s,a,d. [See code](../rover/tank_wasd_keyboard_control/tank_wasd_keyboard_control.ino)

##  USB Control

[This video](https://www.youtube.com/watch?v=Tpe6ubhmzrI&t=126s) from DFrobotshop shows how to connect to it via serial over USB and using the PC program Hyperterminal. I suggest we use the free program [Termite](https://www.compuphase.com/software_termite.htm) instead. 

## Wireless control
    
### Bluetooth    

There is a [bluetooth module](https://www.robotshop.com/en/dfrobot-serial-bluetooth-module.html#Useful-Links) included in the kit.

* [Android app control](https://www.robotshop.com/community/blog/show/dfrobotshop-rover-tutorial-control-with-android-app-bluetooth)

* Iphone does not have a dedicated app, but we should be able to use something like this [Bluetooth terminal app](https://apps.apple.com/us/app/bluetooth-terminal/id1058693037) and use the same commands as when steering it via USB, see above.

* PC bluetooth. Try pairing it and using termial through Termite above? [or try this one, **untested**](http://www.bluesoleil.com/bssoftware/BSoftware.aspx)

### Wifi / web control

We can build a web interface to control the [DF RobotShop rover](https://www.robotshop.com/en/dfrobotshop-rover-tracked-robot-basic-kit.html).

To accomplice this we will use a ESP8266 Wifi-microcontroller module that is Arduino compatible.

It's a 3.3V volt mircocontroller and the rover is 5V so we need to make sure to not fry it. 

*3.3 V vs 5V Checklist:*

* Supply voltage - CHECK, There is a ams1117 5V to 3.3V Linear Regulator on the NODEMCU dev board. Rover outputs ~5V for the bluetooth module. 
* Input Rx voltage - esp8266 should be 5V input compatible according to tests, see [source](https://hackaday.com/2016/07/28/ask-hackaday-is-the-esp8266-5v-tolerant/) and [source, expressif CEO](https://www.facebook.com/groups/1499045113679103/permalink/1731855033731442/?hc_location=ufi). So we need not worry.
* Output voltage / current draw - Should be ok, Rx input is high impedance and should read >~2V as high. See [source](https://learn.sparkfun.com/tutorials/logic-levels/ttl-logic-levels)

All good, moving on.

We should mod [this example code](../HelloServer_LED/HelloServer_LED.ino) to instead send 'w','s','a','d' bytes over serial connected to the TX / RX pins on the rover. Make sure to get the TX -> RX pins to speak to each other and vice versa. (T=transmit and R=recieve.)

We can wire it up and test it with male-female lab cables.

