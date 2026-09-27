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
    nodoH* noListos = nullptr;
    for (int i = 0; i < cantModulos; i++){
        int prioridad;
        cin >> prioridad;
        nodoH* nuevo = new nodoH(i+1, prioridad);
        nuevo->setSig(noListos);
        noListos = nuevo;
    }
    int * entradas = new int[cantModulos]();
    for (int i = 0; i < cantDependencias; i++){
        int origen;
        int destino;
        cin >> origen >> destino;
        grafo.agregarArista(origen, destino, 1);
        entradas[destino - 1]++;
    }
    heapBinario<nodoH*> heap(cantModulos, compararPrioridad);
    while (noListos != nullptr){
        nodoH* aux = noListos;
        nodoH* anterior = nullptr;
        while (aux != nullptr){
            if (entradas[aux->getNum()] == 0){
                heap.insertar(aux);
                if (anterior == nullptr){
                    noListos = aux->getSig();
                }
                else {
                    anterior->setSig(aux->getSig());
                }
            }
            anterior = aux;
            aux = aux->getSig();
        }
        if (heap.estaVacio()){
            return 1;
        }
        nodoH* extraido = heap.eliminarTope();
        cout << extraido->getNum() << '\n';
        GrafoLista::nodoLista* adyacentes = grafo.adyacentes(extraido->getNum());
        while (adyacentes != nullptr){
            entradas[adyacentes->origen]--;
            adyacentes->sig;
        }
    }

    return 0;
}