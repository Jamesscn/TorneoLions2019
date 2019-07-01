# Descripción

Trabajas para el banco Bancomega y muchos clientes tienden a confundirse e intentan hacer transacciones de dinero a cuentas de Bankarel debido a que ambos bancos tienen logos y sucursales parecidos.

Tu jefe te ha pedido que creas un programa para determinar si una tarjeta es de Bancomega o de Bankarel y te ha dicho que todas las tarjetas de Bancomega han sido generadas con el algoritmo de Luhn mientras que las de Bankarel no.

Al ponerte a investigar el algoritmo de Luhn, descubres que puedes comprobar si una tarjeta es válida comparando el último dígito con el resto de los números. Se debe de hacer el siguiente proceso:

 - Empezando desde la derecha a la izquierda multiplicar cada segundo dígito por dos
 - Si el resultado de la multiplicación es un número con dos dígitos, se cambiará por la suma de sus dos dígitos. Si tiene un solo dígito, se queda igual.
 - Sumar todos estos dígitos que se obtuvieron con los otros dígitos que no fueron usados.
 - Si esta suma es divisible entre 10, la tarjeta es válida.

Por ejemplo, si tienes el número 79927398712 y quisieras saber si es válido, debes sacar cada segundo dígito empezando desde la derecha hasta la izquierda y multiplicar estos por dos:
 
7**9**9**2**7**3**9**8**7**1**2

Primero se selecciona 1, luego 8, 3, 2 y 9.

(**9** * 2 = 18, **2** * 2 = 4, **3** * 2 = 6, **8** * 2 = 16, **1** * 2 = 2)

(18, 4, 6, 16, 2)

Luego debes sumar estos dígitos

1 + 8 + 4 + 6 + 1 + 6 + 2 = 28

Y debes de sumar estos números a los dígitos que no se usaron previamente:

**7**9**9**2**7**3**9**8**7**1**2**

28 + **7** + **9** + **7** + **9** + **7** + 2 = 69.

69 no es divisible entre 10 y esto significa que esta tarjeta es inválida.

# Entradas

Un número **C**, la cantidad de tarjetas que se desea inspeccionar y **C** líneas con el número de cada tarjeta $\phi$.

# Salidas

Para cada tarjeta, se debe imprimir en una linea nueva **Bancomega** si $\phi$ cumple con el algoritmo de Luhn o **Bankarel** si no.

# Ejemplo

||input
6
79927398712
79927398713
12345
9999999
123456789007
123456789008
||output
Bankarel
Bancomega
Bankarel
Bankarel
Bancomega
Bankarel
||end

# Límites

$1 \le C \le 1000$
$1 \le \phi \le 10^1000$