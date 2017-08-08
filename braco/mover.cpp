#include <math.h>
#include "mover.h"
#include <arduino.h>

const float altura = 18;
const float braco = 23;
const float antebraco = 23.25;
const float mao = 15;

float _alpha; //ombro
float _beta; //cotovelo
float _gama; //pulso
float _lambda; //base
bool incapaz = true;

bool podeMover (float x, float y, float z) {	

    Serial.print("x: ");
    Serial.print(x);
    Serial.print("  y: ");
    Serial.print(y);
    Serial.print("  z: ");
    Serial.print(z);
    Serial.println();

  
	float modulo = sqrt(pow(x,2) + pow(y,2));
	_lambda = acos(x/modulo) * 180/M_PI;
	
	y = modulo;//frente.
	
	float alturaPulso = z + mao;
	
	float distancia = sqrt(pow(y,2) + pow(alturaPulso - altura,2));
	
	float moduloPulso = sqrt(pow(alturaPulso,2) + pow(y,2));//distancia base pulso.
	
	float complementar1 = acos(( -pow(antebraco,2) + pow(distancia,2) + pow(braco,2)) / (2*distancia*braco));
	float complementar2 = acos(( -pow(moduloPulso,2) + pow(distancia,2) + pow(altura,2)) / (2*distancia*altura));
	
	_alpha = (complementar1 + complementar2) * 180/M_PI-90;

	
	float realCima = z - (altura-mao);
	
	_beta = acos((pow(braco,2) + pow(antebraco,2) - (pow(y,2) + pow(realCima,2))) / (2*braco*antebraco)) * 180/M_PI;
	_gama = 270 - _alpha - _beta;
	
	incapaz = isnan(_alpha) || isnan(_beta) || isnan(_gama) || isnan(_lambda);
	return !incapaz;
}

void mover(){
	if(!incapaz){
		lambda(_lambda);
		alpha(_alpha);
		beta(_beta);
		gama(_gama);


    Serial.print("l: ");
    Serial.print(_lambda);
    Serial.print("  a: ");
    Serial.print(_alpha);
    Serial.print("  b: ");
    Serial.print(_beta);
    Serial.print("  g: ");
    Serial.println(_gama); 
    Serial.println();
	}
}


