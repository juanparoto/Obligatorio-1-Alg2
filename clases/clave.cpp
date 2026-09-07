#include <string>
using namespace std;

class clave {

private:
    int cantidades[26];

public:

    clave() {
        for (int i = 0; i < 26; i++) {
            cantidades[i] = 0;
        }
    }

    clave(string palabra) {
        for (int i = 0; i < 26; i++) {
            cantidades[i] = 0;
        }

        int largo = palabra.length();

        for (int i = 0; i < largo; i++) {
            int posicion = palabra[i] - 'a';
            cantidades[posicion]++;
        }
    }

    int* getClave(){
        return cantidades;
    }
    
   string getPalabra() {

        string palabra = "";

        for (int i = 0; i < 26; i++) {
            char letra = 'a' + i;

            for (int j = 0; j < cantidades[i]; j++) {
                palabra += letra;
            }
        }

        return palabra;
    }

    bool operator==(clave c1){
        for(int i = 0; i<26; i++){
            if(cantidades[i] != c1.cantidades[i]){
                return false;
            }
        }
        return true;
    }
};