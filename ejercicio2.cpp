#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HashAbiertoImp.cpp"

#include "clases/clave.cpp"

using namespace std;


int funcionHash(clave c1){
    int retorno = 0;
    string palabra = c1.getPalabra();
    for(char letra : palabra){
        retorno += letra;
    }
    return retorno;
}

bool sonIguales(clave c1, clave c2){
    return c1 == c2;
}

int main() {

    int cantPalabras;
    cin >> cantPalabras;

    HashAbierto<clave, int> cajonesAgrupados(cantPalabras, funcionHash, sonIguales);

    for(int i = 0; i<cantPalabras; i++){

        string palabra;
        cin >> palabra;

        clave c1 = clave(palabra);
        int* cantidad = cajonesAgrupados.recuperar(c1);

        if (cantidad == NULL) {
            cajonesAgrupados.insertar(c1, 1);
        } else {
            (*cantidad)++;
        }

    }

    return 0;
}