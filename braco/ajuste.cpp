#include "ajuste.h"

Servo servoBase;
Servo servoOmbroInverso;
Servo servoOmbroDireto;
Servo servoCotovelo;
Servo servoPulso;
Servo servoGarra;

int anguloGarra = ANGULO_ABERTO;
void iniciar(){	
  servoBase.attach(22);
  servoOmbroDireto.attach(26);
  servoOmbroInverso.attach(30);
  servoCotovelo.attach(34);
  servoPulso.attach(38);
  servoGarra.attach(42);
  
}

void lambda(int n){
  servoBase.write(n+20);
}

void alpha(int n){
  servoOmbroInverso.write(135-n);
  servoOmbroDireto.write(n+25);
}

void beta(int n){
  servoCotovelo.write(n);
}

void gama(int n){
  servoPulso.write(n);
}

void abrirGarra(){	
     for(;anguloGarra > ANGULO_ABERTO; anguloGarra--){
      servoGarra.write(anguloGarra);
      delay(50);
    }
}

void fecharGarra(){	
    for(;anguloGarra < ANGULO_FECHADO; anguloGarra++){
      servoGarra.write(anguloGarra);
      delay(50);
    }
}

