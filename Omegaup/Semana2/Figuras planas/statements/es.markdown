# Descripción

Dado cuatro puntos **A**, **B**, **C** y **D** determina si la figura **ABCD** es un cuadrado, un rectángulo, un paralelogramo, un trapezoide o ninguno bajo las siguientes definiciones:

Cuadrado: Cuadrilátero con cuatro ángulos rectos y cuatro lados del mismo tamaño

Rectangulo: Cuadrilátero que no es cuadrado pero tiene cuatro ángulos rectos

Paralelogramo: Cuadrilátero que no tiene ángulos rectos pero cada par de lados opuestos tiene el mismo tamaño e inclinación (son paralelos).

Trapezoide: Cuadrilátero que solo tiene dos lados paralelos.

Ninguno: No cumple con las últimas descripciones.

Las figuras no se intersectarán y formarán un cuadrilátero con lados **AB**, **BC**, **CD** y **AD**.

# Entrada

Cuatro pares de números enteros **X**: $-10000 \le X \le 10000$ y **Y**: $-10000 \le Y \le 10000$ en distintas líneas correspondiendo a **A**, **B**, **C** y **D** en ese orden.

# Salida

Cuadrado, Rectangulo, Paralelogramo, Trapezoide o Ninguno dependiendo de la figura

# Ejemplo
||input
0 0
0 1
1 1
1 0
||output
Cuadrado
||end

||input
20 20
50 60
60 80
30 40
||output
Paralelogramo
||end
