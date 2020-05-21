#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utn.h"

char confirma(char* mensaje)
{
    char respuesta;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&respuesta);
    return respuesta;
}

int menu()
{
    int opcion;

    printf("Menu de opciones\n\n");
    printf("1-Alta Cliente\n");
    printf("2-Modificar Cliente\n");
    printf("3-Baja Cliente \n");
    printf("4-Nuevo Prestamo \n");
    printf("5-Saldar Prestamo \n");
    printf("6-Reanudar Prestamo\n");
    printf("7-Imprimir clientes\n");
    printf("8-Imprimir Prestamos\n");
    printf("9-Informes Clientes\n");
    printf("10-Informes Prestamos\n");
    printf("11-Salir\n");
    opcion=inputValidInt("Ingrese una opcion: ","\nNo ha ingresado una opcion correcta\n",1,11,5);

    return opcion;
}

void msg(char* cadena)
{
    printf("%s",cadena);
}

int isSex(char sexo)
{
    int retorno=0;
    if((sexo=='f' || sexo=='m')||(sexo=='F' || sexo=='M'))
    {
        retorno=1;
    }

    return retorno;
}
int validarSexo(char* mensaje,char* mensajeError,int reintentos,char* sexo)
{
    int retorno=-1;
    inputStr(mensaje,sexo);


    if(mensaje!=NULL && mensajeError!=NULL && sexo!=NULL)
    {
        while(reintentos>=0)
        {
            if(isSex(*sexo)==1)
            {
                retorno=1;
                break;
            }
            else
            {
                reintentos--;
                inputStr(mensajeError,sexo);
                retorno=0;
            }
        }

    }

    return retorno;
}

void inputStr(char* msg, char* str)
{
    printf("%s",msg);
    fflush(stdin);
    gets(str);
}

char inputChar(char* msg)
{
    char character;
    printf("%s",msg);
    fflush(stdin);
    scanf("%c",&character);
    return character;
}

int isNumeric(char* string)
{
    int i=0;
    int returnValue=-1;

    while(string[i]!='\0')
    {
        if(string[i]<'0' || string[i]>'9' || string[i]=='-')
        {
            returnValue=0;
        }
        i++;
    }
    return returnValue;
}

int inputInt(char* string)
{
    int number;

    printf("%s",string);
    scanf("%d",&number);
    return number;
}

float inputFloat(char* string)
{
    float number;

    printf("%s",string);
    scanf("%f",&number);
    return number;
}

int inputValidInt(char* message,char* errorMessage,int minimum,int maximum,int retries)
{
    int number;
    char auxNum[20];

    if(message!=NULL && errorMessage!=NULL && minimum>0 && maximum>=minimum)
    {
        do
        {
            inputStr(message,auxNum);

            if(isNumeric(auxNum))
            {
                if(maximum==0 || ((atoi(auxNum)<=maximum) && atoi(auxNum)>=minimum))
                {
                    number=atoi(auxNum);
                    break;
                }
                else
                {
                    printf("Error debe introducir un numero entre %d y %d ",minimum,maximum);
                }
            }
            else
            {
                printf("%s",errorMessage);
                retries--;
            }
        }
        while(retries>0);

    }
    return number;
}

void inputValidDate(int* day,int* month,int* year)
{
    *month=inputValidInt("Ingrese un mes: ","No ha ingresado un mes valido. Intente nuevamente: ",1,12,4);
    switch(*month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        *day=inputValidInt("Ingrese un dia: ","No ha ingresado un dia valido. Intente nuevamente: ",1,31,4);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        *day=inputValidInt("Ingrese un dia: ","No ha ingresado un dia valido. Intente nuevamente: ",1,30,4);
        break;

    case 2:
        *day=inputValidInt("Ingrese un dia: ","No ha ingresado un dia valido. Intente nuevamente: ",1,28,4);
        break;

    default:
        printf("No se ha ingresado una opcion correcta.");
        break;
    }
    *year=inputValidInt("Ingrese anio: ","No ha ingresado un anio valido.",2010,2020,4);
}

