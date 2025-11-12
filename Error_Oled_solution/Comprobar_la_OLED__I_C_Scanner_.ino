#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA=21, SCL=22 para ESP32
  Serial.println("\nEscaneando dispositivos I2C...");
}

void loop() {
  byte error, address;
  int nDevices = 0;

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo I2C encontrado en dirección 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    }
  }

  if (nDevices == 0)
    Serial.println("No se detectaron dispositivos I2C :(");
  else
    Serial.println("Escaneo finalizado.");

  delay(3000);
}
