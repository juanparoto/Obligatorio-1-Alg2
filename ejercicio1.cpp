#include <cassert>
#include <string>
#include <iostream>
#include <limits>
//INCLUIMOS LOS TAD QUE CREAMOS Y LAS CLASES
#include "tads/AvlImp.cpp"
#include "clases/moneda.cpp"
#include "clases/pintura.cpp"
using namespace std;

//FUNCIONES AUXILIARES
string buscarMon(AVL<moneda>*& arbol, long numero){
    if(arbol.buscar(numero)){
        return "si";
    }
    else{
        return "no";
    }
}

string buscarPin(AVL<pintura>*& arbol, string tit){
    if(arbol.buscar(tit)){
        return "si";
    }
    else{
        return "no";
    }
}

void agregarPintura(AVL<pintura>*& arbol, string titulo){
    pintura p1 = pintura(titulo);
    arbol->insertar(p1);
}

void agregarMoneda(AVL<moneda>*& arbol, long numero){
    moneda m1 = moneda(numero);
    arbol->insertar(m1);
}

//MAIN
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
            agregarMoneda(aMonedas, numCat);             
        }

        if(operacion == "ALTA" && tipo == "P"){
            string titulo;
            cin >> titulo;
            agregarPintura(aPinturas, titulo);             
        }

        if(operacion == "BUSCAR" && tipo == "M"){
            long numCat;
            cin >> numCat;
            string respuesta = buscarMon(aMonedas, numCat);
            cout << respuesta << endl;
        }

        if(operacion == "BUSCAR" && tipo == "P"){
            string tit;
            cin >> tit;
            string respuesta = buscarPin(aPinturas, tit);
            cout << respuesta << endl;
        }
    }
    return 0;
}



