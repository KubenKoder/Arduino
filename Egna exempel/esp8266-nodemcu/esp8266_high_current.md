# Maximum current test of a NodeMCU V1.0 dev board with a ExpressIf ESP8266 wifi module

WARNING! These test exceed the maximum ratings set forth by the supplier.
Excessive current values might damage the microcontroller over time or make it misbehave.

## Setup and levels
* General purpose pin 14 (marked D5 on the board) was setup as and output and told to sink current (Digital LOW).
* General purpose pin 12 (marked D6 on the board) was setup as and output and told to source current (Digital HIGH).
* The default HIGH logic level is 3.3V and the default LOW logic level is 0V realtive to the ground pins (GND).

## Code

```
#define LED_SINK  14 //Marked D5 on board (GPIO 14)
#define LED_SOURCE  12 //Marked D6 on board (GPIO 12)


void setup() {
      pinMode(LED_SINK, OUTPUT);
      pinMode(LED_SOURCE, OUTPUT);
      

//LED TEST
 digitalWrite(LED_SINK, LOW);
 digitalWrite(LED_SOURCE, HIGH);
}

void loop() {

}
```

## Equipment
In the test I used green and red LEDs that in other tests draw ~20mA at 2V, this is their recommended rating. 
Please remember that the current vs voltage relationship for LED are highly non-linear.

## Driving LEDs through the microprocessor GPIO pins
A green LED was connected between the oboard 3.3V source pin (fed by a linear regulator that is fed 5V from USB) and the sink-pin.
The current was measured to 24mA and the voltage over the LED was 2.3V.
A red LED was added in paralell with the first one.
The total current was measured to 28mA and the voltage over the LEDs was 2.0V.

I also tested using the output pin as voltage source for the LEDs and the onboard GND-pin as sink.
The measured values for both test were identical, for both the single and paralell LED tests.

### Short circuit currents 
I tested connecting the 3.3V pin straight to the sink pin and measured the short circuit current to 38mA for ~1s. The pin seems to have survived intact. 
Then I connected the source pin to GND and measured the current to 47mA. I left it connected for 10-15s. The microcontroller metal cover was noticeable warmer afterwards. No noticable damage, pin still works.

## Conclusions
The ESP8266 microcontroller can survive currents above the maximum ratings, at least for limited times. 
I still recommend the use of proper current limiting resistors to reduce the risk of damage to the microcontroller. Especially for continious currents and when driving several leds.. 

### Claims of built in current limiting
There has been claims in re-sellers data sheets (Kjell & Co, they have removed the claims now.) that the ESP8266EX provides "current limiting" on the GPIOs but I don't believe this claim unless I read it in a datasheet from the supplier, it's not a common feature and the supplier make no mention of it.

I belive that the currents above 20mA per pin is limited by internal resistances in the microcontroller and that the "lost power" is heating up the microcontroller and eventually would cause damage. To prove this one could solder off the 3.3V regulator and measure the current that goes in and out of the microcontroller. 


### 3.3V to 5V compatablillity
* The board can take 5V Supply voltage - There is a AMS1117 5V to 3.3V Linear Regulator on the NODEMCU dev board for use with USB voltage. 
* Input voltage - Esp8266 should be 5V input compatible according to tests, see [source](https://hackaday.com/2016/07/28/ask-hackaday-is-the-esp8266-5v-tolerant/) and [source, expressif CEO](https://www.facebook.com/groups/1499045113679103/permalink/1731855033731442/?hc_location=ufi). 
* Output voltage - Should be ok as long as the corresponding input is high impedance and reads >~2V as high. (This is standard.) See [source](https://learn.sparkfun.com/tutorials/logic-levels/ttl-logic-levels)
* Current draw -Chip to chip logic draws negliable currents. But if the communication interface uses optocouplers or similar, you need current limiting resistors to stay under [12mA](https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf).
