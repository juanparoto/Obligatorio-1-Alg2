#include <iostream>
#include <string>
#include <cstring>
#include "../funciones/enteros.cpp"
using namespace std;

template<typename T>
struct NodoAVL{
    T dato;
    int h;
    NodoAVL<T> * izq;
    NodoAVL<T> * der;

    NodoAVL(T elem) : dato(elem) {
    h = 1;
    izq = der = NULL;
}
};

template<typename T>
class AVL {
    private:
        NodoAVL<T>* raiz;

        int getAltura(NodoAVL<T>* nodo){
            if(!nodo){
                return 0;
            }
            return nodo->h;
        }

        int getBalance(NodoAVL<T>* nodo){
            if(!nodo){
                return 0;
            }
            return getAltura(nodo->der) - getAltura(nodo->izq);
        }

        NodoAVL<T>* rotacionDerecha(NodoAVL<T>* nodo){
            NodoAVL<T>* A = nodo->izq;
            NodoAVL<T>* B = nodo;
            NodoAVL<T>* T2 = A->der; 

            B->izq = T2;
            A->der = B;

            B->h = 1 + max(getAltura(B->izq), getAltura(B->der));
            A->h = 1 + max(getAltura(A->izq), getAltura(A->der));

            return A;
        }

        NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* nodo) {
            NodoAVL<T>* A = nodo->der;
            NodoAVL<T>* B = nodo;
            NodoAVL<T>* T2 = A->izq;

            B->der = T2;
            A->izq = B;

            B->h = 1 + max(getAltura(B->izq), getAltura(B->der));
            A->h = 1 + max(getAltura(A->izq), getAltura(A->der));

            return A;
        }

        NodoAVL<T>* insertarRec(NodoAVL<T>* r, T elem){

            if(!r){
                return new NodoAVL<T>(elem);
            }
            else if(elem < r->dato){
                r->izq = insertarRec(r->izq, elem);
            }
            else if(elem > r->dato){
                r->der = insertarRec(r->der, elem);
            }
            else{
                return r;
            }

            r->h = 1 + max(getAltura(r->izq),getAltura(r->der));

            int balance = getBalance(r);

            if(balance > 1 && elem > r->der->dato){
                return rotacionIzquierda(r);
            }

            if(balance > 1 && elem < r->der->dato){
                r->der = rotacionDerecha(r->der);
                return rotacionIzquierda(r);
            }

            if(balance < -1 && elem < r->izq->dato){
                return rotacionDerecha(r);
            }

            if(balance < -1 && elem > r->izq->dato){
                r->izq = rotacionIzquierda(r->izq);
                return rotacionDerecha(r);
            }

            return r;
        }

    public:

        AVL(){
            raiz = NULL;
        }

        void insertar(T elem){
            raiz = insertarRec(raiz, elem);
        }
        
};