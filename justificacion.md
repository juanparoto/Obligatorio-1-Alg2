# Justificación de órdenes — Obligatorio 1

## Ejercicio 1

Para este ejercicio utilizamos dos AVL, donde uno lo instanciamos para los objetos de la clase moneda, y otro para los objetos pintura. Si K es la cantidad de piezas registradas en la colección y R la cantidad de piezas reportadas por una consulta.

BUSCAR y ALTA: Como recorren un único camino desde la raiz, tienen cómo orden O(log K) peor caso. Siendo O(log K) la altura del árbol, realizar rotaciones cuesta O(1)

RANGO: Usamos un recorrido in-order y podamos ramas innecesarias comparando la clave del nodo actual con los extremos. Recorre el subárbol izquierdo solamente si la clave actual es mayor que el extremo inferior, y el derecho solo si es menor que el extremo superior. Los nodos visitados fuera del intervalo quedan en los caminos hacia sus extremos, con costo O(log K), y los R nodos reportados agregan O(R). El costo total es O(log K + R) en el peor caso y las piezas se imprimen ordenadas.


## Ejercicio 2

Para este ejercicio utilizamos una tabla de hash abierta. La clave de cada cajón es un array de 26 contadores que registra cuantas veces aparece cada letra. Construir esta clave conlleva O(L) siendo L el largo de la palabra.

Calcular el hash también cuesta O(L) ya que reconstruimos las letras en órden alfabético a partir de los contadores. Comparar las dos claves cuesta O(26) = O(1).

Para calcular el tamaño de la tabla sabiendo que como máximo hay N cajones, lo que hicimos fue utilizar la formula del factor de carga para despejar el tamaño necesario para obtener un factor de carga de 0.6. Registrar una palabra y responder una consulta cuestan O(L) promedio, incluyendo la construcción de la clave y el cálculo del hash.

Iniciar la tabla cuesta O(N), y el procesamiento completo es lineal, en promedio, respecto del tamaño total de la entrada.

Cómo en cada cajon guardamos un contador, registrar otra palabra en el mismo cajón solo incrementa ese contador. Además, durante el registro mantenemos actualizadas la cantidad de cajones distintos y la cantidad de palabras del cajón más grande, con O(1) extra por palabra. Así, obtener la última línea cuesta O(1) en el peor caso.


## Ejercicio 3
En este ejercicio usamos un min-heap binario. Insertar y extraer el mínimo cuestan O(Log N) en el peor caso, ya que flotar y hundir recorren a lo sumo la altura del heap.

Cargar los N datos, cuesta O(N Log N). Despues se hacen N-1 consolidaciones cada una con costo O(Log N). Por lo tanto el tiempo total es O(N Log N) peor caso.

El heap almacena como máximo N elementos y las demás variables ocupan espacio constante, por lo que el orden espacial es O(N).

## Ejercicio 4
Para este ejercicio representamos el grafo mediante listas de adyacencia, utilizando ordenamiento topológico (Algoritmo de Kahn), manteniendo los módulos listos en un min-heap binario.

Construir el grafo y calcular los grados de entrada cuesta O(V + A). En el procesamiento, cada dependencia se recorre máximo una vez, con costo O(A). Cada módulo ingresa al heap cuando su grado de entrada llega a 0 y se extrae como máximo una vez. Como cada inserción y extracción cuesta O(log V), el total sobre es O(V log V).

El tiempo total es O((V + A + V) log V), que simplificado queda O((V + A) log V) peor caso. 

Las listas de adyacencia ocupan O(V + A), mientras que el heap y los arreglos auxiliares ocupan O(V). Por lo tanto, el orden espacial es O(V + A).

## Ejercicio 5

Utilizamos Kruskal con el TAD MFSet

Ordenamos los E senderos por costo mediante un min-heap binario: realizamos E inserciones y E extracciones, cada una de costo O(log E) en el peor caso. Por lo tanto, el ordenamiento cuesta O(E log E).

Luego examinamos como máximo E senderos. Para cada uno consultamos los representantes de sus extremos y, si pertenecen a conjuntos distintos, realizamos una unión. La unión por altura mantiene los caminos con longitud O(log V), y la compresión de caminos los acorta en búsquedas posteriores. Así, cada búsqueda o unión cuesta como máximo O(log V), y este proceso cuesta O(E log V).

Inicializar los conjuntos cuesta O(V). Antes verificamos si E < V − 1 y, en ese caso, devolvemos imposible. Si continuamos, se cumple V ≤ E + 1, por lo que la inicialización queda acotada por O(E) y el procesamiento por O(E log E). Sumado al ordenamiento, el tiempo total es O(E log E) en el peor caso.

El heap y el arreglo de senderos ocupan O(E), y los arreglos de padres y alturas ocupan O(V). Por lo tanto, el orden espacial es O(V + E).
