const int inButton = 2;
int count;

void setup() {
  pinMode(inButton, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  int switchState = digitalRead(inButton);

  if (count == 4 or count == 0) {
    count = 0;
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  if (switchState == HIGH) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(250);
    count++;
    digitalWrite((count + 2), HIGH);
  }
}
