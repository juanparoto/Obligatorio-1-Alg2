class MFSet{
    private:

    int *padres;
    int *alturas;
    int tamaño;

    public:

    MFSet(int n){

        this->tamaño = n;
        this->alturas = new int[n+1];
        this->padres = new int[n+1];
        for(int i = 0; i<=n; i++){
            this->padres[i] = i;
            this->alturas[i] = 0;
        }
    }

    int encontrar(int x){
        if(this->padres[x] == x){
            return x;
        }
        this->padres[x] = encontrar(this->padres[x]);
        return this->padres[x];
    }

    void merge(int x, int y){
        int xRoot = encontrar(x);
        int yRoot = encontrar(y);
            
        if(xRoot == yRoot){
            return;
        }
        if (this->alturas[xRoot] < this->alturas[yRoot]) {
            this->padres[xRoot] = yRoot;

        } else if (this->alturas[xRoot] > this->alturas[yRoot]) {

            this->padres[yRoot] = xRoot;

        } else {

            this->padres[yRoot] = xRoot;
            this->alturas[xRoot]++;

        } 
    }

    ~MFSet() {
        delete[] padres;
        delete[] alturas;
    }
};