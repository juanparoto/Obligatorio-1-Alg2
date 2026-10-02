#include "clases/arista.cpp"
#include "tads/HeapBinImp.cpp"
#include "tads/MFset.cpp"
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

bool compararPrioridad(arista a1, arista a2){
    return a1.getPeso() < a2.getPeso();
}

void heapSort(arista* &arr, heapBinario<arista> &h1){
    int indice = 0;

    while(!h1.estaVacio()){
        arista tope = h1.eliminarTope();
        arr[indice] = tope;
        indice++;
    }
}

int main()
{
    int refugiosV;
    int senderosE; 

    cin >> refugiosV >> senderosE;

    arista* senderosOrdenados = new arista[senderosE];
    heapBinario<arista> heapA(senderosE, compararPrioridad);

    for(int i = 0; i<senderosE; i++){
        
        int origen;
        int destino;
        int peso;

        cin >> origen >> destino >> peso;

        arista a1(origen, destino, peso);

        heapA.insertar(a1);
    }

    heapSort(senderosOrdenados, heapA);

    if (senderosE < refugiosV - 1) {
        cout << "imposible\n";
        delete[] senderosOrdenados;
        return 0;
    }

    MFSet conjuntos(refugiosV);

    long long costoTotal = 0;
    int aceptadas = 0;

    for (int i = 0; i < senderosE && aceptadas < refugiosV - 1; i++) {
        int origen = senderosOrdenados[i].getSalida();
        int destino = senderosOrdenados[i].getDestino();

        if (conjuntos.encontrar(origen) != conjuntos.encontrar(destino)) {
            conjuntos.merge(origen, destino);
            costoTotal += senderosOrdenados[i].getPeso();
            aceptadas++;
        }
    }

    if (aceptadas == refugiosV - 1) {
        cout << costoTotal << "\n";
    } else {
        cout << "imposible\n";
    }   

    delete[] senderosOrdenados;
    return 0;
    
}