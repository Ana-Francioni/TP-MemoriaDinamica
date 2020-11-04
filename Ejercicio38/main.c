#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define togglebit(v, bit) v = v ^ (1<<bit)

struct cola {
    char val;
    struct cola *ant;
    struct cola *sig;

};



int main (){
    struct cola *p=NULL, *u=NULL, *aux, *r;
    int i;
    char val;
    aux = (struct cola*)malloc(sizeof (struct cola));

    for (i=0; i<91; i=i+5){
        aux = (struct cola*)malloc(sizeof (struct cola));
        val = (char)((double)127.0*sin((double)i*M_PI/180));
        aux->val = val;
        if (p==NULL){
            aux->ant = NULL;
            aux->sig = NULL;
            p=u=aux;
            
            
        }else{
            aux->sig = NULL;
            aux->ant = u;
            u->sig = aux,
            u = aux;
        }
        aux = NULL;
        free (aux);
        
    }
    printf ("\n***Los valores de la senoidal son***\n\n");
    r=p;
    while (r->sig){
        printf ("%d / ", r->val);
        r=r->sig;
    }
    r=u;
    printf ("\n");
    while (r->ant){
        printf ("%d / ", r->val);
        r=r->ant;
    }
    if (r==p){
      printf ("%d ", r->val);  
    }
    printf ("\n");
    r=p->sig;
    while (r->sig){
        val = r->val;
        togglebit(val, 7);
        printf ("%d / ", val);
        r=r->sig;
    }
    printf ("\n");
    r=u;
    while (r->ant){
        val = r->val;
        togglebit(val, 7);
        printf ("%d / ", val);
        r=r->ant;
    }
    if (r==p){
      printf ("%d\n\n", r->val);  
    }
    
    system ("pause");
}

