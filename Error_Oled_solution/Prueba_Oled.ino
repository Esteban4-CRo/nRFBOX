#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C  // Cambia a 0x3D si es necesario

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  
  // Inicializar pantalla OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("Error al inicializar la OLED");
    while(true);
  }
  
  Serial.println("OLED inicializada correctamente");
  
  // Limpiar pantalla
  display.clearDisplay();
  
  // Mostrar texto de prueba
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("¡OLED Funciona!");
  display.println("----------------");
  display.println("ESP32 + SSD1306");
  display.display();
}

void loop() {
  // La pantalla mantendrá el mensaje estático
}
