# RTC DS3231 with LED Control

This Arduino project demonstrates how to use the DS3231 Real-Time Clock (RTC) Module to get accurate time, date, and temperature readings. It also includes an LED control feature, where the LED is turned on between specific times (08:15 AM to 09:30 AM) based on the RTC's time. 

# Features:
- Real-time clock: The DS3231 RTC module is used to track the current time, date, and temperature.
- Temperature monitoring: Reads the temperature from the DS3231 sensor.
- LED control: Turns on an LED between 08:15 and 09:30, based on the current time.
- Date and Time Display: Prints the current date, time, and day of the week to the Serial Monitor.

# Components Used:
- Arduino Board (Uno, Nano, etc.)
- DS3231 RTC Module
- LED connected to pin 13 on the Arduino
- Resistor (typically 220Ω for the LED)

# How It Works:
1. RTC Module: The DS3231 RTC module is initialized in the setup() function, and the time is set to the time of the Arduino's compilation time.
2. Time and Date Display: In the loop() function, the current time (hour, minute, second), date (day, month, year), and the day of the week are read from the RTC and displayed on the Serial Monitor.
3. Temperature: The current temperature (in Celsius) is fetched from the DS3231 and displayed on the Serial Monitor.
4. LED Control: The LED connected to pin 13 is turned on between 08:15 and 09:30 based on the current RTC time. If the time is outside this range, the LED is turned off.

# Wiring Diagram:
- DS3231 RTC Module: Connect VCC to 5V, GND to GND, SCL to A5, and SDA to A4 on an Arduino Uno (for other boards, check the appropriate SCL and SDA pins).
- LED: Connect the longer leg (anode) to pin 13 and the shorter leg (cathode) to GND, using a current-limiting resistor (220Ω recommended).

# Code Explanation:
- The code starts by initializing the RTC and setting the time.
- It continuously reads the current time, day, and temperature from the DS3231.
- The LED is controlled based on a time window (08:15 to 09:30), turning on during this period and off otherwise.
- The data is printed to the Serial Monitor every second for real-time tracking.

# Libraries Required:
- RTClib library by Adafruit for interfacing with the DS3231 RTC module.

To install the RTClib library, go to Sketch > Include Library > Manage Libraries..., then search for RTClib and install it. 
