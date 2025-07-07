
#include <Servo.h>

Servo myServo;

void setup() {
  // put your setup code here, to run once:
   myServo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int deg = 0; deg <= 200; deg++) {
    myServo.write(deg);
    delay(20);
  }
  for (int deg = 200; deg >= 0; deg--) {
    myServo.write(deg);
    delay(20);
  }
}
