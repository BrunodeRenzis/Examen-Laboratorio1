#include "eArticulos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "utn.h"
#include "LinkedList.h"


void eArticulo_delete(eArticulo* this)
{
    if(this!=NULL)
    {
        free(this);
    }

}
///////////////////////FUNCION SET Y GET ID
int eArticulo_setId(eArticulo* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id>0)
    {
        this->id_articulo=id;
        todoOk=1;
    }

    return todoOk;
}

int eArticulo_getId(eArticulo* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id_articulo;
        todoOk=1;
    }
    return todoOk;
}
///////////////////////////////////////////////


////////////////////////////////////////////////SET Y GET NOMBRE
int eArticulo_setArticulo(eArticulo* this,char* auxArticulo)
{
    int todoOk=0;
    if(this!=NULL && auxArticulo!=NULL)
    {
        strcpy(this->nombreArticulo,auxArticulo);
        todoOk=1;
    }
    return todoOk;
}

int eArticulo_getArticulo(eArticulo* this,char* auxArticulo)
{
    int todoOk=0;
    if(this!=NULL && auxArticulo!=NULL)
    {
        strcpy(auxArticulo, this->nombreArticulo);
        todoOk=1;
    }
    return todoOk;
}
//////////////////////////////////////////////////////

////////////////////////////////////////////GET Y SET DIAS
int eArticulo_setRubroId(eArticulo* this,int auxRubro)
{
    int todoOk=0;
    if(this!=NULL && auxRubro>=0)
    {
        this->rubroId=auxRubro;
        todoOk=1;
    }
    return todoOk;
}

int eArticulo_getRubroId(eArticulo* this,int* auxRubro)
{
    int todoOk=0;
    if(this!=NULL && auxRubro!=NULL)
    {
        *auxRubro=this->rubroId;
        todoOk=1;
    }
    return todoOk;
}

int eArticulo_setMedida(eArticulo* this,char* auxMedida)
{
    int todoOk=0;

    if(this!=NULL && auxMedida!=NULL)
    {
        strcpy(this->medida,auxMedida);
        todoOk=1;
    }

    return todoOk;
}

int eArticulo_getMedida(eArticulo* this,char* auxMedida)
{

    int todoOk=0;
    if(this!=NULL)
    {
        strcpy(auxMedida,this->medida);
        todoOk=1;
    }
    return todoOk;
}


int eArticulo_setPrecio(eArticulo* this, float auxPrecio)
{
    int todoOk=0;

    if(this!=NULL)
    {
    	this->precio=auxPrecio;
        todoOk=1;
    }

    return todoOk;
}

int eArticulo_getPrecio(eArticulo* this, float* auxPrecio)
{
    int todoOk=0;

    if(this!=NULL && auxPrecio!=NULL)
    {
    	*auxPrecio=this->precio;
        todoOk=1;
    }

    return todoOk;
}
///////////////////////////////////////////////////////////////



eArticulo* eArticulo_new()
{
    eArticulo* newArticulo;
    newArticulo = (eArticulo*) malloc(sizeof(eArticulo));
    if(newArticulo != NULL)
    {
        newArticulo->id_articulo = 0;
        strcpy(newArticulo->nombreArticulo," ");
        strcpy(newArticulo->medida," ");
        newArticulo->precio=0;
        newArticulo->rubroId=0;
    }

    else
    {
        eArticulo_delete(newArticulo);
        newArticulo=NULL;
    }
    return newArticulo;

}


eArticulo* eVenta_newParametros(char* idStr,char* nombreStr,char* medidaStr,char* precioStr,char* rubroIdStr)
{
    eArticulo* newVenta;
    newVenta=eArticulo_new();
    if(idStr!=NULL && precioStr!=NULL && rubroIdStr!=NULL && medidaStr!=NULL &&nombreStr!=NULL)
    {
        if(eArticulo_setId(newVenta,atoi(idStr))==0||
                eArticulo_setMedida(newVenta,medidaStr)==0||
                eArticulo_setRubroId(newVenta,atoi(rubroIdStr))==0||
                eArticulo_setPrecio(newVenta,atof(precioStr))==0||
                eArticulo_setArticulo(newVenta,nombreStr)==0)
        {
            eArticulo_delete(newVenta);
            newVenta=NULL;
        }
    }
    return newVenta;
}

int eVenta_isValid(eArticulo* pAux)
{
    int todoOk=0,id,rubroId;
    float precio;
    char medida[50];
    char nombre[150];

    if(pAux!=NULL)
    {
        eArticulo_getId(pAux,&id);
        eArticulo_getArticulo(pAux,nombre);
        eArticulo_getRubroId(pAux,&rubroId);
        eArticulo_getMedida(pAux,medida);
        eArticulo_getPrecio(pAux,&precio);
        if(id>0 && rubroId >0 && rubroId<=4 && medida!=NULL && nombre !=NULL && precio>0)
        {
            todoOk=1;
        }
    }
    return todoOk;
}

void showHeaderArticulos()
{
	printf("ID                            ARTICULO                      MEDIDA       PRECIO               RUBRO\n");
}

void descRubro(char* auxRubro,int* rubro)
{


		switch (*rubro)
		{

			case 1:
				strcpy(auxRubro,"CUIDADO DE ROPA");
				break;

			case 2:
				strcpy(auxRubro,"LIMPIEZA Y DESINFECCION");
				break;

			case 3:
				strcpy(auxRubro,"CUIDADO PERSONAL E HIGIENE");
				break;

			case 4:
				strcpy(auxRubro,"CUIDADO DEL AUTOMOTOR");
				break;

		}

}

int printArticulos(eArticulo* this)
{
    int todoOk=0,id,idRubro;
    char nombre[150], medida[50],rubroDesc[50];
    float precio;

    if(this!=NULL)
    {
        eArticulo_getId(this,&id);
        eArticulo_getArticulo(this,nombre);
        eArticulo_getMedida(this,medida);
        eArticulo_getPrecio(this,&precio);
        eArticulo_getRubroId(this,&idRubro);
        descRubro(rubroDesc,&idRubro);
        printf("%d %42s %20s %12.2f %30s\n",id,nombre,medida,precio,rubroDesc);
        todoOk=1;
    }

    return todoOk;
}

int eArticulo_sortByArt(void* artA, void* artB){
	int todoOk=-1;
	eArticulo* art1=NULL;
	eArticulo* art2=NULL;
	char articulo1[150];
	char articulo2[150];


	if(artA!=NULL && artB!=NULL){
		art1=(eArticulo*)artA;
		art2=(eArticulo*)artB;
		eArticulo_getArticulo(art1,articulo1);
		eArticulo_getArticulo(art2,articulo2);
		if(stricmp(articulo1,articulo2)==1)
		{
			todoOk=1;
		}

		else if(stricmp(articulo1,articulo2)==-1){
			todoOk=0;
		}

	}
	return todoOk;
}

void* eArticulo_llMap(void* pAux)
{

    if(pAux!= NULL)
    {
    	float precio;
        eArticulo* articulo=(eArticulo*)pAux;
        int rubroId;
        eArticulo_getRubroId(articulo,&rubroId);
        eArticulo_getPrecio(articulo,&precio);

        if(rubroId==1 && precio>=120)
        {
        	precio=precio*0.8;
        }

        else if(rubroId==2 && precio<=200)
        {
        	precio=precio*0.9;
        }

        eArticulo_setPrecio(articulo,precio);
    }
    return pAux;
}
