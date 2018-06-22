/*Testes hardware

Testes motores

**** hardware
https://docs.google.com/drawings/d/1-qWhn8gEQo6laPO37YPNl5I7lbErecEisJWaW6vdXDo/edit?usp=sharing

***** variaveis (pins.h):
MOTOR_DIR_VEL
MOTOR_DIR_DIR
MOTOR_ESQ_VEL
MOTOR_ESQ_DIR

*/

 #include "pins.h"

int velocidade = 0;
int incv = 10; //incremento de velocidade
int tempo = 50;

 void setup(){
   Serial.begin(9600);
   pinMode(MOTOR_DIR_VEL, OUTPUT);
   pinMode(MOTOR_ESQ_VEL, OUTPUT);
   pinMode(MOTOR_DIR_DIR, OUTPUT);
   pinMode(MOTOR_ESQ_DIR, OUTPUT);
   Serial.println("*** Teste motores ***");
 }

void loop(){
  Serial.println("* Motor direito - PARA FRENTE ");
  digitalWrite(MOTOR_DIR_DIR, LOW);
  for (velocidade = 0; velocidade<255; velocidade = velocidade + incv){
    Serial.print("Velocidade: ");
    Serial.println(velocidade);
    analogWrite(MOTOR_DIR_VEL, velocidade);
    delay(tempo);
  }
  velocidade = 0;
  analogWrite(MOTOR_DIR_VEL, velocidade);
  delay(1000);

  Serial.println("* Motor direito - PARA TRAS ");
  digitalWrite(MOTOR_DIR_DIR, HIGH);
  for (velocidade = 0; velocidade<255; velocidade = velocidade + incv){
    Serial.print("Velocidade: ");
    Serial.println(velocidade);
    analogWrite(MOTOR_DIR_VEL, velocidade);
    delay(tempo);
  }

  velocidade = 0;
  analogWrite(MOTOR_DIR_VEL, velocidade);
  delay(1000);

  Serial.println("* Motor esquerdo - PARA FRENTE ");
  digitalWrite(MOTOR_ESQ_DIR, LOW);
  for (velocidade = 0; velocidade<255; velocidade = velocidade + incv){
    Serial.print("Velocidade: ");
    Serial.println(velocidade);
    analogWrite(MOTOR_ESQ_VEL, velocidade);
    delay(tempo);
  }
  velocidade = 0;
  analogWrite(MOTOR_ESQ_VEL, velocidade);
  delay(1000);

  Serial.println("* Motor esquerdo - PARA TRAS ");
  digitalWrite(MOTOR_ESQ_DIR, HIGH);
  for (velocidade = 0; velocidade<255; velocidade = velocidade + incv){
    Serial.print("Velocidade: ");
    Serial.println(velocidade);
    analogWrite(MOTOR_ESQ_VEL, velocidade);
    delay(tempo);
  }

  velocidade = 0;
  analogWrite(MOTOR_ESQ_VEL, velocidade);
  delay(1000);

}
