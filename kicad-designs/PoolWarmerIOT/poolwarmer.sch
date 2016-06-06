EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:sensors
LIBS:Symbols_DCDC-ACDC-Converter_RevC_20Jul2012
LIBS:Symbols_EN60617_13Mar2013
LIBS:Symbols_EN60617-10_HF-Radio_DRAFT_12Sep2013
LIBS:Symbols_ICs-Diskrete_RevD10
LIBS:Symbols_ICs-Opto_RevB_16Sep2013
LIBS:Symbols_Microcontroller_Philips-NXP_RevA_06Oct2013
LIBS:Symbols_Socket-DIN41612_RevA
LIBS:Symbols_Transformer-Diskrete_RevA
LIBS:SymbolsSimilarEN60617+oldDIN617-RevE8
LIBS:74xgxx
LIBS:ac-dc
LIBS:actel
LIBS:Altera
LIBS:analog_devices
LIBS:brooktre
LIBS:cmos_ieee
LIBS:dc-dc
LIBS:diode
LIBS:elec-unifil
LIBS:ESD_Protection
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:ir
LIBS:Lattice
LIBS:logo
LIBS:maxim
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic32mcu
LIBS:motor_drivers
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:onsemi
LIBS:Oscillators
LIBS:Power_Management
LIBS:powerint
LIBS:pspice
LIBS:references
LIBS:relays
LIBS:rfcom
LIBS:silabs
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:transf
LIBS:ttl_ieee
LIBS:video
LIBS:Xicor
LIBS:Zilog
LIBS:ESP8266
LIBS:poolwarmer-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TMP411 U?
U 1 1 5743ADB6
P 4450 2250
F 0 "U?" H 4150 2600 50  0000 L CNN
F 1 "TMP411" H 4500 2600 50  0000 L CNN
F 2 "" H 4350 2250 50  0000 C CIN
F 3 "" H 4350 2250 50  0000 C CNN
	1    4450 2250
	1    0    0    -1  
$EndComp
$Comp
L +12VA #PWR?
U 1 1 57474EB4
P 2800 2700
F 0 "#PWR?" H 2800 2550 50  0001 C CNN
F 1 "+12VA" H 2800 2840 50  0000 C CNN
F 2 "" H 2800 2700 50  0000 C CNN
F 3 "" H 2800 2700 50  0000 C CNN
	1    2800 2700
	1    0    0    -1  
$EndComp
$Comp
L ESP-12E U?
U 1 1 574751BD
P 3400 4450
F 0 "U?" H 3400 4350 50  0000 C CNN
F 1 "ESP-12E" H 3400 4550 50  0000 C CNN
F 2 "" H 3400 4450 50  0001 C CNN
F 3 "" H 3400 4450 50  0001 C CNN
	1    3400 4450
	1    0    0    -1  
$EndComp
$Comp
L ATMEGA328-P IC?
U 1 1 574752A3
P 8450 5250
F 0 "IC?" H 7700 6500 50  0000 L BNN
F 1 "ATMEGA328-P" H 8850 3850 50  0000 L BNN
F 2 "DIL28" H 8450 5250 50  0000 C CIN
F 3 "" H 8450 5250 50  0000 C CNN
	1    8450 5250
	1    0    0    -1  
$EndComp
$Comp
L TMP411 U?
U 1 1 57475497
P 5900 3600
F 0 "U?" H 5600 3950 50  0000 L CNN
F 1 "TMP411" H 5950 3950 50  0000 L CNN
F 2 "" H 5800 3600 50  0000 C CIN
F 3 "" H 5800 3600 50  0000 C CNN
	1    5900 3600
	1    0    0    -1  
$EndComp
$Comp
L TMP411 U?
U 1 1 574754E3
P 5500 5150
F 0 "U?" H 5200 5500 50  0000 L CNN
F 1 "TMP411" H 5550 5500 50  0000 L CNN
F 2 "" H 5400 5150 50  0000 C CIN
F 3 "" H 5400 5150 50  0000 C CNN
	1    5500 5150
	1    0    0    -1  
$EndComp
$Comp
L RM50-xx11 RL?
U 1 1 57475539
P 3100 1950
F 0 "RL?" H 3550 2100 50  0000 L CNN
F 1 "RM50-xx11" H 3550 2000 50  0000 L CNN
F 2 "" H 3100 1950 50  0000 C CNN
F 3 "" H 3100 1950 50  0000 C CNN
	1    3100 1950
	1    0    0    -1  
$EndComp
$Comp
L RM50-xx11 RL?
U 1 1 574755D6
P 1600 2100
F 0 "RL?" H 2050 2250 50  0000 L CNN
F 1 "RM50-xx11" H 2050 2150 50  0000 L CNN
F 2 "" H 1600 2100 50  0000 C CNN
F 3 "" H 1600 2100 50  0000 C CNN
	1    1600 2100
	1    0    0    -1  
$EndComp
$Comp
L BNC P?
U 1 1 574756BF
P 1400 3450
F 0 "P?" H 1410 3570 50  0000 C CNN
F 1 "BNC" V 1510 3390 50  0000 C CNN
F 2 "" H 1400 3450 50  0000 C CNN
F 3 "" H 1400 3450 50  0000 C CNN
	1    1400 3450
	1    0    0    -1  
$EndComp
$Comp
L PHOTORESISTOR U?
U 1 1 57475AE6
P 8300 2350
F 0 "U?" H 8310 2670 50  0000 C CNN
F 1 "PHOTORESISTOR" H 8310 2030 50  0000 C CNN
F 2 "" H 8300 2350 50  0000 C CNN
F 3 "" H 8300 2350 50  0000 C CNN
	1    8300 2350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
