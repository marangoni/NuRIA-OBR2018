/* testes dos sensores de reflexão
determinacao dos valores nas áreas clara e escura da linha


***** variaveis (pins.h):
SENSOR_BAR_LINE_DIR       A0
SENSOR_BAR_LINE_ESQ       A5


*/

#include "pins.h"

//variaveis para armazenamento leitura sensores
int sensor_DIR = 0;
int sensor_ESQ = 0;
int tempo_entre_leituras = 10;


void setup(){
  Serial.begin(9600);
}

void loop(){
  sensor_DIR = analogRead(SENSOR_BAR_LINE_DIR);
  sensor_ESQ = analogRead(SENSOR_BAR_LINE_ESQ);
  delay(tempo_entre_leituras);

  Serial.print("Sensor direito: ");
  Serial.println(SENSOR_BAR_LINE_DIR);
  Serial.print("Sensor esquerdo: ");
  Serial.println(SENSOR_BAR_LINE_ESQ);

  delay(500); //Escreve na serial 2x por segundo
  
}
