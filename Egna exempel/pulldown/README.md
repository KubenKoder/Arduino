# Pulldown test

* Bygg [button](https://www.arduino.cc/en/tutorial/button) kretsen, anvænd D2 som button pin

DigitalRead måler om spenningen på "Button pin" er høy (5V) eller lav (0V) og gir en 1 eller 0 som svar.

Vi ønsker å måle spenningen på "Button pin" trinnløst (anlogt) med arduinon, dette kan vi gjøre hved å:

* Legg til en kabel mellom A0 (analog ingang) og D2

og med denne koden

* Last opp [koden](pulldown/pulldown.ino)
* Slå på Tools > Serial plotter
* Prøve knappen med og uten nedtrekknings-motstand

## Spørsmål
* Hva er forskellen på 0V-signal og å ikke ha noe koblet til?
* Hvorfor trenger vi nedtrekkningsmotstand?
* (Teoretiskt) Hva hade skjedd hvis vi koblet jord direkte til andre beinet på en 2-polt bryter? 

## Bonusuppgave
* Kan nedtrekkningsmotstandet bli for stort?
* Estatt knappen med vridpotentiometer og finn ut ved hvilken spenning den går fra lav til høy signal. Stemmer det med TTL nivåerne? (google)


# Bilder

![](plotter_mV.PNG)

![](plotter_mV_logic.PNG)
