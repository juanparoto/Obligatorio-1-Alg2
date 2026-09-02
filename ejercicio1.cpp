#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AvlImp.cpp"
#include "clases/moneda.cpp"
#include "clases/pintura.cpp"
using namespace std;

int main()
{
    AVL<moneda>* aMonedas = new AVL<moneda>();
    AVL<pintura>* aPinturas = new AVL<pintura>();

    int cantOp;
    cin >> cantOp;

    for(int i = 0; i < cantOp; i++){
        string operacion;
        string tipo;

        cin >> operacion >> tipo;

        if(operacion == "ALTA" && tipo == "M"){
            long numCat;
            cin >> numCat;
            void agregarMoneda(aMonedas, numCat);             
        }

        if(operacion == "ALTA" && tipo == "P"){
            string titulo;
            cin >> titulo;
            void agregarPintura(aPinturas, titulo);             
        }
    }
    return 0;
}

void agregarMoneda(AVL<moneda>*& arbol, long numero){

}

void agregarPintura(AVL<pintura>*& arbol, long numero){

}