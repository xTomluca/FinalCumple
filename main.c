#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Parser.h"
#include "Localidades.h"
#include "Pedidos.h"
#include "Controller.h"
int main()
{
    ArrayList* pPedidos = al_newArrayList();
    ArrayList* pLocalidades = al_newArrayList();
    int opcion;
    char seguir='s';
    do
    {
        getValidInt("\n1) Cargar archivos\n\n2) Imprimir entregas\n\n3) Imprimir localidades\n\n4) Generar archivo de reparto para localidad\n\n5) Salir\n\n","\n\t\tERROR!\n",&opcion,1,5,1);
        switch(opcion)
        {
            case 1:
                if(!parser_Deposito(pPedidos))
                    printf("\n\t\tPARSEO EXITOSO!!\n");
                break;
            case 2:
                imprimirLista(pPedidos);
                break;
            case 3:
                listarLocalidades(pPedidos,pLocalidades);
                break;
            case 4:
                guardarPedidos(pPedidos);
                break;
            case 5:
                seguir='n';
                break;
        }
    }while(seguir!='n');

    return 0;
}
