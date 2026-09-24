# Overvoltage-Undervoltage-Protection
// Overvoltage & Undervoltage Protection

const int voltagePin = A0;
const int relayPin = 8;

const float VREF = 5.0;
const float ADC_MAX = 1023.0;

// Set protection limits
const float OVER_VOLTAGE = 250.0;
const float UNDER_VOLTAGE = 180.0;

// Voltage sensor scaling
const float SENSOR_RATIO = 100.0;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(voltagePin);

  float sensorVoltage = (adcValue * VREF) / ADC_MAX;
  float inputVoltage = sensorVoltage * SENSOR_RATIO;

  Serial.print("Voltage: ");
  Serial.print(inputVoltage);
  Serial.println(" V");

  if (inputVoltage > OVER_VOLTAGE) {
    digitalWrite(relayPin, LOW);
    Serial.println("OVER VOLTAGE! Load OFF");
  }
  else if (inputVoltage < UNDER_VOLTAGE) {
    digitalWrite(relayPin, LOW);
    Serial.println("UNDER VOLTAGE! Load OFF");
  }
  else {
    digitalWrite(relayPin, HIGH);
    Serial.println("Voltage NORMAL - Load ON");
  }

  delay(1000);
}
