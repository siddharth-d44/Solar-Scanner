

// delcarations and initializations
int trig = 10; // digital pin for trig pin
int echo = 11; // digital pin for echo pin
long dur; // variable for the duration of sound waves
float dist; // variable for calculated distance


void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT); // trigger pin outputs sound
  pinMode(echo, INPUT); // echo pin recieves it
  Serial.begin(9600); // starts serial monitor

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW); // makes sure the environment is stable
  delay(10); // delays for 10 ms
  digitalWrite(trig, HIGH); // sends the digital pulse
  delayMicroseconds(10); // digital pulse continues for 10 us
  digitalWrite(trig, LOW); // digital pulse stops
  dur = pulseIn(echo, HIGH); // echo pin goes high and stays high until input is receievd - duration is recorded during this time
  dist = dur * 0.017; // uses a formula to calculate the distance from the duration of the sound pulse
  Serial.print("Distance: "); // gives a label for the duration in the serial monitor
  Serial.print(dist); // prints the distance
  Serial.println("cm"); // prints the cm label

}
