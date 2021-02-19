#include "Liga.hpp"

using namespace std;

Liga::Liga(){
  // cout<<"llamaron al vacio" << endl;
}

Liga::Liga(string nombre,vector<Equipo*> listaEquipos, vector<Partidos*> Jornada, TablaPosiciones* Tabla){
  this->nombre=nombre;
  this->listaEquipos=listaEquipos;
  this->Jornada=Jornada;
  this->tabla=tabla;
}

Liga::~Liga(){
  cout << "Se elimino la liga" << endl;
}

void Liga::agregarEquipo(Equipo* e){
	
	listaEquipos.push_back(e);
	cout<<"Bienvenido "<<e->getNombre()<<" a la liga, su skill es: "<<e->getSkill()<<endl;
	
}

void Liga::agregarPartidos(Partidos* p){
	Jornada.push_back(p);
	cout<<"Partido entre "<<p->getEquipo1()->getNombre()<<" y "<<p->getEquipo2()->getNombre()<<" listo para jugar"<<endl;
}

void Liga::listarEquipos(){
	
	for(int i = 0; i < listaEquipos.size(); i++) {
		Equipo* e =  listaEquipos.at(i);
		cout<<i<<") "<<e->getNombre()<<" Skill: "<<e->getSkill()<<endl;
	}
	
}

void Liga::imprimirJornada(){
	cout<<endl<<"JORNADA ACTUAL"<<endl;
	for(int i = 0; i < Jornada.size(); i++){
		Partidos* p = new Partidos();
		p = Jornada.at(i);
		cout<<i<<" ) "<<p->getEquipo1()->getNombre()<<" vs. "<<p->getEquipo2()->getNombre()<<" "<<p->getGoles1()<<" - "<<p->getGoles2()<<endl;
	}
}


void Liga::setNombre(string nombre){
	this->nombre=nombre;
}

string Liga::getNombre(){
	return this->nombre;
}

vector<Equipo*> Liga::getListaEquipos(){
	return this->listaEquipos;
}

vector<Partidos*> Liga::getJornada(){
	return this->Jornada;
}

void Liga::setTabla(TablaPosiciones* tabla){
	this->tabla=tabla;
}

TablaPosiciones* Liga::getTabla(){
	return this->tabla;
}
