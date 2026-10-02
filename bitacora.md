# Bitácora — Obligatorio 1

**Integrantes:** Juan Pablo Burone (Nº 347086), Nicolas Varela (_ _ _ _ 6 7)

## 2026-09-01 — Juan Pablo Burone
- Inicio: Creamos el repo, descargue el proyecto, hice clone git. Arrancamos la
implementacion del AVL siguiendo la clase de práctico, no compila.

## 2026-09-02 — Juan Pablo Burone
- Hoy terminé la implementación del AVL, ahora compila. Cree las clases moneda y pintura,
con los atributoss que considere necesarios, ademas implemente las operaciones **"=="**, **">"** 
y **"<"** en cada una. Avance con ejercicio1.cpp, creando la operacion Buscar, Alta y sus auxiliares. Falta implementar buscar en el AVL.

## 2026-09-03 - Nicolás Varela
- Implementé todo lo de buscar y rango del ejercicio 1.
Bug: Hay un bug en las funciones de rango, pero no es por lógica

## 2026-09-03 - Juan Pablo Burone
- Borre la función rango que tenia bugs, implemente en TAD AVL, que ahora el template recibe dos cosas, el objeto y el tipo de la llave, mostrado como K. Tuvimos tremendo error con git, se sobrescribieron los archivos, casi perdemos todo, usamos codex para que ejecturara los comandos de git y volviera el repo a su estado original.

## 2026-09-03 - Nicolás Varela
- Volví a programar la función rango, con los cambios que implementó Juan Pablo

## 2026-09-03 - Juan Pablo Burone
- Agregué todo tipo de defensa para casos borde, importé el repo de pruebas, le pedi a la IA que me hiciera un BLOQUE para poder correr las pruebas con un for, adjunto bloque:

```bash
for entrada in pruebas-oficiales/tests/ejercicio1/*.in.txt; do
    base="${entrada%.in.txt}"
    ./main < "$entrada" > miSalida.txt

    if diff -q "$base.out.txt" miSalida.txt > /dev/null; then
        echo "OK: $(basename "$base")"
    else
        echo "FALLA: $(basename "$base")"
    fi
done
|
```

- Todas las pruebas dieron OK, por hoy damos por terminado el ejercicio1.cpp

## 2026-06-05 - Nicolás Varela
- Arranqué el ejercicio 2
- Hice todo el tad del hash abierto

## 2026-09-06 - Juan Pablo Burone
- Arranqué con el main del ejercicio 2. Hice clase clave, y un poquito de main.

## 2026-09-07 - Nicolás Varela
- Terminé el main del ejercicio 2.

## 2026-09-08 - Juan Pablo Burone
- Agregué programacién defensiva a lo que Nico hizo ayer para que pasara todos los Test, teniamos un problema que era que la funcion de Hash nos dejaba todo en clsuters, entonces recurrimos a fuscar en un foro una funcion de hash abierto que reduciera las colisiones.

- Quedo pronto todo el ejercicio2, paso todas las pruebas, las corrimos con el siguiente script que nos dio Codex:

```bash
g++ -std=c++11 ejercicio2.cpp -o /tmp/ejercicio2 && (
    salida=$(mktemp)

    for entrada in pruebas-oficiales/tests/ejercicio2/*.in.txt; do
        esperado="${entrada%.in.txt}.out.txt"

        if /tmp/ejercicio2 < "$entrada" > "$salida" &&
           diff -q "$esperado" "$salida" > /dev/null; then
            echo "OK: $(basename "$entrada")"
        else
            echo "FALLA: $(basename "$entrada")"
        fi
    done

    rm "$salida"
)
```

## 2026-09-10 - Juan Pablo Burone
-Hoy literalmente hice TODO el ejercicio 3, desde la implementacion del heap, hasta la logica del main. Corri las pruebas con el siguiente comando que me dio Codex:

```bash
g++ -std=c++11 -O2 ejercicio3.cpp -o ejercicio3 && (
  set -o pipefail
  ok=0
  total=0
  for entrada in pruebas-oficiales/tests/ejercicio3/*.in.txt; do
    total=$((total + 1))
    if timeout 30s ./ejercicio3 < "$entrada" | diff --strip-trailing-cr "${entrada%.in.txt}.out.txt" - > /dev/null; then
      echo "OK: $(basename "$entrada")"
      ok=$((ok + 1))
    else
      echo "FALLO: $(basename "$entrada")"
    fi
  done
  echo "Resultado: $ok/$total pruebas correctas"
)
```

## 2026-09-11 - Nicolás Varela
- Hice el ejercicio 3 genérico, agregué la función comparar como atributo y todo lo que conlleva, despues creé la función compararGastos en el main
- Ademas agregué las funciones padre e hijos y cambié algunas variables

## 2026-09-11 - Juan Burone
- Cambie la función de hash

## 2026-09-25 - Nicolás Varela
- Arranqué el ejercicio 4 con el main, pero no está completo, lo terminaré cuando hayamos hecho los TADS correspondientes

## 2026-09-26 - Juan Pablo Burone
- Hice el TAD Grafo para que Nico pueda seguir con el ejercicio 4

## 2026-09-27 - Nicolás Varela
- Cree la clase nodoH y terminé el ejercicio 4

## 2026-09-27 - Juan Pablo Burone
- Fui a correr las pruebas del ejercicio 4, no paso nignuna, habian 4 bugs, los correji, y ahora pasó todas las pruebas, utilicé el siguiente script brindado por codex:

```bash
g++ -std=c++11 -Wall -Wextra ejercicio4.cpp -o ejercicio4 && (
    set -o pipefail
    ok=0
    total=0

    for entrada in pruebas-oficiales/tests/ejercicio4/*.in.txt; do
        esperado="${entrada%.in.txt}.out.txt"
        total=$((total + 1))

        if timeout 5s ./ejercicio4 < "$entrada" |
           diff --strip-trailing-cr "$esperado" - > /dev/null; then
            echo "OK: $(basename "$entrada")"
            ok=$((ok + 1))
        else
            echo "FALLÓ: $(basename "$entrada")"
        fi
    done

    echo "Resultado: $ok/$total pruebas correctas"
)
```

## 2026-10-01 - Juan Pablo Burone
- Hoy me hice todo el ejercicio 5, implemente el tad MFSet en base a lo que dimos en teorico, después de eso arranqué con el ejercicio, y ní si quiera fue necesario hacer un grafo, simplemente cree una clase arista, hice un array de aristas, los ordené usando un heap sort. Por último implemente Kruskal utilizando el MFSet.

- Corrí las pruebas y pasaron todas, use el siguiente script:

```bash
g++ -std=c++11 ejercicio5.cpp -o /tmp/ej5

for prueba in pruebas-oficiales/tests/ejercicio5/*.in.txt; do
    esperado=$(tr -d '\r' < "${prueba%.in.txt}.out.txt")
    obtenido=$(/tmp/ej5 < "$prueba")

    if [ "$obtenido" = "$esperado" ]; then
        echo "OK: $prueba"
    else
        echo "FALLO: $prueba"
    fi
done
```

### NO HICIMOS NADA EN CONJUNTO, SIEMPRE TRABAJAMOS EN SERIE.
