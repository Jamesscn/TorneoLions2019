# Descripción

Los bits de tu computadora estan escapando, asi que tu ocupas crear un programa para calcule cuantos bits activados estan dentro de un rango de números

# Entradas

Un número **N**, seguido por **N** casos. Cada caso tiene dos enteros, un valor mínimo **A** (exclusivo) y un valor máximo **B** (inclusivo).

# Salidas

La suma del número de bits prendidos entre todos los números del rango **(A, B]**, es decir {A + 1, A + 2, A + 3 ... B}.

# Ejemplo

||input
4
24 25
0 3
6 6
100 200
||output
3
4
0
416
||end

Para el primer caso, se quiere saber cuantos bits activadoEls hay entre (24, 25] o simplemente el número de bits dentro del número 25. Como 25 es 11001, hay 3 bits que son unos asi que la respuesta es 3.

Para el segundo caso, se quiere saber cuantos bits hay entre (0, 3] o {1, 2, 3}. 1 tiene 1 bit, 2 tiene 1 bit y 3 tiene 2 bits. Al sumar estos valores, se obtiene 1 + 1 + 2 = 4.

# Límites

$1 \le N \le 1000$
$0 \le A \le B \le 1,000,000$