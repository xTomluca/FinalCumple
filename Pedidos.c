#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pedidos.h"

Pedidos* Pedidos_new()
{
    Pedidos* this;
    this=malloc(sizeof(Pedidos));
    return this;
}

void Pedidos_delete(Pedidos* this)
{
    free(this);
}

Pedidos* Pedidos_newConParametros(	int id,char* producto,char* direccion,char* localidad,char* recibe)
{
    Pedidos* this;
    this=Pedidos_new();

    if(
    !Pedidos_setId(this,id)&&
    !Pedidos_setProducto(this,producto)&&
    !Pedidos_setDireccion(this,direccion)&&
    !Pedidos_setLocalidad(this,localidad)&&
    !Pedidos_setRecibe(this,recibe))
        return this;

    Pedidos_delete(this);
    return NULL;
}
Pedidos* Pedidos_newConParametrosStr(char* idStr,char* producto,char* direccion,char* localidad,char* recibe)
{
    Pedidos* this;
    this=Pedidos_new();
    int id;
    if(esNumerico(idStr)&&esSoloLetras(producto)&&esSoloLetras(localidad)&&esSoloLetras(recibe)&&esAlfaNumerico(direccion))
    {
        id=atoi(idStr);
        if(
        !Pedidos_setId(this,id)&&
        !Pedidos_setProducto(this,producto)&&
        !Pedidos_setDireccion(this,direccion)&&
        !Pedidos_setLocalidad(this,localidad)&&
        !Pedidos_setRecibe(this,recibe))
            return this;
    }
    Pedidos_delete(this);
    return NULL;
}

int Pedidos_setId(Pedidos* this,	int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Pedidos_getId(Pedidos* this,	int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Pedidos_setProducto(Pedidos* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int Pedidos_getProducto(Pedidos* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int Pedidos_setDireccion(Pedidos* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

int Pedidos_getDireccion(Pedidos* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(direccion,this->direccion);
        retorno=0;
    }
    return retorno;
}

int Pedidos_setLocalidad(Pedidos* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int Pedidos_getLocalidad(Pedidos* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

int Pedidos_setRecibe(Pedidos* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

int Pedidos_getRecibe(Pedidos* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(recibe,this->recibe);
        retorno=0;
    }
    return retorno;
}

