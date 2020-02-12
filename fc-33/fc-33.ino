#define LED_PIN 3
#define SIGNAL_PIN 12
#define BTN_START 10
#define CYCLE_TIME 10

int count = 0;
bool status = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_START, INPUT);
  pinMode(SIGNAL_PIN, INPUT);
}

void loop() {
  while(digitalRead(BTN_START)==LOW)
    delay(100);
  while(digitalRead(BTN_START)==HIGH)
    delay(100);

  digitalWrite(LED_PIN, HIGH);
  while(digitalRead(BTN_START)==LOW){
    if(digitalRead(SIGNAL_PIN)!=status)
      if(digitalRead(SIGNAL_PIN)==HIGH){
        count++;
          Serial.println(count);
    }
    
    delay(CYCLE_TIME);
  }
  digitalWrite(LED_PIN, LOW);

  while(digitalRead(BTN_START)==HIGH)
    delay(100);
}
