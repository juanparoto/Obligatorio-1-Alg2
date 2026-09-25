#include <cassert>
#include <string>
#include <iostream>

using namespace std;

bool compararPrioridad(int a, int b){
    return a < b;
}

int main()
{
    int cantModulos;
    int cantDependencias;
    cin >> cantModulos >> cantDependencias;
    int* prioridad = new int[cantModulos];
    bool** adyacentes = new bool*[cantModulos]();
    for (int i = 0; i < cantModulos; i++){
        cin >> prioridad[i];
        adyacentes[i] = new bool[cantModulos]();
    }
    int * entradas = new int[cantModulos]();
    for (int i = 0; i < cantDependencias; i++){
        int origen;
        int destino;
        cin >> origen >> destino;
        adyacentes[origen - 1][destino - 1] = true;
        entradas[destino - 1]++;
    }
    return 0;
}