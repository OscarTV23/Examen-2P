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
void otLeerArchivo(string nombreArchivo) 
{
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    int contador = 0;
    cout<<"[+]Leyendo Coordenadas ..."<<endl;
    cout<<"         Cap,   Geo,   Tipo Arsenal"<<endl;
    cout<<GREEN;
    if (archivo.is_open()) 
    {
        while (getline(archivo, linea)) 
        {
            if (contador == 0) {
                contador++;
                continue;
            }
            int ind =0;
            string c= "-"; 
            for(int i=0; i<= 100; i++)
            {   
                if(i % 4 ==0)
                ind =0;
                cout    << "\r" << c[ind++]   
                        << "   " << i << "%"<<"   ";
                Sleep(20);
            }
            cout << linea << endl;
        }
        archivo.close();
    }
    else 
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    cout<<RESET;
}

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

void LeerArchivo(string pathFile, otCoordenada*& raiz) {
    string s;
    fstream f;
    f.open(pathFile, ios_base::in);
    if ( !f.is_open() ) 
        cout << "Error de abrir el archivo." << endl;
    else {
        while(getline(f, s)) {
            stringstream ss(s);
            string capacidad_str, geolocalizacion_str, arsenal_str;
            getline(ss, capacidad_str, ',');
            getline(ss, geolocalizacion_str, ',');
            getline(ss, arsenal_str);
            int capacidad = stoi(capacidad_str);
            string geolocalizacion = geolocalizacion_str;
            string arsenal = arsenal_str;
            otInsertarCoordenada(raiz, capacidad, geolocalizacion, arsenal);
        }
    }
    f.close();
}
void otVerArbol(otCoordenada* arbol, int n) {
    if (arbol == nullptr) {
        return;
    }
    otVerArbol(arbol->derecha, n + 1);


    for (int i = 0; i < n; i++) {
        cout << "      ";
    }

    cout << arbol->geolocalizacion <<  arbol->capacidad <<"{"<< arbol->Arsenal << "}" << endl;

    otVerArbol(arbol->izquierda, n + 1);
}

void otInfoArbol()
{
    cout<<BLUE
        << "[+]Informacion Arbol Binario de capacidad belica Ucrania"<<endl
        << "Developer-Nombre :  "<< OTNOMBRE<<endl
        << "Developer-Cedula :  "<< OTCEDULA<<endl
        << "Capacidad Belica :  34"<<endl
        << "Coordenada Total :  5"<< endl
        << "Cordenadad- SecCarga : 1 2 4 5 7"<<endl<<RESET;
}
int main() {
    otCoordenada* raiz = nullptr;
    //otLeerArchivo("datafiles/Arsenal.txt");
    //system("pause");
    //system("cls");
    //otInfoArbol();
    //system("pause");
    //system("cls");
    otVerArbol(raiz, 0);
    
    return 0;
}
