#include <LiquidCrystal.h>
LiquidCrystal lcd (9, 8, 4,5,6,7); 
int botao1 = 2;
int botao2 = 3;
int stop = 12;
int motor1 = 10;
int motor2 = 11;
int pinopot = A0; 
int valorpot = 0;
void setup()
{
Serial.begin(9600);
lcd.begin(16, 2);
pinMode(botao1, INPUT_PULLUP);
pinMode(botao2, INPUT_PULLUP);
pinMode(stop, INPUT_PULLUP);
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);
pinMode(pinopot, INPUT); 
} 
void loop()
  {
    antih();
    {
      hor();
      {
        desliga();
      }
    }
  }
void hor()  
{ 
  int x = digitalRead(botao1);
  int y = digitalRead(botao2);
  int z = digitalRead(stop);
  float velocidade = 0;
  valorpot = analogRead(pinopot);
  velocidade = map(valorpot, 0, 1023, 0, 255);  
  float tensao = valorpot*0.004881; 
  if (x == LOW && y == HIGH)
 {
  lcd.clear();
  Serial.println("Ligado sentido horario.");
  lcd.setCursor(0,1);
  lcd.print("Horario");
  lcd.setCursor(0,0);
  lcd.print("Sentido:");
  analogWrite(motor1, velocidade);
  digitalWrite(motor2, LOW);
  Serial.print("Valor lido do potenciometro : "); 
  Serial.print(valorpot);   
  Serial.print(" = Velocidade : ");
  Serial.println(velocidade); 
  Serial.print(" = Tensao : ");
  Serial.println(tensao);
 }
} 
void antih()  
{ 
  int x = digitalRead(botao1);
  int y = digitalRead(botao2);
  int z = digitalRead(stop);
  float velocidade = 0;
  valorpot = analogRead(pinopot);
  velocidade = map(valorpot, 0, 1023, 0, 255);  
  float tensao = valorpot*0.004881; 
  if (x == HIGH && y == LOW)
 {
  lcd.clear();
  Serial.println("Ligado sentido anti-horario.");
  lcd.setCursor(0,1);
  lcd.print("Anti-horario");
  lcd.setCursor(0,0);
  lcd.print("Sentido:");
  digitalWrite(motor1, LOW);
  analogWrite(motor2, velocidade);
  Serial.print("Valor lido do potenciometro : "); 
  Serial.print(valorpot);   
  Serial.print(" = Velocidade : ");
  Serial.println(velocidade);  
  Serial.print(" = Tensao : ");
  Serial.println(tensao);
 }
}
  void desliga() 
{
  int x = digitalRead(botao1);
  int y = digitalRead(botao2);
  int z = digitalRead(stop);
  float velocidade = 0;
  valorpot = analogRead(pinopot);
  velocidade = map(valorpot, 0, 1023, 0, 255);  
  float tensao = valorpot*0.004881; 
  if (z == LOW && x == HIGH && y == HIGH)
  {
  lcd.clear();
  Serial.println("Motor desligado.");
  lcd.setCursor(0,2);
  lcd.print("Desligado.");
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
 } 
}