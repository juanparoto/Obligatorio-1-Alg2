#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class pintura{
    private:
        string titulo;
    public:
        string getTitulo(){
            return this->titulo;
        }

        void setTitulo(string tit){
            this->titulo = tit;
        }

        pintura(string tit){
            titulo = tit;
        }

        bool operator == (pintura p1){
            return this->titulo == p1.titulo;
        }

        bool operator > (pintura p1){
            return this->titulo > p1.titulo;
        }

        bool operator < (pintura p1){
            return this->titulo < p1.titulo;
        }

};