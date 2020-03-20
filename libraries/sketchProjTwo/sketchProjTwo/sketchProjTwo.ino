/*
 * Project 2! Spaceship Interface
 * 
 * This is a nice simple button push system. When the input is read from the button push, a simple LED Flash sequence is performed.
 * 
 */
 
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT); //Input from button push.
  pinMode(3, OUTPUT); //Output to Red LED
  pinMode(4, OUTPUT); //Output to Blue LED
  pinMode(5, OUTPUT); //Output to Green LED
}

void loop() {
  // put your main code here, to run repeatedly:
  int switchState = digitalRead(2);

  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  
  if(switchState == HIGH) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250); 
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    delay(250);
  }
}
