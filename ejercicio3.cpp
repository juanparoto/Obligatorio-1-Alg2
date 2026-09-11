#include <cassert>
#include <string>
#include <iostream>
#include "tads/HeapBinImp.cpp"

using namespace std;

bool compararCostos(long a, long b){
    return a < b;
}

int main()
{

    long cantArchivos;
    long costoTotal = 0;
    cin >> cantArchivos;

    if(cantArchivos < 2){
        cout << 0 << endl;
        return 0;
    }

    heapBinario<long> heap(cantArchivos, compararCostos);
    
    for(int i = 0; i<cantArchivos; i++){
        long costo;
        cin >> costo;
        heap.insertar(costo);
    }

    while(heap.elementos() != 1){
        long a1 = heap.eliminarTope();
        long a2 = heap.eliminarTope();
        long costoOperacion = a1 + a2;
        heap.insertar(costoOperacion);
        costoTotal += costoOperacion;
    }

    cout << costoTotal << endl;
    return 0;
}