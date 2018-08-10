#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Localidades.h"
#include "Pedidos.h"
#include "Controller.h"
#include "utn.h"

/** \brief IMPRIME LISTA COMPLETA PEDIDOS
 *
 * \param pPedidos ArrayList* ARRAY PEDIDOS
 * \return void
 *
 */
void imprimirLista(ArrayList* pPedidos)
{
    if(pPedidos!=NULL&&!al_map(pPedidos,imprimirPedido));
    else
        printf("\n\t\tERROR!\n");
}

/** \brief IMPRIME PEDIDO
 *
 * \param pedido void* RECIBE ELEMENTO ARRAYLIST
 * \return void
 *
 */
void imprimirPedido(void* pedido)
{
    Pedidos* aux=NULL;
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    if(pedido!=NULL)
    {
        aux = pedido;
        Pedidos_getId(aux,&id);
        Pedidos_getDireccion(aux,direccion);
        Pedidos_getProducto(aux,producto);
        Pedidos_getLocalidad(aux,localidad);
        Pedidos_getRecibe(aux,recibe);
        printf("%d\t%s\t%s\t%s\t%s\n",id,producto,direccion,localidad,recibe);
    }
    else
        printf("\n\t\tERROR!\n");
}

/** \brief IMPRIMIR LOCALIDAD
 *
 * \param pedido void* RECIBE ELEMENTO DEL ARRAYLIST PEDIDOS
 * \return void
 *
 */
void imprimirLocalidad(void* pedido)
{
    Localidades* aux=NULL;
    char localidad[128];
    if(pedido!=NULL)
    {
        aux = pedido;
        Localidades_getLocalidad(aux,localidad);
        printf("%s\n",localidad);
    }
    else
        printf("\n\t\tERROR!\n");
}

/** \brief LISTA COMPLETA DE LOCALIDADES
 *
 * \param pPedidos ArrayList* RECIBE ARRAYLIST DE PEDIDOS PARA OBTENER LOCALIDAD
 * \param pLocalidades ArrayList* RECIBE ARRAYLIST DE LOCALIDADES A SER CARGADO
 * \return void
 *
 */
void listarLocalidades(ArrayList* pPedidos, ArrayList* pLocalidades)
{
    int i;
    char locPed[128];
    Pedidos* auxPed=NULL;
    Localidades* auxLoc=NULL;
    if(pPedidos!=NULL && pLocalidades!=NULL)
    {
        for(i=0;i<al_len(pPedidos);i++)
        {
            auxPed = al_get(pPedidos,i);
            Pedidos_getLocalidad(auxPed,locPed);
            if(al_len(pLocalidades)==0 && auxPed!=NULL)
            {
                auxLoc = Localidades_newConParametros(locPed);
                if(auxLoc!=NULL&&auxPed!=NULL)
                    al_add(pLocalidades,auxLoc);
            }
            else if(!buscarLocalidad(pLocalidades,locPed))
            {
                auxLoc = Localidades_newConParametros(locPed);
                if(auxLoc!=NULL)
                    al_add(pLocalidades,auxLoc);
            }
        }
        if(al_len(pLocalidades)>0)
            al_map(pLocalidades,imprimirLocalidad);
        else
            printf("\n\t\tERROR!\n");
    }

}

/** \brief VERIFICA SI LA LOCALIDAD PERTENECE AL ARRAYLIST
 *
 * \param pLocalidades ArrayList* ARRAYLIST DE LOCALIDADES A COMPARAR
 * \param locPed char* STRING LOCALIDAD A COMPARAR CON CADA ELEMENTO
 * \return int RETORNA [-1] ERROR
 *                     [ 1] SI LA LOCALIDAD YA FUE CARGADA
 *                     [ 0] SI LA LOCALIDAD DEBE SER CAGADA
 */
