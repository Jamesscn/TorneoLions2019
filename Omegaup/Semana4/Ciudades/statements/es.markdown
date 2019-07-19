# Descripción

Estas jugando un juego donde creas ciudades y has decidido poner varias carreteras para unir tus ciudades y para mejorar tu economia. Sin embargo, tienes poco dinero debido a que has puesto muchas refinerías y quisieras construir las carreteras de tal manera que se puede ir de una ciudad a cualquiera de las otras gastando lo menos posible en carreteras. Cada metro de distancia te cuesta, asi que debes buscar minimizar la distancia acumulada.

Se puede asegurar que siempre habrá una sola configuración más optima que los demás.

# Entrada

Un número **N** seguido por **N** líneas con una cuerda (el nombre de la ciudad sin espacios), la latitud **Lt** y la longitud **Lg** de esa ciudad como números flotantes.

# Salida

**M** líneas con dos cuerdas, el nombre de la primera y la segunda ciudad unida por cierta carretera. Cada línea debe estar ordenada alfabeticamente y las dos cuerdas de cada línea tambien deben estar ordenadas alfabeticamente.

# Ejemplo

||input
5
Monterrey 25.6487281 -100.4431848
Coatzacoalcos 18.1342154 -94.4979666
Guadalajara 20.6737777 -103.4054543
Tampico 22.2662251 -97.9395268
Acapulco 16.8354129 -100.0023981
||output
Acapulco Coatzacoalcos
Acapulco Guadalajara
Coatzacoalcos Tampico
Monterrey Tampico
||end

En este caso se deben construir cuatro carreteras, dos que van de Acapulco a Coatzacoalcos y a Guadalajara, uno que va de Cuatzacoalcos a Tampico y uno que va a Tampico a Monterrey.

# Límites

$2 \le N \le 1000$

$-1,000,000 \le L_t, L_g \le 1,000,000$