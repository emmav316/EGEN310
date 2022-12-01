#include <Servo.h>
#define POWER_PIN  7
#define SIGNAL_PIN A5

Servo servo1;
int servoPin = 9;
int sensor_value = 0; // variable to store the sensor value

void setup(){
  servo1.attach(servoPin);
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
}

void loop(){
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  sensor_value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("Sensor value: ");
  Serial.println(sensor_value);

  delay(1000);

  if(sensor_value > 1){ //120 < sensor_value && sensor_value < 150
    servo1.write(0);
    delay(1000);
    servo1.write(90);
    delay(1000);
    servo1.write(180);
    delay(1000);
  }
  else{
    Serial.print("else servo");
  }
}



