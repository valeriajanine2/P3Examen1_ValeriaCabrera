#ifndef TABLAPOSICIONES_H
#define TABLAPOSICIONES_H
#include<string>
#include<iostream>
#include <vector>
#include "Puntos.hpp"

using namespace std;
class TablaPosiciones {
	private:
		vector<Puntos*> puntosEquipo;
	public:
		TablaPosiciones();
		TablaPosiciones(vector<Puntos*>);
		~TablaPosiciones();
		vector<Puntos*> getPuntosEquipo();
		void agregarPuntos(Puntos*);
		void imprimirTabla();
		
};
#endif