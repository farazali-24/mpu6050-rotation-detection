
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define LED_PIN 26
#define I2C_SCL_PIN 18
#define I2C_SDA_PIN 19

Adafruit_MPU6050 mpu;

float yaw = 0.0;
unsigned long lastTime = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("MPU-6050 Rotation Test");

  pinMode(LED_PIN, OUTPUT);

  // Initialize I2C
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

  // Initialize MPU-6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 Initialized");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  lastTime = millis();
}

void loop() {
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  // Calculate time difference (deltaTime)
  unsigned long currentTime = millis();
  float deltaTime = (currentTime - lastTime) / 1000.0;
  lastTime = currentTime;

  // Read gyroscope Z-axis data for yaw
  float rotationZ = gyro.gyro.z; // Rotation in rad/s

  // Calculate yaw using integration
  yaw += rotationZ * deltaTime;

  // Print yaw angle
  Serial.print("Yaw (radians): ");
  Serial.println(yaw);

  // Turn on LED if yaw angle reaches 90 degrees
  if (yaw >= 1.5708) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(10);
}
