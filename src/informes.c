#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamos.h"
#include "clientes.h"
#include "informes.h"
int menuInformesClientes()
{
    int opcion;
    printf("1-Clientes con mas prestamos activos\n2-Cliente con mas prestamos saldados\n3-Cliente con mas prestamos\n4-Salir");
    opcion=inputValidInt("\nIngrese una opcion: ","\nNo ha ingresado una opcion valida. Intente nuevamente: ",1,4,3);
    return opcion;
}

void informesClientes(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos)
{
    char seguir='s';

    do
    {
        switch(menuInformesClientes())
        {

        case 1:
            clienteConMasPrestamosActivos(vecClientes,vecPrestamos,tamClientes,tamPrestamos);
            break;

        case 2:
            clienteConMasPrestamosSaldados(vecClientes,vecPrestamos,tamClientes,tamPrestamos);
            break;

        case 3:
        	clienteConMasPrestamos(vecClientes,vecPrestamos,tamClientes,tamPrestamos);
        	break;

        case 4:
            seguir='n';
            break;


        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
}


int menuInformesPrestamos()
{
    int opcion;
    printf("1-Prestamos mayores a 1000\n2-Prestamos de 12 cuotas saldados\n3-Imprimir prestamos por cuotas\n4-Salir");
    opcion=inputValidInt("\nIngrese una opcion: ","\nNo ha ingresado una opcion valida. Intente nuevamente: ",1,4,3);
    return opcion;
}

void informesPrestamos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos)
{
    char seguir='s';

    do
    {
        switch(menuInformesPrestamos())
        {

        case 1:
            prestamosMayoresA1000(vecPrestamos,vecClientes,tamPrestamos,tamClientes);
            break;

        case 2:
        	prestamosDe12CuotasSaldados(vecPrestamos,vecClientes,tamPrestamos,tamClientes);
        	break;

        case 3:
        	prestamosPorCuotas(vecPrestamos,vecClientes,tamPrestamos,tamClientes);
        	break;

        case 4:
            seguir='n';
            break;


        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
}

void prestamosPorCuotas(ePrestamos vecPrestamos[],eClientes vecClientes[],int tamPrestamos,int tamClientes){
	int cuotas;
	    int todoOk=-1;
	    cuotas=inputValidInt("Ingrese una cantidad de cuotas a buscar: ","Error, no ha ingresado una cantidad de cuotas valida",1,12,5);

	    showHeaderPrestamo();

	    for(int i=0; i<tamPrestamos; i++)
	    {
	        if(vecPrestamos[i].prestamoCuotas==cuotas && vecPrestamos[i].prestamoEstado==ACTIVO && vecPrestamos[i].isEmpty==0)
	        {
	            showPrestamo(vecPrestamos[i],vecClientes,tamClientes);
	            todoOk=1;
	        }




	    }

	    if(todoOk==-1)
	    {
	        msg("\nNo hay ningun prestamo de dichas cuotas\n");
	    }

}

void clienteConMasPrestamosActivos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos)
{
    int contador;
    int maximo=0;
    int idMax=0;
    int contadorValidacion=0;
    contadorValidacion=cantidadPrestamosActivos(vecPrestamos,tamPrestamos);
    if(contadorValidacion>0)
    {

        for(int i=0; i<tamClientes; i++)
        {
            contador=0;
            for(int j=0; j<tamPrestamos; j++)
            {
                if(vecPrestamos[j].clienteId==vecClientes[i].clienteId && vecPrestamos[j].prestamoEstado==1)
                {
                    contador++;
                }
            }

            if(i==0)
            {
                maximo = contador;
            }
            else if(contador>maximo)
            {
                maximo=contador;
                idMax=i;
            }
        }

        printf("El cliente con mas prestamos activos es: \n");
        showHeaderClientes();
        showCliente(vecClientes[idMax],vecPrestamos,tamPrestamos);
    }

    else
    {
        msg("\nNo hay prestamos activos para realizar este informe\n");
    }

}

void clienteConMasPrestamosSaldados(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos)
{
    int contador;
    int maximo=0;
    int idMax=0;
    int contadorValidacion=0;
    contadorValidacion=cantidadPrestamosSaldados(vecPrestamos,tamPrestamos);

    if(contadorValidacion>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            contador=0;
            for(int j=0; j<tamPrestamos; j++)
            {
                if(vecPrestamos[j].clienteId==vecClientes[i].clienteId && vecPrestamos[j].prestamoEstado==SALDADO)
                {
                    contador++;
                }
            }

            if(i==0)
            {
                maximo = contador;
            }
            else if(contador>maximo)
            {
                maximo=contador;
                idMax=i;
            }


        }

        printf("El cliente con mas prestamos saldados es: \n");
        showHeaderClientesSaldados();
        showClientePrestamosSaldados(vecClientes[idMax],vecPrestamos,tamPrestamos);
    }
    else
    {
        msg("No hay prestamos saldados");
    }

}


void prestamosDe12CuotasSaldados(ePrestamos vecPrestamos[],eClientes vecClientes[],int tamPrestamos,int tamClientes){
	showHeaderPrestamo();
	for(int i=0;i<tamPrestamos;i++){
		if(vecPrestamos[i].prestamoCuotas==12 && vecPrestamos[i].prestamoEstado==SALDADO){
			showPrestamo(vecPrestamos[i],vecClientes,tamClientes);
		}

		else {
			msg("No hay ningun prestamo saldado de 12 cuotas");
			break;
		}
	}
}

void clienteConMasPrestamos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos)
{
    int contador;
    int maximo=0;
    int idMax=0;
    int contadorValidacion=0;
    contadorValidacion=cantidadPrestamosActivos(vecPrestamos,tamPrestamos);
    if(contadorValidacion>0)
    {

        for(int i=0; i<tamClientes; i++)
        {
            contador=0;
            for(int j=0; j<tamPrestamos; j++)
            {
                if(vecPrestamos[j].clienteId==vecClientes[i].clienteId && (vecPrestamos[j].prestamoEstado==ACTIVO || vecPrestamos[j].prestamoEstado==SALDADO))
                {
                    contador++;
                }
            }

            if(i==0)
            {
                maximo = contador;
            }
            else if(contador>maximo)
            {
                maximo=contador;
                idMax=i;
            }
        }

        printf("El cliente con mas prestamos es: \n");
        showHeaderClientesSaldados();
        showClientePrestamosSaldados(vecClientes[idMax],vecPrestamos,tamPrestamos);
        printf("\n\n");
        showHeaderClientes();
        showCliente(vecClientes[idMax],vecPrestamos,tamPrestamos);

    }

    else
    {
        msg("\nNo hay prestamos activos para realizar este informe\n");
    }

}

void prestamosMayoresA1000(ePrestamos vecPrestamos[],eClientes vecClientes[],int tamPrestamos,int tamClientes)
{
    float importe;
    int todoOk=-1;
    importe=inputFloat("Ingrese un importe a buscar: ");
    while(importe<1000)
    {
    	msg("Debe ingresar una cifra mayor a 1000");
    	importe=inputFloat("Ingrese un importe a buscar: ");

    }
    showHeaderPrestamo();
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoImporte==importe && importe>1000 && vecPrestamos[i].prestamoEstado==1 && vecPrestamos[i].isEmpty==0)
        {
            showPrestamo(vecPrestamos[i],vecClientes,tamClientes);
            todoOk=1;
        }




    }

    if(todoOk==-1)
    {
        msg("\nNo hay ningun prestamo de dicho importe");
    }
}
