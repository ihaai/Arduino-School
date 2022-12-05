int led_pins[] = { 12, 10, 11, 13 };

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btnState = digitalRead(8);

  if (btnState == LOW) {
    for (auto i : led_pins) {
      digitalWrite(i, HIGH);
      delay(1000);
      digitalWrite(i, LOW);
    }
  }
}
