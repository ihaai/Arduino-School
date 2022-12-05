#define BUZZ_PIN      13
#define GREEN_BTN_PIN 12
#define RED_BTN_PIN   11
#define BLUE_BTN_PIN  10
#define GREY_BTN_PIN  9

template<typename K, typename V>
struct pair {
  private:
    K Key;
    V Value;
  
  public:
    pair(K key, V value) {
      this->Key = key;
      this->Value = value;
    }

    K getKey() {
      return this->Key;
    }

    V getValue() {
      return this->Value;
    }
};

pair<int, int> btnPairValues[4] {
  pair<int, int>(GREEN_BTN_PIN, 100),
  pair<int, int>(RED_BTN_PIN, 150),
  pair<int, int>(BLUE_BTN_PIN, 250),
  pair<int, int>(GREY_BTN_PIN, 333)
};

void setup() {
  // put your setup code here, to run once:
  for (int i = 9; i <= 12; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(BUZZ_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (auto currentPair : btnPairValues) {
    if (digitalRead(currentPair.getKey()) == LOW) {
      tone(BUZZ_PIN, currentPair.getValue());
      delay(100);
    }
  }

  noTone(BUZZ_PIN);
}