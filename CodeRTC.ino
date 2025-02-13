#include "RTClib.h"
RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int hour, minute, second;
int day, month, year;
String weekday;

const int ledPin = 13; // Adjust with the pin used for the LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);  // Wait indefinitely if the RTC is not found
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Adjust the RTC time to the compile time
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0)); // Example of manual adjustment
}

void loop() {
  DateTime now = rtc.now();

  // Get time data
  hour    = now.hour();
  minute  = now.minute();
  second  = now.second();
  day     = now.day();
  month   = now.month();
  year    = now.year();
  weekday = daysOfTheWeek[now.dayOfTheWeek()];

  // Display current date and time
  Serial.println(String() + "Day: " + weekday + ", " + day + "-" + month + "-" + year);
  Serial.println(String() + "Time: " + hour + ":" + minute + ":" + second);

  // Display temperature from the DS3231 RTC sensor
  float temperature = rtc.getTemperature();
  Serial.print("Current Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Condition to turn on LED between 08:15 and 09:30
  if ((hour == 10 && minute >= 39) || (hour == 11 && minute < 30)) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    Serial.println("LED is ON");
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED
    Serial.println("LED is OFF");
  }

  Serial.println();
  delay(1000); // Wait for 1 second before the next loop
}
