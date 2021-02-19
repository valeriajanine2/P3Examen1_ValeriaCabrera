#include "Equipo.hpp"
#include <stdlib.h>
#include <ctime>

Equipo::Equipo(){
  // cout<<"llamaron al vacio" << endl;
}

Equipo::Equipo(string nombre,int skill){
  this->nombre=nombre;
  this->skill=skill;
}

Equipo::~Equipo(){
  cout << "Se elimino el equipo" << endl;
}

void Equipo::setNombre(string nombre){
	this->nombre=nombre;
}

string Equipo::getNombre(){
	return this->nombre;
}

void Equipo::setSkill(int skill){
	this->skill = skill;
}

int Equipo::getSkill(){
	return this->skill;
}