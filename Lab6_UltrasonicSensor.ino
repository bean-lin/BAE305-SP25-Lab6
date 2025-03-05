// Declares constants and variables
const int trigPin = 11;
const int echoPin = 10;

float duration, distance;

void setup() {
  // put your setup code here, to run once:

  // Assigns input and output pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Declares the serial communication rate
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Resets the transmitter to low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Transmits a sonic burst from the transmitter
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Records the travel time of the sonic burst between the transmitter and the reciever
  duration = pulseIn(echoPin, HIGH);
  // Computes distance by comparing to the speed of sound, round trip
  distance = (duration*.0343)/2;

  // Prints distance to the user's Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
