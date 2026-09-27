class nodoH{
    private:
        int num;
        int prioridad;
        nodoH* sig;

    public:
        int getNum(){
            return this->num;
        }
        int getPrioridad(){
            return this->prioridad;
        }

        nodoH* getSig(){
            return this->sig;
        }

        void setSig(nodoH* sig){
            this->sig = sig;
        }

        nodoH(int num, int prioridad){
            this->num = num;
            this->prioridad = prioridad;
            this->sig = nullptr;
        }

};