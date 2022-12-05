int led_pins[] = { 12, 10, 11, 13 };

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potentiometerValue = analogRead(A0);

  delay(potentiometerValue);

  if (potentiometerValue != 0) {
    for (auto i : led_pins) {
      digitalWrite(i, HIGH);
    }

    delay(potentiometerValue);

    for (auto i : led_pins) {
      digitalWrite(i, LOW);
    }
  }

  if (potentiometerValue == 0) {
    for (auto i : led_pins) {
      digitalWrite(i, LOW);
    }
  }
}
