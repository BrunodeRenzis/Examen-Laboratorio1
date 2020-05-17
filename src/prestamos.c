#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamos.h"
#include "clientes.h"

void initPrestamos(ePrestamos vecPrestamos[],int tamPrestamos)
{
    for(int i=0; i<tamPrestamos; i++)
    {
        vecPrestamos[i].clienteId=0;
        vecPrestamos[i].prestamoCuotas=0;
        vecPrestamos[i].prestamoEstado=INACTIVO;
        vecPrestamos[i].prestamoId=0;
        vecPrestamos[i].prestamoImporte=0;
        vecPrestamos[i].isEmpty=1;
    }
}

ePrestamos newPrestamo(int clienteId,float prestamoImporte,int prestamoCuotas,int prestamoId)
{
    ePrestamos unPrestamo;

    unPrestamo.clienteId=clienteId;
    unPrestamo.prestamoCuotas=prestamoCuotas;
    unPrestamo.prestamoImporte=prestamoImporte;
    unPrestamo.prestamoId=prestamoId;
    unPrestamo.isEmpty=0;
    unPrestamo.prestamoEstado=ACTIVO;

    return unPrestamo;
}

int automaticIdPrestamos()
{
    static int prestamoId=100;
    return prestamoId++;
}

int getActivePrestamos(ePrestamos vecPrestamos[],int tamPrestamos)
{
    int contador=0;
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==ACTIVO)
        {
            contador++;
        }
    }
    return contador;
}

int findFreePrestamos(ePrestamos vecPrestamos[],int tamPrestamos)
{
    int indice=-1;
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int addPrestamo(ePrestamos vecPrestamos[],int tamPrestamos,eClientes vecClientes[],int tamClientes)
{
    int emptySpace=-1;
    int idPrestamo;
    int idCliente;
    int idClienteMaximo;
    int idClienteMinimo;
    int prestamoCuotas;
    float prestamoImporte;
    idPrestamo=automaticIdPrestamos();
    emptySpace=findFreePrestamos(vecPrestamos,tamPrestamos);
    obtenerUltimoIdRegistrado(vecClientes,tamClientes,&idClienteMaximo);
    obtenerPrimerIdRegistrado(vecClientes,tamClientes,&idClienteMinimo);

    if(emptySpace!=-1)
    {
        showClientes(vecClientes,tamClientes,vecPrestamos,tamPrestamos);
        idCliente=inputValidInt("Ingrese un idCliente: ","\nNo ha ingresado un id cliente valido. Intente nuevamente: ",idClienteMinimo,idClienteMaximo,3);
        prestamoImporte=inputValidFloat("Ingrese el importe prestado: ",100000);
        prestamoCuotas=inputValidInt("Seleccione la cantidad de cuotas: ","No ha ingresado un tipo de dato valido. ",1,12,3);
        vecPrestamos[emptySpace]=newPrestamo(idCliente,prestamoImporte,prestamoCuotas,idPrestamo);
        printf("Prestamo registrado!!!\n");
        showHeaderPrestamo();
        showPrestamo(vecPrestamos[emptySpace],vecClientes,tamClientes);
    }

    else
    {
        printf("No hay mas lugar para agregar prestamos");
    }

    return emptySpace;
}

int saldarPrestamo(ePrestamos vecPrestamos[],int tamPrestamos,int prestamoId,eClientes vecClientes[],int tamClientes)
{
    int idPrestamo;
    int contadorActivos;
    int indice;
    char confirm='n';
    contadorActivos=cantidadPrestamosActivos(vecPrestamos,tamPrestamos);
    if(contadorActivos>0)
    {
        showPrestamos(vecPrestamos,tamPrestamos,vecClientes,tamClientes);
        indice=findPrestamoActivoById(vecPrestamos,tamPrestamos,&idPrestamo,vecClientes,tamClientes);


        if(indice!=-1)
        {
            confirm=confirma("Confirma la cancelacion? s/n: ");
            if(confirm=='s')
            {
                vecPrestamos[indice].prestamoEstado=SALDADO;
                msg("Prestamo cancelado!");
            }
            else
            {
                msg("\nOperacion cancelada!");
            }
        }
    }
    else
    {
        msg("No hay prestamos para saldar");
    }
    return indice;
}

int reanudarPrestamo(ePrestamos vecPrestamos[],int tamPrestamos,int prestamoId,eClientes vecClientes[],int tamClientes)
{
    int idPrestamo;
    int indice;
    char confirm='n';
    int contadorSaldados=0;
    contadorSaldados=cantidadPrestamosSaldados(vecPrestamos,tamPrestamos);
    if(contadorSaldados>0)
    {
        showHeaderPrestamo();
        showPrestamosCancelados(vecPrestamos,tamPrestamos,vecClientes,tamClientes);
        indice=findPrestamoCanceladoById(vecPrestamos,tamPrestamos,&idPrestamo,vecClientes,tamClientes);


        if(indice!=-1 && indice!=-2)
        {
            confirm=confirma("Confirma la reanudacion? s/n: ");
            if(confirm=='s')
            {
                vecPrestamos[indice].prestamoEstado=ACTIVO;
                msg("Prestamo reactivado!");
            }
            else
            {
                msg("\nOperacion cancelada!");
            }
        }
    }
    else
    {
        msg("\nNo hay prestamos para reactivar");
    }
    return indice;
}

void showHeaderPrestamo()
{
    printf("ID PRESTAMO   ID CLIENTE PRESTAMO   CUIL CLIENTE      IMPORTE     CUOTAS");
}

void showPrestamo (ePrestamos unPrestamo,eClientes vecClientes[],int tamClientes)
{
    char cuil[14];
    getCuilCliente(vecClientes,tamClientes,unPrestamo.clienteId,cuil);
    printf("\n%6d %15d %25s %13.2f %5d\n",unPrestamo.prestamoId,unPrestamo.clienteId,cuil,unPrestamo.prestamoImporte,unPrestamo.prestamoCuotas);
}

void showPrestamos(ePrestamos vecPrestamos[],int tamPrestamos,eClientes vecClientes[],int tamClientes)
{
    showHeaderPrestamo();
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==ACTIVO && vecPrestamos[i].isEmpty==0)
        {
            showPrestamo(vecPrestamos[i],vecClientes,tamClientes);
        }
    }
}

