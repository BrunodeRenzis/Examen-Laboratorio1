#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#define NOMBRETAM 20
#define APELLIDOTAM 20
#define CLIENTESTAM 50
#define CUIL 15
typedef struct{
 char clienteNombre[NOMBRETAM];
 char clienteApellido[NOMBRETAM];
 char clienteCuil[CUIL];
 int clienteId;
 int isEmpty;
}eClientes;


#endif // CLIENTES_H_INCLUDED
eClientes newCliente(int clienteId,char clienteNombre[],char clienteApellido[],char clienteCuil[]);
/** \brief Genera un cliente con datos pasados por parametro y algunos creados de manera automatica
 *
 * \param clienteId numero de id del cliente
 * \param clienteNombre Nombre del cliente
 * \param clienteApellido Apellido del cliente
 * \param clienteCuil Cuil del cliente
 * \return retorna un cliente creado
 *
 */
void initClientes(eClientes vecClientes[],int tamClientes);
/** \brief Inicializa todos  los campos del cliente
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.

 *
 */
int findFree(eClientes vecClientes[],int tamClientes);
/** \brief Obtiene el primer espacio libre que encuentra
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.

 *\return retorna el indice libre
 */
int automaticIdClientes();
/** \brief Genera un id automatico

 * \return retorna el id generado
 */
int getActiveClientes(eClientes vecClientes[],int tamClientes);
/** \brief Obtiene La cantidad de clientes activos
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.
 * \return retorna la cantidad de clientes activos
 */
void showHeaderClientes();
/** \brief Muestra un cabezal con los nombres de los datos del cliente
 *
 *
 */
int addCliente(eClientes vecClientes[],int tamClientes);
/** \brief Agrega un cliente
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.
 * \return retorna el numero de indice si se pudo agregar correctamente si no retorna -1
 */

int obtenerPrimerIdRegistrado(eClientes vecClientes[],int tamClientes,int* ultimoId);
/** \brief Obtiene el primer id registrado
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.
 * \param ultimoId Guarda el valor del ultimo id generado
 * \return retorna 0 si todo esta bien y -1 si algo salio mal.
 *
 */

int obtenerUltimoIdRegistrado(eClientes vecClientes[],int tamClientes,int* ultimoId);
/** \brief Obtiene el ultimo id registrado
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.
 * \param ultimoId Guarda el valor del ultimo id generado
 * \return retorna 0 si todo esta bien y -1 si algo salio mal.
 *
 */
void showCliente(eClientes unCliente,ePrestamos vecPrestamos[],int tamPrestamos);
/** \brief Muestra los datos de un cliente seleccionado
 *
 * \param unCliente es una variable de la estructura eClientes con todoso los datos almacenados de esa posicion.
 * \param vecPrestamos recorre la estructura de prestamos
 * \param tamPrestamos es el tamaño de prestamos

 *
 */
void showClientes(eClientes vecClientes[],int tamClientes,ePrestamos vecPrestamos[],int tamPrestamos);
/** \brief Muestra a todos los clientes activos
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.
 * \param vecPrestamos recorre la estructura de prestamos
 * \param tamPrestamos es el tamaño de prestamos.
 *
 */
int modifyCliente(eClientes vecClientes[],int tamClientes,int id,ePrestamos vecPrestamos[],int tamPrestamos);
/** \brief Mediante un id trabaja con la posicion en memoria de ese id y modifica los datos que solicite el usuario.
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.
 * \param vecPrestamos recorre la estructura de prestamos
 * \param tamPrestamos es el tamaño de prestamos.
 * \param id es el id del cliente a modificar
 * \return retorna el indice del cliente modificado
 */
int removeCliente(eClientes vecClientes[],int tamClientes,ePrestamos vecPrestamos[],int tamPrestamos,int* idCliente);
/** \brief Elimina un cliente mediante baja logica.
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.
 * \param vecPrestamos recorre la estructura de prestamos
 * \param tamPrestamos es el tamaño de prestamos.

 * \return retorna el indice del cliente modificado
 */
int findClienteById(eClientes vecClientes[],int tamClientes,int* idCliente);
/** \brief Busca un cliente mediante su id
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param idCliente es el id del cliente a buscar.

 * \return retorna el indicel del cliente buscado
 */

int contadorTotalClientes(eClientes vecClientes[],int tamClientes);
/** \brief Cuenta los clientes activos.
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.

 * \return retorna la cantidad de clientes
 */

void showHeaderClientesSaldados();
/** \brief Muestra el header de clientes saldados
 */

void showClientePrestamosSaldados(eClientes unCliente,ePrestamos vecPrestamos[],int tamPrestamos);
/** \brief Muestra los clientes con la cantidad de prestamos saldados.
 * \param unCliente variable correspondiente a la estructura de clientes.
 * \param vecPrestamos recorre la estructura de prestamos
 * \param tamPrestamos es el tamaño de prestamos.

 */
int getCuilCliente(eClientes vecClientes[],int tamClientes,int idCliente,char* cuilCliente);
/** \brief Busca mediante el id del cliente su cuil para ser mostrado en la descripcion de los prestamos
 *
 * \param vecClientes recorre la estructura de clientes
 * \param tamClientes es el tamaño de clientes.
 * \param idCliente es el id del cliente
 * \param cuilCliente es el cuil del cliente.
 * \return retorna -1 si no salio bien, o 0 si salio todo ok
 *
 */
