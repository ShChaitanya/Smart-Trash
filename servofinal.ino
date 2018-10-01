#include <Servo.h>

Servo myservo;
int input;
void setup()
{
  pinMode(5,INPUT);
  myservo.attach(9);
  Serial.begin(9600);
  myservo.write(75);
}

void loop() {
  if (digitalRead(5) == HIGH) {
    input = 70;
    myservo.write(input);
    Serial.println(input);
    delay (1000);
  }
  myservo.write(0);
}
