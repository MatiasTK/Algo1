#include <stdbool.h>
#define MAX_AMIGOS 5

bool registrar_amigo(int amigos[MAX_AMIGOS], int* tope_amigos, int id_amigo) {

    bool rt;

    for(int i = 0; i <= *tope_amigos; i++){
        if (*tope_amigos < 4 && (*tope_amigos) != 0){
            (*tope_amigos)++;
            amigos[*tope_amigos - 1] = id_amigo;
            rt = true;
            break;
        } else if((*tope_amigos) == 0){
            (*tope_amigos)++;
            amigos[*tope_amigos - 1] = id_amigo;
            rt = true;
            break;
        }else{
            rt = false;
            break;
        }
    }
    return rt;
}

int main(){

    int amigos[MAX_AMIGOS] = {2, 3};
    int tope_amigos = 0;
    int id_amigo = 9;

    registrar_amigo(amigos,&tope_amigos,id_amigo);


    return 0;
}