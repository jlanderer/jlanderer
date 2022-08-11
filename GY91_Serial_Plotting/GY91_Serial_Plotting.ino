#include <MPU9250_asukiaaa.h>
#include <math.h>
#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 4
#define SCL_PIN 5
#endif

MPU9250_asukiaaa mySensor;
float aX, aY, aZ, aSqrt, gX, gY, gZ, mDirection, mX, mY, mZ;

void setup() {
  Serial.begin(9600);
  while(!Serial);

#ifdef _ESP32_HAL_I2C_H_ // For ESP32
  Wire.begin(SDA_PIN, SCL_PIN);
  mySensor.setWire(&Wire);
#endif

  mySensor.beginAccel();
  mySensor.beginGyro();
}

void loop() {
  uint8_t sensorId;  
  int result;
  result = mySensor.readId(&sensorId);

  result = mySensor.accelUpdate();
  if (result == 0) {
    aX = mySensor.accelX();
    aY = mySensor.accelY();
    aZ = mySensor.accelZ();
}
  result = mySensor.gyroUpdate();
  if (result == 0) {
    gX = mySensor.gyroX();
    gY = mySensor.gyroY();
    gZ = mySensor.gyroZ();
}
float theta = atan2(aX,aZ)/(2*PI);  // Nose tilt angle
float phi = atan2(aY,aZ)/(2*PI);    // Side tilt angle
  Serial.print(aX);Serial.print(" , ");Serial.print(aY);Serial.print(" , ");Serial.print(aZ);Serial.print(" , ");
  Serial.print(theta);Serial.print(" , ");Serial.print(phi);Serial.print(" , ");
  Serial.print(gX);Serial.print(" , ");Serial.print(gY);Serial.print(" , ");Serial.println(gZ);   // Send Serial data

}