void showPrestamosCancelados(ePrestamos vecPrestamos[],int tamPrestamos,eClientes vecClientes[],int tamClientes)
{
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==SALDADO && vecPrestamos[i].isEmpty==0)
        {
            showPrestamo(vecPrestamos[i],vecClientes,tamClientes);
        }
    }
}

int cantidadPrestamosUnCliente(ePrestamos vecPrestamos[],int tamPrestamos,int clienteId)
{
    int contadorPrestamos=0;
    for(int i=0; i<tamPrestamos; i++)
    {


        if(vecPrestamos[i].prestamoEstado==ACTIVO && vecPrestamos[i].clienteId==clienteId)
        {
            contadorPrestamos++;
        }

    }
    return contadorPrestamos;
}

int cantidadPrestamosSaldadosUnCliente(ePrestamos vecPrestamos[],int tamPrestamos,int clienteId)
{
    int contadorPrestamos=0;
    for(int i=0; i<tamPrestamos; i++)
    {


        if(vecPrestamos[i].prestamoEstado==SALDADO && vecPrestamos[i].clienteId==clienteId)
        {
            contadorPrestamos++;
        }

    }
    return contadorPrestamos;
}

void mostrarPrestamosDeUnCliente(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos,int* clienteId)
{
    showHeaderPrestamo();
    for(int i=0; i<tamPrestamos; i++)
    {
        for(int j=0; j<tamClientes; j++)
        {
            if(vecPrestamos[i].clienteId == vecClientes[j].clienteId && vecPrestamos[i].clienteId==*clienteId && vecClientes[j].clienteId==*clienteId)
            {
                showPrestamo(vecPrestamos[i],vecClientes,tamClientes);
            }
        }
    }
}

int cantidadPrestamosActivos(ePrestamos vecPrestamos[],int tamPrestamos)
{
    int contadorActivos=0;

    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==ACTIVO)
        {
            contadorActivos++;
        }
    }
    return contadorActivos;
}

int cantidadPrestamosSaldados(ePrestamos vecPrestamos[],int tamPrestamos)
{
    int contadorSaldados=0;

    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==SALDADO)
        {
            contadorSaldados++;
        }
    }
    return contadorSaldados;
}

int findPrestamoById(ePrestamos vecPrestamos[],int tamPrestamos,int* idPrestamo,eClientes vecClientes[],int tamClientes)
{

    *idPrestamo=inputInt("\nIngrese numero de prestamo: ");
    int indice=-1;
    printf("Prestamo:\n");
    showHeaderPrestamo();
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoId==*idPrestamo)
        {
            showPrestamo(vecPrestamos[i],vecClientes,tamClientes);
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
        msg("No se ha encontrado el id!\n");
    }

    return indice;
}

int findPrestamoActivoById(ePrestamos vecPrestamos[],int tamPrestamos,int* idPrestamo,eClientes vecClientes[],int tamClientes)
{

    *idPrestamo=inputInt("\nIngrese numero de prestamo: ");
    int indice=-1;
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoId==*idPrestamo && vecPrestamos[i].prestamoEstado==ACTIVO)
        {
        	printf("Prestamo:\n");
        	showHeaderPrestamo();
            showPrestamo(vecPrestamos[i],vecClientes,tamClientes);
            indice=i;
            break;
        }
        else if(vecPrestamos[i].prestamoId==*idPrestamo && vecPrestamos[i].prestamoEstado==SALDADO)
        {
        	indice=-2;
        }

        else
        {
            continue;
        }
    }
    if(indice==-1)
    {
        msg("No se ha encontrado el id!\n");
    }

    if(indice==-2)
    {
    	msg("Este prestamo ya se encuentra saldado!");
    }

    return indice;
}

int findPrestamoCanceladoById(ePrestamos vecPrestamos[],int tamPrestamos,int* idPrestamo,eClientes vecClientes[],int tamClientes)
{

	*idPrestamo=inputInt("\nIngrese numero de prestamo: ");
	    int indice=-1;
	    for(int i=0; i<tamPrestamos; i++)
	    {
	        if(vecPrestamos[i].prestamoId==*idPrestamo && vecPrestamos[i].prestamoEstado==SALDADO)
	        {
	        	printf("Prestamo:\n");
	        	showHeaderPrestamo();
	            showPrestamo(vecPrestamos[i],vecClientes,tamClientes);
	            indice=i;
	            break;
	        }
	        else if(vecPrestamos[i].prestamoId==*idPrestamo && vecPrestamos[i].prestamoEstado==ACTIVO)
	        {
	        	indice=-2;
	        }

	        else
	        {
	            continue;
	        }
	    }
	    if(indice==-1)
	    {
	        msg("No se ha encontrado el id!\n");
	    }

	    if(indice==-2)
	    {
	    	msg("Este prestamo ya se encuentra activo!");
	    }

	    return indice;
}
