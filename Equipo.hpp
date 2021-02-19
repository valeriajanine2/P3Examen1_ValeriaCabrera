#ifndef EQUIPO_H
#define EQUIPO_H
#include<string>
#include<iostream>
using namespace std;
class Equipo {
  private:
  string nombre;
  int skill;
  public:
  Equipo();  
  Equipo(string,int);
  ~Equipo();
  string getNombre();
  int getSkill();
  void setNombre(string);
  void setSkill(int);
};
#endif