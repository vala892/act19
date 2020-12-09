#ifndef VIDEOJUEGO_H_INCLUDED
#define VIDEOJUEGO_H_INCLUDED

#include "civilizacion.h"
#include <vector>
#include <iomanip>

class VideoGame
{ 
    string nombreGame;
    vector<Civilizacion> _civilizacion;

public:
    VideoGame();
    void setNombreGame(const string &v);
    string getNombreGame();

    void agregarPersonaje(const Civilizacion &p);
    void mostrar();

    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    size_t total();
    void inicializar(const Civilizacion &c, size_t n);
    void eliminar(size_t pos);
    void primera();
    void ultimo();
    void ordenarNombre();
    void ordenarUbicacionX();
    void ordenarUbicacionY();
    void ordenarPuntuacion();



    Civilizacion* buscar(const Civilizacion &c);
    Civilizacion* modificar(Civilizacion &c);

    
    void respaldarCivilizacion();
    void recuperarCivilizacion();

    friend VideoGame& operator<<(VideoGame &v, const Civilizacion &p)
    {
        v.agregarPersonaje(p);

        return v;
    }



        // Respaldar
    friend ostream& operator<<(ostream &out, const VideoGame &c)
    {
        out << left;
        out << setw(20) << c.nombreGame;
        out << endl;
        return out;
    }

        // Recuperar
    friend istream& operator>>(istream &in, VideoGame &v){
        string s;
        
        cout << "Nombre de usuario: ";
        getline(cin, v.nombreGame);
        
        return in;
    }  

};

#endif // VIDEOJUEGO_H_INCLUDED
