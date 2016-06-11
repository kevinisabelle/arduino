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
LIBS:74xgxx
LIBS:ac-dc
LIBS:actel
LIBS:Altera
LIBS:analog_devices
LIBS:battery_management
LIBS:bbd
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
LIBS:sensors
LIBS:silabs
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:transf
LIBS:ttl_ieee
LIBS:video
LIBS:Worldsemi
LIBS:Xicor
LIBS:Zilog
LIBS:opa-audio-input-cache
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Audio input with OPA2132"
Date "2016-05-31"
Rev ""
Comp "Kevin Isabelle"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TL072 U1
U 1 1 574D0A2E
P 5350 4300
F 0 "U1" H 5300 4500 50  0000 L CNN
F 1 "TL072" H 5300 4050 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 5350 4300 50  0000 C CNN
F 3 "" H 5350 4300 50  0000 C CNN
	1    5350 4300
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR01
U 1 1 574D0B0A
P 5250 3950
F 0 "#PWR01" H 5250 3800 50  0001 C CNN
F 1 "+9V" H 5250 4090 50  0000 C CNN
F 2 "" H 5250 3950 50  0000 C CNN
F 3 "" H 5250 3950 50  0000 C CNN
	1    5250 3950
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR02
U 1 1 574D0B60
P 5250 4700
F 0 "#PWR02" H 5250 4450 50  0001 C CNN
F 1 "GNDREF" H 5250 4550 50  0000 C CNN
F 2 "" H 5250 4700 50  0000 C CNN
F 3 "" H 5250 4700 50  0000 C CNN
	1    5250 4700
	1    0    0    -1  
$EndComp
$Comp
L JACK_2P J1
U 1 1 574D0BEA
P 3800 4400
F 0 "J1" H 3450 4200 50  0000 C CNN
F 1 "JACK_2P" H 3650 4650 50  0000 C CNN
F 2 "Connect:BARREL_JACK" H 3800 4400 50  0000 C CNN
F 3 "" H 3800 4400 50  0000 C CNN
	1    3800 4400
	1    0    0    -1  
$EndComp
$Comp
L Earth #PWR03
U 1 1 574D0CA4
P 4350 3650
F 0 "#PWR03" H 4350 3400 50  0001 C CNN
F 1 "Earth" H 4350 3500 50  0001 C CNN
F 2 "" H 4350 3650 50  0000 C CNN
F 3 "" H 4350 3650 50  0000 C CNN
	1    4350 3650
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 4300 6000 4300
Text GLabel 6000 4300 2    60   Input ~ 0
Output
Wire Wire Line
	5250 4000 5250 3950
Wire Wire Line
	5250 4600 5250 4700
$Comp
L C C1
U 1 1 574D0EAD
P 4500 4400
F 0 "C1" H 4525 4500 50  0000 L CNN
F 1 "0.1uf" H 4525 4300 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 4538 4250 50  0000 C CNN
F 3 "" H 4500 4400 50  0000 C CNN
	1    4500 4400
	0    1    1    0   
$EndComp
$Comp
L CP1 C2
U 1 1 574D0B78
P 5250 5000
F 0 "C2" H 5275 5100 50  0000 L CNN
F 1 "10uf" H 5275 4900 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2.5" H 5250 5000 50  0000 C CNN
F 3 "" H 5250 5000 50  0000 C CNN
	1    5250 5000
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 574D11D7
P 5200 3650
F 0 "R3" V 5300 3650 50  0000 C CNN
F 1 "R" V 5200 3650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 5130 3650 50  0000 C CNN
F 3 "" H 5200 3650 50  0000 C CNN
	1    5200 3650
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 574D1260
P 4650 3650
F 0 "R1" V 4730 3650 50  0000 C CNN
F 1 "R" V 4650 3650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4580 3650 50  0000 C CNN
F 3 "" H 4650 3650 50  0000 C CNN
	1    4650 3650
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 574D12F3
P 4850 5250
F 0 "R2" V 4930 5250 50  0000 C CNN
F 1 "R" V 4850 5250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4780 5250 50  0000 C CNN
F 3 "" H 4850 5250 50  0000 C CNN
	1    4850 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4200 5050 4200
Wire Wire Line
	4800 3650 5050 3650
Wire Wire Line
	5350 3650 5800 3650
Wire Wire Line
	5800 3650 5800 5000
Connection ~ 5800 4300
Wire Wire Line
	5800 5000 5400 5000
Wire Wire Line
	5100 5000 4850 5000
Wire Wire Line
	4850 4400 4850 5100
Wire Wire Line
	4650 4400 5050 4400
Connection ~ 4850 4400
Connection ~ 4850 3650
Connection ~ 4850 5000
Wire Wire Line
	4250 4400 4350 4400
Wire Wire Line
	4250 4250 4450 4250
Wire Wire Line
	4850 3650 4850 4200
Wire Wire Line
	4450 4250 4450 3650
Wire Wire Line
	4350 3650 4500 3650
Connection ~ 4450 3650
$Comp
L Earth #PWR04
U 1 1 574DB97A
P 4850 5400
F 0 "#PWR04" H 4850 5150 50  0001 C CNN
F 1 "Earth" H 4850 5250 50  0001 C CNN
F 2 "" H 4850 5400 50  0000 C CNN
F 3 "" H 4850 5400 50  0000 C CNN
	1    4850 5400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
