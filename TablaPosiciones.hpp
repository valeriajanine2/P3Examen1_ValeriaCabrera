#ifndef TABLAPOSICIONES_H
#define TABLAPOSICIONES_H
#include<string>
#include<iostream>
#include <vector>
using namespace std;
class TablaPosiciones {
	private:
		vector<Puntos*> puntosEquipo;
	public:
		TablaPosiciones();
		TablaPosiciones(vector<Puntos*>);
		~TablaPosiciones();
		vector<Puntos*> getPuntosEquipo();
};
#endif