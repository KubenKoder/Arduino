# Ultrasound + Rover

Vi ønsker å kombinere disse:

* [Ultrasonic range finder, 4 pin](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)
* [DFRoboshop Rover](https://github.com/KubenKoder/Arduino/blob/master/Egna%20exempel/Rover/readme.md)

Rovern lytter etter bokstaver w,s,a, og d på seriell-port. Når den mottar en bokstav så kjører den av gårde tils dess at den får ett kommando den ikke kjenner igen. Då stanner den opp.

Vi kan sende den bokstaver på tre forskellige måter, med samme resultater:
* USB-to-Serial fra Arduino programmets serial monitor.
* [Bluetooth-to-Serial](https://github.com/KubenKoder/Arduino/blob/master/Egna%20exempel/Rover/readme.md#bluetooth) fra Arduino programmets serial monitor.
* [Wifi-to-Serial](https://github.com/KubenKoder/Arduino/blob/master/Egna%20exempel/Rover/readme.md#wifi-control-using-esp8266-onboard-web-server---now-working) fra et nettside som sendes på lokalt nettverk av en ESP8266

Det speler ingen rolle vilken av disse vi bruker.

## Koblinger

Når vi skall smelte to Arduino-programmer sammen så må vi passe på å ikke bruke samme koblingpunkter til flere ting samtidig. 

Rover-programmet bruker koblingspunkter 5 til 8 for å styre motorerne. Koblingspunkter kalles ofte "pins".

```cpp
int E1 = 6; //M1 Speed Control
int E2 = 5; //M2 Speed Control
int M1 = 8; //M1 Direction Control
int M2 = 7; //M2 Direction Control
```

Dette sensor-programmet bruker pins 9 og 10 så de passer sammen. (Det finns sikkert 100 forskellige sensor-programmer på nett som gjører samme sak, lit forskellig.)

```cpp
const int trigPin = 9;
const int echoPin = 10;
```

Du kan ikke bruke samme pin til forksellige funksjoner. Vis du har en kollisjon så må du flytte sensor-pinnerne, motor-pinnernen er faste i rovern. 

## Slå sammen kode

Koden har tre hoveddeler. 

* Ting som har med minne og gjøre
* Setup delen
* Loop delen

(Rover programmet har i tillegg ekstra deler for forward, reverse, left, right og stop.)

Når du slår ting sammen så må du hålle kode fra en del inom sin del. Det hjelper å markere hva som er hva med kommentarer i koden, de gjør du med to //-tegn. Allt bak dem blir ignorert i koden.

På denne måten:

```
// SENSOR-TING
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
//SLUTT PÅ SENSOR-TING
```

## IF - Hvis noe er sant, gjør dette

[Kode med if satser for å reagere på sensor](ultrasound_rover/ultrasound_rover.ino)

```
// Reagere på sensor
if(distance <20){
  reverse(120, 120); //Bakke i halv fart (255 er max)
  delay(2000); //bakke i 2 sekunder (i millisekunder)
  stop();
}
//Slutt på reaksjon
```
