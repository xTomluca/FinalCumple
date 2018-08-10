#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Pedidos.h"
#include "Controller.h"
#include "utn.h"

/** \brief AGREGA ELEMENTOS AL ARRAYLIST DESDE ARCHIVO CSV
 *
 * \param pArray ArrayList* PUNTERO A ARRAYLIST PEDIDOS
 * \return int RETORNA [-1] ERROR
 *                     [ 0] PARSEO EXITOSO!
 */
int parser_Deposito(ArrayList* pArray)
{
    Pedidos* aux;
    int retorno=-1;
    char id[128];
    char fileName[128];
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    int cantidadLeida;
    FILE* fp;
    getString("\nINGRESE NOMBRE DE ARCHIVO SIN FORMATO: ",fileName);
    strcat(fileName,".csv");
    fp = fopen(fileName,"r");
    if(fp==NULL)
        printf("\n\t\t\tERROR AL ABRIR ARCHIVO\n");
    if(fp!=NULL && pArray!=NULL)
    {
        fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,producto,direccion,localidad,recibe);
        while(!feof(fp))
        {
            cantidadLeida = fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,producto,direccion,localidad,recibe);
            if(cantidadLeida==5)
            {
                aux = Pedidos_newConParametrosStr(id,producto,direccion,localidad,recibe);
                if(aux!=NULL)
                {
                    al_add(pArray,aux);
                    retorno = 0;
                }
            }
        }
    }
    fclose(fp);

    return retorno;
}
