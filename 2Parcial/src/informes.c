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



int precioArticulosMayoresA100(void* pElement)
{
	int returnAux=0;
	float precio;

	if(pElement!=NULL)
	{
		pElement=(eArticulo*) pElement;
		eArticulo_getPrecio(pElement,&precio);

		if(precio>100)
		{
			returnAux=1;
		}
	}
	return returnAux;
}

int rubroCuidadoRopa(void* pElement)
{
	int returnAux=0;
	int rubroId;

	if(pElement!=NULL)
	{
		pElement=(eArticulo*) pElement;
		eArticulo_getRubroId(pElement,&rubroId);

		if(rubroId==1)
		{
			returnAux=1;
		}
	}
	return returnAux;
}


int menuInformes()
{
	int option;
	printf("1- Precio articulos mayores a 100 \n  2-Articulos cuidado de ropa \n 3-Salir \n");
	option=inputValidInt("Ingrese una opcion: ", "\n Ha ingresado una opcion incorrecta. Intente nuevamente", 1, 3, 2);
	return option;
}

void informes(LinkedList* this)
{
	char seguir ='s';

	do{
		switch(menuInformes())
		{
			case 1:
				printf("La cantidad de articulos cuyo precio es mayor a 100 es: %d \n",ll_count(this, precioArticulosMayoresA100));
				break;

			case 2:
				printf("La cantidad de articulos del rubro cuidado ropa es: %d \n",ll_count(this, rubroCuidadoRopa));
				break;

			case 3:
				seguir='n';
				break;
		}
			system("pause");
			system("cls");
	  }while(seguir=='s');
}
