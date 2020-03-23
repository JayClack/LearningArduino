int const analogInput = A0;
int const calibOutput = 9;

int sensorBaseline;
int sensorValue;
int sensorMax = 0;
int sensorMin = 1023;

void setup() {
  Serial.begin(9600);
  
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(analogInput);
    
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  sensorBaseline = analogRead(analogInput);
  float voltageBaseline = (sensorBaseline / 1024.0) * 5.0;
  digitalWrite(9, LOW);
}

void loop() {
  sensorValue = analogRead(analogInput);
  float voltageBaseline = (sensorBaseline / 1024.0) * 5.0;
  float temperatureBaseline = (voltageBaseline - 0.5) * 100.0;
  float voltageIn = (sensorValue / 1024.0) * 5.0;
  float temperatureIn = (voltageIn - 0.5) * 100.0;

  if (temperatureIn < temperatureBaseline + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperatureIn > temperatureBaseline + 2 && temperatureIn <= temperatureBaseline + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperatureIn > temperatureBaseline + 4 && temperatureIn <= temperatureBaseline + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperatureIn > temperatureBaseline + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  Serial.print("The baseline voltage is: ");
  Serial.print(voltageBaseline);
  Serial.print(". The temperature baseline is: ");
  Serial.println(temperatureBaseline);
  Serial.print("The current sensor value is: ");
  Serial.print(sensorValue);
  Serial.print(". The Voltage is: ");
  Serial.print(voltageIn);
  Serial.print(". The temperature is: ");
  Serial.println(temperatureIn);

  delay(1);
}
