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


void setup() {
  // put your setup code here, to run once:

  // sets up inputs and outputs
  myServo.attach(serve);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:

  // this for loop turns the servo motor half a counterclockwise rotation
  for (int deg = 0; deg <= 180; deg++) {

    myServo.write(deg); // turns the servo motor to the respective degree
    delay(10); // delay of 10 ms between each turn in degree

    // the following code emits waves and calculates distance
    digitalWrite(trig, LOW); // eliminates sound
    delay(10); // delays for 10 ms
    digitalWrite(trig, HIGH); // emits sound waves 
    delayMicroseconds(10); // delayes 10 us
    digitalWrite(trig, LOW); // stops sound pulses
    dur = pulseIn(echo, HIGH); // finds time duration
    dist = dur * 0.017; // calculates distance from object

    // executes if object is less than 10 cm from scanner
    if (dist < 10)
    {
      digitalWrite(red, HIGH); // turns off red LED
      digitalWrite(green, LOW); // turns the green light on when object is far away
      digitalWrite(blue, LOW); // turns off blue LED
      tone(buzz, 432); // plays high note
    }

    // executes if if object is more than 10 cm but less than 25 cm from scanner
    else if (dist < 25)
    {
      digitalWrite(red, LOW); // turns off red LED
      digitalWrite(green, HIGH); // turns the green light on when object is far away
      digitalWrite(blue, LOW); // turns off blue LED
      tone(buzz, 216); // plays lower note
    }

    // executes if distance of object is greater than 25 cm from scanner
    else 
    {
      digitalWrite(red, LOW); // turns off red LED
      digitalWrite(green, LOW); // turns the green light on when object is far away
      digitalWrite(blue, HIGH); // turns off blue LED
      noTone(buzz); // plays lower note
    }
  }

  // this for loop turns the servo motor half  clockwise rotation
  for (int deg = 180; deg >= 0; deg--) {
    myServo.write(deg); // turns the servo motor to the respective degree
    delay(10); // delay of 20 ms between each turn in degree
    
    // the following code emits waves and calculates distance
    digitalWrite(trig, LOW); // eliminates sound
    delay(10); // delays for 10 ms
    digitalWrite(trig, HIGH); // emits sound waves 
    delayMicroseconds(10); // delayes 10 us
    digitalWrite(trig, LOW); // stops sound pulses
    dur = pulseIn(echo, HIGH); // finds time duration
    dist = dur * 0.017; // calculates distance from object

    // executes if object is less than 10 cm from scanner
    if (dist < 10)
    {
      digitalWrite(red, HIGH); // turns off red LED
      digitalWrite(green, LOW); // turns the green light on when object is far away
      digitalWrite(blue, LOW); // turns off blue LED
      tone(buzz, 432); // plays high note
    }

    // executes if if object is more than 10 cm but less than 25 cd from scanner
    else if (dist < 25)
    {
      digitalWrite(red, LOW); // turns off red LED
      digitalWrite(green, HIGH); // turns the green light on when object is far away
      digitalWrite(blue, LOW); // turns off blue LED
      tone(buzz, 216); // plays lower note
    }

    // executes if distance of object is greater than 25 cm from scanner
    else 
    {
      digitalWrite(red, LOW); // turns off red LED
      digitalWrite(green, LOW); // turns the green light on when object is far away
      digitalWrite(blue, HIGH); // turns off blue LED
      noTone(buzz); // plays lower note
    }
  }
}
