// defining the pins
const int trigPin = 9;
const int echoPin = 10;

const int speakerOut = 3;


// NOTE FREQUENCIES
const double MIDDLE_C = 261.626;

// defining variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  while (true) {
    check();
    delay (1000);
  }
}

void check() {
  Serial.println ("Checking...");
  noTone (speakerOut);
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 100) {
    tone (speakerOut, MIDDLE_C, 1000);
  }

}

//void loop() {
//  // Clears the trigPin
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  // Sets the trigPin on HIGH state for 10 micro seconds
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  // Reads the echoPin, returns the sound wave travel time in microseconds
//  duration = pulseIn(echoPin, HIGH);
//  // Calculating the distance
//  distance= duration*0.034/2;
//  // Prints the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.println(distance);
//
//  if (distance < 100) {
//    tone (speakerOut, MIDDLE_C, 1000);
//    //delayMicroseconds(1000);
//  }
//
//  //noTone (speakerOut);
//}


