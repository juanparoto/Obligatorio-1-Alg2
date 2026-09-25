# Bitácora — Obligatorio 1

**Integrantes:** Juan Pablo Burone (Nº 347086), Nicolas Varela (_ _ _ _ 6 7)

## 2026-09-01 — Juan Pablo Burone
- Inicio: Creamos el repo, descargue el proyecto, hice clone git. Arrancamos la
implementacion del Avl siguiendo la clase de práctico, no compila.

## 2026-09-02 — Juan Pablo Burone
- Hoy terminé la implementación del AVL, ahora compila. Cree las clases moneda y pintura,
con los atributoss que considere necesarios, ademas implemente las operaciones **"=="**, **">"** 
y **"<"** en cada una.
Avance con ejercicio1.cpp, creando la operacion Buscar, Alta y sus auxiliares. Falta implementar
buscar en el AVL.

## 2026-09-03 - Nicolás Varela
- Implemente todo lo de buscar y rango del ejercicio 1.
Bug: Hay un bug en las funciones de rango pero no es por logica

## 2026-09-03 - Juan Pablo Burone
- Borre la funcion rango que tenia bugs, implemente en TAD Avl, que ahora el template
recibe dos cosas, el objeto y el tipo de la llave, mostrado como K.
Tuvimos tremendo error con git, se sobrescribieron los archivos, casi perdemos todo, usamos LA IA CODEX, COMO AGENTE
para que ejecturara los comandos de git y volviera el repo a su estado original.

## 2026-09-03 - Nicolás Varela
- Volvi a programar la funcion rango, con los cambios que implemento Juan Pablo

## 2026-09-03 - Juan Pablo Burone
- Agrege todo tipo de defensa para casos borde, importe el repo de pruebas, le pedi a la IA que me hiciera un BLOQUE para poder correr
las pruebas con un for, adjunto bloque:

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
- Arranque el ejercicio 2
- Hice todo el tad del hash abierto

## 2026-09-06 - Juan Pablo Burone
- Arranque con el main del ejercicio 2. Hice clase clave, y un poquito de main.

## 2026-09-07 - Nicolás Varela
- Termine el main del ejercicio 2.

## 2026-09-08 - Juan Pablo Burone
- Agregue programacion defensiva a lo que nico hizo ayer para que pasara todos los Test, teniamos un problema que
era que la funcion de Hash nos dejaba todo en clsuters, entonces recurrimos a fuscar en un foro una funcion de hash abierto que
reduciera las colisiones:

Robert Sedgewick y Kevin Wayne. Algorithms, 4.ª edición, sección 3.4: Hash Tables.
Funcion elegida: hash = (R * hash + caracter) % M;
Como multiplicador elejimos 31. 
Para elejir el M, como la letra dice que el maximo a registrar son 100.000 palabras, que dividido por 0,6 daria 166.667 buckets, le pedimos a Codex que nos dijiera el proximo primo, para evitar colisiones hasta en el peor caso.

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
-Hoy literalmente hice TODO el ejercicio 3, desde la implementacion del heap, hasta la logica del main, la verad muy facil
subanle la dificultad, me llevo 1 hora REVENTANDO. Corri las pruebas con el siguiente comando que me dio Codex:

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
- Hice el ejercicio 3 generico, agregue la funcion comparar como atributo y todo lo que conlleva, despues cree la funcion compararGastos en el main
- Ademas agregue las funciones padre e hijos y cambie algunas variables

## 2026-09-11 - Juan Burone
- Cambie la funcion de hash

## 2026-09-25 - Nicolás Varela
- Arranque el ejercicio 4 con el main, pero no esta completo, lo terminare cuando hayamos hecho los tads

## AAAA-MM-DD — En conjunto
- Ejemplo: Implementamos ... Bug: ... Lo corregimos ...
- Pasan los casos de prueba 1 a 4 del ejercicio 1.
