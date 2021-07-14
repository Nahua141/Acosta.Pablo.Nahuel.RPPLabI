#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funciones.h"

int isChar(char string[])
{
	int isOk = 0;
	int i;
	int stringTam = strlen(string);

	for(i = 0; i<stringTam; i++)
	{
		if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z')) //Valido si lo que ingreso el usuario son solo letras
		{
			isOk = -1;
			break;
		}
	}

	return isOk;
}

int getString(char input[], int tam)
{
    char auxString[tam];
    int isOk = -1;

    if (input != NULL && tam > 0)
    {
        fflush(stdin);
        fgets(auxString,tam,stdin);	//Se ingresa el string, cumpliendo con su limite
        if (auxString[strlen(auxString)-1]=='\n') //Se cuestiona si en la posicion final del string hay un "enter"
        {
            auxString[strlen(auxString)-1]='\0';	//Si se cumple la condicion anterior, se cambia el \n por el final (\0)
        }
        if(strlen(auxString)<= tam)
        {
            strncpy(input, auxString, tam);	//Se copia la variable escrita a su destino
            isOk=0;
        }
    }

    return isOk;
}

int SizeString(char string[])
{
	int isOk = -1;
	int i = 0;

	if(string != NULL)
	{
		strlwr(string);	//Convierte toda la cadena a minuscula
		string[0] = toupper(string[0]); //Se convierte la primera letra en mayuscula
		while(string[i] != '\0')
		{
			if(string[i] == ' ')	//Cuestiono si en la posicion hay un space
			{
				string[i + 1] = toupper(string[i + 1]);	//Si hay un espacio, se que la proxima posicion habra una letra, por eso mismo la posicion + 1 la convierto a mayuscula
				isOk = 0;
			}
			i++;
		}
	}

	return isOk;
}

int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[])
{
	int isOk = 1;
    char auxString[tam];

    if(input != NULL && mensaje != NULL && mensajeError != NULL && tam > 0 && reintentos >= 0)
    {
        do{
        	printf("%s", mensaje);
            if(!(getString(auxString,tam)) && !(isChar(auxString)))	//Llamo a las funciones y si me devuelven todo bien, entro a la condicion
            {
                strncpy(input,auxString,tam);
                isOk = 0;
                break;
            }
            else	//Sino muestro el mensaje de error y el usuario tendra que volver intentarlo
            {
            	printf("%s", mensajeError);
            	reintentos--;
            }

        }while(reintentos>=0);
    }

    return isOk;
}
int isInt(char input[])
{
    int isOk = 0;
    int i = 0;
    int stringTam = strlen(input); //Devuelve la longitud de la cadena sin contar final \0

    for(i=0; i<stringTam ;i++)
    {
    	if(input[i]< '0' || input[i]> '9' )	//Valido si en la posicion i hay solo numeros, si hay una letra se inicia y corta la iteracion
        {
    		isOk=-1;
            break;
        }
    }

    return isOk;
}

int getInt(int* input)
{
    char auxString[400];
    int isOk = -1;

    if(!(getString(auxString,sizeof(auxString))) && !(isInt(auxString))) //Utilizo el sizeof para pasarle el tama�o sin necesidad de escribir 400
    {
    	*input=atoi(auxString); // La cadena se convierte en int y la devuelve
    	isOk=0;
    }

    return isOk;
}

int utn_getInt(char mensaje[], char mensajeError[], int min, int max, int reintentos, int* input)
{
    int isOk=-1;
    int auxInt;

   if(mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0 && input != NULL)
   {
	   do
	   {
			reintentos--;
			printf("%s", mensaje);
			if(!(getInt(&auxInt)) && auxInt >= min && auxInt <= max)	//Cuestiono si me devolvio un entero y si dicho entero respeta el max y el min
			{
				*input= auxInt;
				isOk = 0;
				break;
			}
			else
			{
				printf("%s ",mensajeError);
			}
	   }
	   while(reintentos >= 0);
   }

    return isOk;
}
int isFloat(char input[])
{
    int isOk = 0;
    int i;
    int stringTam = strlen(input);

    for(i=0; i<stringTam ;i++)
    {
        if((input[i]< '0' || input[i]> '9' ) && (input[i]!='.')) //Valido si en la posicion i hay solo numeros, si hay una letra se inicia y corta la iteracion
        {
        	isOk = -1;
            break;
        }
    }

    return isOk;
}

