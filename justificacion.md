# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 2
- Usamos una tabla de hash abierta con encadenamiento. Cada cajon distinto ocupa
  un nodo con un contador; las palabras repetidas o anagramas incrementan ese
  contador, sin agregar nodos a la lista.
- Elegimos un factor de carga objetivo de 0,6. Si N es la cantidad de palabras
  registradas, hay a lo sumo N cajones distintos. Dimensionamos la tabla con
  M = ceil(N / 0,6) buckets. Durante todo el registro, si D es la cantidad de
  cajones distintos, alfa = D / M <= N / M <= 0,6. No se necesita rehash y la
  tabla ocupa O(N) espacio. Si las palabras comparten cajon, alfa sera menor.
- Para N <= 100000, M <= 166667. Usamos 166667, que es primo, como modulo
  intermedio del hash para que su rango cubra todos los buckets posibles. Las
  colisiones se resuelven mediante las listas y la comparacion de las claves.
- Construir la clave contando letras cuesta O(L). Reconstruir su palabra
  ordenada cuesta O(L + 26), y calcular el hash cuesta O(L). Comparar dos claves
  cuesta O(26). Como el alfabeto es constante y, bajo una dispersion adecuada,
  las listas tienen longitud constante en promedio, registrar y consultar
  cuestan O(L) promedio. El costo no depende de cuantas palabras comparten cajon.
- La cantidad de cajones y el mayor contador se actualizan con O(1) extra por
  palabra registrada. Obtener la ultima linea cuesta O(1) en el peor caso.
  El tiempo total es lineal promedio respecto del tamano de la entrada y el
  espacio total es O(N).
- Justificacion redactada con ayuda de Codex a partir de la implementacion y
  del factor de carga objetivo elegido por el equipo.

## Ejercicio 3
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 4
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5
- Sin restricciones de órdenes. / Justificación: ...

