
#include "ajuste.h"

int LAMBDA = 90;
int ALPHA = 90;
int BETA = 90;
int GAMA = 90;
char value;
int flag = 0;
bool fechado = false;

void setup() {
  Serial.begin(9600);
  iniciar();
  configure();
  abrirGarra();
}

void configure() {
  lambda(LAMBDA);
  alpha(ALPHA);
  beta(BETA);
  gama(GAMA);

  Serial.print("lambda: ");
  Serial.print(LAMBDA);
  Serial.print("alpha: ");
  Serial.print(ALPHA);
  Serial.print("beta: ");
  Serial.print(BETA);

}


void loop() {
  if (Serial.available()) {
    value = Serial.read();
    Serial.flush();

    switch (value) {      
      case '0': 
        BETA += 2; 
        flag = 1; 
        break;
        
      case '1':       
        ALPHA += 2;   
        flag = 1; 
        break;
        
      case '2': 
        GAMA += 1; 
        flag = 1;   
        break;
      case '3': 
        LAMBDA -= 2; 
        flag = 1; 
        break;
      case '4': 
      if (fechado){
        abrirGarra();
      }
      else{
        fecharGarra();
      }
      fechado = !fechado;
      
        break;
      case '5': 
        LAMBDA += 2; 
        flag = 1; 
        break;
      case '6':      
        BETA -= 2; 
        flag = 1; 
        break;
      case '7':      
        ALPHA -= 2; 
        flag = 1; 
      case '8':      
        GAMA -= 1; 
        flag = 1; 
        break;
    }

    if (flag)
      configure();
    flag = false;
  }

}