int getFloat(float* input)
{
    char auxString[200];
    int isOk =-1;

    if(!(getString(auxString,200)) && !(isFloat(auxString)))
    {
        *input = atof(auxString); // La cadena se convierte en float y la devuelve
        isOk = 0;
    }

    return isOk;
}

int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input)
{
    int isOk = -1;
    float auxFloat;

    if(input != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
    {
        do
        {
        	printf("%s", mensaje);
        	if(!(getFloat(&auxFloat)) && auxFloat >= min && auxFloat <= max) //Cuestiono si me devolvio un flotante y si dicho flotante respeta el max y el min
        	{
        		*input= auxFloat;
        		isOk = 0;
        		break;
        	}
        	else
        	{
        		printf("%s ",mensajeError);
        		reintentos--;
        	}
        }
        while(reintentos >= 0);
    }

    return isOk;
}

int DameCantidadReemplazos(char palabra[],char unaLetra, char otraLetra)
{
    int i;
    int lenght;
    int contador = 0;

    lenght = strlen(palabra);

    for(i = 0; i < lenght; i++)
    {
        if(tolower(palabra[i]) == tolower(unaLetra))
        {
            palabra[i] = otraLetra;
            contador++;
        }
    }
    if(contador != 0)
    {
        printf("%s\n", palabra);
    }
    return contador;
}

int ordenamientoInt(int lista[], int tam, int orden)
{
    int aux;
    int todoOk = 0;

    if(lista != NULL && tam > 0 && (orden == 1 || orden == 0))
    {
        if(orden == 1)
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(lista[i] > lista[j])
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                }
            }
            todoOk = 1;
        }
        else
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(lista[i] < lista[j])
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int ordenamientoString(char nombre[][20], int tam, int orden)
{
    char aux[20];
    int todoOk = 0;

    if(nombre != NULL && tam > 0 && (orden == 1 || orden == 0))
    {
        if(orden == 1)
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(strcmp(nombre[i], nombre[j]) > 0)
                    {
                        strcpy(aux, nombre[i]);
                        strcpy(nombre[i], nombre[j]);
                        strcpy(nombre[j], aux);
                    }
                }
            }
            todoOk = 1;
        }
        else
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(strcmp(nombre[i], nombre[j]) < 0)
                    {
                        strcpy(aux, nombre[i]);
                        strcpy(nombre[i], nombre[j]);
                        strcpy(nombre[j], aux);
                    }
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int invertirCadena(char cadena[])
{
    int todoOk = 0;
    int longitud = strlen(cadena);
    int tam;
    char aux;

    tam = strlen(cadena) / 2;

    if(cadena != NULL)
    {
        for (int i = 0; i < tam; i++)
        {
            aux = cadena[i];
            cadena[i] = cadena[longitud - i - 1];
            cadena[longitud - i - 1] = aux;
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarCaracteres(char nombre[], int orden)
{
    char aux;
    int todoOk = 0;
    int tam;
    tam = strlen(nombre);

    if(nombre != NULL)
    {
        if(orden == 1)
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(nombre[i] > nombre[j])
                    {
                        aux = nombre[i];
                        nombre[i] = nombre[j];
                        nombre[j] = aux;
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(nombre[i] < nombre[j])
                    {
                        aux = nombre[i];
                        nombre[i] = nombre[j];
                        nombre[j] = aux;
                    }
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

