#include "lib.h"

int main(){
    struct pila *p=NULL, *aux;
    int op;
    datos_t dat;

    bienvenida();
    op=menu();
    while (op !=2){
        leerdat (&dat);
        p = apilar (&aux, p, dat);
        op=menu();
    }    
    while (p){
        desapilar (&p); 
    }   
    
    system ("pause");
    return 0;
}

