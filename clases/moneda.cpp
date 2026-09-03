class moneda{
    private:
        long numCatalogo;

    public:
        long getKey(){
            return this->numCatalogo;
        }

        moneda(long num){
            numCatalogo = num;
        }

};
