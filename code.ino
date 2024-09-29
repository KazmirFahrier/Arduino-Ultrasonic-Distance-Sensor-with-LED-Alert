// Variables
unsigned long echo = 0;  // To store the echo time from the ultrasonic sensor
int ultraSoundSignal = 7;  // Pin number for the ultrasonic sensor trigger
unsigned long ultrasoundValue = 0;  // To store the calculated distance value
int val;  // To read input from the button connected to pin 13

// Setup function
void setup() {
  // Initialize serial communication at 9600 bps for debugging
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(ultraSoundSignal, OUTPUT);  // Ultrasonic trigger pin
  pinMode(9, OUTPUT);  // Pin to control the LED
  pinMode(13, INPUT);  // Button pin
}

// Function to measure distance using the ultrasonic sensor
unsigned long ping() {
  // Trigger the ultrasonic sensor
  pinMode(ultraSoundSignal, OUTPUT);  // Set pin to output
  digitalWrite(ultraSoundSignal, LOW);  // Set low to initialize
  delayMicroseconds(2);  // Wait for 2 microseconds
  digitalWrite(ultraSoundSignal, HIGH);  // Set high to send a pulse
  delayMicroseconds(5);  // Wait for 5 microseconds
  digitalWrite(ultraSoundSignal, LOW);  // Turn off the pulse

  // Listen for echo
  pinMode(ultraSoundSignal, INPUT);  // Switch pin to input
  echo = pulseIn(ultraSoundSignal, HIGH);  // Get the duration of the echo

  // Calculate the distance in inches
  ultrasoundValue = (float)echo * 0.01723;  // Conversion from echo time to distance
  return ultrasoundValue;  // Return the calculated distance
}

// Main loop function
void loop() {
  val = digitalRead(13);  // Read the button state
  
  // If the button is pressed (HIGH state)
  if (val == HIGH) {
    int x = ping();  // Measure distance
    Serial.println(x);  // Print distance to serial monitor for debugging

    // If the object is closer than 12 inches, turn on the LED
    if (x < 12) {
      digitalWrite(9, HIGH);  // Turn on LED
      delay(100);  // Wait for 100 ms
      digitalWrite(9, LOW);  // Turn off LED
      delay(100);  // Wait for 100 ms
    } else {
      // Otherwise, keep the LED off
      digitalWrite(9, LOW);  // Keep LED off
      delay(250);  // Wait for 250 ms
    }
  }
}

