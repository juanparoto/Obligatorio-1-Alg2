class arista{
    private:
        long salida;
        long destino;
        long peso;

    public:
        long getPeso(){
            return this->peso;
        }

        long getDestino(){
            return this->destino;
        }

        long getSalida(){
            return this->salida;
        }

        arista(long sal, long des, long pe){
            salida = sal;
            destino = des;
            peso = pe;
        }

        arista(){
            salida = 0;
            destino = 0;
            peso = 0;
        }

};