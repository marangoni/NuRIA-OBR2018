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
//
#define MOTOR_DC_DIR_PIN          6 // Lado direito - números pinos PARES
#define MOTOR_DC_ESQ_PIN          5 // Lado esquerdo - números pinos ÍMPARES

//
// Motor - Garra - Pino PWM
//
#define MOTOR_DC_GARRA_PIN             11

// Servo motores - radares - PWM
#define SERVO_RADAR_FRENTE_PIN            8
#define SERVO_RADAR_TRAS_PIN              9

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

//Sensores de reflexão - modo digital
#define SENSOR_BAR_LINE_DIR       2
#define SENSOR_BAR_LINE_ESQ       7

//Sensor ultrasônico
#define TRIGGER_PIN  12
#define ECHO_PIN     13
