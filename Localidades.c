#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Localidades.h"
#include "utn.h"

Localidades* Localidades_new()
{
    Localidades* this;
    this=malloc(sizeof(Localidades));
    return this;
}

void Localidades_delete(Localidades* this)
{
    free(this);
}

Localidades* Localidades_newConParametros(char* localidad)
{
    Localidades* this;
    this=Localidades_new();
    if(esSoloLetras(localidad))
    {
        if(
        !Localidades_setLocalidad(this,localidad))
            return this;
    }

    Localidades_delete(this);
    return NULL;
}

int Localidades_setLocalidad(Localidades* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int Localidades_getLocalidad(Localidades* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

