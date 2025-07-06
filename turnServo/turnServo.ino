# include <Servo.h>
Servo myServo;

// declarations and initalizations

int pot = A0; // defines A0 as the input pin for the slide pot
int serve = 10; // defines 10 as the output pin for the servo motor
int value; // value for the reading from the slide pot
int angle; // angle that the servo motor turns


void setup() {
  // put your setup code here, to run once:
  
  myServo.attach(serve); // setup for servo pin
  pinMode(pot, INPUT); // setup for slide pot


}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(pot); // reads the slide pot
  angle = map(value, 0, 1023, 0, 180); // maps 0 - 1023 reading from the slide pot to 0 - 180 input to the servo
  myServo.write(angle);
  

}
