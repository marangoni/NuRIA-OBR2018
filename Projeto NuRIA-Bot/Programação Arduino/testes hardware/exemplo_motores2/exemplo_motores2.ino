/*
      RoboCore - Motor Driver 2x2A example
                    (01/07/2015)

  Written by FranÃ§ois.

  Example of how to use the Motor Driver 2x2A.
  Open a Serial Monitor and enter the comands:
    - u : for PWM 0 to 255
    - d : for PWM 255 to 0
    - o : for ON
    - f : for OFF
    - 1 : for Direction 1
    - 2 : for Direction 2

*/

//#define MOTOR_DIR_VEL          6 // Lado direito - velocidade - números pinos PARES
//#define MOTOR_ESQ_VEL          5 // Lado esquerdo - velocidade - números pinos ÍMPARES

//#define MOTOR_ESQ_DIR          7 // lado direito direito direcao
//#define MOTOR_DIR_DIR          8 // lado direito direito direcao

//M1 no shield



const int MOTOR_ESQ_VEL = 5; //motor A
const int MOTOR_ESQ_DIR = 7; //dirA


const int MOTOR_DIR_VEL = 6; //motor B
const int MOTOR_DIR_DIR = 8;           //dir B

byte b;

// ------------------------------------------------

void setup(){
  Serial.begin(9600);
  Serial.println("Start");

  pinMode(MOTOR_ESQ_VEL, OUTPUT);
  pinMode(MOTOR_ESQ_DIR, OUTPUT);
  pinMode(MOTOR_ESQ_DIR, OUTPUT);
  pinMode(MOTOR_DIR_DIR, OUTPUT);
}

// ------------------------------------------------

void loop(){

  if(Serial.available()){
    b = Serial.read();

    switch(b){
      // PWM Up
      case 'u':
        for(int i=0 ; i <= 255 ; i++){
          analogWrite(MOTOR_ESQ_VEL, i);
          analogWrite(MOTOR_ESQ_VEL, i);
          delay(20);
        }
        Serial.println("\tok");
        break;

      // PWM Down
      case 'd':
        for(int i=255 ; i >= 0 ; i--){
          analogWrite(MOTOR_ESQ_VEL, i);
          analogWrite(MOTOR_ESQ_VEL, i);
          delay(20);
        }
        Serial.println("\tok");
        break;


      // On
      case 'o':
        digitalWrite(MOTOR_ESQ_DIR, HIGH);
        digitalWrite(MOTOR_ESQ_DIR, HIGH);
        Serial.println("ON");
        break;

      // Off
      case 'f':
        digitalWrite(MOTOR_ESQ_DIR, LOW);
        digitalWrite(MOTOR_ESQ_DIR, LOW);
        Serial.println("OFF");
        break;


      // Dir-1
      case '1':
        digitalWrite(MOTOR_ESQ_DIR, HIGH);
        digitalWrite(MOTOR_DIR_DIR, HIGH);
        Serial.println("\tdir-1");
        break;

      // Dir-2
      case '2':
        digitalWrite(MOTOR_ESQ_DIR, LOW);
        digitalWrite(MOTOR_DIR_DIR, LOW);
        Serial.println("\tdir-2");
        break;


      // PWM Max
      case '>':
          analogWrite(MOTOR_ESQ_VEL, 240);
          analogWrite(MOTOR_ESQ_VEL, 240);
        Serial.println("\tMax");
        break;

      // PWM Min
      case '<':
          analogWrite(MOTOR_ESQ_VEL, 20);
          analogWrite(MOTOR_ESQ_VEL, 20);
        Serial.println("\tMin");
        break;

      default:
        Serial.println("nothing");
        break;
    }
  }

}

// ------------------------------------------------
