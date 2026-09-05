#include <iostream>
#include <string>
#include <cstring>
#include "../funciones/enteros.cpp"
using namespace std;

template<typename T,typename K>
struct NodoAVL{
    T dato;
    K key;
    int h;
    NodoAVL<T,K> * izq;
    NodoAVL<T,K> * der;

    NodoAVL(T elem, K llave) : dato(elem) , key(llave){
    h = 1;
    izq = der = NULL;
    }
};

template<typename T, typename K>
class AVL {
    private:
        NodoAVL<T,K>* raiz;

        int getAltura(NodoAVL<T,K>* nodo){
            if(!nodo){
                return 0;
            }
            return nodo->h;
        }

        int getBalance(NodoAVL<T,K>* nodo){
            if(!nodo){
                return 0;
            }
            return getAltura(nodo->der) - getAltura(nodo->izq);
        }

        NodoAVL<T,K>* rotacionDerecha(NodoAVL<T,K>* nodo){
            NodoAVL<T,K>* A = nodo->izq;
            NodoAVL<T,K>* B = nodo;
            NodoAVL<T,K>* T2 = A->der; 

            B->izq = T2;
            A->der = B;

            B->h = 1 + max(getAltura(B->izq), getAltura(B->der));
            A->h = 1 + max(getAltura(A->izq), getAltura(A->der));

            return A;
        }

        NodoAVL<T,K>* rotacionIzquierda(NodoAVL<T,K>* nodo) {
            NodoAVL<T,K>* A = nodo->der;
            NodoAVL<T,K>* B = nodo;
            NodoAVL<T,K>* T2 = A->izq;

            B->der = T2;
            A->izq = B;

            B->h = 1 + max(getAltura(B->izq), getAltura(B->der));
            A->h = 1 + max(getAltura(A->izq), getAltura(A->der));

            return A;
        }

        NodoAVL<T,K>* insertarRec(NodoAVL<T,K>* r, T elem, K key){

            if(!r){
                return new NodoAVL<T,K>(elem,key);
            }
            else if(key < r->key){
                r->izq = insertarRec(r->izq, elem, key);
            }
            else if(key > r->key){
                r->der = insertarRec(r->der, elem, key);
            }
            else{
                return r;
            }

            r->h = 1 + max(getAltura(r->izq),getAltura(r->der));

            int balance = getBalance(r);

            if(balance > 1 && key > r->der->key){
                return rotacionIzquierda(r);
            }

            if(balance > 1 && key < r->der->key){
                r->der = rotacionDerecha(r->der);
                return rotacionIzquierda(r);
            }

            if(balance < -1 && key < r->izq->key){
                return rotacionDerecha(r);
            }

            if(balance < -1 && key > r->izq->key){
                r->izq = rotacionIzquierda(r->izq);
                return rotacionDerecha(r);
            }

            return r;
        }

        bool buscarRec(NodoAVL<T, K>* r, K key) {
            if (!r) {
                return false;
            }
            if (key == r->key) {
                return true;
            }
            if (key < r->key) {
                return buscarRec(r->izq, key);
            }
            return buscarRec(r->der, key);
        }

        void rangoRec(NodoAVL<T, K>* r, K desde, K hasta){
            if (r == NULL){
                return;
            }

            if (r->key > desde){
                rangoRec(r->izq, desde, hasta);
            }

            if (r->key >= desde && r->key <= hasta){
                cout << r->key << endl;
            }

            if (r->key < hasta){
                rangoRec(r->der, desde, hasta);
            }
        }

    public:

        AVL(){
            raiz = NULL;
        }
        void insertar(T elem){
            raiz = insertarRec(raiz, elem, elem.getKey());
        }

        bool buscar(K key){
            return buscarRec(raiz, key);
        }

        void rango(K desde, K hasta){
            rangoRec(raiz, desde, hasta);
        }
};

template<typename T, typename K>
class HashAbierto {
    private:
    struct Nodo {
        K clave;
        V valor;
        Nodo* sig;
        Nodo(K nuevaClave, V nuevoValor){
            clave = nuevaClave;
            valor = nuevoValor;
            sig = NULL;
        }
    };
    Nodo** tabla;
    int cantBuckets;
    int (*funcionDeHash)(K);
    bool (*sonIguales)(K, K);

    int obtenerIndice(K clave){
        return funcionDeHash(clave) % cantBuckets;
    }

    public:
    HashAbierto(int nuevaCantBuckets, int (*funcionDeHashParam)(K), bool (*sonIgualesParam)(K, K)) {
        tabla = new Nodo*[nuevacantBuckets]();
        cantBuckets = nuevaCantBuckets;
        funcionDeHash = funcionDeHashParam;
        sonIguales = sonIgualesParam; 
    }
    ~HashAbierto() {
        for (int i = 0; i < cantBuckets; i++){
            if (tabla[i]){
                delete tabla[i];
                tabla[i] = NULL;
            }
        }
        delete[] tabla;
        tabla = NULL;
    }
    void insertar(K clave, V valor){
        int indice = obtenerIndice(clave);
        Nodo* aux = tabla[indice];
        while (aux != NULL && aux->clave != clave){
            aux = aux->sig;
        }
        if (aux != NULL){
            aux->valor = valor;
        }
        else {
            Nodo* nuevo = new nodo(clave, valor);
            nuevo->sig = tabla[indice];
            tabla[indice] = nuevo;
        }
    }
    void eliminar(K clave){
        int indice = obtenerIndice(clave);
        Nodo* aux = tabla[indice];
        Nodo* ant = NULL;
        while (aux != NULL && aux->clave != clave){
            ant = aux;
            aux = aux->sig;
        }
        if (aux == NULL){
            return;
        }
        if (ant == NULL){
            Nodo* borrar = aux;
            tabla[indice] = aux->sig;
            delete borrar;
            return;
        }
        Nodo* borrar = aux;
        ant->sig = aux->sig;
        delete borrar;
    }
    V* recuperar(K clave){
        int indice = obtenerIndice(clave);
        Nodo* aux = tabla[indice];
        while (aux != NULL && aux->clave != clave){
            aux = aux->sig;
        }
        if (aux == NULL){
            return NULL;
        }
        return aux->valor;
    }
    bool existe(K clave){
        int indice = obtenerIndice(clave);
        Nodo* aux = tabla[indice];
        while (aux != NULL && aux->clave != clave){
            aux = aux->sig;
        }
        if (aux == NULL){
            return false;
        }
        return true;
    }
};