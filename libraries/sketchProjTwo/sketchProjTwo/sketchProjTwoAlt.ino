/*
 * Project 2! Spaceship Interface
 * 
 * This is a nice simple button push system. In this alternate version the cycle runs forever, but will not start if the button is pushed.
 * 
 */
const int inButton = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(inButton, INPUT); //Input from button push.
  pinMode(3, OUTPUT); //Output to Red LED
  pinMode(4, OUTPUT); //Output to Blue LED
  pinMode(5, OUTPUT); //Output to Green LED
}

void loop() {
  // put your main code here, to run repeatedly:

  int switchState = digitalRead(inButton);
  
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  // Check to see if button is pushed, if not then begin light sequence.
  if (!switchState) {
    digitalWrite(3, HIGH);
    delay(200);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(4, LOW);
  }
}
