# Descripción

¡Steve está atrapado en una cueva y ocupa tu ayuda para escapar antes de que oscurezca! Steve tiene un mapa consigo que le permite ver los bloques que están a su alrededor, y necesita que tu creas un programa que le diga cual es el camino más corto a su casa.

El mapa consiste en **N** x **N** cáracteres, con el cáracter X representando la ubicación inicial de Steve, H representando su casa, # indicando una pared y con . marcando un espacio libre.

# Entrada

Un número **N**, seguido por **N** líneas con **N** caracteres representando el mapa.

# Salida

**M** comandos indicando como se debe mover Steve para llegar a su casa. Puede ser ARRIBA, ABAJO, IZQUIERDA o DERECHA. Siempre habrá un solo camino más óptimo que los demás y siempre se podrá llegar a la casa.

# Ejemplo

||input
7
##H####
#..##X#
#.###..
#..#..#
##...##
#.....#
#######
||output
ABAJO
ABAJO
IZQUIERDA
ABAJO
IZQUIERDA
IZQUIERDA
ARRIBA
IZQUIERDA
ARRIBA
ARRIBA
DERECHA
ARRIBA
||end

# Límites:

$3 \le N \le 100$