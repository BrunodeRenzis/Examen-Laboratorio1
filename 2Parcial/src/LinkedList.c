#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL){
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
		Node* pNode = NULL;

		if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
		{
			pNode = this->pFirstNode;
			for(int i=0;i<nodeIndex;i++){
				pNode = pNode->pNextNode;
			}
		}

	    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;

	    Node* nuevoNodo = (Node*) malloc(sizeof(Node)); //Pido espacio en memoria para el nuevo Nodo
	    Node* auxNodo = NULL; //El nodo al no estar asignado apuntará a NULL

	    if(this != NULL && nodeIndex >= 0 && nodeIndex <= this->size && nuevoNodo != NULL)
	    {

	        nuevoNodo->pElement = pElement; //El nuevo nodo apuntará a la estructura asignada
	        nuevoNodo->pNextNode = NULL; // El nodo al no estar asignado apuntará a NULL
	        this->size++; //Aumenta el tamaño de la LL
	        returnAux = 0;

	        if(nodeIndex == 0 && this->size == 0)
	        {
	            this->pFirstNode = nuevoNodo; //Si no hay elementos en la lista, el nuevo nodo se asigna a la 1 posicion
	        }

	        else if(nodeIndex == 0 && this->size!=0)
	        {
	                auxNodo = getNode(this, 0); //Guardo el primer nodo en el Aux
	                this->pFirstNode = nuevoNodo; //El nuevo Nodo es el 1 item de la lista
	                nuevoNodo->pNextNode = auxNodo; //AuxNodo es el 2 item de la lista
	        }

	        else if(nodeIndex == this->size)
	        {
	                    auxNodo = getNode(this, nodeIndex-1);  //Guardo el nodo anterior en el Aux
	                    auxNodo->pNextNode = nuevoNodo; // Coloco el nuevo nodo al final de la lista
	        }

	        else
	        {
	                    auxNodo = getNode(this, nodeIndex-1);
	                    auxNodo->pNextNode = nuevoNodo; //Intercambio posiciones del nuevo Nodo con el aux
	                    nuevoNodo->pNextNode = auxNodo; //Intercambio posiciones del nuevo Nodo con el aux
	        }

	   }


	    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	addNode(this,ll_len(this),pElement);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoAux;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	nodoAux = getNode(this,index);
    	returnAux = nodoAux->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAux;
	if(this!=NULL && index>=0 && index<ll_len(this))
	{
		nodoAux=getNode(this,index);
		nodoAux->pElement = pElement;
		returnAux=0;
	}

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAux;
    Node* nodoEliminar;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	nodoEliminar = getNode(this,index);
    	if(index == 0)
    	{
    		this->pFirstNode=nodoEliminar->pNextNode;

    	}
    	else
    	{
    		nodoAux = getNode(this,index-1);
    		nodoAux->pNextNode=nodoEliminar->pNextNode;
    	}
    	free(nodoEliminar);
   		this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* eliminaNodos;
    Node* auxNodos;

    if(this!=NULL && this->size>0)
    {
		for(int i=0;i<ll_len(this);i++)
		{
			eliminaNodos=getNode(this,i);
			if(eliminaNodos!=NULL)
			{
				auxNodos = eliminaNodos->pNextNode;
				this->size--;
				free(eliminaNodos);
			}

			free(auxNodos);
		}
			this->pFirstNode=NULL;

			if(this->size==0)
	    	{
	    		returnAux = 0;
	    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodoAux;
    if(this!=NULL)
    {
    	nodoAux=this->pFirstNode;
    	for(int i=0;i<ll_len(this);i++)
    	{
    		if(nodoAux->pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    		nodoAux = nodoAux->pNextNode;
    	}
    }
    	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL && ll_len(this)==0)
    {
    	returnAux=1;
    }
    else if(this!=NULL && ll_len(this)>0)
    {
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
    	addNode(this,index,pElement);
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	returnAux=ll_get(this,index);
    	ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement){
    int returnAux = -1;

    if(this!=NULL)
    {
    	if(ll_indexOf(this,pElement)>=0)

    		returnAux=1;

    	else

    		returnAux = 0;

    }

    return returnAux;
}


/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	    int contador = 0;
	    int i;
	    Node* auxNodo;

	    if(this != NULL && this2 != NULL)
	    {
	        if(this->size >= this2->size)
	        {
	            for(i = 0; i < this2->size; i++)
	            {
	                auxNodo = ll_get(this2,i);
	                if(ll_contains(this,auxNodo))
	                {
	                    contador++;
	                }
	            }
	        }

	        if(contador == this2->size)
	        {
	            returnAux = 1;
	        }

	        else
	        {
	            returnAux = 0;
	        }
	    }

	    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* auxElement=NULL;

    if(this!=NULL && from>=0 && from<=to && to<=ll_len(this))
    {
    	cloneArray = ll_newLinkedList();

		if(cloneArray!=NULL)
		{
			for(int i=from;i<to;i++)
			{
				auxElement=ll_get(this,i);
				ll_add(cloneArray,auxElement);
			}
		}


    }


    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL)
    {
    	cloneArray=ll_subList(this,0,ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
		int returnAux =-1;
	    void* aux;
	    void* auxI;
	    void* auxJ;

	    if (this != NULL && this->size > 1 && (order == 1 || order == 0) && pFunc != NULL)
	    {
	        returnAux = 0;
	        for(int i = 0; i < this->size - 1; i++)
	        {
	            for(int j = i + 1; j < this->size; j++)
	            {
	                auxI = ll_get(this, i);
	                auxJ = ll_get(this, j);

	                if(order == 0)
	                {
	                    if( pFunc(auxI, auxJ) == -1 )
	                    {
	                        aux = auxI;
	                        ll_set(this, i, auxJ);
	                        ll_set(this, j, aux);
	                    }
	                }

	                else if(order == 1)
	                {
	                    if( pFunc(auxI, auxJ) == 1 )
	                    {
	                        aux = auxI;
	                        ll_set(this, i, auxJ);
	                        ll_set(this, j, aux);
	                    }
	                }
	            }
	        }
	    }

	    return returnAux;

}

LinkedList* ll_map(LinkedList* this, void* (*pFunc)(void*))
{
    LinkedList* pAux = NULL;
    void* pAuxElement = NULL;
    int len=ll_len(this);
    if(this!=NULL &&len>0)
    {
        pAux=ll_newLinkedList();
        if(pAux!=NULL)
        {
            for(int i=0; i<len; i++)
            {
                pAuxElement=ll_get(this, i);
                if(pAuxElement!=NULL)
                {
                    pAuxElement=pFunc(pAuxElement);
                    ll_add(pAux,pAuxElement);
                }
            }
        }
    }
    return pAux;
}



LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* pAux = NULL;
    void* pAuxElement = NULL;
    int len=ll_len(this);
    if(this != NULL &&len>0)
    {
        pAux = ll_newLinkedList();
        if(pAux != NULL)
        {
            for(int i=0; i<len; i++)
            {
                pAuxElement=ll_get(this, i);
                if(pAuxElement!=NULL)
                {
                    if(pFunc(pAuxElement)==1)
                    {
                        ll_add(pAux,pAuxElement);
                    }
                }

            }
        }
    }
    return pAux;
}

void* ll_reduce(LinkedList* this, void*(*pFunc)(void*, void*),void* total)
{
    void* pAuxElement = NULL;
    int i;
    int len=ll_len(this);
    if(this != NULL && len> 0)
    {
        for(i = 0; i <len; i++)
        {
            pAuxElement = ll_get(this, i);
            total = pFunc(total,pAuxElement);
        }
    }
    return total;
}

int ll_count(LinkedList* this,int (*pFunc)(void*))
{
	int total=0;
	int len=ll_len(this);
	if(this!=NULL && len >=0)
	{
		for(int i=0;i<len;i++)
		{
			total+=pFunc(ll_get(this,i));

		}
	}
	return total;
}
