# Descripción

Uno de tus amigos quiere hacer una página web donde distintos usuarios pueden ingresar y interactuar con otras personas, pero tu le has encontrado una vulnerabilidad muy grande. Para razones de seguridad las contraseñas de cada usuario no son guardadas en el servidor, sino que se calcula un valor único a partir de esta contraseña y se compara con la contraseña (efectivamente un hash). Tu amigo calcula estos hashes sumando el valor númerico de cada letra en ASCII, excepto que te has dado cuenta que varias contraseñas pueden tener la misma suma.

Para ver que tán vulnerable es una contraseña decides crear un programa que imprime el número de contraseñas posibles que suman a un valor **S** usando solo cáracteres alfanúmericos.

Por ejemplo, la suma de la contraseña **Ab6** se puede calcular con 'A' + 'b' + '6' o 65 + 98 + 54 = 217 en ASCII. Otra contraseña igual a esa sería **98h** con suma '9' + '8' + 'h' o 57 + 56 + 104 = 217.

# Entradas

Un valor **S**, la suma de todos los cáracteres.

# Salidas

Un número **C** correspondiendo a cuantas contraseñas suman a **S** considerando que son alfanúmericas y de cualquier tamaño (los cáracteres alfanúmericos son **A-Z**, **a-z** y **0-9** para este problema).

# Ejemplos

||input
100
||output
6
||end

En este ejemplo solo hay 6 posibles contraseñas con cáracteres que suman a 100: **d**, **04**, **40**, **13**, **31** y **22**.

||input
217
||output
2319
||end

# Límites

$ 0 \le S \le 10,000 $

$ 0 \le C \le 10^{18} $ para $ 70 \% $ de los casos

$ 10^{18} \le C \le 10^{200} $ para $ 30 \% $ de los casos