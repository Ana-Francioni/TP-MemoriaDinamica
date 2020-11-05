#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define togglebit(v, bit) v = v ^ (1<<bit)
#define checkbit(a, v, bit) a = v & (1<<bit)



typedef struct {
    char desc[60];
    unsigned char potencia;
    unsigned int estado;
}datos_t;

typedef struct{
    datos_t inf;
    int id;
}d_archivo_t;

struct pila{
    d_archivo_t dat;
    struct pila *l;
    
};

void funcion (unsigned int, struct pila **);

void funcion (unsigned int id, struct pila **p){
    FILE *fp;
    d_archivo_t bf;
    char *paux, pinv[60];
    int i=0, j, a, b;
    struct pila *aux;
    if ((fp=fopen (".../ejercicio39/potencia.dat", "rb+"))==NULL){
        printf ("\nNo se pudo abrir el archivo potencia.dat");
    }else
    {
        fseek (fp, (1L)*sizeof(d_archivo_t)*(id-1), 0);
        if (bf.id==id){
            fread (&bf, sizeof (datos_t), 1, fp);
            paux=bf.inf.desc;
            while (*paux && *paux!= ' '){
                *paux ++;
                i++;
            }
            if (*paux==0 || *paux==' ') *paux--;
            for (j=0; j<i; j++){
                pinv[j]=*paux;
                *paux--;
            }
            pinv[i]=0;
            printf ("\nLa primer palabra de descripcion invertida es:", pinv);
            togglebit(bf.inf.estado, 3);
            fseek (fp, (-1L)*sizeof(d_archivo_t), 1);
            if (fwrite(&bf, sizeof(d_archivo_t), 1, fp)==1){
                printf ("\nSe actualizo el registro en el archivo potencia.dat");
            }else{
                printf ("\nNo se pudo actualizar el registro");
            }
            checkbit(a, bf.inf.estado, 2);
            checkbit(b, bf.inf.estado, 0);
            if (a && b){
                aux=(struct pila *)malloc (sizeof (struct pila));
                aux->dat=bf;
                aux->l=*p;
                *p=aux;
                aux=NULL;
                free (aux);
                
            }else
            {
                /* pendiente archivar el registro en el nuevo archivo "salida.dat" */
            }
            

            
        }else{
            printf ("\nRegistro no encontrado");
        }

    }
    fclose (fp);
    return;
}


