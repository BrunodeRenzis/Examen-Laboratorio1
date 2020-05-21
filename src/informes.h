#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


int menuInformesClientes();
/** \brief Despliega el menu de informes de cliente
 *
 * \return retorna la opcion seleccionada
 *
 */

void informesClientes(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos);

/** \brief Utiliza el valor de retorno del menu informes dentro de un switch y ejecuta el informe seleccionado
 *
 * \param vecClientes vector de clientes de la estructura eClientes
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos
 * \param tamClientes tamanio de clientes
 * \param tamPrestamos tamanio de prestamos

 *
 */

void clienteConMasPrestamos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos);
/** \brief Recorre el vector de prestamos y clientes y muestra al cliente con mas prestamos.
 *
 * \param vecClientes vector de clientes de la estructura eClientes
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos
 * \param tamClientes tamanio de clientes
 * \param tamPrestamos tamanio de prestamos
 *
 */

void clienteConMasPrestamosActivos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos);
/** \brief Recorre el vector de prestamos y clientes y muestra al cliente con mas prestamos activos
 *
 * \param vecClientes vector de clientes de la estructura eClientes
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos
 * \param tamClientes tamanio de clientes
 * \param tamPrestamos tamanio de prestamos
 *
 */

void clienteConMasPrestamosSaldados(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos);
/** \brief Recorre el vector de prestamos y clientes y muestra al cliente con mas prestamos saldados
 *
 * \param vecClientes vector de clientes de la estructura eClientes
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos
 * \param tamClientes tamanio de clientes
 * \param tamPrestamos tamanio de prestamos
 *
 */

int menuInformesPrestamos();
/** \brief Despliega el menu de informes de prestamos
 *
 * \return retorna la opcion seleccionada
 *
 */

void informesPrestamos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamPrestamos,int tamClientes);
/** \brief Utiliza el valor de retorno del menu informes prestamos dentro de un switch y ejecuta el informe seleccionado
 *
 *
 * \param vecClientes vector de clientes de la estructura eClientes
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos
 * \param tamClientes tamanio de clientes
 * \param tamPrestamos tamanio de prestamos
 *
 */

void prestamosMayoresA1000(ePrestamos vecPrestamos[],eClientes vecClientes[],int tamPrestamos,int tamClientes);
/** \brief Imprime los prestamos mayores a 1000 de una cifra ingresada por el usuario
 *
 * \param vecClientes vector de clientes de la estructura eClientes
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos
 * \param tamClientes tamanio de clientes
 * \param tamPrestamos tamanio de prestamos
 *
 */

void prestamosPorCuotas(ePrestamos vecPrestamos[],eClientes vecClientes[],int tamPrestamos,int tamClientes);
/** \brief Imprime los prestamos de la cantidad de cuotas ingresada por el usuario
 *
 * \param vecClientes vector de clientes de la estructura eClientes
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos
 * \param tamClientes tamanio de clientes
 * \param tamPrestamos tamanio de prestamos
 *
 */

void prestamosDe12CuotasSaldados(ePrestamos vecPrestamos[],eClientes vecClientes[],int tamPrestamos,int tamClientes);
/** \brief Imprime los prestamos de 12 cuotas saldados e indica el cliente al que pertenece.
 *
 * \param vecClientes vector de clientes de la estructura eClientes
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos
 * \param tamClientes tamanio de clientes
 * \param tamPrestamos tamanio de prestamos
 *
 */
