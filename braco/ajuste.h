#ifndef AJUSTE_H
#define AJUSTE_H
#include <Servo.h>    //biblioteca (.h)
#include "Arduino.h"

const int ANGULO_ABERTO = 50;
const int ANGULO_FECHADO = 80;

void iniciar();

void lambda(int n);

void alpha(int n);

void beta(int n);

void gama(int n);

void abrirGarra();

void fecharGarra();


#endif
