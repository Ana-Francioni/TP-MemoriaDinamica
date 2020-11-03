#include "lib.h"

void bienvenida (void){
    printf ("Bienvenido, seleccione una opcion:\n");
    return;
}

int menu (void){
    int op;
    printf ("\n1.Cargar datos\n2.Salir\n");
    fflush (stdin);
    scanf ("%d", &op);
    return op;
}

void leerdat (datos_t *datos){
    printf ("\nIngrese su apellido: \t");
    fflush (stdin);
    gets (datos->apellido);
    printf ("\nIngrese su nombre: \t");
    fflush (stdin);
    gets (datos->nombre);
    printf ("\nIngrese su edad: \t");
    fflush (stdin);
    scanf ("%d", &datos->edad);
    printf ("\nIngrese su email: \t");
    fflush (stdin);
    gets (datos->email);    
    printf ("\nIngrese su telefono: \t");
    fflush (stdin);
    scanf ("%ld", &datos->tel);
    return;
}

struct pila * apilar (struct pila **u, struct pila *p, datos_t d){
    *u = (struct pila *)malloc(sizeof (struct pila));
    (*u)->datos=d;
    (*u)->p = p;
    p = *u;
    return p;
}

void desapilar (struct pila **p){
    struct pila *aux;
    aux = *p;

    if ((*p)->datos.edad>21){
        archivar ((*p)->datos);
    }
    *p = (*p)->p;
    free (aux);
    return;
}

void archivar (datos_t d){
    FILE *fp;
    int id;
    datos_t darchivo, bf;
    if (!(fp=fopen ("contactos.dat", "ab+")))
        printf("\nNo se pudo crear el archivo ""contactos.dat""\n");
    else{
        imprimir (d);
        printf ("\nIngrese el ID de este contacto:\t");
        fflush (stdin);
        scanf ("%d", &id);
        fseek (fp, 0L, 0);
        fread (&bf, sizeof (datos_t), 1, fp);
        while (!feof(fp)){
            while (bf.id == id){
                printf ("\nID ya ingresado, ingrese uno nuevo: \t");
                fflush (stdin);
                scanf ("%d", &id);
            }
        fread (&bf, sizeof (datos_t), 1, fp);   
        }
        d.id = id;
        darchivo = d;
        fseek (fp, 0L, 2);
        //fwrite (&darchivo, sizeof(darchivo_t), 1, fp);
        if ((fwrite (&darchivo, sizeof(datos_t), 1, fp))==1)
        printf ("\nSe archivo el contacto con ID: %.4d\n", darchivo.id);
    }
    fclose (fp);
    return;
}

void imprimir (datos_t dt){
    printf ("\n Nombre: %s", dt.nombre);
    printf ("\n Apellido: %s", dt.apellido);
    printf ("\n Edad: %d", dt.edad);
    printf ("\n Telefono: %ld", dt.tel);
    printf ("\n Email: %s\n", dt.email);
    return;
}

