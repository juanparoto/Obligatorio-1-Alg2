#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include "../funciones/enteros.cpp"
using namespace std;

template <typename T>
class heapBinario{
    T* heap;
    int cantOcupados;
    int capacidad;

    private:

        void floto(int posicion){
            while(posicion > 1 && heap[posicion/2] > heap[posicion]){
                swap(posicion, posicion/2);
                posicion = posicion/2;
            }
        }

        void hundo(int posicion){
            while(2*posicion <= cantOcupados){
                int j = 2*posicion;
                if (j < cantOcupados && heap[j] > heap[j + 1]) j++;
                if (heap[posicion] <= heap[j]) break;
                swap(posicion, j);
                posicion = j;
            }
        }

        void swap(int i, int j){
            T aux = heap[i];
            heap[i] = heap[j];
            heap[j] = aux;
        }
    
    public:

    heapBinario(int capacidad) : cantOcupados(0), capacidad(capacidad){
        heap = new T[capacidad + 1];
    }

    ~heapBinario(){
        delete[] heap;
    }

    void insertar(T insertado){
        if(cantOcupados == capacidad){
            cout << "El heap esta lleno" << endl;
            return;
        }
        cantOcupados++;
        heap[cantOcupados] = insertado;
        floto(cantOcupados);
    }

    T eliminarMin(){
        if(estaVacio()){
            cout << "El Heap esta vacio" << endl;
            return T();
        }
        T min = heap[1];
        swap(1,cantOcupados);
        cantOcupados--;
        hundo(1);
        return min;
    }

    T peek(){
        if(estaVacio()){
            cout << "El heap no tiene cima" << endl;
            return T();
        }
        return heap[1];
    }

    bool estaVacio(){
        return cantOcupados == 0;
    }

    int elementos(){
        if(estaVacio()){
            cout << "El heap no tiene elementos" << endl;
            return T();
        }
        return cantOcupados;
    }

};