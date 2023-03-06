#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include "../lib/otcolores.h"

using namespace std;
string const OTNOMBRE ="Oscar Danilo Tumbaco Vilcacundo";
int const OTCEDULA =1725721144;

struct otCoordenada
{
    int capacidad;
    string geolocalizacion;
    string Arsenal;
    otCoordenada* izquierda;
    otCoordenada* derecha;
};
void otInsertarCoordenada(otCoordenada*& raiz, int capacidad, string geo, string arsenal ) {
    if (raiz == nullptr) {
        raiz = new otCoordenada;
        raiz->capacidad  = capacidad;
        raiz->geolocalizacion = geo;
        raiz-> Arsenal = arsenal;
        raiz->izquierda = nullptr;
        raiz->derecha = nullptr;
    } else if (capacidad < raiz->capacidad) {
        otInsertarCoordenada(raiz->izquierda, capacidad, geo, arsenal);
    } else {
        otInsertarCoordenada(raiz->derecha, capacidad, geo, arsenal);
    }
}

void otLeerArchivo(string pathFile, otCoordenada*& raiz) {
    string s;
    fstream f;
    f.open(pathFile, ios_base::in);
    if ( !f.is_open() ) 
        cout << "Error de abrir el archivo." << endl;
    else {
        while(getline(f, s)) {
            size_t pos = s.find(',');
            int capacidad = s.substr(0, pos);
            string geo = s.substr(pos+1);  
            string arsenal = s.substr(pos+2);    
            int destruccion;
            stringstream ss(geo);  
            ss >> destruccion;  

            otInsertarCoordenada(raiz, capacidad, geo, arsenal);
        }
    }
    f.close();
}
void otLeerArchivo(string pathFile) { 
    string s;
    fstream f;
    f.open(pathFile, ios_base::in);
    if ( !f.is_open() ) 
        cout << "Error de abrir el archivo." << endl;
    else
    {
        int progress = 0;
        int totalLines = 0;
        while ( getline(f, s) )
        {
            cout << s << endl;
            progress++;
            totalLines++;
            int load = (progress * 100) / totalLines;
            cout << "Carga: " << load << "%" << endl;
        }
        Sleep(600);
    }
    f.close();
    system("pause");
}

void otVerArbol(Coordenda* arbol, int n) {
    if (arbol == nullptr) {
        return;
    }
    verArbol(arbol->derecha, n+1);

    for (int i=0; i<n; i++) {
        cout << "      ";
    }

    cout << arbol->nombre << " (Poblacion: " << arbol->poblacion << ")" << endl;

    verArbol(arbol->izquierda, n+1);
}

void otInfoArbol()
{
    cout<< "[+]Informacion Arbol Binario de capacidad belica Ucrania"<<endl
        << "Developer-Nombre :  "<< OTNOMBRE<<endl
        << "Developer-Cedula :  "<< OTCEDULA<<endl
        << "Capacidad Belica :  34"<<endl
        << "Coordenada Total :  10"<< endl
        << "Cordenadad- SecCarga : 1 2 4 5 7";
}
int main()
{
    
    otLeerArchivo("datafiles/Arsenal.txt");
    otInfoArbol();
    return 0;
}


//void otInsertarCoordenada(otCoordenada*& raiz, int capacidad, string geo, string arsenal ) {
//    if (raiz == nullptr) {
//        raiz = new otCoordenada;
//        raiz->capacidad  = capacidad;
//        raiz->geolocalizacion = geo;
//        raiz-> Arsenal = arsenal;
//        raiz->izquierda = nullptr;
//        raiz->derecha = nullptr;
//    } else if (capacidad < raiz->capacidad) {
//        otInsertarCoordenada(raiz->izquierda, capacidad, geo, arsenal);
//    } else {
//        otInsertarCoordenada(raiz->derecha, capacidad, geo, arsenal);
//    }
//}
//
//void otLeerArchivo(string pathFile, otCoordenada*& raiz) {
//    string s;
//    fstream f;
//    f.open(pathFile, ios_base::in);
//    if ( !f.is_open() ) 
//        cout << "Error de abrir el archivo." << endl;
//    else {
//        while(getline(f, s)) {
//            size_t pos = s.find(',');
//            string capacidad = s.substr(0, pos);
//            string geo = s.substr(pos+1);  
//            string arsenal = s.substr(pos+2);    // Leer la población como una cadena de caracteres
//            int destruccion;
//            stringstream ss(geo);  // Crear un objeto stringstream con la cadena de caracteres
//            ss >> destruccion;  // Leer el valor entero de la cadena de caracteres
//
//            otInsertarCoordenada(raiz, capacidad, geo, arsenal);
//        }
//    }
//    f.close();
//}
