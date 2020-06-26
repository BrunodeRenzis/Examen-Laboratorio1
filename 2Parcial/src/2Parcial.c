/*
 ============================================================================
 Name        : 2Parcial.c
 Author      : Bruno de Renzis
 Version     :
 Copyright   : Bruno de Renzis
 Description : 2 Parcial Programacion UTN
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "Controller.h"
#include "eArticulos.h"
#include "parser.h"
#include "validaciones.h"
#include "Save.h"
#include "utn.h"
#include "informes.h"
int main()
{
	setbuf(stdout,NULL);
    LinkedList* listaArticulos = ll_newLinkedList();
    LinkedList* listaArtConDesc = NULL;
    char seguir='s', path[20];

    if(listaArticulos!=NULL)
    {
        do
        {
            switch(menu())
            {
                case 1:
                    inputStr("Ingrese nombre de archivo: ",path);
                    if(controller_loadFromText(path,listaArticulos)==1)
                    {
                        printf("\nlista cargada correctamente!");
                    }
                    else
                    {
                        printf("Error al cargar los datos");
                    }

                    break;
                case 2:
                    if(!(ll_isEmpty(listaArticulos)==1))
                    {
                    	ll_sort(listaArticulos,eArticulo_sortByArt,1);
                        controller_List(listaArticulos);
                    }
                    else
                    {
                        puts("No se pudo mostrar la lista");
                    }

                    break;

                case 3:
                    if(!(ll_isEmpty(listaArticulos)==1))
                      {
                          listaArtConDesc = ll_map(listaArticulos,eArticulo_llMap);
                          if(listaArticulos!=NULL)
                          {
                              if(saveAsText("mapeado.csv",listaArtConDesc)==1)
                              {
                                  printf("Lista creada");
                              }
                          }
                      }
                      else
                      {
                          printf("Error al cargar los datos");
                      }

                    break;

                case 4:
                	if(!(ll_isEmpty(listaArticulos)==1))
                	{
                		informes(listaArticulos);
                	}

                	else
                	{
                	  printf("Error al cargar los datos");
                	}

                	break;

                case 5:
                    seguir='n';
                    break;
           }
             system("pause");

           }while(seguir=='s');

    }
    return 0;
}
