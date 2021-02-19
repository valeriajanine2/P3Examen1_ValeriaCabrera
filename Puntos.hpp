#ifndef PUNTOS_H
#define PUNTOS_H
#include<string>
#include<iostream>
#include <vector>
#include "Equipo.hpp"
using namespace std;
class Puntos {
	private:
		Equipo* equipo;
		int aFavor;
		int enContra;
		int ganados;
		int perdidos;
		int empatados;
	public:
		Puntos();
		Puntos(Equipo*,int,int,int,int,int);
		~Puntos();
		Equipo* getEquipo();
		int getAFavor();
		int getEnContra();
		int getGanados();
		int getPerdidos();
		int getEmpatados();
		void setEquipo(Equipo*);
		void setAFavor(int);
		void setEnContra(int);
		void setGanados(int);
		void setPerdidos(int);
		void setEmpatados(int);
};
#endif
