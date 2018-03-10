# About

This is a fork of [rcswitch-pi](https://github.com/r10r/rcswitch-pi). The send.cpp was altered so that a TriState code can be passed as an argument.


## Usage

First you have to install the [wiringpi](http://wiringpi.com/download-and-install/) library.
Afterwards, the example program can be compiled by executing `make`.
You may want to change the used GPIO pin in the send.cpp source file before compilation. By default GPIO17 will be used for sending data to the 433Mhz transmitter.

The example program can be used as follows:
```
./send <TriStateCode> ON
```
Of course,``<TriStateCode>`` must be replaced by a proper TriState code, e.g. `FF0FF00`, followed by ON or OFF. Information on TriState codes can be found in the [FHEM wiki](http://www.fhemwiki.de/wiki/Intertechno_Code_Berechnung) (only available in German).

## OpenHAB

This branch is compatible with the OpenHAB exec binding.

Example thing:

```
Thing exec:command:itD4 [command="/home/openhabian/rcswitch-pi/send FF00FF00 %2$s", interval=0, timeout=5, autorun=true]
```

Example item:
```
String LR_LIGHT "Living Room Light" [ "Switchable" ] { channel="exec:command:itD4:input" }
```

The `"Switchable"` tag ensures that the item can be found by Alexa (requires that the hue bridge emulator of OpenHAB is activated).
