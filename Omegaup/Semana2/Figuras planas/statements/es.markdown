# Descripción

Dado cuatro puntos **A**, **B**, **C** y **D** determina si la figura **ABCD** es un cuadrado, un rectángulo, un trapezoide, un paralelogramo o ninguno bajo las siguientes definiciones:

Cuadrado: Cuadrilátero con cuatro ángulos rectos y cuatro lados del mismo tamaño
Rectangulo: Cuadrilátero que no es cuadrado pero tiene ángulos rectos
Paralelogramo: Cuadrilátero que no tiene ángulos rectos pero cada par de lados opuestos tiene el mismo tamaño e inclinación (son paralelos).
Trapezoide: Cuadrilátero que solo tiene dos lados paralelos.
Ninguno: No cumple con los últimos descripciones.


# Entrada

Cuatro pares de números enteros **X**: $-10000 \le X \le 10000$ y **Y**: $-10000 \le Y \le 10000$ en distintas líneas

# Salida

Cuadrado, Rectangulo, Paralelogramo, Trapezoide o Ninguno dependiendo del tipo de figura

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