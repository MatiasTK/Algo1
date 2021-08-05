/*
1-Explico el metodo de insercion:
A-Empiezo analizando el vector por la derecha(Osea desde el final hasta el principio), analizando alfabeticamente la primer inicial de cada vector
B-Si encuentro una inicial mayor al que tengo que insertar entonces a partir desde ahi hasta el tope del vector muevo todo una
posicion hacia la derecha.
C-Como ahora me va a quedar una posicion vacia(Ya que movi todo una posicion a la derecha a partir del elemento encontrado)
en esa posicion vacia inserto MANDY.
D-Finalmente como movi todo una posicion a la derecha para no eliminar una palabra del vector aumento el tope.

2-Si solo se tiene que buscar un elemento no te conviene ordenarlo, ya que ordenarlo es un trabajo muy largo y no conviene hacer tanto trabajo solo para buscar
un elemento -> Deberia usar busqueda lineal

3-La diferencia es que la busqueda lineal se utiliza en un vector no ordenado y la busqueda binaria en un vector ordenado, aunque se puede utilizar busqueda
lineal en un vector ordenado conviene utilizar la busqueda binaria ya que esta realiza menos iteraciones.
*/