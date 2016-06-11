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
LIBS:ESP8266
LIBS:arduino_shieldsNCL
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Wifi Sensor array shield"
Date "2016-06-10"
Rev "1.0"
Comp "Kevin Isabelle"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP-12E U1
U 1 1 575B6A25
P 7550 4200
F 0 "U1" H 7550 4100 50  0000 C CNN
F 1 "ESP-12E" H 7550 4300 50  0000 C CNN
F 2 "ESP8266:ESP-12E" H 7550 4200 50  0001 C CNN
F 3 "" H 7550 4200 50  0001 C CNN
	1    7550 4200
	-1   0    0    1   
$EndComp
$Comp
L ARDUINO_SHIELD Wifi1
U 1 1 575B6AE3
P 4000 4300
F 0 "Wifi1" H 3750 5250 60  0000 C CNN
F 1 "ARDUINO_SHIELD" H 4050 3350 60  0000 C CNN
F 2 "arduino_shields:ARDUINO_SHIELD_2" H 4000 4300 60  0001 C CNN
F 3 "" H 4000 4300 60  0000 C CNN
	1    4000 4300
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P1
U 1 1 575B703F
P 5650 4100
F 0 "P1" H 5650 4300 50  0000 C CNN
F 1 "PIR Sensor" V 5750 4100 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03" H 5650 4100 50  0001 C CNN
F 3 "" H 5650 4100 50  0000 C CNN
	1    5650 4100
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P2
U 1 1 575B71D4
P 2400 5200
F 0 "P2" H 2400 5400 50  0000 C CNN
F 1 "Light Sensor" V 2500 5200 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03" H 2400 5200 50  0001 C CNN
F 3 "" H 2400 5200 50  0000 C CNN
	1    2400 5200
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X03 P3
U 1 1 575B738F
P 2400 4600
F 0 "P3" H 2400 4800 50  0000 C CNN
F 1 "Sound Sensor" V 2500 4600 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03" H 2400 4600 50  0001 C CNN
F 3 "" H 2400 4600 50  0000 C CNN
	1    2400 4600
	-1   0    0    1   
$EndComp
NoConn ~ 3050 4200
NoConn ~ 3050 3900
NoConn ~ 3050 4400
NoConn ~ 3050 4600
NoConn ~ 3050 4700
NoConn ~ 3050 4800
NoConn ~ 3050 4900
NoConn ~ 4950 5100
NoConn ~ 4950 5000
NoConn ~ 4950 4800
NoConn ~ 4950 4700
NoConn ~ 4950 4600
NoConn ~ 4950 4500
NoConn ~ 4950 4400
NoConn ~ 4950 4200
NoConn ~ 4950 4100
NoConn ~ 4950 3800
NoConn ~ 4950 3700
NoConn ~ 4950 3500
NoConn ~ 7300 3300
NoConn ~ 7400 3300
NoConn ~ 7500 3300
NoConn ~ 7600 3300
NoConn ~ 7700 3300
NoConn ~ 7800 3300
NoConn ~ 6650 4000
NoConn ~ 6650 4200
NoConn ~ 6650 4300
NoConn ~ 8450 3900
NoConn ~ 8450 4000
NoConn ~ 8450 4100
NoConn ~ 8450 4200
NoConn ~ 8450 4400
NoConn ~ 8450 4500
Wire Wire Line
	5450 4200 5450 4900
Wire Wire Line
	5450 4900 4950 4900
Wire Wire Line
	5450 4100 5250 4100
Wire Wire Line
	5250 4100 5250 3600
Wire Wire Line
	4950 3600 6350 3600
Wire Wire Line
	5450 4000 5450 3150
Wire Wire Line
	5450 3150 2950 3150
Wire Wire Line
	2950 3150 2950 4100
Wire Wire Line
	2650 4100 3050 4100
Wire Wire Line
	2600 5100 3050 5100
Wire Wire Line
	2600 4500 2900 4500
Wire Wire Line
	2900 4500 2900 5000
Wire Wire Line
	2900 5000 3050 5000
Wire Wire Line
	3050 4300 2750 4300
Wire Wire Line
	2750 4300 2750 5200
Wire Wire Line
	2750 5200 2600 5200
Wire Wire Line
	2600 4600 2750 4650
Connection ~ 2750 4650
Wire Wire Line
	2600 4700 2650 4700
Wire Wire Line
	2650 4100 2650 5300
Connection ~ 2950 4100
Wire Wire Line
	2650 5300 2600 5300
Connection ~ 2650 4700
Wire Wire Line
	3050 4000 2700 4000
Wire Wire Line
	2700 4000 2700 2850
Wire Wire Line
	2700 2850 8750 2850
Wire Wire Line
	8750 2850 8750 4300
Wire Wire Line
	8750 3800 8450 3800
Wire Wire Line
	6500 2850 6500 4100
Wire Wire Line
	6500 4100 6650 4100
Connection ~ 6500 2850
Wire Wire Line
	8750 4300 8450 4300
Connection ~ 8750 3800
Wire Wire Line
	6350 3600 6350 3900
Wire Wire Line
	6350 3800 6650 3800
Connection ~ 5250 3600
Wire Wire Line
	6350 3900 6650 3900
Connection ~ 6350 3800
Wire Wire Line
	6650 4500 5100 4500
Wire Wire Line
	5100 4500 5100 3900
Wire Wire Line
	5100 3900 4950 3900
Wire Wire Line
	6650 4400 5000 4400
Wire Wire Line
	5000 4400 5000 4000
Wire Wire Line
	5000 4000 4950 4000
$EndSCHEMATC
