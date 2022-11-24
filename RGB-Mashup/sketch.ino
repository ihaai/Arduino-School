#define LED_RED_PIN       13
#define LED_GREEN_PIN     12
#define LED_BLUE_PIN      11
#define PR_AI_RED_PIN     A0
#define PR_AI_GREEN_PIN   A1
#define PR_AI_BLUE_PIN    A2

// LED values
int rValue = 0;
int gValue = 0;
int bValue = 0;

// Photoresistor raw values
int pr_rawRed = 0;
int pr_rawGreen = 0;
int pr_rawBlue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pr_rawRed = analogRead(PR_AI_RED_PIN);
  pr_rawGreen = analogRead(PR_AI_GREEN_PIN);
  pr_rawBlue = analogRead(PR_AI_BLUE_PIN);

  rValue = pr_rawRed / 4;
  gValue = pr_rawGreen / 4;
  bValue = pr_rawBlue / 4;

  analogWrite(LED_RED_PIN, rValue);
  analogWrite(LED_GREEN_PIN, gValue);
  analogWrite(LED_BLUE_PIN, bValue);

  Serial.println(rValue);
  Serial.println(gValue);
  Serial.println(bValue);

  delay(1000);
}
