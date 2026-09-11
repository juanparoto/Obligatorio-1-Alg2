#include <cassert>
#include <string>
#include <iostream>
//INCLUIMOS LOS TAD QUE CREAMOS Y LAS CLASES
#include "tads/AvlImp.cpp"
#include "clases/moneda.cpp"
#include "clases/pintura.cpp"
using namespace std;

//FUNCIONES AUXILIARES
void agregarPintura(AVL<pintura,string>*& arbol, string titulo){
    pintura p1 = pintura(titulo);
    arbol->insertar(p1);
}

void agregarMoneda(AVL<moneda,long>*& arbol, long numero){
    moneda m1 = moneda(numero);
    arbol->insertar(m1);
}

string buscarMon(AVL<moneda,long>*& arbol, long numero){
    if(arbol->buscar(numero)){
        return "si";
    }
    else{
        return "no";
    }
}

bool chequeoSeguridadC(long num){
    if(num>1000000000000 || num < 1){
        cout << "Numero de catalogo invalido" << endl;
        return true;
    }
    else{
        return false;
    }
}

bool chequeoSeguridadP(string tit){

    if(tit.length() < 1 || tit.length() > 20){
        cout << "Titulo invalido" << endl;
        return true;
    }

    for(char caracter : tit){
        if(caracter == ' ' || (caracter >= 'A' && caracter <= 'Z')){
            cout << "El titulo no puede tener espacios y debe estar en minusculas" << endl;
            return true;
        }
    }

    return false;
}

string buscarPin(AVL<pintura,string>*& arbol, string tit){
    if(arbol->buscar(tit)){
        return "si";
    }
    else{
        return "no";
    }
}

void rangoMon(AVL<moneda,long>*& arbol, long desde, long hasta){
    arbol->rango(desde, hasta);
}

void rangoPin(AVL<pintura,string>*& arbol, string desde, string hasta){
    arbol->rango(desde, hasta);
}

//MAIN
int main()
{
    AVL<moneda,long>* aMonedas = new AVL<moneda,long>();
    AVL<pintura,string>* aPinturas = new AVL<pintura,string>();

    
    int cantOp;
    cin >> cantOp;

    if(cantOp > 200000 || cantOp < 1){
        cout << "La cantidad de operaciones debe estar entre 0 y 200000" << endl;
        return 1;
    }


    for(int i = 0; i < cantOp; i++){

        string operacion;
        string tipo;

        cin >> operacion >> tipo;

        if(operacion == "ALTA" && tipo == "M"){
            long numCat;
            cin >> numCat;

            if(chequeoSeguridadC(numCat)){
                return 1;
            }

            agregarMoneda(aMonedas, numCat);             
        }

        if(operacion == "ALTA" && tipo == "P"){
            string titulo;
            cin >> titulo;

            if(chequeoSeguridadP(titulo)){
                return 1;
            }

            agregarPintura(aPinturas, titulo);             
        }

        if(operacion == "BUSCAR" && tipo == "M"){
            long numCat;
            cin >> numCat;

            if(chequeoSeguridadC(numCat)){
                return 1;
            }

            string respuesta = buscarMon(aMonedas, numCat);
            cout << respuesta << endl;
        }

        if(operacion == "BUSCAR" && tipo == "P"){
            string tit;
            cin >> tit;

            if(chequeoSeguridadP(tit)){
                return 1;
            }

            string respuesta = buscarPin(aPinturas, tit);
            cout << respuesta << endl;
        }

        if (operacion == "RANGO" && tipo == "M"){
            long desde;
            long hasta;
            cin >> desde >> hasta;
            if(chequeoSeguridadC(desde)){
                return 1;
            }
            if(chequeoSeguridadC(hasta)){
                return 1;
            }
            rangoMon(aMonedas, desde, hasta);
        }

        if (operacion == "RANGO" && tipo == "P"){
            string desde;
            string hasta;
            cin >> desde >> hasta;

            if(chequeoSeguridadP(desde)){
                return 1;
            }
            if(chequeoSeguridadP(hasta)){
                return 1;
            }

            rangoPin(aPinturas, desde, hasta);
        }
    }
    return 0;
}



