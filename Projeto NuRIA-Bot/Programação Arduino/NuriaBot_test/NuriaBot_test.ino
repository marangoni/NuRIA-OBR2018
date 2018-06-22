/* NuriaBot Test - file
 *
 * NuRIA Bot IA Control file
 *
 * Versão: 01.1
 * Data: 22062018
 * Luiz C M Oliveira
 */

 #include <Ultrasonic.h>
 #include <Servo.h>
 #include <TimerOne.h>
 #include <Wire.h>
 #include <MultiFuncShield.h>

 #include "pins.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_DIR_VEL, OUTPUT);
  pinMode(MOTOR_ESQ_VEL, OUTPUT);
  pinMode(MOTOR_DIR_DIR, OUTPUT);
  pinMode(MOTOR_ESQ_DIR, OUTPUT);
  
  pinMode(MOTOR_DC_GARRA_PIN, OUTPUT);
  pinMode(SERVO_RADAR_FRENTE_PIN, OUTPUT);
  pinMode(LED_CALIBRATION_LIGHTS_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
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

void loop() {
  // put your main code here, to run repeatedly:

}
