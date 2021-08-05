int buscar_reputacion(reputacion_t reputaciones[MAX_REPUTACIONES], int tope, int actual, int
id_buscado){

if (reputaciones[actual].id_reputacion == id_buscado)
return actual;

return buscar_reputacion(reputaciones , tope, actual, id_buscado);
}

a- Solo funciona si la primer posicion es el id buscado, para que funcione para los demas casos arreglaria las {} que le faltan al if y en el ultimo return seria ->
buscar_reputacion(reputaciones,tope,actual+1,id_buscado);

b- Solucionado:

int buscar_reputacion(reputacion_t reputaciones[MAX_REPUTACIONES], int tope, int actual, int
id_buscado){

    if(actual >= tope){ //Si se sale del tope significa que no lo encontro
        return -1; 
    }

    if(reputaciones[actual].id_reutacion == id_buscado){
        return actual;
    }

    return buscar_reputacion(reputaciones,tope,actual+1,id_buscado);
}

c- En el caso en el que la reputacion este ordenada por id no es la mejor opcion, si esta ordenado por id la mejor opcion es hacer busqueda binaria, la cual consiste
en ir a la mitad del vector y ver si es el indicado, si es menor se busca en los menores a esa mitad y si es mayor se busca en los mayores a esa mitad
