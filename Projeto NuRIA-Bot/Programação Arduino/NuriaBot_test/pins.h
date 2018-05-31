/*
 * NuRIA Bot Test Firmware
 * Versao inicial
 *
 */

/** Designações dos pinos - configuração hardware
 *  Placa: Arduino UNO
 *
 ******************************************************************/
/* Resumo pinos - Arduino
 * Convenção motores - Números pares - lado DIREITO/DIANTEIRO
 *  
 * D0, D1 - Não utilizados (Utilizados para RX/TX na programação do Arduino)
 * D2  - OUT - reservado - SWITCH - botão controle
 * ~D3  - OUT - reservado para buzzer indicação sonora  
 * D4  - OUT - reservado - leds do "sensor-bar"
 * ~D5 - OUT - velocidade motor lado esquerdo
 * ~D6 - OUT - velocidade motor lado direito
 * D7  - OUT - direção motor lado direito
 * D8 - OUT -  direção motor lado esquerdo
 * ~D9 - OUT -  reservado servo-motor radar traseiro
 * ~D10 - OUT - reservado servo-motor radar dianteiro
 * ~D11 - OUT - reservado motor DC garra
 * D12 - reservado para sensor ultrasônico - ECHO
 * D13 - reservado para sensor ultrasônico - TRIGGER
*/

//
// Motores DC - Pinos PWM
//
#define MOTOR_DC_DIR_PWM_PIN          6 // ~D6 - PWM Lado direito - 0 - 255 - velocidade
#define MOTOR_DC_ESQ_PWM_PIN          5 // ~D5 - PWM Lado esquerdo  0 - 255 - velocidade

#define MOTOR_DC_DIR_DIR_PIN          8 // D8 - direção motor direito - 0 - horário/  1 - antihorário       
#define MOTOR_DC_ESQ_DIR_PIN          7 // D7 - direção motor esquerdo - 0 - horário/ 1 - antihorário 

//
// Motor - Garra - Pino PWM
//
#define MOTOR_DC_GARRA_PIN             11

// Servo motores - radares - PWM
#define SERVO_RADAR_FRENTE_PIN            10
#define SERVO_RADAR_TRAS_PIN              9

//
// LED - Calibration Lights
//
#define LED_CALIBRATION_LIGHTS_PIN        4  // Leds para calibração linhas

//
// LED - Indicação luminosa
//
#define LED_PIN       2 // Led para indicações luminosas

// Botão - Controle robô - entrada analógica 2
#define BUTTON_PIN      A2 //Botão controle do robô 

//
// Buzzer
//
#define BUZZER_PIN    3 // Buzzer para indicações sonoras

//
//Sensores
//

//Botão - Switch - botão de controle robô
//

//Sensores de reflexão - modo analógico
#define SENSOR_BAR_LINE_DIR       A0
#define SENSOR_BAR_LINE_ESQ       A1

//Sensor ultrasônico
#define TRIGGER_PIN  12
#define ECHO_PIN     13
