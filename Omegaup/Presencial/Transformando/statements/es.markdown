# Descripción

Tienes un conjunto de puntos ($X_i$, $Y_i$) y sabes que una sola transformación de traslación, rotación, escalamiento o reflección ha sido aplicada a estos puntos y ahora se encuentran en ($X_f$, $Y_f$). No sabes cual fue la tranformación aplicada pero sí conoces las ubicaciones de los puntos iniciales y los puntos finales, asi que tu tarea es determinar que tipo de transformación fue aplicada y en que manera.

Si la transformación fue una traslación entonces los puntos se desplazaron sin rotar a otro lugar, debes indicar cuanto movieron en X y cuanto movieron en Y. Por ejemplo: **traslacion 5 -8** indica que todos los puntos fueron movidos 5 unidades a la derecha y 8 unidades hacia abajo.

Si todos los puntos fueron rotados al rededor del centro del plano (0, 0), entonces de debe imprimir que fue una rotación y se debe indicar el ángulo de rotación en grados considerando un angulo positivo como una rotación en contra de las manecillas del reloj.
Por ejemplo: **rotacion 30** indica que los puntos fueron rotados 30 grados en sentido contrario a las manecillas del reloj.

Si todos los puntos fueron escalados desde el centro del plano (0, 0), entonces de debe imprimir que fue un escalamiento y se debe indicar el factor de escalamiento. Por ejemplo: **escalamiento 2** indica que el area entre todos los puntos expandió a dos veces su tamaño original.

Finalmente si todos los puntos fueron reflejados sobre el eje X o el eje Y se debe indicar este y sobre que eje fueron reflejados. Por ejemplo: **reflexion y** indica que todos los puntos fueron reflejados sobre el eje Y.

Todas los puntos tendran coordenadas enteros y todos los ángulos, desplazamientos y escalamientos deben ser redondeados al entero más cercano.

# Entrada

Un número **N** seguido por **N** líneas con dos enteros, la $X_i$ y la $Y_i$ de cada punto, luego otras **N** líneas con la $X_f$ y la $Y_f$ de cada punto.

# Salida

La transformación que fue aplicada. Solo podrá haber una transformación valida para cualquier caso.

# Ejemplos

||input
4
1 1
1 -1
-1 1
-1 -1
-2 -2
-2 2
2 -2
2 2
||output
escalamiento -2
||end

En este caso los puntos fueron escalados por un factor de -2, expandiendo la distancia de todos los puntos al origen por 2 e invirtiendo el signo de sus coordenadas (por el signo negativo).

||input
3
0 0
2 0
1 1
5 6
7 6
6 7
||output
traslacion 5 6
||end

En este caso todos los puntos fueron movidos 5 unidades a la derecha y 6 hacia arriba.

||input
4
6 3
4 5
0 -1
-2 3
6 -3
4 -5
0 1
-2 -3
||output
reflexion x
||end

Todos los puntos fueron reflejados sobre el eje X.

||input
3
-4 3
-5 2
-3 6
3 4
2 5
6 3
||output
rotacion -90
||end

Los puntos fueron rotados 90 grados a favor de las manecillas del reloj sobre el centro.

# Límites

$ 3 \le N \le 10,000 $

$ -10^9 \le X_i, X_f, Y_i, Y_f \le 10^9 $