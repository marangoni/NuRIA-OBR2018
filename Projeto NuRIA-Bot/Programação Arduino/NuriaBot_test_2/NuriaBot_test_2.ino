/* NuriaBot Test - file
 *
 * NuRIA Bot IA Control file
 *
 * Versão: 01.1
 * Segue linha inicial - base programa alexandre
 * Data: 22062018
 * Luiz C M Oliveira
 */

 #include <Ultrasonic.h>
 #include <Servo.h>
 #include <TimerOne.h>
 #include <Wire.h>
 #include <MultiFuncShield.h>

 #include "pins.h"


//const int MOTOR_ESQ_VEL = 5;
//const int MOTOR_ESQ_DIR = 6;

const int MOTOR_ESQ_VEL = 5;
const int MOTOR_ESQ_DIR = 7;

const int MOTOR_DIR_VEL = 6;
const int MOTOR_DIR_DIR = 8;


 //variaveis para armazenamento leitura sensores

 int sensor_DIR = 0;
 int sensor_ESQ = 0;
 int tempo_entre_leituras = 10;

int branco_esq = 25;
int branco_dir = 25;

int preto_esq = 500;
int preto_dir = 500;

int verde_esq = 38;
int verde_dir = 38;

int velocidade = 110;

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT); 
  pinMode(MOTOR_DIR_VEL, OUTPUT);
  pinMode(MOTOR_ESQ_VEL, OUTPUT);
  pinMode(MOTOR_DIR_DIR, OUTPUT);
  pinMode(MOTOR_ESQ_DIR, OUTPUT);

  pinMode(MOTOR_DC_GARRA_PIN, OUTPUT);
  pinMode(SERVO_RADAR_FRENTE_PIN, OUTPUT);
//  pinMode(LED_CALIBRATION_LIGHTS_PIN, OUTPUT);
//  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(SENSOR_BAR_LINE_DIR, INPUT);
  pinMode(SENSOR_BAR_LINE_ESQ, INPUT);

  Timer1.initialize();
  MFS.initialize(&Timer1); // initialize multi-function shield library

  //Beep de inicialização do robô
  MFS.beep(5, // beep for 50 milliseconds
 5, // silent for 50 milliseconds
 4, // repeat above cycle 4 times
 3, // loop 3 times
 50 // wait 500 milliseconds between loop
 );

// Blink de inicialização do  robô
for (int n=1;n<4;n++){
 MFS.blinkLeds(LED_4, ON);
 delay(200);
 MFS.blinkLeds(LED_4, OFF);
 delay(200);
}

}

// Funções movimentação robô - segue-linha
// Deve ser adaptado para o robô N3

void siga (int dir, int vel) {
  // função para que o N3 ande em linha reta
  // parametros: dir - direção - HIGH - Frente - LOW - tras
  // vel velocidade - numero entre 0 e 255 - padrao 50

 digitalWrite(MOTOR_DIR_DIR, dir);
 digitalWrite(MOTOR_ESQ_DIR, dir);
 analogWrite(MOTOR_DIR_VEL,vel*1.20);
 analogWrite(MOTOR_ESQ_VEL,vel*0.40);

 //analogWrite (IN4, (vel - 20)); // a vel do IN4 precisa ser +20 em relação ao motor esquerdo, do contrario, ele andará torto.
}

//void curva (int IN1, int IN2, int IN3, int IN4, int dir, int velE, int velD) { // função para executar curvas, a direção pode ser controlada alternando as velocidades dos motores.
//  digitalWrite ( IN1, dir);
//  analogWrite (IN2, velE); // mais velocidade no IN2 resulta em uma curva para a direita.
//  digitalWrite (IN3, dir);
//  analogWrite (IN4, (velD - 20)); // mais velocidade no IN4 resulta em uma curva para a esquerda
//}

void curva_direita (int dir, int vel, int ang) {
  // função para que o N3 ande faça curva
  // parametros: dir - direção - HIGH - Frente - Low - tras
  // vel velocidade
  // ang - angulo de curva

digitalWrite(MOTOR_DIR_DIR, dir);
digitalWrite(MOTOR_ESQ_DIR, dir);
// para virar para direita velocidade Direita > velocidade Esquerda
analogWrite(MOTOR_DIR_VEL, (vel + ang)*1.20);
analogWrite(MOTOR_ESQ_VEL, (vel - ang)*0.40);
}

