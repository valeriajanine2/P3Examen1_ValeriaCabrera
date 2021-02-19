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

void TablaPosiciones::agregarPuntos(Puntos* p){
	puntosEquipo.push_back(p);
}

void TablaPosiciones::imprimirTabla(){
	
	cout<<endl<<"TABLA DE POSICIONES MINI LIGA"<<endl;
	for(int i = 0; i < puntosEquipo.size(); i++){
		Puntos* p = new Puntos();
		p = puntosEquipo.at(i);
		cout<<i<<") "<<p->imprimirPuntos()<<" Puntos Totales: "<<p->puntosTotales()<<endl;
	}
	
}

vector<Puntos*> TablaPosiciones::getPuntosEquipo(){
	return this->puntosEquipo;
}