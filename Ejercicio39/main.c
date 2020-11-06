#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char desc[60];
    unsigned char potencia;
    unsigned int estado;
}datos_t;

typedef struct{
    datos_t inf;
    int id;
}d_archivo_t;

struct lista{
    datos_t dat;
    struct lista *l;
    
};

typedef enum {
    l_sin_inf = 0,
    l_con_inf = 1,
} lista_t;
 

void bienvenida (void);
int menu (void);
void leerdat (datos_t *);
void carga_est (datos_t *);
void listar (struct lista **, struct lista**, datos_t);
void archivar (struct lista **, struct lista**);

int main(){
    datos_t datos;
    struct lista *p = NULL, *u = NULL;
    int op=1;
    bienvenida();

    while (op == 1){
        leerdat(&datos);
        carga_est(&datos);
        listar(&p, &u, datos);
        op=menu();
    }
    archivar(&p,&u);
    printf ("\n");
    system ("pause");

}

void bienvenida (void){
    printf ("\n***Bienvenido, ingrese los datos***\n");
    return;
}
int menu (void){
    int op;
    printf ("\n\n1.Cargar mas datos\n2.Finalizar\n");
    fflush (stdin);
    scanf ("%d", &op);
    return op;
}
void leerdat (datos_t *d){
    printf ("\n\nIngrese la descripcion: \t");
    fflush (stdin);
    gets (d->desc);
    printf ("\nIngrese el valor de potencia: \t");
    fflush (stdin);
    scanf ("%d", &d->potencia);
    return;
}
void carga_est (datos_t *d){
    char k;
    k=d->desc[0];
    d->estado=(unsigned int)k*(unsigned int)d->potencia;
    printf ("\nEl valor de estado asignado es: %d", d->estado);
    return;
}
void listar (struct lista **p, struct lista**u, datos_t d){
    struct lista *aux, *r;
    lista_t k;
    unsigned char a, b;
    int j=1;
    aux=(struct lista *)malloc(sizeof(struct lista));
    aux->dat=d;
    if (*p==NULL) k=0;
    else k=1;
          
    switch(k){
                
        case l_sin_inf:
            aux->l=NULL;
            *p=*u=aux;
            printf ("\nSe asigno el primer elemento de la lista");
        break;

        case l_con_inf:
            a=(*p)->dat.potencia;
            b=aux->dat.potencia;   
            if (b>a){
                aux->l=*p;
                *p=aux;
                printf ("\nSe actualizo el primer elemento de la lista");
            } 
            else{
                r=*p;
                if (r->l==NULL){
                    aux->l = (*p)->l;
                    (*p)->l = aux;

                }else
                {
                    a=r->l->dat.potencia;
                
                    while (r->l && b<a){
                        
                        r=r->l;
                        if (r->l !=NULL) a=r->l->dat.potencia;
                    
                    }
                    if (r==*u){
                        
                        (*u)->l=aux;
                        *u=aux;
                        (*u)->l=NULL;
                                
                    }else
                        {
                            
                            aux->l=r->l;
                            r->l=aux;
                        }
                }
                
                
            }
        printf ("\nSe añadio un elemento a la lista");
        break;
    }
    aux= NULL;
    free (aux);
    return;
}
void archivar (struct lista **p, struct lista**u){
    FILE * fp;
    struct lista *aux;
    d_archivo_t bf;
    int i=0;
    if((fp=fopen("potencia.dat", "wb"))==NULL)
    printf ("\nNo se pudo crear el archivo potencia.dat");
    else{
        while (*p){
            aux=(struct lista *)malloc(sizeof(struct lista));
            bf.inf=(*p)->dat;
            bf.id = i+1;
            if ((fwrite (&bf, sizeof(d_archivo_t),1,fp))==1){
                printf ("\n\nSe archivo el registro con los siguientes datos:");
                printf ("\nID: %d, Descripcion: %s, potencia: %d, estado: %d", bf.id,bf.inf.desc,bf.inf.potencia, bf.inf.estado);
                i++;
            }
            aux=*p;
            *p=(*p)->l;
            free (aux);
        }
        
    }
    fclose (fp);
    return;

}