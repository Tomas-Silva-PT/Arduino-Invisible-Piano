#define echoPin 9
#define trigPin 10
#define led1 13
#define led2 2
#define buzzer 5  // buzzer pin in Maker Nano RP2040 is 22

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int frequency; // variable for frequency of sound

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  // Ultrasonic Code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  
  if (distance < 10) {
    frequency = 523;
  }
  else if (distance < 15) {
    frequency = 587;
  }
  else if (distance < 20) {
    frequency = 659;
  }
  else if (distance < 25) {
    frequency = 698;
  }
  else if (distance < 30) {
    frequency = 783;
  }
  else if (distance < 35) {
    frequency = 880;
  }
  else if (distance < 40) {
    frequency = 987;
  }
  else if (distance < 45) {
    frequency = 1046;
  }
  else {
    frequency = 0;
  }

  if ( frequency != 0 ) {
    tone(buzzer, frequency);
    turnOnLeds();
    delay(500);
    noTone(buzzer);
    turnOffLeds();
    delay(500);
  } else {
    turnOffLeds();
  }
}

void turnOnLeds() {
digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
}

void turnOffLeds() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}
