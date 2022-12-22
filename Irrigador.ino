
// Código que inclui a biblioteca de lcd ao programa e a atribuição das portas do arduino com os pinos do lcd
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,9); // Pinos 2 e 3 para controle, pinos 4,5,6 e 9 para dados

// Código de Funcionamento para Sistema de Monitoramento e Irrigação com Arduino
#define pinoAnalog A0 // Define o pino A0 como "pinoAnalog"
#define pinoRele 8 // Define o pino 8 como "pinoRele"
 
int ValAnalogIn; // Introduz o valor analógico ao código
 
void setup() {
lcd.begin(16,2); // Declara a quantidade de colunas e linhas do lcd
Serial.begin(9600); // Declara o BaundRate em 9600
Serial.println("Sistema de Irrigação Automatizado"); // Imprime a frase no monitor serial
pinMode(pinoRele, OUTPUT); // Declara o pinoRele como Saída
}
  
void loop() {
 ValAnalogIn = analogRead(pinoAnalog); // Relaciona o valor analógico com o recebido do sensor
int Porcento = map(ValAnalogIn, 1023, 0, 0, 100); // Relaciona o valor analógico à porcentagem
 
Serial.print(Porcento); // Imprime o valor em Porcento no monitor Serial
Serial.println("%"); // Imprime o símbolo junto ao valor encontrado
 
if (Porcento <= 45) { // Se a porcentagem for menor ou igual à
Serial.println("Irrigando a planta ..."); // Imprime a frase no monitor serial
digitalWrite(pinoRele, LOW); // Altera o estado do pinoRele para nível baixo e liga a bomba
lcd.print(Porcento); // Escreve o valor númerico da variável porcentagem no lcd
lcd.print("% umido"); // Escreve grandeza com a qual estamos trabalhando em porcentagem %
lcd.setCursor(0,1); // Altera a linha que será utilizada no lcd para os próximos comandos
lcd.print("Irrigando ..."); // Escreve no lcd a ação que está sendo realizada pelo sistema
delay (1000);
lcd.clear(); // Limpa o que esta escrito no lcd
}
 
else { // Se não ...
Serial.println("Planta Irrigada ..."); // Imprime a frase no monitor serial
digitalWrite(pinoRele, HIGH); // Altera o estado do pinoRele para nível alto e desliga a bomba
lcd.print(Porcento);
lcd.print("% umido");
lcd.setCursor(0,1);
lcd.print("Irrigada ...");
delay (1000);
lcd.clear();
}3
  
;}
