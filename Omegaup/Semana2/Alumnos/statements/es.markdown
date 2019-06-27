# Descripción

Te han asignado como presidente de la generación, y tus superiores quieren que hagas una encuesta y que determines qué tan saludables están todos los alumnos.

Para hacer esta tarea, has monitoreado a los demás alumnos y podrás hacer un modelo matemático de la salud respecto a dos variables: comida y tiempo en el gimnasio.

Tienes una lista de **N** alumnos y sabes que hay cuatro comidas en la cafetería en orden ascendente de salud:
Pizza (la menos saludable)
Tacos
Torta
Ensalada (la más saludable)

También sabes que la comida tiene más impacto en la salud que el tiempo en el gimnasio, así que decides ordenar los alumnos primero por comida y luego por tiempo en el gimnasio.


# Entrada

Un entero **N**, el número de alumnos en la generación, seguido por **N** líneas. En cada una de las siguientes líneas, estará el nombre del alumno (una sola cuerda), el nombre de su comida preferida (una sola cuerda) y finalmente un entero que representa el tiempo en el gimnasio en horas **H**.


# Salida

**N** líneas, cada uno con el nombre de cada alumno. El más saludable debe ir primero y el menos saludable debe ir al final.

# Ejemplo
||input
4
Blanca Tacos 2
Brayan Pizza 0
Edison Ensalada 6
Miguel Tacos 24
||output
Edison
Miguel
Blanca
Brayan
||end

#Límites

$1 \le N \le 1,000,000$

$1 \le H \le 1,000,000$

