#include "Partidos.hpp"
#include <stdlib.h>
#include <ctime>

Partidos::Partidos(){
  // cout<<"llamaron al vacio" << endl;
}

Partidos::Partidos(Equipo* equipo1, Equipo* equipo2, int goles1, int goles2, bool jugado){
  this->equipo1=equipo1;
  this->equipo2=equipo2;
  this->goles1=goles1;
  this->goles2=goles2;
  this->jugado=jugado;
}

Partidos::~Partidos(){
  cout << "Se elimino el Partido" << endl;
}

void Partidos::setEquipo1(Equipo* equipo1){
	this->equipo1=equipo1;
}

Equipo* Partidos::getEquipo1(){
	return this->equipo1;
}

void Partidos::setEquipo2(Equipo* equipo2){
	this->equipo2=equipo2;
}

Equipo* Partidos::getEquipo2(){
	return this->equipo2;
}

int Partidos::getGoles1(){
	return this->goles1;
}

void Partidos::setGoles1(int goles1){
	this->goles1=goles1;
}

int Partidos::getGoles2(){
	return this->goles2;
}

void Partidos::setGoles2(int goles2){
	this->goles2=goles2;
}

bool Partidos::getJugado(){
	return this->jugado;
}

void Partidos::setJugado(bool jugado){
	this->jugado=jugado;
}
