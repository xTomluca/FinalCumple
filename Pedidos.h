#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED
typedef struct
{
    	int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
}Pedidos;

Pedidos* Pedidos_new();
void Pedidos_delete();
Pedidos* Pedidos_newConParametros(	int id,char* producto,char* direccion,char* localidad,char* recibe);
Pedidos* Pedidos_newConParametrosStr(char* idStr,char* producto,char* direccion,char* localidad,char* recibe);

int Pedidos_setId(Pedidos* this,	int id);
int Pedidos_getId(Pedidos* this,	int* id);

int Pedidos_setProducto(Pedidos* this,char* producto);
int Pedidos_getProducto(Pedidos* this,char* producto);

int Pedidos_setDireccion(Pedidos* this,char* direccion);
int Pedidos_getDireccion(Pedidos* this,char* direccion);

int Pedidos_setLocalidad(Pedidos* this,char* localidad);
int Pedidos_getLocalidad(Pedidos* this,char* localidad);

int Pedidos_setRecibe(Pedidos* this,char* recibe);
int Pedidos_getRecibe(Pedidos* this,char* recibe);

#endif // PEDIDOS_H_INCLUDED
