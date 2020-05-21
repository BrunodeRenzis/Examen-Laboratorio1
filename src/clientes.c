#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamos.h"
#include "clientes.h"
eClientes newCliente(int clienteId,char clienteNombre[],char clienteApellido[],char clienteCuil[])
{

    eClientes cliente;
    cliente.clienteId = clienteId;
    strcpy(cliente.clienteNombre,clienteNombre);
    strcpy(cliente.clienteApellido,clienteApellido);
    strcpy(cliente.clienteCuil,clienteCuil);
    cliente.isEmpty = 0;

    return cliente;
}

void initClientes(eClientes vecClientes[],int tamClientes)
{
    for(int i=0; i<tamClientes; i++)
    {
        vecClientes[i].isEmpty=1;
        vecClientes[i].clienteId=0;
        strcpy(vecClientes[i].clienteNombre," ");
        strcpy(vecClientes[i].clienteApellido," ");
        strcpy(vecClientes[i].clienteCuil," ");
    }
}

int findFree(eClientes vecClientes[],int tamClientes)
{
    int emptySpace=-1;
    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].isEmpty==1)
        {
            emptySpace=i;
            printf("\nSe ha asignado la posicion %d\n",i);
            break;
        }
    }

    return emptySpace;
}

int automaticIdClientes()
{
    static int clienteId=1000;
    return clienteId++;
}

int getActiveClientes(eClientes vecClientes[],int tamClientes)
{
    int activeCounter=0;
    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].isEmpty==0)
        {
            activeCounter++;
        }
    }
    return activeCounter;
}


void showHeaderClientes()
{
    msg("    ID      NOMBRE      APELLIDO      CUIL          CANTIDAD PRESTAMOS ACTIVOS ");

}

void showHeaderClientesSaldados()
{
    msg("    ID      NOMBRE      APELLIDO      CUIL          CANTIDAD PRESTAMOS SALDADOS");

}



int getCuilCliente(eClientes vecClientes[],int tamClientes,int idCliente,char* cuilCliente){
	int retorno=-1;

	for(int i=0;i<tamClientes;i++){
		if(vecClientes[i].clienteId==idCliente){
			strcpy(cuilCliente,vecClientes[i].clienteCuil);
			retorno=0;
			break;
		}
	}
	return retorno;
}

int addCliente(eClientes vecClientes[],int tamClientes)
{
    char name[NOMBRETAM],lastName[APELLIDOTAM];
    int emptySpace;
    int clienteId=automaticIdClientes();
    char cuil[CUIL];

    emptySpace=findFree(vecClientes,tamClientes);

    if(emptySpace==-1)
    {
        printf("No hay mas lugar para agregar abonados");
    }
    else
    {
        /** 1- Pido datos personales*/
        utn_getString(name,NOMBRETAM,3,"Ingrese un nombre: ","Ese no es un nombre valido");
        utn_getString(lastName,APELLIDOTAM,3,"Ingrese un apellido: ","Ese no es un apellido valido");
        isValidCuit(cuil,"Ingrese numero de cuil xx-xxxxxxxx-x: ","Error, ha ingresado mal el cuit. Intente nuevamente: ",5);
        vecClientes[emptySpace]=newCliente(clienteId,name,lastName,cuil);

        printf("Cliente registrado! Se lo ha registrado con el id: %d\n",clienteId);

    }
    return emptySpace;
}

void showCliente(eClientes unCliente,ePrestamos vecPrestamos[],int tamPrestamos)
{
    int cantidadPrestamosCliente=0;
    cantidadPrestamosCliente=cantidadPrestamosUnCliente(vecPrestamos,tamPrestamos,unCliente.clienteId);
    printf("\n %5d %10s %15s %10s %10d\n",unCliente.clienteId,unCliente.clienteNombre,unCliente.clienteApellido,unCliente.clienteCuil,cantidadPrestamosCliente);
}

void showClientePrestamosSaldados(eClientes unCliente,ePrestamos vecPrestamos[],int tamPrestamos)
{
    int cantidadPrestamosSaldadosCliente=0;
    cantidadPrestamosSaldadosCliente=cantidadPrestamosSaldadosUnCliente(vecPrestamos,tamPrestamos,unCliente.clienteId);
    printf("\n %5d %10s %15s %10s %10d\n",unCliente.clienteId,unCliente.clienteNombre,unCliente.clienteApellido,unCliente.clienteCuil,cantidadPrestamosSaldadosCliente);
}

void showClientes(eClientes vecClientes[],int tamClientes,ePrestamos vecPrestamos[],int tamPrestamos)
{
    showHeaderClientes();
    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].isEmpty==0)
        {
            showCliente(vecClientes[i],vecPrestamos,tamPrestamos);
        }
    }
}

int findClienteById(eClientes vecClientes[],int tamClientes,int* idCliente)
{

    *idCliente=inputInt("Ingrese numero de cliente: ");
    int indice=-1;
    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].clienteId==*idCliente)
        {
            printf("El cliente es: %s %s",vecClientes[i].clienteNombre,vecClientes[i].clienteApellido);
            indice=i;
            break;
        }
        else
        {
            continue;
        }
    }
    if(indice==-1)
    {
        msg("No se ha encontrado el id!");
    }
    return indice;
}


