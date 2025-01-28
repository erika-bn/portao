#include <ESP32Servo.h>  // Biblioteca ESP32Servo para controle de servos no ESP32

// Definição de pino
const int servoPin = 13;  // GPIO 13 para o motor servo

// Instanciação do objeto Servo
Servo motor;

bool estadoPortao = false;  // false = fechado, true = aberto

void setup() {
  Serial.begin(115200);      // Inicializa a comunicação serial para debug
  motor.attach(servoPin);    // Conecte o servo no pino GPIO 13 do ESP32
  motor.write(20);           // Inicia o servo na posição fechada
  Serial.println("Sistema iniciado: portão fechado.");
}

void loop() {
  // Simula a abertura e o fechamento do portão
  if (estadoPortao) {
    abrirPortao();  // Função para abrir o portão
    estadoPortao = false;
  } else {
    fecharPortao(); // Função para fechar o portão
    estadoPortao = true;
  }

  delay(5000);  // Espera 5 segundos antes de inverter o estado
}

void abrirPortao() {
  Serial.println("Abrindo portão...");
  for (int pos = 40; pos <= 160; pos++) {  // Abre indo de 20 a 70
    motor.write(pos);  // Move o servo lentamente para a posição aberta
    delay(20);         // Atraso para suavizar o movimento
  }
  Serial.println("Portão aberto.");
}

void fecharPortao() {
  Serial.println("Fechando portão...");
  for (int pos = 160; pos >= 40; pos--) {  // Fecha indo de 70 a 20
    motor.write(pos);  // Move o servo lentamente para a posição fechada
    delay(20);         // Atraso para suavizar o movimento
  }
  Serial.println("Portão fechado.");
}
