template<typename T, typename K>
class HashAbierto {
    
    private:
    struct Nodo {
        K clave;
        V valor;
        Nodo* sig;
        Nodo(K nuevaClave, V nuevoValor){
            clave = nuevaClave;
            valor = nuevoValor;
            sig = NULL;
        }
    };
    Nodo** tabla;

    int cantBuckets;
    int (*funcionDeHash)(K);
    bool (*sonIguales)(K, K);

    int obtenerIndice(K clave){
        return funcionDeHash(clave) % cantBuckets;
    }

    public:
    HashAbierto(int nuevaCantBuckets, int (*funcionDeHashParam)(K), bool (*sonIgualesParam)(K, K)) {
        tabla = new Nodo*[nuevacantBuckets]();
        cantBuckets = nuevaCantBuckets;
        funcionDeHash = funcionDeHashParam;
        sonIguales = sonIgualesParam; 
    }
    ~HashAbierto() {
        for (int i = 0; i < cantBuckets; i++){
            if (tabla[i]){
                delete tabla[i];
                tabla[i] = NULL;
            }
        }
        delete[] tabla;
        tabla = NULL;
    }
    void insertar(K clave, V valor){
        int indice = obtenerIndice(clave);
        Nodo* aux = tabla[indice];
        while (aux != NULL && aux->clave != clave){
            aux = aux->sig;
        }
        if (aux != NULL){
            aux->valor = valor;
        }
        else {
            Nodo* nuevo = new nodo(clave, valor);
            nuevo->sig = tabla[indice];
            tabla[indice] = nuevo;
        }
    }
    void eliminar(K clave){
        int indice = obtenerIndice(clave);
        Nodo* aux = tabla[indice];
        Nodo* ant = NULL;
        while (aux != NULL && aux->clave != clave){
            ant = aux;
            aux = aux->sig;
        }
        if (aux == NULL){
            return;
        }
        if (ant == NULL){
            Nodo* borrar = aux;
            tabla[indice] = aux->sig;
            delete borrar;
            return;
        }
        Nodo* borrar = aux;
        ant->sig = aux->sig;
        delete borrar;
    }
    V* recuperar(K clave){
        int indice = obtenerIndice(clave);
        Nodo* aux = tabla[indice];
        while (aux != NULL && aux->clave != clave){
            aux = aux->sig;
        }
        if (aux == NULL){
            return NULL;
        }
        return aux->valor;
    }
    bool existe(K clave){
        int indice = obtenerIndice(clave);
        Nodo* aux = tabla[indice];
        while (aux != NULL && aux->clave != clave){
            aux = aux->sig;
        }
        if (aux == NULL){
            return false;
        }
        return true;
    }
};