#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED
int utn_getChar(char* pResult,char* message,char* errorMessage,char minimum,char maximum,int retries);
/** \brief Obtiene un caracter valido
 *
 * \param pResult es el caracter a ser evaluado
 * \param message es el mensaje a ser leido por el usuario
 * \param errorMessage es el mensaje a ser leido por el usuario en caso de haber error
 * \param minimum es el minimo caracter a ser ingresado
 * \param maximum es el maximo caracter a ser ingresado
 * \param retries es la cantidad de reintentos permitidos

 * \return retorna 0 si se pudo copiar, -1 si no se pudo copiar.
 *
 */

int utn_getString(char *pAux,int limit,int retries,char* msj,char*msjError);
/** \brief Obtiene un string valido
 *
 * \param pAux Es el string a ser validado
 * \param limit es el limite de caracteres para el string
 * \param retries es la cantidad de reintentos permitidos
 * \param msj es el mensaje a ser leido por el usuario
 * \param msjError es el mensaje a mostrar en caso de haber ingresado caracteres incorrectos

 * \return retorna 0 si se pudo copiar, -1 si no se pudo copiar.
 *
 */

int isLetters(char*pAux);
/** \brief valida que los caracteres de una cadena sean letras
 *
 * \param pAux cadena a ser evaluada
 *  \return retorna 0 si se pudo copiar, -1 si no se pudo copiar.
 *
 */

int getString(char* pAux,int limit);
/** \brief Evalua si un string no supera el limite y copia su valor
 *
 * \param pAux Es la variable destino a portar el string si la validacion es correcta
 * \param limit es el limite de caracteres permitidos
 * \return retorna 0 si se pudo copiar -1 si no se pudo copiar.
 *
 */

int validFloat(char str[]);
/** \brief ingresa una cadena de caracteres, si esta cumple con las condiciones la convierte a float
 *
 * \param str cadena a ser evaluada como float
 * \return retorna 0 si se pudo copiar -1 si no se pudo copiar.
 *
 */

float inputValidFloat(char message[], int max);
/** \brief Pide un dato al usuario y lo valida como float
 *
 * \param message es el mensaje que se le muestra al usuario
 * \param max es el valor maximo permitido
 * \return retorna el valor ingresado
 *
 */

void inputStr(char* msg, char* str);
/** \brief Pide un string y lo guarda
 *
 * \param msg es el mensaje que se le muestra al usuario
 * \param str cadena a ser guardada
 *
 */

int inputValidInt(char* message,char* errorMessage,int minimum,int maximum,int retries);
/** \brief Ingresa un int y lo valida
 *
 * \param message es el mensaje a ser leido por el usuario
 * \param errorMessage es el mensaje a ser leido por el usuario en caso de haber error
 * \param minimum es el minimo valor a ser ingresado
 * \param maximum es el maximo valor a ser ingresado
 * \param retries es la cantidad de reintentos permitidos
 *
 */

int inputInt(char* string);
/** \brief Pide un numero al usuario
 *
 * \param string es el mensaje para pedir el dato al usuario
 * \return retorna el numero ingresado
 *
 */

int isNumeric(char* string);
/** \brief Valida que los caracteres de una cadena sean numericos
 *
 * \param cadena a ser evaluada
 * \return retorna 1 si todo es correcto y 0 si no es correcta la cadena
 *
 */

void msg(char* cadena);
/** \brief Manera abreviada de mostrar un mensaje sin mascaras
 *
 * \param cadena es el mensaje a ser mostrado
 *
 */

void inputValidDate(int* day,int* month,int* year);
/** \brief Valida una fecha ingresada en base al mes ingresado con la cantidad de dias.
 *
 * \param day es el numero de dia
 * \param month es el numero de mes
 * \param year es el numero de año
 *
 */

int validarSexo(char* mensaje,char* mensajeError,int reintentos,char* sexo);
/** \brief valida el sexo ingresado
 *
 * \param mensaje mensaje a ser leido por el usuario
 * \param mensajeError mensaje a ser mostrado en caso de no coincidir con los parametros
 * \param reintentos cantidad de reintentos
 * \param sexo caracter a ser evaluado
 * \return retorna 1 si esta todo bien, 0 si algo salio mal
 *
 */

int isSex(char sexo);
/** \brief valida el sexo ingresado
 *
 * \param sexo caracter a ser evaluado
 * \return retorna 1 si esta todo bien, 0 si algo salio mal
 *
 */

int menu();
/** \brief Despliega el menu de opciones
 * \return retorna la opcion seleccionada
 *
 */


char confirma(char* mensaje);
/** \brief confirma una accion
 *
 * \param mensaje es el pedido de confirmacion
 * \return retorna la respuesta en un caracter
 *
 */

char inputChar(char* msg);
/** \brief Ingresa un caracter
 *
 * \param msg es el mensaje a ser leido por el usuario
 * \return retorna el caracter
 *
 */

float inputFloat(char* string);
/** \brief Ingresa un float
 *
 * \param msg es el mensaje a ser leido por el usuario
 * \return retorna el float
 *
 */

void isValidCuit(char* cadena,char* mensaje,char* mensajeError,int reintentos);
/** \brief Valida un cuit con los -
 *
 * \param cadena es el cuit a ser ingresado
 * \param mensaje es el mensaje a ser mostrado al usuario
 * \param mensajeError es el mensaje a ser mostrado al usuario en caso de tener caracteres incorrectos
 * \param reintentos es la cantidad de reintentos permitidos para ingresar el cuit.

 *
 */
