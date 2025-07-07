#include <Servo.h>

// creates a servo object
Servo myServo;


// declarations and initalizations for the ultrasonic sensor

int trig = 10; // trig pin on pin 10
int echo = 11; // trig pin on pin 11
long dur; // variable for the time duration of the high signal
float dist; // variable for the distance calculated

int buzz = 9; // passive buzzer on pin 9
int serve = 3; // servo motor attached as output on pin 3

int red = 4; // red anode on pin 4
int green = 5; // green anode on pin 5
int blue = 6; // blue anode on pin 6


// this is my setup code
void setup() {
  // put your setup code here, to run once:
  myServo.attach(serve);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}


// this code operates the scanner and loops over and over again
void loop() {
  // put your main code here, to run repeatedly:

  // this for loop turns the servo motor half a counterclockwise rotation
  for (int deg = 0; deg <= 180; deg++) {
    myServo.write(deg); // turns the servo motor to the respective degree
    
    
    delay(20);
  }

  // this for loop turns the servo motor half  clockwise rotation
  for (int deg = 180; deg >= 0; deg--) {
    myServo.write(deg); // turns the servo motor to the respective degree
    
    
    
    delay(20);
  }

}
