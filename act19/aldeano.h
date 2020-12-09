#ifndef ALDEANO_H_INCLUDED
#define ALDEANO_H_INCLUDED

#include <iostream>
#include <iomanip>


using namespace std;

class Aldeano
{
public:
    Aldeano() {}
    Aldeano(const string &nombreAldeano, int edad, const string &genero, int salud = 0)
    : nombreAldeano(nombreAldeano), edad(edad), genero(genero), salud(salud) {}

    void setNombreAldeano(const string &nombreAldeano);
    string getNombreAldeano() const ;

    void setEdad(int edad);
    int getEdad() const ;

    void setGenero(const string &genero);
    string getGenero() const ;

    void setSalud(int salud);
    int getSalud() const;


    // Respaldar aldeano
    void respaldarAldeano();



    /* Primera carga de extraccion */
    friend ostream& operator<<(ostream &out, const Aldeano &j)
    {
        out << left;
        out << setw(15) << j.nombreAldeano;
        out << setw(10) << j.edad;
        out << setw(15) << j.genero;
        out << setw(10) << j.salud;

        return out;
    }

    /* Segunda carga de insersion */
    friend istream& operator>>(istream &in, Aldeano &c)
    {

        cout << "Nombre Aldeano: ";
        getline(cin, c.nombreAldeano);
        
        cout << "Edad: ";
        cin >> c.edad;
        
        cout << "Genero: ";
        cin >> c.genero;
        
        cout << "Salud: ";
        cin >> c.salud;

        return in;
    } 


    bool operator==(const Aldeano& j){
        return nombreAldeano == j.nombreAldeano;
    }
    
    bool operator==(const Aldeano& j) const{
        return nombreAldeano == j.nombreAldeano;
    }

    bool operator<(const Aldeano& j){ 
        return nombreAldeano < j.nombreAldeano;
    }

    bool operator<(const Aldeano& j) const{ 
        return nombreAldeano < j.nombreAldeano;
    }

private:
    string nombreAldeano;
    int edad;
    string genero;
    int salud;
};

#endif
