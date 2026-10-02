#include <iostream>
#include <cassert>
class GrafoLista{

    public:

    struct nodoLista{
        int origen;
        int destino;
        int peso;
        nodoLista* sig;

        nodoLista(int unOrigen, int unDestino, int unPeso, nodoLista* unSig = NULL){
            this->origen = unOrigen;
            this->destino = unDestino;
            this->peso = unPeso;
            this->sig = unSig;
        }
        
    };

    private:

    bool dirigido;
    bool ponderado;
    int cantVertices;
    nodoLista** vertices;

    public:

    GrafoLista(bool esDirigido, bool esPonderado, int cantVertices){
        this->dirigido = esDirigido;
        this->ponderado = esPonderado;
        this->cantVertices = cantVertices;
        this->vertices = new nodoLista*[cantVertices + 1];
    
        for(int i = 0; i<= cantVertices; i++){
            vertices[i] = NULL;
        }
    }

    void agregarArista(int unOrigen, int unDestino, int unPeso = 1){
        assert(ponderado || unPeso == 1);
        nodoLista* nuevoNodo = new nodoLista(unOrigen, unDestino, unPeso);
        nuevoNodo->sig = vertices[unOrigen];
        vertices[unOrigen] = nuevoNodo;

        if(!dirigido){
            nodoLista* nuevoNodoInverso = new nodoLista(unDestino, unOrigen, unPeso);
            nuevoNodoInverso->sig = vertices[unDestino];
            vertices[unDestino] = nuevoNodoInverso;
        }
    }

    nodoLista* adyacentes(int vertice){
        return vertices[vertice];
    }

    int cantidadVertices(){
        return this->cantVertices;
    }
};