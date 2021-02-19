#ifndef PARTIDOS_H
#define PARTIDOS_H
#include<string>
#include<iostream>
#include <vector>
using namespace std;
class Partidos {
	private:
		Equipo* equipo1;
		Equipo* equipo2;
		int goles1;
		int goles2;
		bool jugado;
	public:
		Partidos();
		Partidos(Equipo*,Equipo*,int,int,bool);
		~Partidos();
		Equipo* getEquipo1();
		Equipo* getEquipo2();
		int getGoles1();
		int getGoles2();
		bool getJugado();
		void setEquipo1(Equipo*);
		void setEquipo2(Equipo*);
		void setGoles1(int);
		void setGoles2(int);
		void setJugado(bool);
};
#endif