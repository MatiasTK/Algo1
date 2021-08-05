_Bubble sort:
1-Tomo los dos primeros numeros y si no estan ordenados los intercambio
2-Repito el 1 pero con los dos siguientes numeros(osea posicion 2 y 3)
3-Repito el 2 hasta llegar al final
4-Repito del 1 al 3 pero sin contar este ultimo numero que ya esta ordenado
5-Repito todos los pasos hasta que el vector quede ordenado

_Insercion:
1-Empiezo del segundo valor, si alguno de los numeros de la izquierda es menor lo intercambio 
2-Hago lo mismo pero empiezo por el siguiente valor(el tercero), busco el ultimo menor en la izquierda, osea hasta que encuentre un mayor
3-Repito hasta tener el vector ordenado

_Seleccion:
1-Busco el menor elemento del vector y lo envio al principio
2-Busco nuevamente el menor del vector pero sin contar esta primera posicion y lo mando a la siguiente posicion (segunda)
3-Repito hasta tener el vector ordenado

_Busqueda binaria:
1-Solo lo utilizo si el archivo esta ordenado
2-Voy hasta la mitad del vector, si el numero que quiero encontrar esta en la mitad termino ahi sino sigo con el paso 3
3-Si el numero buscado es mayor a la mitad entonces repito este proceso pero tomando como inicio la mitad + 1
4-Si el numero buscado es menor a la mitad entonces repito este proceso pero tomando como final la mitad - 1
5-Repito hasta hallar el numero

_Busqueda lineal:
1-Recorro desde el inicio hasta el final el vector, si encuentro el numero ya esta.

_Mezcla:
1- Uno la informacion de los dos vectores(tambien los repetidos)

_Union:
1-Uno la informacion de los dos vectores pero sin contar los repetidos

_Diferencia:
1-De los dos vectores solo escribo lo que esta en un vector pero no en el otro

_Interseccion:
1-Pongo la informacion que este tanto en el vector 1 como en el vector 2

_Insertar ordenado:
1-Recorro el vector por la izquierda (desde el final hasta el principio)
2-Si encuentro un numero mayor al que quiero insertar entonces a partir de ahi hasta el tope muevo todo una posicion a la derecha
3-Como ahora me va a quedar una posicion vacia ya que movi todo una posicion a la derecha, en esa posicion vacia inserto el valor que queria
4-Finalmente como movi todo una posicion a la derecha para no eliminar un numero del vector aumento el tope

_Insertar desordenado:
1-Lo inserto en el tope
2-Aumento el tope

_Eliminar ordenado;
1-Recorro el vector hasta encontrar el valor que quiero eliminar
2-A partir de esa posicion muevo todo una posicion a la izquierda y el numero siguiente va a reemplazar al que tengo que eliminar
3-Como tengo un numero menos en el vector reduzco el tope

_Eliminar desordenado:
1-Recorro el vector hasta encontrar el valor que quiero eliminar
2-Lo reemplazo por el que esta una posicion antes que el tope
3-Ya que elimine un numero reduzco el tope

