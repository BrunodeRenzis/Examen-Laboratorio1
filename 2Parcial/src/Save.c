#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "Controller.h"
#include "eArticulos.h"
#include "parser.h"
#include "validaciones.h"

int saveAsText(char* path , LinkedList* pVentas)
{
    int todoOk = 0;
    int tam = 0;
    int contador = 0;
    int id,rubroId;
    float precio;
    char nombre[150];
    char medida[120];

    FILE* f = NULL;
    eArticulo* venta;

    if( path != NULL && pVentas != NULL )
    {
        tam = ll_len(pVentas);
        f = fopen(path, "w");

        if( f != NULL )
        {
            fprintf(f, "id,articulo,medida,precio,rubro\n");
            char auxRubro[100];

            for(int i=0; i<tam; i++)
            {
                venta = (eArticulo*) ll_get(pVentas, i);
                eArticulo_getId(venta, &id);
                eArticulo_getArticulo(venta, nombre);
                eArticulo_getMedida(venta,medida);
                eArticulo_getPrecio(venta,&precio);
                eArticulo_getRubroId(venta, &rubroId);
                descRubro(auxRubro,&rubroId);
                fprintf(f, "%d,%s,%s,%f,%s\n", id, nombre, medida, precio,auxRubro);
                contador++;
            }


            fclose(f);

            if( contador == tam )
            {
                todoOk = 1;

            }

        }
        else
        {
            printf("No se pudo abrir el archivo de texto.\n");
        }
    }

    return todoOk;
}



/*int saveAsBinary(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int todoOk=0;
    int i;
    int len= ll_len(pArrayList);
    eCachorro* this;
    if(path != NULL && pArrayList!= NULL){
       if(fopen(path,"rb")!=NULL){
             f=fopen(path,"wb");
        }else{
            f=fopen(path,"wb");
        }
        if(f!=NULL){
                for(i=0;i<len;i++){
                    this=ll_get(pArrayList,i);
                    if(this!= NULL)
                        fwrite(this,sizeof(eCachorro),1,f);
                        }
                if(i==len){
                    todoOk=1;
                    fclose(f);
                }else{
                    todoOk=0;
                }
            }
    }

    return todoOk;
}
*/
