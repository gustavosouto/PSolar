#include <Servo.h>      // incluindo a biblioteca do servo motor
Servo sg90;
int initial_position = 90;   // posição inicial do servo
int LDR1 = A0;          // Declaração do pino onde está conectado o primeiro fotossensor
int LDR2 = A1;          // Declaração do pino onde está conectado o segundo fotossensor
int error = 5;          // margem de erro para as leituras dos fotossensores
int servopin = 9;         // pino PWM onde o servo motor está conectado

String ssid = "Simulator Wifi";  // SSID to connect to
String password = ""; // Our virtual wifi has no password (so dont do your banking stuff on this network)
String host = "api.thingspeak.com"; // ThingSpeak API
const int httpPort = 80;
String apiKey = "8RWKSCIJ44EIED7F"; // Your ThingSpeak API Key
String apiKeySMS = "E560M8A29NJPE3K1";

int setupESP8266(void) {
  // Start our ESP8266 Serial Communication
  Serial.begin(115200);   // Serial connection over USB to computer
  Serial.println("AT");   // Serial connection on Tx / Rx port to ESP8266
  delay(10);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 1;

  // Connect to 123D Circuits Simulator Wifi
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  delay(10);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 2;

  // Open TCP connection to the host:
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
  delay(50);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 3;

  return 0;
}

void sendSms(String mensagem){
	String uri = "/apps/thinghttp/send_request?api_key=" + apiKeySMS + "&message=" + mensagem;
	String httpPacket = "GET " + uri + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  	int length = httpPacket.length();
  
  	Serial.print("AT+CIPSEND=");
	Serial.println(length);
  	delay(500);
    
    Serial.print(httpPacket);
  	delay(1000);
}

void enviaDados_ESP8266(int lum1, int lum2, int rot) {
  // Construct our HTTP call
  String uri = "/update?api_key=" + apiKey + "&field1=" + String(lum1) + "&field2=" + String(lum2) + "&field3=" + String(rot);
  String httpPacket = "GET " + uri + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length = httpPacket.length();

  // Send our message length
  Serial.print("AT+CIPSEND=");
  Serial.println(length);
  delay(10); // Wait a little for the ESP to respond
  if (!Serial.find(">")) return;

  // Send our HTTP request
  Serial.print(httpPacket);
  delay(10); // Wait a little for the ESP to respond
  if (!Serial.find("SEND OK\r\n")) return;
}


void setup() {
  sg90.attach(servopin);  // associa o servo ao pino definido
  pinMode(LDR1, INPUT);   // define LDR1 como entrada
  pinMode(LDR2, INPUT);   // define LDR2 como entrada
  sg90.write(initial_position);   // move o servo para 90 graus
  delay(2000);           // aguarda 2 segundos para estabilização
  setupESP8266();
}

void loop() {
  int R1 = analogRead(LDR1); // lê o valor do LDR1
  int R2 = analogRead(LDR2); // lê o valor do LDR2
  int diff1 = abs(R1 - R2);   // calcula a diferença entre as leituras dos LDRs
  int diff2 = abs(R2 - R1);

  if ((diff1 <= error) || (diff2 <= error)) {
    // Não faz nada se a diferença estiver dentro da margem de erro
  } else {
    if (R1 > R2) {
      initial_position = --initial_position;  // decrementa a posição inicial se a leitura de R1 for maior
    }
    if (R1 < R2) {
      initial_position = ++initial_position;  // incrementa a posição inicial se a leitura de R1 for menor
    }
  }
  sg90.write(initial_position); // move o servo para a posição calculada

  int lum1 = map(analogRead(LDR1), 20, 358, -40, 125);
  int lum2 = map(analogRead(LDR2), 20, 358, -40, 125);
  int rot = initial_position;

  enviaDados_ESP8266(lum1, lum2, rot);

  delay(10); // aguarda 2000 milissegundos antes da próxima iteração
}
