typedef struct
{
    int id_articulo;
    char nombreArticulo[150];
    char medida[50];
    float precio;
    int rubroId;
}eArticulo;
#include "LinkedList.h"

void eArticulo_delete(eArticulo* this);
eArticulo* mapearArticulos(eArticulo* this);
int eArticulo_setId(eArticulo* this,int id);
int eArticulo_getId(eArticulo* this,int* id);
int eArticulo_setArticulo(eArticulo* this,char* auxArticulo);
int eArticulo_getArticulo(eArticulo* this,char* auxArticulo);
int eArticulo_setMedida(eArticulo* this,char* auxMedida);
int eArticulo_getMedida(eArticulo* this,char* auxMedida);
int eArticulo_setRubroId(eArticulo* this,int auxRubroId);
int eArticulo_getRubroId(eArticulo* this,int* auxRubroId);
int eArticulo_setPrecio(eArticulo* this, float auxPrecio);
int eArticulo_getPrecio(eArticulo* this, float* auxPrecio);
eArticulo* eArticulo_new();
eArticulo* eVenta_newParametros(char* idStr,char* nombreStr,char* medidaStr,char* precioStr,char* rubroIdStr);
int eArticulo_isValid(eArticulo* pAux);
void showHeaderArticulos();
int printArticulos(eArticulo* this);
void* eArticulo_llMap(void* pAux);
void descRubro(char* auxRubroId,int* dia);
int eArticulo_sortByArt(void* artA, void* artB);
void* eArticulo_llMap(void* pAux);
