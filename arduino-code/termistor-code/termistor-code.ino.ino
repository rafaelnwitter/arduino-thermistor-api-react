
// Include Libraries
#include "Arduino.h"
#include "Thermistor.h"

// Pin Definitions
#define THERMISTOR_PIN_CON1 A3

// Global variables and defines

// object initialization
Thermistor thermistor(THERMISTOR_PIN_CON1);

// define vars for testing menu
const int timeout = 10000; //define timeout of 10 sec
int azul = 9;              //Atribui o valor 9 a variável azul
int verde = 10;            //Atribui o valor 10 a variável verde
int vermelho = 12;         //Atribui o valor 12 a variável vermelholong time0;
int timeO = 0;
int buzzer = 8;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup()
{


  // Setup Serial which is useful for debugging
  // Use the Serial Monitor to view printed messages
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);

  // Setup the output to leds
  pinMode(azul, OUTPUT);     //Define a variável azul como saída
  pinMode(verde, OUTPUT);    //Define a variável verde como saída
  pinMode(vermelho, OUTPUT); //Define a variável vermelho como saída
  
  while (!Serial); // wait for serial port to connect. Needed for native USB
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop()
{
  float thermistorTempC = GetTempC();
  int choice = Cases(thermistorTempC);
  Serial.println(thermistorTempC);

  switch (choice)
  {
  case 1:
    Magenta();
    //ActiveBuzzer();
    break;
  case 2:
    Ciano();
    //ActiveBuzzer();
    break;
  case 3:
    Azul();
    break;
  case 4:
    Branco();
    break;
  case 5:
    Verde();
    break;
  case 6:
    Amarelo();
    break;
  case 7:
    Vermelho();
    ActiveBuzzer();
    break;
  default:
    ActiveBuzzer();
    break;
  }
}

void ActiveBuzzer()
{
  tone(buzzer, 200);
  delay(500);
  noTone(buzzer);
}

float GetTempC()
{
  return thermistor.getTempC();
}

int Cases(float thermistorTempC)
{
  if (thermistorTempC <= 20)
  {
    return 1;
  }
  else if (thermistorTempC > 20 && thermistorTempC <= 40)
  {
    return 2;
  }
  else if (thermistorTempC >= 41 && thermistorTempC <= 50)
  {
    return 3;
  }
  else if (thermistorTempC >= 51 && thermistorTempC <= 60)
  {
    return 4;
  }
  else if (thermistorTempC >= 61 && thermistorTempC <= 70)
  {
    return 5;
  }
  else if (thermistorTempC >= 71 && thermistorTempC <= 80)
  {
    return 6;
  }
  else if (thermistorTempC >= 85)
  {
    return 7;
  }
}

void Vermelho()
{
  digitalWrite(vermelho, HIGH); //Coloca vermelho em nível alto, ligando-o
  delay(1000);                  //Intervalo de 1 segundo
  digitalWrite(vermelho, LOW);  //Coloca vermelho em nível baixo
  delay(1000);                  //Intervalo de 1 segundo
}
void Verde()
{
  digitalWrite(verde, HIGH); //Coloca verde em nível alto
  delay(1000);               //Intervalo de 1 segundo
  digitalWrite(verde, LOW);  //Coloca verde em nível baixo
  delay(1000);               //Intervalo de 1 segundo
}
void Azul()
{
  digitalWrite(azul, HIGH); //Coloca azul em nível alto
  delay(100);               //Intervalo de 1 segundo
  digitalWrite(azul, LOW);  //Coloca azul em nível baixo
  delay(100);               //Intervalo de 1 segundo
}
void Branco()
{
  digitalWrite(azul, HIGH);     //Coloca azul em nível alto
  digitalWrite(vermelho, HIGH); //Coloca vermelho em nível alto
  digitalWrite(verde, HIGH);    //Coloca verde em nível alto, ligando-o
  delay(1000);                  //Intervalo de 1 segundo
  digitalWrite(azul, LOW);      //Coloca azul em nível baixo
  digitalWrite(vermelho, LOW);  //Coloca vermelho em nível baixo
  digitalWrite(verde, LOW);     //Coloca verde em nível baixo
  delay(1000);                  //Intervalo de 1 segundo
}
void Magenta()
{
  digitalWrite(azul, HIGH);     //Coloca azul em nível alto
  digitalWrite(vermelho, HIGH); //Coloca vermelho em nível alto
  delay(1000);                  //Intervalo de 1 segundo
  digitalWrite(azul, LOW);      //Coloca azul em nível baixo
  digitalWrite(vermelho, LOW);  //Coloca vermelho em nível baixo
  delay(1000);                  //Intervalo de 1 segundo
}
void Amarelo()
{
  digitalWrite(verde, HIGH);    //Coloca verde em nível alto
  digitalWrite(vermelho, HIGH); //Coloca vermelho em nível alto
  delay(1000);                  //Intervalo de 1 segundo
  digitalWrite(verde, LOW);     //Coloca verde em nível baixo
  digitalWrite(vermelho, LOW);  //Coloca vermelho em nível baixo
  delay(1000);                  //Intervalo de 1 segundo
}
void Ciano()
{
  digitalWrite(verde, HIGH); //Coloca verde em nível alto
  digitalWrite(azul, HIGH);  //Coloca azul em nível baixo alto
  delay(1000);               //Intervalo de 1 segundo
  digitalWrite(verde, LOW);  //Coloca verde em nível baixo
  digitalWrite(azul, LOW);   //Coloca azul em nível baixo
  delay(1000);               //Intervalo de 1 segundo
}
