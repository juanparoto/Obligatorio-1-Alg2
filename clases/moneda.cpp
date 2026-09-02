class moneda{
    private:
        long numCatalogo;

    public:
        long getNumCat(){
            return this->numCatalogo;
        }

        void setNumCat(long num){
            this->numCatalogo = num;
        }

        moneda(long num){
            numCatalogo = num;
        }

        bool operator == (moneda m2){
            return this->numCatalogo == m2.numCatalogo;
        }

        bool operator > (moneda m2){
            if(this->numCatalogo > m2.numCatalogo){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator < (moneda m2){
            if(this->numCatalogo < m2.numCatalogo){
                return true;
            }
            else{
                return false;
            }
        }
};
