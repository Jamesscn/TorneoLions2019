# Descripción

Las series de Fibonacci estan de moda, asi que quisieras saber cual es el índice más pequeño de un número $\lambda$ que tiene al menos **M** dígitos y pertenece a la serie de Fibonacci. Se debe de considerar que la serie empiece a partir del primer uno con índice 1: {1, 1, 2, 3, 5, 8, 13...}

# Entradas

Un número **N** de casos seguido por N líneas con **M**, el mínimo número de digitos.

# Salidas

El índice más pequeño donde $\lambda$ tiene al menos **M** dígitos.

# Ejemplo

||input
3
1
2
5
||output
1
7
21
||end

El primer caso pregunta por el primer índice con un número que tiene al menos un dígito, en este caso es 1 porque todos los números de la serie tienen al menos 1 digito.

El segundo caso pregunta por el primer índice con un número que tiene al menos dos dígitos, en este caso es 7 con $\lambda = 13$: {1, 1, 2, 3, 5, 8, 13}.

# Límites

$1 \le N \le 1000$

$1 \le M \le 1000$

$1 \le \lambda \le 10^{1001}$