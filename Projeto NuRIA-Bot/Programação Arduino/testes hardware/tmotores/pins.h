/*
 * NuRIA Bot Test Firmware
 * Versao inicial
 *
 */

/** Designações dos pinos - configuração hardware
 *  Placa: Arduino UNO
 *
 ******************************************************************/

//
// Motores DC - Pinos PWM
// Definicao conforme sheild
// https://www.robocore.net/loja/produtos/arduino-shield-motor-driver-2x2a.html#descricao
// Diagrama de ligações
// https://docs.google.com/drawings/d/1-qWhn8gEQo6laPO37YPNl5I7lbErecEisJWaW6vdXDo/edit?usp=sharing

//M2 no shield
#define MOTOR_DIR_VEL          6 // Lado direito - velocidade - números pinos PARES
#define MOTOR_DIR_DIR          8 // lado direito direito direcao

//M1 no shield
#define MOTOR_ESQ_VEL          5 // Lado esquerdo - velocidade - números pinos ÍMPARES
#define MOTOR_ESQ_DIR          7 // lado direito direito direcao

//
// Motor - Garra - Pino PWM
//
#define MOTOR_DC_GARRA_PIN             11

// Servo motores - radares - PWM
#define SERVO_RADAR_FRENTE_PIN            9
//#define SERVO_RADAR_TRAS_PIN              9

//
// LED - Calibration Lights
//
#define LED_CALIBRATION_LIGHTS_PIN        4  // Leds para calibração linhas

//
// LED - Indicação luminosa
//
#define LED_PIN       10 // Led para indicações luminosas

//
// Buzzer
//
#define BUZZER_PIN    3 // Buzzer para indicações sonoras

//
//Sensores
//

//Sensores de reflexão - modo analogico
#define SENSOR_BAR_LINE_DIR       A0
#define SENSOR_BAR_LINE_ESQ       A5

//Sensor ultrasônico
#define TRIGGER_PIN  12
#define ECHO_PIN     13
