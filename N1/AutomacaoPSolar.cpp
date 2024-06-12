#include <Servo.h>      //incluindo a biblioteca do servo motor
Servo sg90;
int initial_position = 90;   // posição inicial do servo
int LDR1 = A0;          // Declaração do pino onde está conectado o primeiro fotossensor
int LDR2 = A1;          // Declaração do pino onde está conectado o segundo fotossensor
int error = 5;          // margem de erro para as leituras dos fotossensores
int servopin = 9;         // pino PWM onde o servo motor está conectado

void setup() 
{ 
  sg90.attach(servopin);  // associa o servo ao pino definido
  pinMode(LDR1, INPUT);   // define LDR1 como entrada
  pinMode(LDR2, INPUT);   // define LDR2 como entrada
  sg90.write(initial_position);   // move o servo para 90 graus
  delay(2000);           // aguarda 2 segundos para estabilização
}  

void loop() 
{ 
  int R1 = analogRead(LDR1); // lê o valor do LDR1
  int R2 = analogRead(LDR2); // lê o valor do LDR2
  int diff1= abs(R1 - R2);   // calcula a diferença entre as leituras dos LDRs
  int diff2= abs(R2 - R1);
  
  if((diff1 <= error) || (diff2 <= error)) {
    // Não faz nada se a diferença estiver dentro da margem de erro
  } else {    
    if(R1 > R2)
    {
      initial_position = --initial_position;  // decrementa a posição inicial se a leitura de R1 for maior
    }
    if(R1 < R2) 
    {
      initial_position = ++initial_position;  // incrementa a posição inicial se a leitura de R1 for menor
    }
  }
  sg90.write(initial_position); // move o servo para a posição calculada
  delay(100); // aguarda 100 milissegundos antes da próxima iteração
}
