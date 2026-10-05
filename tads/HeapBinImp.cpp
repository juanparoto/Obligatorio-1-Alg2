#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include "../funciones/enteros.cpp"
using namespace std;
// Basado en la implementación vista en práctico.
template <typename T>
class heapBinario{
    T* heap;
    int ultimoOcupado;
    int capacidad;
    bool (*comparar)(T, T);

    private:

        int padre(int posicion){
            return posicion / 2;
        }

        int hijoIzq(int posicion){
            return posicion * 2;
        }

        int hijoDer(int posicion){
            return (posicion * 2) + 1;
        }

        void flotar(int posicion){
            if (posicion == 1) {
                return;
            }
            int posicionPadre = padre(posicion);
            if (comparar(heap[posicion], heap[posicionPadre])){
                swap(posicion, posicionPadre);
                flotar(posicionPadre);
            }
        }

        void hundir(int posicion){
            int posicionHijoIzq = hijoIzq(posicion);
            if (posicionHijoIzq > ultimoOcupado){
                return;
            }
            int posicionMax = posicionHijoIzq;
            int posicionHijoDer = hijoDer(posicion);
            if (posicionHijoDer <= ultimoOcupado && comparar(heap[posicionHijoDer], heap[posicionHijoIzq])){
                posicionMax = posicionHijoDer;
            }
            if (comparar(heap[posicionMax], heap[posicion])){
                swap(posicionMax, posicion);
                hundir(posicionMax);
            }
        }

        void swap(int i, int j){
            T aux = heap[i];
            heap[i] = heap[j];
            heap[j] = aux;
        }
    
    public:

    heapBinario(int capacidad, bool (*comparar)(T, T)) : ultimoOcupado(0), capacidad(capacidad){
        this->heap = new T[capacidad + 1];
        this->comparar = comparar;
    }

    ~heapBinario(){
        delete[] heap;
    }

    void insertar(T insertado){
        if(ultimoOcupado == capacidad){
            cout << "El heap esta lleno" << endl;
            return;
        }
        heap[++ultimoOcupado] = insertado;
        flotar(ultimoOcupado);
    }

    T eliminarTope(){
        if(estaVacio()){
            cout << "El Heap esta vacio" << endl;
            return T();
        }
        T tope = heap[1];
        swap(1, ultimoOcupado);
        ultimoOcupado--;
        hundir(1);
        return tope;
    }

    T peek(){
        if(estaVacio()){
            cout << "El heap no tiene cima" << endl;
            return T();
        }
        return heap[1];
    }

    bool estaVacio(){
        return ultimoOcupado == 0;
    }

    int elementos(){
        if(estaVacio()){
            cout << "El heap no tiene elementos" << endl;
            return T();
        }
        return ultimoOcupado;
    }

};