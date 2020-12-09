#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<string>
#include <vector>

#include "videojuego.h"
#include "aldeanomenu.h"

using namespace std;

    // Civilizacion
void nombreUsuario();
void agregar();
void insertar();
void crear();
void primPos();
void ultiPos();
void ordenarCivilizacion();
void eliminarCivilizacion();
void buscarCivilizacion();
void buscarCivilizacionAgregaAldeano();
void modificarCivilizacion();
void resumen();


    // Aldeanos
void vectorMenuAldeanos();
void agregaSeleccion();
void elegirSeleccion();

Videojuego 1;
vector<Civilizacion> vectorAldeanos;

int main(){
    string op;

    while (true){

        system("cls");

        cout << "\t Usuario:" << l.getNombreGame() << endl;
        cout << "1) Nombre de usuario" << endl;
        cout << "2) Agregar " << endl;
        cout << "3) Insertar " << endl;
        cout << "4) Crear" << endl;
        cout << "5) Primera" << endl;
        cout << "6) Ultima" << endl;
        cout << "7) Ordena" << endl;
        cout << "8) Elimina" << endl;
        cout << "9) Busca" << endl;
        cout << "10) Modifica" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Salir" << endl;
        cout << "13) buscar y agrega aldeano" << endl;
        cout << "14) Respaldar Civilizacion" << endl;
        cout << "15) Recuperar Civilizacion y aldeanos" << endl;
        cout << "Opcion:" << endl;
        getline(cin, op);



        if (op == "1"){
            nombreUsuario();
        }
        else if (op == "2"){
            agregar();
        }
        else if (op == "3"){
            insertar();
        }
        else if (op == "4"){
            crear();
        }
        else if (op == "5"){
            primPos();
        }
        else if (op == "6"){
            ultiPos();
        }
        else if (op == "7"){
            ordenarCivilizacion();
        }
        else if (op == "8"){
            eliminarCivilizacion();
        }
        else if (op == "9"){
            buscarCivilizacion();
        }
        else if (op == "10"){
            modificarCivilizacion();
        }
        else if (op == "11"){
            resumen();
        }
        else if (op == "12"){
            system("pause");
            break;
        }
        else if (op == "13"){
            buscarCivilizacionAgregaAldeano();
        }
        else if (op == "14"){
            l.respaldarCivilizacion();
        }
        else if (op == "15"){
            l.recuperarCivilizacion();
        }
    }



    getch();
    return 0;
}
    // Nombre usuario de civilizacion
void nombreUsuario(){
    string _nombreGame;
    cout << "Ingresa de usuario" << endl;
    getline(cin, _nombreGame);
    l.setNombreGame(_nombreGame);

}
    // Agrega civilizacion
void agregar(){
    Civilizacion c;

    cin >> c;

    l.agregarPersonaje(c);
    cin.ignore();
}

    // Inserta civilizacion
void insertar(){
    Civilizacion c;
    cin >> c;

    size_t pos;
    cout << "Posicion: " << endl;
    cin >> pos; cin.ignore();

    if (pos >= l.size()){
        cout << "Posicion no valida" << endl;
    }
    else {
        l.insertar(c,pos);
    }
}

    // Crea civilizacion
void crear(){
    Civilizacion c;
    cin >> c;

    size_t n;
    cout << "n: " << endl;
    cin >> n; cin.ignore();
    l.inicializar(c, n);
}

    // Manda civilizacion en primera posicion
void primPos(){
    l.primera();
    cout << endl;
    system("pause");
}

    // Manda civilizacion en ultima posicion
void ultiPos(){
    l.ultimo();
    cout << endl;
    system("pause");
}

    // Menu de ordenamiento de civilizacion
void ordenarCivilizacion(){
    string opc;

    cout << endl;
    cout << "Selecciona la opcion a ordenar: " << endl;
    cout << "1) Nombre" << endl;
    cout << "2) Ubicacion en X" << endl;
    cout << "3) Ubicacion en Y" << endl;
    cout << "4) Puntuacion" << endl;
    getline(cin, opc);

    if (opc == "1"){
        l.ordenarNombre();
    }
    else if (opc == "2"){
        l.ordenarUbicacionX();
    }
    else if (opc == "3"){
        l.ordenarUbicacionY();
    }
    else if (opc == "4"){
        l.ordenarPuntuacion();
    }
}

    // Civilizacion
void eliminarCivilizacion(){
    size_t pos;
    cout << "Posicion: " << endl;
    cin >> pos; cin.ignore();

    if (pos >= l.size()){
        cout << "Posicion no valida" << endl;
    }
    else {
        l.eliminar(pos);
    }
}

    // Busca civilizacion
void buscarCivilizacion(){
    Civilizacion c;
    cin >> c; cin.ignore();

    Civilizacion *ptr = l.buscar(c);
    if (ptr == nullptr){
        cout << endl << "No encontrado" << endl;
    }
    else {
        cout << "Encontrado" << endl << endl;
        cout << *ptr << endl;
        system("pause");
    }
    cout << endl;
    system("pause");
}

    // Busca civilizacion para agregar aldeano
void buscarCivilizacionAgregaAldeano(){
    Civilizacion c;
    cin >> c; cin.ignore();

    Civilizacion *ptr = l.buscar(c);
    if (ptr == nullptr){
        cout << endl << "No encontrado" << endl;
    }
    else {
        cout << endl <<"ENCONTRADO" << endl << endl;
        system("pause");
        menuAldeano(*ptr);

    }
    cout << endl;
    system("pause");
}

    //  Modifica civilizacion
void modificarCivilizacion(){
    // Modificar
    Civilizacion c;
    cin >> c; cin.ignore();


    Civilizacion *ptr = l.buscar(c);
    if (ptr == nullptr){
        cout << endl << "No encontrado" << endl;
    }
    else {
        cout << endl << endl << "Civilizacion encontrada" << endl;
        cout << *ptr << endl;
        l.modificar(*ptr);

    }
    cout << endl;
    system("pause");
}

void resumen(){
    l.mostrar();
    cout << endl;
    system("pause");
}

    // Funcion agregar seleccion
void agregaSeleccion() {
    string nombre;
    Civilizacion aldea;

    cout << endl <<"Nombre: " << endl;
    getline(cin, nombre);
    aldea.setNombreList(nombre);

    vectorAldeanos.push_back(aldea);
}


    // Funcion vector aldeanos
void elegirSeleccion(){
    if (vectorAldeanos.empty()) {
        cout << endl <<"No hay civilizaciones" << endl;
        system("pause");
    } else {
        for (size_t i=0; i < vectorAldeanos.size(); i++){
            Civilizacion &aldea = vectorAldeanos[i];

            cout <<i+1 << ") ";
            cout << aldea.getNombreList() << endl;
        }
        cout << "0) Salir" << endl;

        size_t ops;
        cin >> ops; cin.ignore();

        if (ops > vectorAldeanos.size()){
            cout << "Opcion invalida" << endl;
        } else if (ops != 0) {
            Civilizacion &aldea = vectorAldeanos[ops-1];
            menuAldeano(aldea);
        }
    }
}

