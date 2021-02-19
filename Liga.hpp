#ifndef LIGA_H
#define LIGA_H
#include<string>
#include<iostream>
#include <vector>
using namespace std;
class Liga {
  private:
  string nombre;
  vector<Equipo*> listaEquipos;
  vector<Partidos*> Jornada;
  TablaPosiciones* tabla;
  public:
  Liga();  
  Liga(string,vector<Equipo*>,vector<Partidos*>,TablaPosiciones*);
  ~Liga();
  string getNombre();
  vector<Equipo*> getListaEquipos();
  vector<Partidos*> getJornada();
  TablaPosiciones* getTabla();
  void setNombre(string);
  void setTabla(TablaPosiciones*);
};
#endif