#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class pintura{
    private:
        string titulo;
    public:
        string getKey(){
            return this->titulo;
        }

        pintura(string tit){
            titulo = tit;
        }


};