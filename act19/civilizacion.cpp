#include "civilizacion.h"
#include<fstream>

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &nombre, float ubicacionX, float ubicacionY, float puntuacion)
{
    this->nombre = nombre;
    this->ubicacionX = ubicacionX;
    this->ubicacionY = ubicacionY;
    this->puntuacion = puntuacion;
}
void Civilizacion::setNombre(const string &v){
    nombre = v;
}
string Civilizacion::getNombre(){
    return nombre;
}

void Civilizacion::setUbicacionX(float v){
    ubicacionX = v;
}
float Civilizacion::getUbicacionX(){
    return ubicacionX;
}

void Civilizacion::setUbicacionY(float v){
    ubicacionY = v;
}
float Civilizacion::getUbicacionY(){
    return ubicacionY;
}

void Civilizacion::setPuntuacion(float v){
    puntuacion = v;
}
float Civilizacion::getPuntuacion(){
    return puntuacion;
}

void Civilizacion::respaldar_aldeanos()
{
    ofstream aldeanosOF(getNombre() + ".txt", ios::out);
    
    for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        aldeanosOF << aldeano.getNombreAldeano() << endl;
        aldeanosOF << aldeano.getEdad()   << endl;
        aldeanosOF << aldeano.getGenero() << endl;
        aldeanosOF << aldeano.getSalud()  << endl;
    }
    aldeanosOF.close();
}




    // Recuperar aldeanos
void Civilizacion::recuperar_aldeanos(){
    ifstream archivo(getNombre() + ".txt");
    if (archivo.is_open()){
        string temp;
        int _edad;
        int _salud;
        Aldeano p;

        while (true){
            getline(archivo, temp); 
            if(archivo.eof()){ break;} cin.sync();
            p.setNombreAldeano(temp);

            getline(archivo, temp); 
            _edad = stof(temp); cin.sync();      
            p.setEdad(_edad);
            
            getline(archivo, temp);
            if(archivo.eof()){ break;} cin.sync();   
            p.setGenero(temp);
            
            getline(archivo, temp); 
            puntuacion = stoi(temp); cin.sync();      
            p.setSalud(puntuacion);

            agregarFinal(p);
        }
    }
    archivo.close();
}    



    // Nombre de la seleccion
void Civilizacion::setNombreList(const string &nombreList){
    this->nombreList = nombreList;
}

string Civilizacion::getNombreList(){
    return nombreList;
}

// Agrega al final
void Civilizacion::agregarFinal(const Aldeano &j){
    aldeanos.push_back(j);
}

// Agrega al inicio
void Civilizacion::agregarInicio(const Aldeano &j){
    aldeanos.push_front(j);
}

// Imprime aldeanos
void Civilizacion::print(){
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        cout << *it << endl;
    }
}

// Elimina nombre  aldeano
void Civilizacion::eliminarNombre(const string &nombre)
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        Aldeano &j = *it;

        if (nombre == j.getNombreAldeano()) {
            aldeanos.erase(it);
            break;
        }
    }
}

// Busca nombre  aldeano
void Civilizacion::buscarNombreAldeano(const string &nombre) {
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        Aldeano &j = *it;

        if (nombre == j.getNombreAldeano()) {
            cout << endl << *it << endl << "Si se encontro aldeano"<< endl;
            system("pause");
            break;
        }
    }
    cout << "No se encontro aldeano";
}

// Busca nombre  aldeano para editar
void Civilizacion::buscarAldeano(const string &nombre) {
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        Aldeano &j = *it;

        if (nombre == j.getNombreAldeano()) {
            cout << *it << endl << "Si se Encuentro"<< endl;
            modificarAldeano(*it);
            break;
        }
    }
}


// Comparara y eliminara a todos los aldeanos con edad mayor o igual a 60
bool comparador(const Aldeano &j) {
    return j.getEdad()>=60; 
}

void Civilizacion::eliminarEdad() {
    aldeanos.remove_if(comparador);
}

// Elimina en salud n
void Civilizacion::eliminarSalud(int salud) {   
    //funcion lambda salud                                           ?
    aldeanos.remove_if([salud](const Aldeano &j){return j.getSalud() < salud;});
}






    // Ordenamiento por Nombre
void Civilizacion::ordenarNombre() {
    aldeanos.sort();
}

    // Comparador de numero menor a mayor
bool comparadorEdad(const Aldeano &j1, const Aldeano &j2) {                   
    return j1.getEdad() > j2.getEdad();
}

    // Ordenamiento por numero
void Civilizacion::ordenarEdad() {
    aldeanos.sort(comparadorEdad);
}

    // Ordenar por goles de mayor a menor
void Civilizacion::ordenarSalud() {                                             //  ?
    aldeanos.sort([](const Aldeano &j1, const Aldeano &j2){return j1.getSalud() > j2.getSalud();});
}

void Civilizacion::mostrar() {

    cout << endl;
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(10) << "Edad";
    cout << setw(15) << "Genero";
    cout << setw(10) << "Salud";
    cout << endl << endl;
    for ( auto it = aldeanos.begin() ; it != aldeanos.end() ; it++ ){

        Aldeano &j = *it;
        cout << j << endl;
    }

}



// Modificar aldeano
Aldeano* Civilizacion::modificarAldeano(Aldeano &c) {
    int op;
    string _nombreAldeano;
    int _edad;
    string _genero;
    int _salud;
    cout << endl <<".:Modificar Civilizacion:." << endl;
    cout << "1) Modificar el Nombre" << endl;
    cout << "2) Modificar la Edad" << endl;
    cout << "3) Modificar la Genero" << endl;
    cout << "4) Modificar la Salud" << endl;
    cout << "Selecciona el dato que desee modificar: " << endl;
    cin >> op; 
    cin.ignore();
    cout << endl;

    if (op == 1) {
        cout << "Ingresa el nombre:" << endl;
        getline(cin,_nombreAldeano);
        c.setNombreAldeano(_nombreAldeano);   
    } 
    else if (op == 2) {
        cout << "Ingresa la Edad:" << endl;
        cin >> _edad; cin.ignore();
        c.setEdad(_edad);
    }
    else if (op == 3) {
        cout << "Ingresa la Genero:" << endl;
        getline(cin,_genero);
        c.setGenero(_genero);  
    }
    else if (op == 4) {
        cout << "Ingresa la Salud:" << endl;
        cin >> _salud; cin.ignore();
        c.setSalud(_salud); 
    }
    cout << endl <<"Registro Actializado" << endl;
}
