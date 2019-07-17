# Descripción

La novia de Karel irá a visitarlo a su casa pero la casa de Karel esta hecho un desastre y hay beepers en todos lados. Karel te ha pedido la lista más corta de comandos para que pueda recoger todos estos beepers lo más rapido posible. Karel es un robot antiguo y solo es capaz de girarse 90 grados a la izquierda en cada turno o moverse un espacio adelante en la dirección que esta viendo.

Karel solo reconoce estos tres comandos:

* **move();** moverse un espacio adelante
* **turnLeft();** voltearse 90 grados a la izquierda
* **pickBeeper();** recoger un beeper

# Entrada

Dos enteros **X** y **Y** representando las coordenadas de Karel, una cuerda **NORTE**, **SUR**, **ESTE** u **OESTE** indicando la dirección inicial de Karel y un entero **N**, el número de beepers en el mapa.

En las siguientes **N** líneas habrá dos enteros **Xb** y **Yb** representando las coordenadas X y Y de cada beeper.

Se puede asumir que siempre habrá una lista más corta que los demás.

# Salida

La lista más corta de comandos que recoge todos los beepers. Inmediatamente después de colocarse sobre un beeper, se debe llamar **pickBeeper();**

# Ejemplo

||input
1 1 ESTE 2
-1 4
2 4
||output
move();
turnLeft();
move();
move();
move();
pickBeeper();
turnLeft();
move();
move();
move();
pickBeeper();
||end

# Límites

$1 \le N \le 1000$

$-1,000,000 \le X, X_b, Y, Y_b \le 1,000,000$