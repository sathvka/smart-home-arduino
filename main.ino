int pirPin = 2;        // PIR sensor
int ldrPin = A0;       // Light sensor
int tempPin = A1;      // Temperature sensor (LM35)
int ledPin = 13;       // LED indicator

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  int light = analogRead(ldrPin);
  int tempVal = analogRead(tempPin);

  float temperature = (tempVal / 1023.0) * 500;  // LM35 approx convert

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" | Light: ");
  Serial.print(light);
  Serial.print(" | Temp(C): ");
  Serial.println(temperature);

  if (motion == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(300);
}
