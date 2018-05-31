/* NuriaBot Test - file
 *
 * NuRIA Bot IA Control file
 *
 * Versão: 01
 * Data: 25052018
 * Luiz C M Oliveira, Alexandre Strabello, Enzo Pirinelli, Raphael Siqueira
 */

 #include <Ultrasonic.h>
 #include <Servo.h>
 #include <TimerOne.h>
 #include <Wire.h>
 #include <MultiFuncShield.h>

 #include "pins.h"    //Pinagem de Hardware no N3

void setup() {
  // put your setup code here, to run once:
 
  pinMode(MOTOR_DC_DIR_PWM_PIN, OUTPUT);
  pinMode(MOTOR_DC_ESQ_PWM_PIN, OUTPUT);
  pinMode(MOTOR_DC_DIR_DIR_PIN, OUTPUT);
  pinMode(MOTOR_DC_ESQ_DIR_PIN, OUTPUT);
  
  pinMode(MOTOR_DC_GARRA_PIN, OUTPUT);
  
  pinMode(SERVO_RADAR_FRENTE_PIN, OUTPUT);
  pinMode(SERVO_RADAR_TRAS_PIN, OUTPUT);
  
  pinMode(LED_CALIBRATION_LIGHTS_PIN, OUTPUT);
 
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
  Timer1.initialize();
  MFS.initialize(&Timer1); // initialize multi-function shield library

  //Beep de inicialização do robô
  MFS.beep(5, // beep for 50 milliseconds
 5, // silent for 50 milliseconds
 4, // repeat above cycle 4 times
 3, // loop 3 times
 50 // wait 500 milliseconds between loop
 );

// Blink de inicialização do robô - LED_PIN - pino 2 - somente se houver pino disponível
for (int n=1;n<4;n++){
 MFS.blinkLeds(LED_4, ON);
 delay(200);
 MFS.blinkLeds(LED_4, OFF);
 delay(200);
}

}

void loop() {
  // put your main code here, to run repeatedly:
  // Leitura do botão pra iniciar a operação do robô
  int button_ind = analogRead(BUTTON_PIN);
  bool estado_robo = false;

  if (button_ind > 1020 && estado_robo == false){
    // Se o botao for pressionado e não estiver seguindo linha - siga a linha
    estado_robo = true;
    // Aqui deve entrar a rotina principal do robô




    
  }
  else if (button_ind > 1020 && estado_robo == true){
    // Se o botao for pressionado enquanto o robô estiver seguindo linha - pare de seguir linha
  }

  

}
