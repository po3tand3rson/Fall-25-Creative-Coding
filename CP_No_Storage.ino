#include <Adafruit_CircuitPlayground.h>

void setup() {
  // Initialize the circuit playground
  CircuitPlayground.begin();
}

void loop() {
  // If the left button is pressed....
  if(CircuitPlayground.leftButton()) {
    int r = random(0, 255);
    int g = random(0, 255);
    int b = random(0, 255);
  }

  //playground board makes sound when moved
  float x = CircuitPlayground.motionX();
  float y = CircuitPlayground.motionY();
  float z = CircuitPlayground.motionZ();

  //movement speed 
  float magnitude = sqrt(x * x + y * y + z * z);

  //motion indicator
  if (magnitude > 15) {
    //pitch adjustor!
    int frequency = map((int)magnitude, 15, 50, 400, 1200);
    //frequency = constrain(frequency, 400, 1200);
    CircuitPlayground.playTone(frequency, 150); // Play short tone
  }

  //loop delay so i don't go crazy
  delay(50);
}
