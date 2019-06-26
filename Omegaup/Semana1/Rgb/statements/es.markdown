# Descripción

Es bien sabido que los leds favoritos de James son los RGB, pero cuando sus compañeros ven sus proyectos tienden a confundirse acerca de qué color están viendo. James ya terminó un programa que detecta cuál es el valor RGB que tienen sus leds usando OpenCV y ROS con su nuevo robot que barre y trapea, pero como está muy ocupado comiendo alitas picantes (se las cocinó su robot) necesita que lo ayudes a discrepar cuál es el color que predomina.

El sistema que programó James funciona de la siguiente manera:

Lee el color RGB y regresa tres valores que corresponden a la intensidad de cada color, con un máximo de 255 y un mínimo de 0 (por el valor convencional de un RGB).

Tu tarea es, dados los valores **R**, **G**, y **B**, decidir cuales son los que predominan (los máximos), y elegir una de las categorías de color dada la siguiente lista.

rojo = max min min

verde = min max min

azul = min min max

amarillo = max max min

cyan = min max max

morado = max min max

blanco = max max max


# Entrada

Un número **N**: $1 \le N \le 10000$ que indicará el número de Leds RGBs que tiene James (te sorprendería cuántos caben en su caja).

En las siguientes **N** líneas, tres enteros **R**: $0 \le R \le 255$, **G**: $0 \le G \le 255$, y **B**: $0 \le B \le 255$. Al menos uno de los valores de **R**, **G** o **B** será mayor que cero en todos los casos.

# Salida

**N** categorizaciones de los Leds de James

# Ejemplo

||input
5
119 118 117
110 0 0
0 0 1
1 1 1
255 255 254
||output
rojo
rojo
azul
blanco
amarillo
||end