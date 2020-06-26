#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#include "eArticulos.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int todoOk=0;
    if(path!=NULL && pArrayList!=NULL)
    {
        strcat(path,".csv");
        f=fopen(path,"r");
        if(f!=NULL){
            parser_FromText(f,pArrayList);
            fclose(f);
            todoOk=1;
        }else{
            todoOk=0;
        }
    }
    return todoOk;
}



int controller_List(LinkedList* pArrayList)
{
    eArticulo* aux;
    int todoOk=0;
    int len;

    if(pArrayList!=NULL){
        len=ll_len(pArrayList);
        showHeaderArticulos();
        for(int i=0;i<len;i++){
            aux=(eArticulo*)ll_get(pArrayList,i);
            printArticulos(aux);
            todoOk=1;
        }
    }

    return todoOk;
}

int controller_sortArticulos(LinkedList* artList)
{

	int todoOk=-1;
	if(artList!=NULL)
	{
		if(ll_len(artList)>0)
		{
			ll_sort(artList,eArticulo_sortByArt,1);
			todoOk=1;
		}
	}

	else{
		msg("\nLa lista en el sort tira null");
	}

    return todoOk;
}
