#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_PEDIDOS 20

typedef struct pedidos{
    char nombre[MAX_NOMBRE];
    int cantidad_shampoo;
    int cantidad_crema_enjuage;
    int precio;
} pedidos_t;

void bubble_sort(pedidos_t vector[MAX_PEDIDOS], int tope){
    int i,j;
    pedidos_t aux;
    for(i = 0; i < tope; i++){
        for(j = 0; j < (tope-1-i);j++){
            if(strcmp(vector[j].nombre,vector[j+1].nombre) > 0){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}

void ordenar_archivo(){
    FILE* archivo = fopen("pedidos.txt","r");
    FILE* ordenado = fopen("pedidos_ordenado.txt","w");

    if(!archivo){
        perror("No se pudo abrir pedidos.txt");
        return;
    }
    if(!ordenado){
        fclose(archivo);
        perror("no se pudo crear pedidos_ordenado.txt");
        return;
    }

    pedidos_t pedidos;
    pedidos_t vector_pedidos[MAX_PEDIDOS];
    int tope = 0;

    int leer = fscanf(archivo,"%[^;];%i;%i;%i\n",pedidos.nombre,&pedidos.cantidad_shampoo,&pedidos.cantidad_crema_enjuage,&pedidos.precio);
    vector_pedidos[tope] = pedidos;

    while(leer == 4){
        tope++;
        leer = fscanf(archivo,"%[^;];%i;%i;%i\n",pedidos.nombre,&pedidos.cantidad_shampoo,&pedidos.cantidad_crema_enjuage,&pedidos.precio);
        vector_pedidos[tope] = pedidos;
    }

    bubble_sort(vector_pedidos,tope);

    for(int i = 0; i < tope; i++){
        fprintf(ordenado,"%s;%i;%i;%i\n",vector_pedidos[i].nombre,vector_pedidos[i].cantidad_shampoo,vector_pedidos[i].cantidad_crema_enjuage,vector_pedidos[i].precio);
    }

    fclose(archivo);
    fclose(ordenado);

    remove("pedidos.txt");
    rename("pedidos_ordenado.txt","pedidos.txt");
}

int main(){

    ordenar_archivo();

    return 0;
}