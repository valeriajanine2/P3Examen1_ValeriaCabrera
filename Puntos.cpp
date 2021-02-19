#include "Puntos.hpp"
#include <stdlib.h>
#include <ctime>
#include "Equipo.hpp"

Puntos::Puntos(){
  // cout<<"llamaron al vacio" << endl;
}

Puntos::Puntos(Equipo* equipo, int aFavor, int enContra, int ganados, int perdidos, int empatados){
  this->equipo=equipo;
  this->aFavor=aFavor;
  this->enContra=enContra;
  this->ganados=ganados;
  this->perdidos=perdidos;
  this->empatados=empatados;
}

Puntos::~Puntos(){
  cout << "Se elimino el Puntos" << endl;
}

Equipo* Puntos::getEquipo(){
	return this->equipo;
}

string Puntos::imprimirPuntos(){
	string resp;
	int totaljugados;
	totaljugados=ganados+perdidos+empatados;
	resp = equipo->getNombre() +"|" +std::to_string(totaljugados) + "|" + std::to_string(ganados) + "|" + std::to_string(perdidos) + "|" + std::to_string(empatados) + "|" + std::to_string(aFavor) + "|" + std::to_string(enContra) + "|";
	return resp;
}

string Puntos::puntosTotales(){
	string resp;
	int points = (ganados*3) + (empatados);
	resp = std::to_string(points);
	return resp;
}

void Puntos::setEquipo(Equipo* equipo){
	this->equipo=equipo;
}

int Puntos::getAFavor(){
	return this->aFavor;
}

void Puntos::setAFavor(int aFavor){
	this->aFavor=aFavor;
}

int Puntos::getEnContra(){
	return this->enContra;
}

void Puntos::setEnContra(int enContra){
	this->enContra=enContra;
}

int Puntos::getGanados(){
	return this->ganados;
}

void Puntos::setGanados(int ganados){
	this->ganados=ganados;
}

int Puntos::getPerdidos(){
	return this->perdidos;
}

void Puntos::setPerdidos(int perdidos){
	this->perdidos=perdidos;
}

int Puntos::getEmpatados(){
	return this->empatados;
}

void Puntos::setEmpatados(int Empatados){
	this->empatados=empatados;
}
