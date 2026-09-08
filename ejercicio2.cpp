#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include "tads/HashAbiertoImp.cpp"

#include "clases/clave.cpp"

using namespace std;



int funcionHash(clave c1) {
    long retorno = 0;
    string palabra = c1.getPalabra();

    for (char letra : palabra) {
        retorno = (retorno * 31 + letra) % 166669;
    }

    return retorno;
}

bool sonIguales(clave c1, clave c2){
    return c1 == c2;
}

int main() {

    int cantPalabras;
    cin >> cantPalabras;

    int bucketsUsados = 0;
    int max = 0;

    int cantBuckets = (cantPalabras / 0.6) + 1; //redondea para arriba

    HashAbierto<clave, int> cajonesAgrupados(cantBuckets, funcionHash, sonIguales);

    for(int i = 0; i<cantPalabras; i++){

        string palabra;
        cin >> palabra;

        clave c1 = clave(palabra);
        int* cantidad = cajonesAgrupados.recuperar(c1);

        if (cantidad == NULL) {
            cajonesAgrupados.insertar(c1, 1);
            bucketsUsados++;
            if (max == 0){
                max = 1;
            }
        } else {
            (*cantidad)++;
            if (max < *cantidad){
                max = *cantidad;
            }
        }

    }

    int cantConsultas;
    cin >> cantConsultas;

    for (int i = 0; i < cantConsultas; i++) {
        string palabra;
        cin >> palabra;

        clave c1(palabra);
        int* cantidad = cajonesAgrupados.recuperar(c1);

        if (cantidad == NULL) {
            cout << 0 << '\n';
        } else {
            cout << *cantidad << '\n';
        }
    }

    cout << bucketsUsados << " " << max << '\n';

    return 0;
}