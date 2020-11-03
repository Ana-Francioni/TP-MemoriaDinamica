#ifndef __LIB_H_
#define __LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    int id;
    char nombre[20];
    char apellido [20];
    char edad;
    long tel;
    char email [30];

} datos_t;

struct pila{
    datos_t datos;
    struct pila *p;
};



void bienvenida (void);
int menu (void);
void leerdat (datos_t *);
struct pila * apilar (struct pila **, struct pila *, datos_t);
void desapilar (struct pila **);
void archivar (datos_t);
void imprimir (datos_t);
int id (void);

#endif