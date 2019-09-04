# Ultrasound + Rover

Vi ønsker å kombinere disse:

* [Ultrasonic range finder, 4 pin](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)
* [DFRoboshop Rover](https://github.com/KubenKoder/Arduino/blob/master/Egna%20exempel/Rover/readme.md

Rovern lytter etter bokstaver w,s,a, og d på seriell-port. Når den mottar en bokstav så kjører den av gårde tils dess at den får ett kommando den ikke kjenner igen. Då stanner den opp.

Vi kan sende den bokstaver på tre forskellige måter, med samme resultater:
* USB-to-Serial fra Arduino programmets serial monitor.
* [Bluetooth-to-Serial](https://github.com/KubenKoder/Arduino/blob/master/Egna%20exempel/Rover/readme.md#bluetooth) fra Arduino programmets serial monitor.
* [Wifi-to-Serial](https://github.com/KubenKoder/Arduino/blob/master/Egna%20exempel/Rover/readme.md#wifi-control-using-esp8266-onboard-web-server---now-working) fra et nettside som sendes på lokalt nettverk av en ESP8266

Det speler ingen rolle vilken av disse vi bruker.

## Koblinger

Når vi skall smelte to Arduino-programmer sammen så må vi passe på å ikke bruke samme koblingpunkter til flere ting samtidig. 

Rover-programmet bruker koblingspunkter 5 til 8 for å styre motorerne. Koblingspunkter kalles ofte "pins".

<code>
int E1 = 6; //M1 Speed Control
int E2 = 5; //M2 Speed Control
int M1 = 8; //M1 Direction Control
int M2 = 7; //M2 Direction Control
</code>

Dette sensor-programmet bruker pins 9 og 10 så de passer sammen. (Det finns sikkert 100 forskellige sensor-programmer på nett som gjører samme sak, lit forskellig.)

<code>
const int trigPin = 9;
const int echoPin = 10;
</code>

Du kan ikke bruke samme pin til forksellige funksjoner. Vis du har en kollisjon så må du flytte sensor-pinnerne, motor-pinnernen er faste i rovern. 



