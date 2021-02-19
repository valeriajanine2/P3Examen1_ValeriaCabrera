#include "TablaPosiciones.hpp"
#include <stdlib.h>
#include <ctime>

TablaPosiciones::TablaPosiciones(){
  // cout<<"llamaron al vacio" << endl;
}

TablaPosiciones::TablaPosiciones(vector<Puntos*> puntosEquipo){
  this->puntosEquipo=puntosEquipo;
}

TablaPosiciones::~TablaPosiciones(){
  cout << "Se elimino la Tabla de Posiciones" << endl;
}

vector<Puntos*> TablaPosiciones::getPuntosEquipo(){
	return this->puntosEquipo;
}