void curva_esquerda (int dir, int vel, int ang) {
  // função para que o N3 ande faça curva
  // parametros: dir - direção - HIGH - Frente - Low - tras
  // vel velocidade - 0 e 255
  // ang - angulo de curva - 0 - linha reta - 100 - curva fechada

digitalWrite(MOTOR_DIR_DIR, dir);
digitalWrite(MOTOR_ESQ_DIR, dir);
// para virar para direita velocidade Esquerda > velocidade Direita
analogWrite(MOTOR_DIR_VEL, (vel - ang)*1.20);
analogWrite(MOTOR_ESQ_VEL, (vel + ang)*0.40);

}

void pare() {
  // função para que o N3 ande faça curva
  
// para virar para direita velocidade Esquerda > velocidade Direita
analogWrite(MOTOR_DIR_VEL, 0);
analogWrite(MOTOR_ESQ_VEL, 0);

}


// Programa principal


void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED_VERDE,LOW);
  digitalWrite(LED_AZUL,LOW);
  digitalWrite(LED_VERMELHO,LOW);

  // lê o valor de entrada que o sensor esquerdo está mandando e o nomeia como sensor_ESQ,
  int sensor_ESQ = analogRead (SENSOR_BAR_LINE_ESQ); 
  
  // lê o valor de entrada que o sensor direito está mandando e o nomeia como sensor_DIR.
  int sensor_DIR = analogRead (SENSOR_BAR_LINE_DIR); 

// REFERENCIA COMEÇA NA DIREITA

//  Serial.print("Direito: ");
//  Serial.println(sensor_DIR);
//
//  Serial.print("Esquerdo: ");
//  Serial.println(sensor_ESQ);
//  delay(500);

 if ( (sensor_DIR > branco_dir) && (sensor_ESQ > preto_esq) ) {
   // caso em que os dois sensores estejam na parte preta, ou seja,o N3 está em uma parte reta.
   siga(HIGH, velocidade); // anda para frente
   digitalWrite(LED_VERDE,HIGH);
   digitalWrite(LED_VERMELHO,LOW);
   digitalWrite(LED_AZUL,LOW);
 }
 else if ( (sensor_DIR < branco_dir) && (sensor_ESQ < branco_esq)) {
 // caso em que o sensor esquerdo está na parte branca e o sensor direito está na parte preta, ou seja,
 // o N2 está em uma curva para a direita.

//  // curva (2, 3, 4, 5, HIGH, 240, 180); // curva para a direita
    curva_esquerda(HIGH,velocidade*1.10,30);
    digitalWrite(LED_AZUL,HIGH);
    digitalWrite(LED_VERDE,LOW);
    digitalWrite(LED_VERMELHO,LOW);
  }
 else if( (sensor_ESQ > preto_esq) && (sensor_DIR > preto_dir) ) {
//  // caso em que o sensor esquerdo está na parte preta e o sensor direito está na parte branca, logo,
//  // o N2 está em uma curva para a esquerda.
//  //curva (2, 3, 4, 5, HIGH,180 , 240); // curva para a esquerda
//
    curva_direita(HIGH,velocidade,15);
    digitalWrite(LED_VERMELHO,HIGH);
    digitalWrite(LED_VERDE,LOW);
    digitalWrite(LED_AZUL,LOW);
//
  }
//  else if ( (sensor_DIR < branco_dir) && (sensor_ESQ < branco_esq) ) {
//    // os dois sensores estao na parte branca. Esse caso é usado principalmente para as curvas
//    // de 90º ou para corrigir a direção do N2.
//    // vai para trás. Esse caso torna o N2 mais lento, mais aumenta a precisão
//    // e possibilita a curva de 90º.
//    //tras ( 2, 3, 4, 5, LOW, 40);
//
//    //siga(HIGH,velocidade-50);
//     curva_esquerda(LOW,velocidade*0.30,5);
//
//  }

}
