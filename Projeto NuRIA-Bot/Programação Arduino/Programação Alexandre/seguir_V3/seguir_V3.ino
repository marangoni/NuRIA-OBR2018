//------------------------------------------------
// Programa: seguir_v3 
// Autor: Alexandre Strabello 
// Data: 17/01/2017
// Descrição: programa principal do seguidor de linhas
// Entradas: não há
// Saídas: não há
//------------------------------------------------


void setup () {
  pinMode (2, OUTPUT); // pino 2 = IN1, digital, responsável pela direção do movimento do motor esquerdo.
  pinMode (3, OUTPUT); // pino 3 = IN2, PWM, responsável pela velocidade do motor esquerdo.
  pinMode (4, OUTPUT); // pino 4 = IN3, digital, responsável pela direção do movimento do motor direito.
  pinMode (5, OUTPUT); // pino 5 = IN4, PWM, responsável pela velocidade do motor direito.
  pinMode (0, INPUT); // analógico, pino de entrada do sensor de reflexão esquerdo.
  pinMode (1, INPUT); // analógico, pino de entrada do sensor de reflexão esquerdo.
}
void frente ( int IN1, int IN2, int IN3, int IN4, int dir, int vel) {  // função para que o N2 ande em linha reta
  digitalWrite ( IN1, dir);
  analogWrite (IN2, vel);
  digitalWrite (IN3, dir);
  analogWrite (IN4, (vel - 20)); // a vel do IN4 precisa ser +20 em relação ao motor esquerdo, do contrario, ele andará torto.
}
void tras (int IN1, int IN2, int IN3, int IN4, int sentido, int velocidade) { //função para que o N2 dê ré em linha reta
  digitalWrite ( IN1, sentido);
  analogWrite (IN2, velocidade);
  digitalWrite (IN3, sentido);
  analogWrite (IN4, (velocidade + 20));
}
void curva (int IN1, int IN2, int IN3, int IN4, int dir, int velE, int velD) { // função para executar curvas, a direção pode ser controlada alternando as velocidades dos motores.
  digitalWrite ( IN1, dir);
  analogWrite (IN2, velE); // mais velocidade no IN2 resulta em uma curva para a direita.
  digitalWrite (IN3, dir);
  analogWrite (IN4, (velD - 20)); // mais velocidade no IN4 resulta em uma curva para a esquerda
}  
void loop () { // rotina principal para seguir linha 
  int dadoE = analogRead (0); // lê o valor de entrada que o sensor esquerdo está mandando e o nomeia como dadoE,
  int dadoD = analogRead (1); // lê o valor de entrada que o sensor direito está mandando e o nomeia como dadoD.
  
  
 if ( (dadoD > 150) && (dadoE > 150) ) {  // caso em que os dois sensores estejam na parte preta, ou seja,o N2 está em uma parte reta.
   frente (2, 3, 4, 5, HIGH, 200); // anda para frente
 }
 else if ( (dadoD > 150) && (dadoE < 150)) { //caso em que o sensor esquerdo está na parte branca e o sensor direito está na parte preta, ou seja, o N2 está em uma curva para a direita.
 
   curva (2, 3, 4, 5, HIGH, 240, 180); // curva para a direita
 
  }
  else if( (dadoE > 150) && (dadoD < 150) ) { // caso em que o sensor esquerdo está na parte preta e o sensor direito está na parte branca, logo, o N2 está em uma curva para a esquerda.
   
    curva (2, 3, 4, 5, HIGH,180 , 240); // curva para a esquerda
  
  }
  else if ( (dadoD < 150) && (dadoE < 150) ) { // os dois sensores estao na parte branca. Esse caso é usado principalmente para as curvas de 90º ou para corrigir a direção do N2.
    tras ( 2, 3, 4, 5, LOW, 40); // vai para trás. Esse caso torna o N2 mais lento, mais aumenta a precisão e possibilita a curva de 90º.
  }

       
}
