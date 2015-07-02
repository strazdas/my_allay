// the setup function runs once when you press reset or power the board
int sensorPin = 14;  // A0
int humidity_value = 0;
int humidity_low = 70;   // max 710
int times_pumped = 0;

void setup() {
  pinMode(sensorPin, INPUT);
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);              // wait for a second
  humidity_value = analogRead(sensorPin);
  Serial.println(humidity_value);
  times_pumped = 0;
  while ((humidity_value <= humidity_low) && (times_pumped < 5)) {
    digitalWrite(13, HIGH);
    delay(1000);
    humidity_value = analogRead(sensorPin);
    times_pumped += 1;
    Serial.println(humidity_value);
  };
}
