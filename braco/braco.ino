
#include "ajuste.h"
#include "mover.h"


float X = 0;
float Y = 23.15;
float Z = 26;
char value;
int flag = 0;
bool fechado = false;

void setup() {
  Serial.begin(9600);
  iniciar();
  podeMover(X, Y, Z);
  abrirGarra();
}




void loop() {
  if (Serial.available()) {
    value = Serial.read();
    Serial.flush();

    switch (value) {
      case '0':
        X++;
        flag = 1;
        break;

      case '1':
        X--;
        flag = 1;
        break;

      case '2':
        Y++;
        flag = 1;
        break;
        
      case '3':
        Y--;
        flag = 1;
        break;

      case '4':
        if (fechado) {
          abrirGarra();
        }
        else {
          fecharGarra();
        }
        fechado = !fechado;
        break;

      case '5':
        Z++;
        break;

      case '6':
        Z--;
        flag = 1;
        break;

    }

    if (flag)
      podeMover(X, Y, Z);
    mover();
    flag = false;
  }

}
