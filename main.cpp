#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Equipo.hpp"
#include "Liga.hpp"
#include "Partidos.hpp"
#include "Puntos.hpp"
#include "TablaPosiciones.hpp"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	srand (time(NULL));
	Liga* league = new Liga();
	league->setNombre("Mini Liga");
	Equipo* equipo = new Equipo();
	Partidos* partido = new Partidos();
	Puntos* puntos = new Puntos();
	TablaPosiciones* tabla = new TablaPosiciones();
	
	vector<Equipo*> temp;

	int opcion = 0;
	int opcion2 = 0;
	while(opcion!=5) {

		cout<<"MENU\n1) Mantenimiento de Equipos\n2) Generar Jornada de Partidos\n3) Simular Partidos\n4) Imprimir Tabla de Posiciones y Resultados\n5) Salir"<<endl;
		cout<<"Ingrese el numero de la opcion que desea realizar: ";
		cin>>opcion;

		switch(opcion) {
			case 1: {

				cout<<"1) Crear Equipo\n2) Modificar Equipo\n3) Listar Equipo\n4)Eliminar Equipo";
				cout<<endl<<"Ingrese el numero de la opcion que desea realizar: ";
				cin>>opcion2;

				switch(opcion2) {

					case 1: {

						string nombre;
						cout<<"Ingrese el nombre del equipo: ";
						cin>>nombre;

						int skill = 0 + (rand()%101);

						equipo = new Equipo(nombre,skill);

						league->getListaEquipos().push_back(equipo);

						puntos = new Puntos(equipo,0,0,0,0,0);

						league->agregarEquipo(equipo);
						
						temp.push_back(equipo);
						
						tabla->agregarPuntos(puntos);

						break;
					}//fin del case de agregar

					case 2: {

						int index;

						cout<<"Ingrese el numero del indice que desea modificar: ";
						cin>>index;

						while(league->getListaEquipos().size() < index || index<0) {

							cout<<"No existe un equipo con ese indice";
							cout<<"Ingrese el numero del indice que desea modificar: ";
							cin>>index;
						}//fin de la validacion

						Equipo* e = league->getListaEquipos().at(index);

						string nom;
						int skill = 0 + (rand()%101);

						cout<<"Ingrese el nuevo nombre del equipo: ";
						cin>>nom;

						e->setNombre(nom);
						
						int change;
						cout<<"Desea modificar el skill? Ingrese 1 para si y 0 para no: ";
						cin>>change;
						
						if(change==1){
							e->setSkill(skill);
						}else if(change==0){
							//no se cambia solo lo ocupo para validacion
						}else{
							cout<<"Asegurese de leer bien las instrucciones"<<endl;
						}

						break;
					}//fin del case de modificar

					case 3: {

						league->listarEquipos();

						break;
					}//fin del case de listar

					case 4: {
						
						int index;
						
						cout<<"Ingrese el indice del equipo que desea eliminar: ";
						cin>>index;
						
						while(league->getListaEquipos().size() < index || index<0) {

							cout<<"No existe un equipo con ese indice";
							cout<<"Ingrese el numero del indice que desea eliminar: ";
							cin>>index;
							
						}//fin de la validacion
						
							league->getListaEquipos().erase(league->getListaEquipos().begin() + index);
						
						break;
					}

					default: {
						cout<<"Asegurese de ingresar una de las opciones del menu"<<endl;
						break;
					}

				}//fin del switch interno

				break;
			}

			case 2: {

				int team1, team2;
				
				
				while(temp.size()!=0){
					
					int limit = temp.size();
					team1 = 0 + (rand()%limit);
					team2 = 0 + (rand()%limit);
					
					while(team1==team2){
						team1 = 0 + (rand()%limit);
						team2 = 0 + (rand()%limit);
					}//fin de la validacion
					
					Equipo* equipo1 = temp.at(team1);
					Equipo* equipo2 = temp.at(team2);
					
					Partidos* p = new Partidos(equipo1,equipo2,0,0,false);
					
					league->agregarPartidos(p);
					
					if(team1>team2){
						temp.erase(temp.begin() + team1);
						temp.erase(temp.begin() + team2);
					}else{
						temp.erase(temp.begin() + team2);
						temp.erase(temp.begin() + team1);
					}
				}
					
				break;
			}

			case 3:{		                                    
				
				
				for(int i = 0; i < league->getJornada().size(); i++){
					
					Puntos* puntos1 = new Puntos();
					Puntos* puntos2 = new Puntos();
					
					int rand1, rand2;
					rand1 = -15 + (rand()%15);
					rand2 = -15 + (rand()%15);
					Partidos* p = new Partidos();
					p = league->getJornada().at(i);
					int avg1 = p->getEquipo1()->getSkill() + rand1;
					int avg2 = p->getEquipo2()->getSkill() + rand2;
					int goles1 = avg1/10;
					int goles2 = avg2/10;
					
					//determinar goles
					if(goles1<=0){
						p->setGoles1(0);
					}else if(goles2<=0){
						p->setGoles2(0);
					}else{
						p->setGoles1(goles1);
						p->setGoles2(goles2);
					}
					
					for(int i = 0; i < tabla->getPuntosEquipo().size(); i++){
						Puntos* points = new Puntos();
						points = tabla->getPuntosEquipo().at(i);
						//si el nombre del equipo es igual
						if(points->getEquipo()->getNombre() == p->getEquipo1()->getNombre() ){
							puntos1 = points;
						}else if(points->getEquipo()->getNombre() == p->getEquipo2()->getNombre()){
							puntos2 = points;
						}
					}
					
					//set a favor
					int set1 = puntos1->getAFavor() + goles1;
					puntos1->setAFavor(set1);
					int set2 = puntos2->getAFavor() + goles2;
					puntos2->setAFavor(set2);
					
					//en contra
					int set3 = puntos1->getEnContra() + goles2;
					puntos1->setEnContra(set3);
					int set4 = puntos2->getEnContra() + goles1;
					puntos2->setEnContra(set4);
					
					//determinar ganador
					if(avg1>avg2){
						int g = puntos1->getGanados() + 1;
						puntos1->setGanados(g);
						int p = puntos2->getPerdidos() + 1;
						puntos2->setPerdidos(p);
					}else if(avg2>avg1){
						int g = puntos2->getGanados() + 1;
						puntos2->setGanados(g);
						int p = puntos1->getPerdidos() + 1;
						puntos1->setPerdidos(p);
					}else{
						int e = puntos1->getEmpatados() + 1;
						int e2 = puntos2->getEmpatados() + 1;
						puntos1->setEmpatados(e);
						puntos2->setEmpatados(e2);
					}
					
				}
				
				
				

				break;
		 	}

			case 4: {

				tabla->imprimirTabla();
				league->imprimirJornada();
				cout<<endl;
				
					
				break;
			}

			case 5: {
				cout<<"Adios, tenga buen dia <3";
				break;
			}

			default: {
				cout<<"Asegurese de ingresar una de las opciones del menu"<<endl;
				break;
			}
		}

	}//fin del while del menu

	return 0;
}