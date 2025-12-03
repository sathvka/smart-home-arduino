#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int irPin = 3;
int ldrPin = A0;
int acPin = 4;
int lightPin = 5;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(acPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  int irState = digitalRead(irPin);    
  int ldrValue = analogRead(ldrPin);  
  float temp = dht.readTemperature();  

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" C | IR: "); Serial.print(irState);
  Serial.print(" | LDR: "); Serial.println(ldrValue);

  if (irState == HIGH) { // Person detected
    // Light control
    if (ldrValue < 500) {
      digitalWrite(lightPin, HIGH);
      Serial.println("Room Light ON");
    } else {
      digitalWrite(lightPin, LOW);
      Serial.println("Room Light OFF");
    }

    // AC control
    if (temp > 25) {
      digitalWrite(acPin, HIGH);
      Serial.println("AC ON");
    } else {
      digitalWrite(acPin, LOW);
      Serial.println("AC OFF");
    }

  } else { // No person
    digitalWrite(lightPin, LOW);
    digitalWrite(acPin, LOW);
    Serial.println("Room Empty → AC and Light OFF");
  }

  delay(1000);
}