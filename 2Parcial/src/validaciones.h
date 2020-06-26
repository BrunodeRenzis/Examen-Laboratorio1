/** \brief Valida una entrada del usuario en formato INT
 *
 * \param punteor a int.
 * \param cantidad de reintentos.
 * \param un mensaje que se muestra a la hora de pedir el entero.
 * \param el mensaje de error cuando lo que se ingreso no es valido.
 * \param un rango minimo.
 * \param un rango maximo.
 * \return devuelve 0 si el entero se guardo en la variable ingresada ya validado, y -1 si no pudo.
 *
 */
int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max);

/** \brief Valida una entrada del usuario en formato FLOAT.
 *
 * \param punteor a float.
 * \param cantidad de reintentos.
 * \param un mensaje que se muestra a la hora de pedir el flotante.
 * \param el mensaje de error cuando lo que se ingreso no es valido.
 * \param un rango minimo.
 * \param un rango maximo.
 * \return devuelve 0 si el flotante se guardo en la variable ingresada ya validado, y -1 si no pudo.
 *
 */
int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max);

/** \brief Valida una entrada del usuario en formato cadena de caracteres.
 *
 * \param vector de caracteres por ejemplo char cadena[50].
 * \param limite del vector de caracteres por ejemplo 50.
 * \param cantidad de reintentos que tiene el usuario de ingresar la cadena de forma erronea.
 * \param un mensaje que se muestra a la hora de pedir la cadena..
 * \param el mensaje de error cuando lo que se ingreso no es valido.
 * \return devuelve 0 si la cadena se guardo en la variable ingresada ya validada, y -1 si no pudo.
 *
 */
int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);

/** \brief Valida un EMAIL ingresado por el usuario.
 *
  * \param vector de caracteres por ejemplo char cadena[50].
 * \param limite del vector de caracteres por ejemplo 50.
 * \param cantidad de reintentos que tiene el usuario de ingresar la el email de forma erronea.
 * \param un mensaje que se muestra a la hora de pedir el email.
 * \param el mensaje de error cuando lo que se ingreso no es valido.
 * \return devuelve 0 si el email se guardo en la variable ingresada ya validado, y -1 si no pudo.
 *
 */
int utn_getEmail(char* pString, int limite, int reintentos, char* msg, char* msgError);

/** \brief toma datos en forma de cadena de caracteres, que se usa para validar float, int e char, usa un AUX muy grande, ingresas una cadena de caracteres, va al ultimo caracter o al fin de la linea \n y \0 para darle fin a la cadena y luego se lee de nuevo la cadena si es menor o igual al limite que se paso lo guarda en el puntero.
 *
 * \param se le pasa un puntero al auxiliar donde se desea guardar la cadena.
 * \param un limite de la cadena.
 * \return devuelve 0 si esta todo ok, -1 si no pudo validar la cadena e copiarla en el auxiliar que se paso por referencia.
 *
 */
int getCadena(char* pAux,int limite);

/** \brief Em combinacion con la funcion getcadena y isInt, pide enteros y valida en ASCII entre 0 y 9.
 *
 * \param puntero auxiliar donde se desea guardar el entero
 * \return todo ok si pudo convertir la cadena e validar que solo este en rango 0 y 9 de ASCII y guardarlo en el puntero pasado por referencia, -1 si no pudo.
 *
 */
int getInt(int* pAux);

/** \brief Se le pasa un puntero auxiliar que esta siendo validado, esta funcion valida del 0 a 9 en ASCII
 *
 * \param la cadena de caracteres pasada por referencia que se va a validar.
 * \return devuelve 0 si valido que solo hay numeros ingresados de 0 a 9 y -1 si no pudo validarlo.
 *
 */
int isInt(char *pAux);


/** \brief Valida un flotante, leyendo una cadena y validando que solo tenga numeros de 0 a 9 y como maximo un punto.
 *
 * \param la cadena de caracteres pasada por referencia que se va a validar.
 * \return devuelve 0 si valido que solo hay numeros ingresados de 0 a 9 y como maximo un punto. -1 si no pudo validarlo.
 *
 */
int isFloat(char* pAux);

/** \brief En combinacion con isFloat y utnGetCadena, pide un float en formato de cadena de caracteres lo valida, y lo copia en el puntero pasado por referencia.
 *
 * \param puntero pasado por referencia donde se quiere guardar el float ya validado.
 * \return 0 si valido el float con maximo 1 punto y solo numeros. -1 si no pudo.
 *
 */
int getFloat(float*pAux);

/** \brief Funcion utilizada por utn_getCadena, que valida que las cadenas de caracteres que se ingresaron sea SOLO LETRAS.
 *
 * \param Puntero pasado por referencia de lo que se quiere validar.
 * \return 0 si esta todo ok y todo lo que contiene la cadena son SOLO letras, y -1 si no pudo validar la cadena.
 *
 */
int isLetras(char*pAux);

/** \brief Funcion utilizada por utn_getEmail, valida que antes del @ existan caracteres o numeros, que tenga 1 arriba y por lo menos 1 punto despues del arroba.
 *
 * \param puntero pasado por referencia de lo que se quiere validar.
 * \return 0 si lo valido -1 si no pudo.
 *
 */
int validarMail(char *pAux);

char preguntarSiEstaSeguro(char* msg, char* msgerror);
