#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <set>
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
    set<string> lineasImpresas; 
    cout<<"[+]Leyendo Coordenadas ..."<<endl;
    cout<<RED<<">>Error:  Cap,   Geo,   Tipo Arsenal-> stoi"<<RESET<<endl;
    cout<<GREEN;
    if (archivo.is_open()) 
    {
        while (getline(archivo, linea)) 
        {
            if (contador == 0) {
                contador++;
                continue;
            }
            if (lineasImpresas.count(linea) > 0) {
                continue;
            }
            lineasImpresas.insert(linea);
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
struct otnodo
{
    string coordenada;
    otnodo *izq, *der;
};

void otInsertar(string coordenada, otnodo *&arbol)
{
    if (arbol == NULL)
    {
        arbol = new otnodo;
        arbol->coordenada = coordenada;
        arbol->izq = NULL;
        arbol->der = NULL;
    }
    else if (coordenada < arbol->coordenada)
    {
        otInsertar(coordenada, arbol->izq);
    }
    else
    {
        otInsertar(coordenada, arbol->der);
    }
}

void verArbol(otnodo *arbol, int n)
{
    if (arbol == NULL)
        return;
    verArbol(arbol->der, n + 3);

    for (int i = 0; i < n; i++)
        cout << "   ";

    cout << arbol->coordenada << endl;

    verArbol(arbol->izq, n + 3);
}


int main() {
    otLeerArchivo("datafiles/Arsenal.txt");
    system("pause");
    system("cls");
    otInfoArbol();
    system("pause");
    system("cls");
    otnodo *arbol = NULL;

    otInsertar(BLUE"GPS.4 {acd}", arbol);
    otInsertar(BLUE"GPS.1 {bc}", arbol);
    otInsertar(BLUE"GPS.2 {ac}", arbol);
    otInsertar(RED"GPS.7 {aaabbct   BOMB-IP}", arbol);
    otInsertar(BLUE"GPS.5 {bct}", arbol);
    verArbol(arbol, 0);
    return 0;
}
