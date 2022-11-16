#define POWER_PIN  7
#define SIGNAL_PIN A5
#define RELAY_PIN A0

int value = 0; // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  sensor_value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("Sensor value: ");
  Serial.println(sensor_value);

  delay(1000);

  if(120 < sensor_value && sensor_value < 150){
    //insert relay activation here
    digitalWrite(RELAY_PIN, HIGH);
  }
  
}


//range between 120-150 for water sensor
