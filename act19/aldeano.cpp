#include "aldeano.h"

// NombreAldeano
void Aldeano::setNombreAldeano(const string &nombreAldeano) {
    this->nombreAldeano = nombreAldeano;
}

string Aldeano::getNombreAldeano() const {
    return nombreAldeano;
}

// Edad
void Aldeano::setEdad(int edad) {
    this->edad = edad;
}

int Aldeano::getEdad() const {
    return edad;
}

// Genero
void Aldeano::setGenero(const string &genero) {
    this->genero = genero;
}

string Aldeano::getGenero() const {
    return genero;
}

// Salud
void Aldeano::setSalud(int salud) {
    this->salud = salud;
}

int Aldeano::getSalud() const {
    return salud;
}
