#ifndef LOCALIDADES_H_INCLUDED
#define LOCALIDADES_H_INCLUDED
typedef struct
{
    char localidad[128];
}Localidades;

Localidades* Localidades_new();
void Localidades_delete();
Localidades* Localidades_newConParametros(char* localidad);

int Localidades_setLocalidad(Localidades* this,char* localidad);
int Localidades_getLocalidad(Localidades* this,char* localidad);

#endif // LOCALIDADES_H_INCLUDED
