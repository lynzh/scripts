int x = 13;          // declare pin 13 as x

void setup() { // open a bracket
  Serial.begin(9600);              // start serial communication at 9600 bytes per second
  pinMode(x, OUTPUT);              // declare pin13 as an OUTPUT
} // a bracket be closed

void loop() { // startaloop, open a bracket
  digitalWrite(x, HIGH);            // set the value of pin to HIGH voltage
  Serial.println(digitalRead(x));  // print the value of the led pin
  delay(1000);            // delay 1 sec
  digitalWrite(x, LOW);   // set the led pin to LOW voltage
  Serial.println(digitalRead(x)); // read the value of X
  delay(1000);      // delay by 1000 ms
}
