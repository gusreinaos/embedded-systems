## Bit handling

- En caso de que queramos hacer toggle de un determinado bit o cambiar un bit ya existente podemos hacer uso del operador XOR de la misma forma: ew_num = num ^ (1 << n); El operador XOR cuando comparamos 1-0 o 0-1 da de resultado 1, pero en caso de que sean iguales da de resultado 0. 
Esto es si comparamos nuestro actual numero con un numero en binario con todo 0s, introduciendo un 1 en el bit que queremos cambiar y los comparamos y asignamos a un nuevo numero el cambio si va a realizar.

