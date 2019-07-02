# Descripción

Al viajar más al sur has descubierto zonas habitadas por alienígenas que tienen un número distinto de dedos. Por un malentendido te han dado el puesto de traductor y tienes el cargo de convertir números enteros de una base a otra para poder comunicar con otras alienígenas.

Como son muy raros, ellos utilizan letras y símbolos para representar a sus números. Por ejemplo, !MM#e puede representar 2513.

# Entradas

Recibirás dos enteros **A** y **B**, la base del número que se te dará y la base a la que la tienes que convertir. En la siguiente línea, se te darán A cáracteres sin espacios que representan los dígitos de 0 a A en el primer sistema númerico. En otra línea, se darán B cáracteres sin espacios que son los dígitos de 0 a B en el segundo sistema númerico. Finalmente, se te dará un valor **C** que esta representado en el primer sistema y este número es el que tienes que convertir.

En cada sistema númerico NO se repitirán cáracteres, pero dos sistemas distintos sí podrán compartir el mismo cáracter. Los cáracteres mayusculas y minusculas tambien se consideran distintos; A y a serian diferentes.

# Salidas

La representación del valor **C** en el segundo sistema.

# Ejemplos

||input
16 2
0123456789ABCDEF
?!
16A
||output
!?!!?!?!?
||end

En este caso, se convierte lo que sería 362 en decimal o 16A en hexadecimal a un especie de binario con signos de interrogación que representan 0 y signod de admiración que representan 1.

||input
5 10
M=#e!
0123456789
!MM#e
||output
2513
||end

Aqui, se tiene que M es el primer dígito, = es el segundo, # es el tercero, e es el cuarto y ! es el quinto. Al realizar la conversion se obtiene que esto es 2513 en decimal.

# Límites

$1 \le A, B \le 64$

$0 \le C \le 1,000,000$