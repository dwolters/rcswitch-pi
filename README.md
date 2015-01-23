# About

This is a fork of [rcswitch-pi](https://github.com/r10r/rcswitch-pi). The send.cpp was altered so that a TriState code can be passed as an argument.


## Usage

First you have to install the [wiringpi](http://wiringpi.com/download-and-install/) library.
Afterwards, the example program can be compile be executing *make*.
You may want to change the used GPIO pin before compilation in the send.cpp source file. By default GPIO17 will be used for sending data to the 433Mhz transmitter.

The example program can be used as follows:
```
sudo ./send <TriStateCode>
```
Of course, *<TriStateCode>* must be replaced by a proper TriState code, e.g. *000000000FFF* (A01 On) or *000000000FF0* (A01 Off). Information on TriState codes can be found in the [FHEM wiki](http://www.fhemwiki.de/wiki/Intertechno_Code_Berechnung) (only available in German).
