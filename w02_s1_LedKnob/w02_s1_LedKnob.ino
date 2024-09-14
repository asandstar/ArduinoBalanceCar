/*
  LedKnob

  用电位器调节LED灯的明暗变化，了解
    1. PWM的用法
    2. 电位器的用法
  
  modified 2023-09-11
  by 唐国安 郭明旻
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9;  // Analog output pin that the LED is attached to

int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  /*
    value: the number to map.
    fromLow: the lower bound of the value’s current range.
    fromHigh: the upper bound of the value’s current range.
    toLow: the lower bound of the value’s target range.
    toHigh: the upper bound of the value’s target range.
  */

  // change the analog out value:
  analogWrite(analogOutPin, outputValue);


  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}