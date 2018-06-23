// calibracao sensores reflexão

#include "pins.h"

int sensor_direito = 0;
int sensor_esquerdo = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_direito = analogRead(SENSOR_BAR_LINE_DIR);
  sensor_esquerdo = analogRead(SENSOR_BAR_LINE_ESQ);

Serial.print("Direito: ");
Serial.println(sensor_direito);

Serial.print("Esquerdo: ");
Serial.println(sensor_esquerdo);

delay(500);
  
}
