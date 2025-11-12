#include <Wire.h>
#include <MPU6050_light.h>
#include <BleMouse.h>

BleMouse bleMouse("Smart Glove Mouse", "Rizwan", 100);
MPU6050 mpu(Wire);

// Hall sensors
const int hallLeft = 35;   // Left click
const int hallRight = 32;  // Right click
const int hallMove = 34;   // Movement control

int baseLeft, baseRight, baseMove;
const int threshold = 500;  

// Motion smoothing parameters
float smoothX = 0, smoothY = 0;
float damping = 0.85;      
float sensitivity = 0.25;   
float deadzone = 2.0;      

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing Smart Glove Mouse...");

  Wire.begin(21, 22);
  mpu.begin();
  mpu.calcOffsets(); 
  bleMouse.begin();

  delay(2000);
  Serial.println("Calibrating Hall sensors...");
  baseLeft = analogRead(hallLeft);
  baseRight = analogRead(hallRight);
  baseMove = analogRead(hallMove);

  Serial.println("System Ready — Pair Bluetooth 'Smart Glove Mouse'");
}

void loop() {
  if (!bleMouse.isConnected()) {
    Serial.println("Waiting for Bluetooth connection...");
    delay(1000);
    return;
  }

  
  mpu.update();

  int leftVal = analogRead(hallLeft);
  int rightVal = analogRead(hallRight);
  int moveVal = analogRead(hallMove);


  if (abs(leftVal - baseLeft) > threshold) {
    if (!bleMouse.isPressed(MOUSE_LEFT)) bleMouse.press(MOUSE_LEFT);
  } else {
    if (bleMouse.isPressed(MOUSE_LEFT)) bleMouse.release(MOUSE_LEFT);
  }

  
  if (abs(rightVal - baseRight) > threshold) {
    if (!bleMouse.isPressed(MOUSE_RIGHT)) bleMouse.press(MOUSE_RIGHT);
  } else {
    if (bleMouse.isPressed(MOUSE_RIGHT)) bleMouse.release(MOUSE_RIGHT);
  }

  
  bool movementActive = (abs(moveVal - baseMove) > threshold);

  if (movementActive) {
  
    float tiltX = mpu.getAngleX();
    float tiltY = mpu.getAngleY();

    
    smoothX = damping * smoothX + (1 - damping) * tiltX;
    smoothY = damping * smoothY + (1 - damping) * tiltY;

   
    if (abs(smoothX) < deadzone) smoothX = 0;
    if (abs(smoothY) < deadzone) smoothY = 0;

    int moveX = constrain(-smoothY * sensitivity, -10, 10); // flipped sign
    int moveY = constrain(-smoothX * sensitivity, -10, 10); // same as before (normal up/down)

    bleMouse.move(moveX, moveY);

    Serial.print("MoveX: "); Serial.print(moveX);
    Serial.print(" | MoveY: "); Serial.println(moveY);
  } else {
    bleMouse.move(0, 0);
  }

  delay(20); 
}