int buscarLocalidad(ArrayList* pLocalidades,char* locPed)
{
    Localidades* aux=NULL;
    int i=0;
    int retorno=-1;
    char locLoc[128];
    if(pLocalidades!=NULL && locPed!=NULL)
    {
        for(i=0;i<al_len(pLocalidades);i++)
        {
            aux=al_get(pLocalidades,i);
            if(aux!=NULL)
            {
                Localidades_getLocalidad(aux,locLoc);
                if(strcmp(locLoc,locPed)==0)
                {
                    retorno = 1;
                    break;
                }
                retorno=0;
            }
        }
    }
    return retorno;
}
/** \brief FUNCION UTILIZADA PARA VERIFICAR SI LA LOCALIDAD INGRESADA
 *                                       PERTENECE A LISTA DE PEDIDOS
 * \param pPedidos ArrayList* ARRAYLIST DE PEDIDOS
 * \param auxLocalidad char* LOCALIDAD
 * \return int RETORNA [-1] ERROR
 *                     [ 0] SI LA LOCALIDAD ES VALIDA
 */
int buscarLocalidadPedidos(ArrayList* pPedidos,char* auxLocalidad)
{
    Pedidos* aux=NULL;
    int i=0;
    int retorno=-1;
    char locLoc[128];
    if(pPedidos!=NULL && auxLocalidad!=NULL)
    {
        for(i=0;i<al_len(pPedidos);i++)
        {
            aux=al_get(pPedidos,i);
            if(aux!=NULL)
            {
                Pedidos_getLocalidad(aux,locLoc);
                if(strcmp(locLoc,auxLocalidad)==0)
                {
                    retorno=0;
                    break;
                }
            }
        }
    }
    return retorno;
}
/** \brief ALMACENA PEDIDOS POR LOCALIDAD EN ARCHIVO CSV
 *
 * \param pPedidos ArrayList* ARRAYLIST DE PEDIDOS
 * \param auxLocalidad char* LOCALIDAD
 * \return void
 *
 */
void imprimirPedidosPorLoc(ArrayList* pPedidos,char* auxLocalidad)
{
    Pedidos* aux=NULL;
    int i=0;
    int id;
    char nombreArchivo[128];
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    FILE* fp = NULL;

    if(pPedidos!=NULL&&auxLocalidad!=NULL)
    {
        strcpy(nombreArchivo,auxLocalidad);
        strcat(nombreArchivo,".csv");
        fp = fopen(nombreArchivo,"w");
        if(fp!=NULL)
        {
            fprintf(fp,"id,producto,direccion,localidad,recibe\n");
            for(i=0;i<al_len(pPedidos);i++)
            {
                aux=al_get(pPedidos,i);
                if(aux!=NULL)
                {
                    Pedidos_getLocalidad(aux,localidad);
                    if(strcmp(localidad,auxLocalidad)==0)
                    {
                        Pedidos_getId(aux,&id);
                        Pedidos_getDireccion(aux,direccion);
                        Pedidos_getProducto(aux,producto);
                        Pedidos_getRecibe(aux,recibe);
                        fprintf(fp,"%d,%s,%s,%s,%s\n",id,producto,direccion,localidad,recibe);
                    }
                }
            }
            fclose(fp);
        }


    }
}



/** \brief  PIDE LOCALIDAD Y GENERA ARCHIVO EN CASO DE SER VALIDA
 *
 * \param pPedidos ArrayList* ARRAYLIST PEDIDOS
 * \return void
 *
 */
void guardarPedidos(ArrayList* pPedidos)
{
    int imprimir=0;
    char auxLocalidad[128];
    if(pPedidos!=NULL)
    {
        getString("INGRESE LOCALIDAD: ",auxLocalidad);
        if(!buscarLocalidadPedidos(pPedidos,auxLocalidad))
            imprimir=0;
        else
            printf("\n\t\tERROR!");
        if(!imprimir)
        {
            imprimirPedidosPorLoc(pPedidos,auxLocalidad);
            printf("\n\t\tARCHIVO GENERADO CON EXITO!\n");
        }

    }
}