int validFloat(char str[])
{
    int i=0;
    int validation = 1;
    int contDot = 0;
    int contNum = 0;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9' )
        {
            if( str[i] != '.')
            {
                validation = 0;
            }
            else if( str[i] == '.')
            {
                contDot++;
            }
        }
        else
        {
            contNum++;
        }
        i++;
    }
    if(contDot > 1)
    {
        validation = 0;
    }

    if(contDot == 1 && contNum < 1)
    {
        validation = 0;
    }
    if(str[0] == '.')
    {
        validation = 0;
    }

    return validation;
}

float inputValidFloat(char message[], int max)
{
    float value;
    char input[500] ;
    int length;
    int loop = 1;

    do
    {
        if(max < 0)
        {
            printf("Error de configuracion: inputValidFloat(.. max) debe ser un numero positivo \n\n");
            break;
        }
        inputStr(message,input);
        length = strlen (input);
        if(length > 0)
        {
            if(validFloat(input))
            {
                if(max == 0 || atoi(input) <= max)
                {
                    value = atof(input);
                    loop = 0;
                }
                else
                {
                    printf("Error, debe introducir un numero entre 0 y %d. \n\n",max);
                }
            }
            else
            {
                printf("Error, debe introducir solo numeros o un punto \n\n");
            }
        }
        else
        {
            if(length == 0)
            {
                printf("Error, este campo es Obligatorio. \n\n");
            }
            else
            {
            }
        }

    }
    while(loop);

    return value;
}

int utn_getString(char *pAux,int limit,int retries,char* msg,char*errorMsg)
{
    int returnValue=-1;
    char auxString[limit];
    if(pAux!=NULL && limit >0 && retries >=0)
    {
        do
        {
            retries--;
            printf("%s",msg);
            if(getString(auxString,limit)==0 && isLetters(auxString)==0)
            {
                strncpy(pAux,auxString,limit);
                returnValue=0;
                break;
            }
            else
                printf("%s",errorMsg);
        }
        while(retries>=0);
    }
    return returnValue;
}

int isLetters(char*pAux)
{
    int returnValue=-1;
    int i=0;
    if(pAux!=NULL)
    {
        do
        {
            if(((*(pAux+i)<65 && *(pAux+i)!=32)||*(pAux+i)>90) && (*(pAux+i)<97||*(pAux+i)>122))
            {
                break;
            }
            i++;
        }
        while(i<strlen(pAux));
        if(i==strlen(pAux))
        {
            returnValue=0;
        }
    }
    return returnValue;
}

int getString(char* pAux,int limit)
{
    char auxString[2000];
    int returnValue =-1;
    if (pAux != NULL && limit >0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux,auxString,limit);
            returnValue=0;
        }
    }
    return returnValue;
}



void isValidCuit(char* cadena,char* mensaje,char* mensajeError,int reintentos)
{
    char cuil[15];
    int i=0;
    int length;
    inputStr(mensaje,cuil);
    length=strlen(cuil);

    if(cuil!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
    {


			while(cuil[i]!='\0')
			{

				if(isNumeric(cuil)!=-1)
				{




					if((cuil[2]=='-' && cuil[11]=='-' && length==13) ||(length==11))
					{
						strcpy(cadena,cuil);
						break;
					}
					else
					{
						printf("%s\n",mensajeError);
						inputStr(mensaje,cuil);
						if(cuil[2]=='-' && cuil[11]=='-')
						{
							strcpy(cadena,cuil);
							break;
						}
					}
				}

				else
				{
					printf("Ha ingresado caracteres no numericos, por favor vuelva a intentar: ");
					inputStr(mensaje,cuil);
					if(cuil[2]=='-' && cuil[11]=='-')
					{
					   strcpy(cadena,cuil);
					   break;
					}
				}
				i++;
			}


        reintentos--;
    }
}
