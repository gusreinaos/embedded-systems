## Bit handling

- Un numero is impar/odd si el least significant bit es 1 y par si es al contrario

- (IMPORTANTE) En caso de que queramos hacer toggle de un determinado bit o cambiar un bit ya existente podemos hacer uso del operador XOR de la misma forma: ew_num = num ^ (1 << n); El operador XOR cuando comparamos 1-0 o 0-1 da de resultado 1, pero en caso de que sean iguales da de resultado 0. 
Esto es si comparamos nuestro actual numero con un numero en binario con todo 0s, introduciendo un 1 en el bit que queremos cambiar y los comparamos y asignamos a un nuevo numero el cambio si va a realizar.

- Para bitpacking añadir valores usamos el bitwise operator |= (lo que haya que introducir) << (donde en el byte)

- Para comparar bits podemos hacer right shitfing porque siempre comparamos el ultimo significant bit y usar el & operator para ver si el resultado es 1 o 0. 

- Hexadecimal number --> unsigned char

- A byte starts counting from 0 until 7 (included) - 8 spaces

