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
    datos_t dat;
    struct pila *l;
    
};

void funcion (unsigned int, struct pila **);


void funcion (unsigned int id, struct pila **p){
    FILE *fp, *fp2;
    d_archivo_t bf, bf2;
    unsigned int clave, i=0, j, a, b;
    char *paux, pinv[60];
    struct pila *aux;
    if ((fp=fopen ("../ejercicio39/potencia.dat", "rb+"))==NULL){
        printf ("\nNo se pudo abrir el archivo potencia.dat");
    }else
    {
        
        fseek (fp, (long)sizeof (d_archivo_t)*(id-1), 0);
        fread (&bf, sizeof (d_archivo_t), 1, fp);
        if (bf.id==id){
            
            paux=bf.inf.desc;
            while (*paux && *paux!= ' '){
                *paux ++;
                i++;
            }
            *paux--;
            for (j=0; j<i; j++){
                pinv[j]=*paux;
                *paux--;
            }
            pinv[i]=0;
            printf ("\nLa primer palabra de descripcion invertida es: %s", pinv);
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
                aux->dat=bf.inf;
                aux->l=*p;
                *p=aux;
                aux=NULL;
                printf ("\nSe apilo el registro");
                free (aux);
                
            }else
            {
                if ((fp2=fopen("salida.dat", "ab+"))==0){
                    printf("\nError al abrir el archivo salida.dat");
                }
                else{
                    
                    printf ("\nIngrese la clave para archivar este registro:\t");
                    fflush (stdin);
                    scanf ("%d", &clave);
                    fseek (fp2, 0L, 0);
                    fread (&bf2, sizeof (d_archivo_t), 1, fp2);
                    while (!feof(fp2)){
                        while (bf2.id == clave){
                                    printf ("\nClave ya ingresada, ingrese uno nuevo: \t");
                                    fflush (stdin);
                                    scanf ("%d", &clave);
                        }
                        fread (&bf, sizeof (datos_t), 1, fp2);   
                    }
                    bf.id = clave;
                    fseek (fp2, 0L, 2);
                    if ((fwrite (&bf, sizeof(d_archivo_t), 1, fp2))==1)
                    printf ("\nSe archivo el registro con clave: %.4d\n", bf.id);
                }
                        
                fclose (fp2);
            }
                printf ("\nregistro archivado en salida.dat");   

            
        }else{
            printf ("\nRegistro no encontrado");
        }

    }
    fclose (fp);
    return;
}

