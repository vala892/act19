#ifndef ALDEANOMENU_H_INCLUDED
#define ALDEANOMENU_H_INCLUDED

#include "civilizacion.h"
#include <string>
#include <cstdlib>


Aldeano capturar(){
    Aldeano j;
    string _nombreAldeano;
    int _edad;
    string _genero;
    int _salud;


    cout << "Nombre de aldeano: ";
    getline(cin, _nombreAldeano); fflush(stdin);
    j.setNombreAldeano(_nombreAldeano);
    
    cout << "Edad: ";
    cin >> _edad; fflush(stdin);
    j.setEdad(_edad);

    cout << "Genero: ";
    getline(cin, _genero); fflush(stdin);
    j.setGenero(_genero);
    
    cout << "Salud: ";
    cin >> _salud; fflush(stdin);
    j.setSalud(_salud);

    return j;
}




void menuAldeano(Civilizacion &p){   
        // menu aldeanos
    string opcion;
    while(true){
        system ("cls");
        cout << "\t.:MENU ALDEANO:." << endl;
        cout << "1) Agregar Aldeano" << endl;
        cout << "2) Eliminar Aldeano" << endl;
        cout << "3) Clasificar Aldeanos" << endl;
        cout << "4) Buscar Aldeano" << endl;
        cout << "5) Modificar Aldeano" << endl;
        cout << "6) Mostrar" << endl;
        cout << "7) Respaldar aldeano" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";
        getline (cin, opcion);
            
            //Agregar
        if (opcion=="1"){   
            system ("cls");
            int opcion;
            cout << "\t.:AGREGAR ALDEANO:." << endl;
            cout << "1) Agregar el objeto aldeano al inicio" << endl;
            cout << "2) Agregar el objeto aldeano al final" << endl;
            cout << "Opcion: ";
            cin >> opcion; cin.ignore();
            switch(opcion){   
                case 1:
                p.agregarInicio(capturar());
                break;

                case 2:
                p.agregarFinal(capturar());
                break;

                default:
                cout << "Opcion invalida, pruebe de nuevo...";
                system("pause");
                break;
                }
            } 

            // eliminar
        else if (opcion == "2"){
            string nombre;
            int salud;
            int opcion;
            system ("cls");
            cout << "\t.:ELIMINAR ALDEANO:." << endl;
            cout << "1) Eliminar por nombre" << endl;
            cout << "2) Eliminar aldeanos donde su salud sea menor a x" << endl;
            cout << "3) Eliminar aldeanos donde su edad sea mayor igual a 60" << endl;
            cout << "Opcion: ";
            cin >> opcion; cin.ignore();
            switch(opcion){
                case 1:
                cout << "Ingrese el nombre del Aldeano a eliminar: ";
                getline(cin,nombre);

                p.eliminarNombre(nombre);
                break;

                case 2:
                cout << "Eliminar por Salud" << endl;
                cout << "Salud: ";
                cin >> salud; cin.ignore();

                p.eliminarSalud(salud);
                break;

                case 3:
                p.eliminarEdad();
                break;

                default:
                cout << "Opcion invalida, pruebe de nuevo...";
                system("pause");
                break;
                }
            } 
            
            // clasificar
        else if (opcion == "3"){
            int opcion;
            system ("cls");
            cout << "\t.:CLASIFICAR ALDEANO:." << endl;
            cout << "1) Clasificar la lista de aldeanos por nombre" << endl;
            cout << "2) Clasificar la lista de aldeanos por edad " << endl;
            cout << "3) Clasificar la lista de aldeanos por salud " << endl;
            cout << "Opcion: ";
            cin >> opcion; cin.ignore();
            switch(opcion){
                case 1:
                    p.ordenarNombre();
                    break;

                case 2:
                    p.ordenarEdad();
                    break;

                case 3:
                    p.ordenarSalud();
                    break;

                    default:
                    cout << "Opcion invalida, pruebe de nuevo...";
                    system("pause");
                    break;
                }
        } 
            
            // buscar
        else if (opcion == "4"){
            string _nombreAldeano;
            cout << "Ingrese el nombre del Aldeano a buscar: ";
            getline(cin,_nombreAldeano);

            p.buscarNombreAldeano(_nombreAldeano);

            cout << endl;
            system("pause");
        } 
            

            // modificar
        else if (opcion == "5"){
            string _nombreAldeano;
            cout << "Ingrese el nombre del Aldeano a buscar: ";
            getline(cin,_nombreAldeano);

            p.buscarAldeano(_nombreAldeano);

            cout << endl;
            system("pause");
        } 
            

            // mostrar
        else if (opcion == "6"){   
            system ("cls");

            cout << endl << ".:Tabla:.";
            p.mostrar();
            system ("pause");
        }


        // Respaldar Aldeano
        else if (opcion == "7"){   
            system ("cls");
            p.respaldar_aldeanos();
            system ("pause");
        }

            // Salir
        else if (opcion == "0"){   
            break;
        }
    }
}


#endif // ALDEANOMENU_H_INCLUDED
