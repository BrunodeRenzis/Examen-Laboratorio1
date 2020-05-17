#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamos.h"
#include "informes.h"
#include "clientes.h"
int main()
{
	//* REVISAR LA BAJA CLIENTE */

    setbuf(stdout,NULL);
    eClientes vecClientes[CLIENTESTAM];
    ePrestamos vecPrestamos[PRESTAMOSTAM];
    initClientes(vecClientes,CLIENTESTAM);
    initPrestamos(vecPrestamos,PRESTAMOSTAM);
    char salir='n';
    int id=0;

    do
    {
        switch(menu())
        {
        case 1:
            addCliente(vecClientes,CLIENTESTAM);
            break;

        case 2:
            if(getActiveClientes(vecClientes,CLIENTESTAM)>0)
                modifyCliente(vecClientes,CLIENTESTAM,id,vecPrestamos,PRESTAMOSTAM);
            else
                msg("No hay clientes para realizar esta operacion");

            break;

        case 3:
            if(getActiveClientes(vecClientes,CLIENTESTAM)>0)
                removeCliente(vecClientes,CLIENTESTAM,vecPrestamos,PRESTAMOSTAM,&id);
            else

                msg("No hay clientes para realizar esta operacion");

            break;
        case 4:
            if(getActiveClientes(vecClientes,CLIENTESTAM)>0)
                addPrestamo(vecPrestamos,PRESTAMOSTAM,vecClientes,CLIENTESTAM);

            else

                msg("No hay clientes para realizar esta operacion");

            break;
        case 5:
            if(getActivePrestamos(vecPrestamos,PRESTAMOSTAM)>0)
                saldarPrestamo(vecPrestamos,PRESTAMOSTAM,id,vecClientes,CLIENTESTAM);

            else
                msg("No hay prestamos para saldar");
            break;
        case 6:
            if(getActiveClientes(vecClientes,CLIENTESTAM)>0)
                reanudarPrestamo(vecPrestamos,PRESTAMOSTAM,id,vecClientes,CLIENTESTAM);
            else
                msg("No hay prestamos para reanudar");
            break;
        case 7:
            if(getActiveClientes(vecClientes,CLIENTESTAM)>0)
                showClientes(vecClientes,CLIENTESTAM,vecPrestamos,PRESTAMOSTAM);
            else

                msg("No hay clientes para realizar esta operacion");

            break;

        case 8:

            if(getActivePrestamos(vecPrestamos,PRESTAMOSTAM)>0)
                showPrestamos(vecPrestamos,PRESTAMOSTAM,vecClientes,CLIENTESTAM);

            else

                msg("No hay prestamos para mostrar");

            break;


        case 9:
            if(getActiveClientes(vecClientes,CLIENTESTAM)>0 && getActivePrestamos(vecPrestamos,PRESTAMOSTAM)>0)
                informesClientes(vecClientes,vecPrestamos,CLIENTESTAM,PRESTAMOSTAM);

            else
                msg("No se pueden consultar los informes.");


            break;
        case 10:
            if(getActiveClientes(vecClientes,CLIENTESTAM)>0 && getActivePrestamos(vecPrestamos,PRESTAMOSTAM)>0)
                informesPrestamos(vecClientes,vecPrestamos,CLIENTESTAM,PRESTAMOSTAM);
            else
                msg("No se pueden consultar los informes.");

            break;

        case 11:
            salir=confirma("Desea salir? s/n: ");
            break;
        }
        system("pause");
        system("cls");
    }
    while(salir!='s');

    return 0;
}
