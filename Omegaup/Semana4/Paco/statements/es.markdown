
# Descripción

Paco se quejó de que hicimos un problema con el nombre de Carlos pero no con el suyo. Entonces decidimos crear este problema que explica el proceso de decisión de Paco para llegar del trabajo a su casa. 

Paco es un empleado de Google en California, cada día en el camino de regreso a su casa donde lo está esperando Domene para jugar Smash, tiene que elegir qué parada de camion tomar para poder llegar pronto, sin embargo, en el camino hacia las paradas de camión hay distracciones que toman el tiempo de Paco. 
Tu tarea es encontrar cuantas rutas de camion diferentes puede tomar Paco para llegar a tiempo a la casa y poder jugar Smash con Domene. 

La distribución de camiones y distracciones se presentarán en un árbol con N nodos donde los nodos hoja serán las paradas de camión y los demás serán lugares por los que tiene que pasar Paco para llegar a las paradas de camión.

Paco es muy determinado a la hora de querer jugar Smash, por lo que solo se distraerá realmente si hay más de K distracciones consecutivas en su camino hasta la parada del camión. Si en una de las rutas hay más de K distracciones consecutivas, no llegará a tiempo y Domene apagará su Switch.

#Entrada

En la primera línea de entrada habrá dos enteros N y K separados por espacios. 
En la segunda línea habrá N números separados por espacios, el N-ésimo número de esta línea representará si hay o no hay distracción en el N-ésimo vértice del grafo. La representación será solo 0 o 1 (0 si no hay distracción y 1 si sí la hay). 
En las siguientes N - 1 líneas habrá adyacencias entre dos vértices del árbol. 

#Salida

La cantidad de paradas a las cuales puede ir Paco para alcanzar a jugar Smash.
Seguido de la frase “Paco trabaja en Google”. 

Nota: El primer vértice representa el trabajo de Paco (Google para que no se les olvide, porque ahí trabaja Paco).

# Ejemplo

||input
5 2
1 1 0 1 1
1 2
2 3
3 4
4 5
||output
1
Paco trabaja en Google
||end


#Limites
$2 \le N \le 100000$
$1 \le M \le n$
