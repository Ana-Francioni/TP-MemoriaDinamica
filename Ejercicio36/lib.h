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



struct lista{
    datos_t inf;
    struct lista *l;
};

typedef enum {
    l_sin_inf = 0,
    l_con_inf = 1,
} lista_t;

#endif