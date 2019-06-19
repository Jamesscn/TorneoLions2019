# Descripción

Dado un set de números, quieres determinar cuántos números son mayores a cada valor.

# Entrada

Un número **N**, el número de valores en el arreglo, seguido por **N** valores $i_n$, el valor de cada elemento del arreglo

# Salida

**N** líneas con los valores correspondientes a cuántos números mayores hay a partir del elemento en ese lugar

# Ejemplo

||input
6
7 2 4 3 5 1
||output
0
4
2
3
1
5
||end

No hay números mayores a 7 porque es el más grande

Hay 4 valores {3, 4, 5 y 7} mayores a 2

Hay 2 valores {5 y 7} mayores a 4

Hay 3 valores {4, 5 y 7} mayores a 3

Hay 1 valor {7} mayor a 5

Hay 5 valores {2, 3, 4, 5 y 7} mayores a 1

# Límites

$1 \le N \le 1000$

$0 \le i_n \le 1000$