int contadorTotalClientes(eClientes vecClientes[],int tamClientes){

    int contadorTotal=0;

    for(int i=0;i<tamClientes;i++){
        if( (vecClientes[i].isEmpty==0) || (vecClientes[i].isEmpty==1 && vecClientes[i].clienteId==-1)){
            contadorTotal++;
        }
    }
    return contadorTotal;
}

int obtenerUltimoIdRegistrado(eClientes vecClientes[],int tamClientes,int* ultimoId){
    int retorno=-1;

    for(int i=0;i<tamClientes;i++){
        if(vecClientes[i].isEmpty==0){
            *ultimoId=vecClientes[i].clienteId;
            retorno=0;
        }
    }

    return retorno;
}

int obtenerPrimerIdRegistrado(eClientes vecClientes[],int tamClientes,int* primerId){
    int retorno=-1;

    for(int i=0;i<tamClientes;i++){
        if(vecClientes[i].isEmpty==0){
            *primerId=vecClientes[i].clienteId;
            retorno=0;
            break;
        }
    }

    return retorno;
}


int removeCliente(eClientes vecClientes[],int tamClientes,ePrestamos vecPrestamos[],int tamPrestamos,int* idCliente)
{
    int todoOk=-1;
    char respuesta;
    int remove;
    showClientes(vecClientes,tamClientes,vecPrestamos,tamPrestamos);
    remove=findClienteById(vecClientes,tamClientes,idCliente);

    if(remove!=-1)
    {
        printf("\n\nPrestamos de: %s %s: \n",vecClientes[remove].clienteNombre,vecClientes[remove].clienteApellido);

        mostrarPrestamosDeUnCliente(vecClientes,vecPrestamos,tamClientes,tamPrestamos,idCliente);
        respuesta=inputChar("\nDesdea eliminar este cliente? s/n: ");

        if(respuesta=='s')
        {
            for(int i=0; i<tamClientes; i++)
            {
                if(vecClientes[i].clienteId==*idCliente)
                {
                    vecClientes[i].isEmpty=1;
                    vecClientes[i].clienteId=-1;
                    strcpy(vecClientes[i].clienteNombre," ");
                    strcpy(vecClientes[i].clienteApellido," ");
                    strcpy(vecClientes[i].clienteCuil," ");
                }


                for(int j=0; j<tamPrestamos; j++)
                {
                    if(vecPrestamos[j].clienteId==*idCliente)
                    {
                        vecPrestamos[j].isEmpty=1;
                        vecPrestamos[j].clienteId=-1;
                        vecPrestamos[j].prestamoCuotas=0;
                        vecPrestamos[j].prestamoEstado=INACTIVO;
                        vecPrestamos[j].prestamoId=0;
                        vecPrestamos[j].prestamoImporte=0;

                    }
                }

            }
            msg(" Ha sido removido");

        }
        else
        {
            printf("Baja anulada");
        }
        todoOk=1;

    }

    else{
        msg("   Intente con otro id!\n");
    }

    return todoOk;
}


int modificationMenu()
{
    int option;
    printf("\n1-Modificar Nombre\n2-Modificar Apellido\n3-Modificar CUIL\n4-Salir");
    option=inputValidInt("\nIngrese opcion: ","Error ingrese un numero valido: ",1,4,4);
    return option;
}


int modifyCliente(eClientes vecClientes[],int tamClientes,int id,ePrestamos vecPrestamos[],int tamPrestamos)
{
    int todoOk=1;
    int idCliente=0;
    int loop=1;
    int modify;
    char seguir='s';
    char nuevoNombre[NOMBRETAM];
    char nuevoApellido[APELLIDOTAM];
    char nuevoCuil[CUIL];
    showClientes(vecClientes,tamClientes,vecPrestamos,tamPrestamos);
    modify=findClienteById(vecClientes,tamClientes,&idCliente);

    if(modify!=-1)
    {


			do
			{
				switch(modificationMenu())
				{
				case 1:
					utn_getString(nuevoNombre,NOMBRETAM,4,"Ingrese nuevo nombre: ","Error, ha ingresado un nombre invalido, intente nuevamente: ");
					strcpy(vecClientes[modify].clienteNombre,nuevoNombre);
					todoOk=1;
					break;

				case 2:
					utn_getString(nuevoApellido,APELLIDOTAM,4,"Ingrese nuevo apellido: ","Error, ha ingresado un apellido invalido, intente nuevamente: ");
					strcpy(vecClientes[modify].clienteApellido,nuevoApellido);
					todoOk=1;
					break;


				case 3:
					isValidCuit(nuevoCuil,"Ingrese nuevo cuit xx-xxxxxxxx-x: ","No ha ingresado un cuit valido, intente nuevamente: ",5);
					strcpy(vecClientes[modify].clienteCuil,nuevoCuil);
					break;

				case 4:
					loop=0;
					break;

				}
				printf("Desea realizar mas modificaciones? S/N");
				scanf("%c",&seguir);
				if(seguir=='n' || seguir=='N')
				{
					loop=0;
				}
			}
			while(loop==1);

   }
    else
    {
    	printf(" Intente con otro id.\n");
    }
	return todoOk;
}

