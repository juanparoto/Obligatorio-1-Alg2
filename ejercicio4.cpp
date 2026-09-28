#include <cassert>
#include <string>
#include <iostream>
#include "tads/GrafoImp.cpp"
#include "tads/HeapBinImp.cpp"
#include "clases/nodoH.cpp"

using namespace std;

bool compararPrioridad(nodoH* a, nodoH* b){
    if (a->getPrioridad() < b->getPrioridad()){
        return true;
    }
    else {
        if (b->getPrioridad() < a->getPrioridad()){
            return false;
        }
        else {
            return a->getNum() < b->getNum();
        }
    }
}

int main()
{
    int cantModulos;
    int cantDependencias;
    cin >> cantModulos >> cantDependencias;

    GrafoLista grafo(true, false, cantModulos);

    
    nodoH** modulos = new nodoH*[cantModulos + 1];
    int* entradas = new int[cantModulos + 1]();

    for (int i = 1; i <= cantModulos; i++) {
        int prioridad;
        cin >> prioridad;
        modulos[i] = new nodoH(i, prioridad);
    }

    for (int i = 0; i < cantDependencias; i++) {
        int origen;
        int destino;
        cin >> origen >> destino;

        grafo.agregarArista(origen, destino, 1);
        entradas[destino]++;
    }

    heapBinario<nodoH*> heap(cantModulos, compararPrioridad);

    
    for (int i = 1; i <= cantModulos; i++) {
        if (entradas[i] == 0) {
            heap.insertar(modulos[i]);
        }
    }

    
    int* orden = new int[cantModulos];
    int compilados = 0;

    while (!heap.estaVacio()) {
        nodoH* actual = heap.eliminarTope();
        int numero = actual->getNum();

        orden[compilados] = numero;
        compilados++;

        GrafoLista::nodoLista* adyacente = grafo.adyacentes(numero);

        while (adyacente != nullptr) {
            int destino = adyacente->destino;

            entradas[destino]--;

            if (entradas[destino] == 0) {
                heap.insertar(modulos[destino]);
            }

            adyacente = adyacente->sig;
        }
    }

    if (compilados == cantModulos) {
        for (int i = 0; i < compilados; i++) {
            cout << orden[i] << '\n';
        }
    }
    else {
        cout << "imposible\n";
    }

    for (int i = 1; i <= cantModulos; i++) {
        delete modulos[i];
    }

    delete[] modulos;
    delete[] entradas;
    delete[] orden;

    return 0;
}