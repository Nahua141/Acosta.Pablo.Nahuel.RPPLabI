#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "datawarehouse.h"
#include "cliente.h"

int inicializarClientes(eCliente lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreCliente(eCliente lista[], int tam)
{
    int ubicacion = -1;
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            ubicacion = i;
            break;
        }
    }
    return ubicacion;
}

int altaCliente(eCliente lista[], int tam, int* nextId)
{
    int todoOk = 0;
    eCliente aux;
    int index;

    if(lista != NULL && tam > 0 && nextId != NULL)
    {
        index = buscarLibreCliente(lista, tam);
        if(index != -1)
        {
            printf("\nEl id del cliente es: %d\n", *nextId);
            utn_getString("Ingrese el nombre del cliente: ", "Error, reingrese: ", 20, 5, aux.nombre);
            utn_getString("Ingrese el sexo del cliente ('f' femenino 'm' masculino): ", "Error, reingrese: ", 4, 5, &aux.sexo);
            aux.sexo = tolower(aux.sexo);
            while(aux.sexo != 'f' &&  aux.sexo != 'm')
            {
                utn_getString("Error, reingrese el sexo del cliente ('f' femenino 'm' masculino): ", "Error, reingrese: ", 4, 5, &aux.sexo);
                aux.sexo = tolower(aux.sexo);
            }
            utn_getString("Ingrese localidad del cliente: ", "Error, reingrese: ", 20, 5, aux.localidad);
            aux.isEmpty = 0;
            aux.id = *nextId;
            (*nextId)++;
            lista[index] = aux;
            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarClientes(eCliente lista[], int tam)
{
    printf("Lista de clientes \n");
    printf("|\tID   \tCliente\t\t   \tSexo   \tLocalidad\n");
    for(int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarCliente(lista[i]);
        }
    }
}

void mostrarCliente(eCliente cliente)
{
    printf("%d  %-20s \t%c   %-20s\n", cliente.id, cliente.nombre, cliente.sexo, cliente.localidad);
}

int cargarNombreDeCliente(int id, eCliente lista[], int tam, char nombre[])
{
    int todoOk = 0;
    if(lista != NULL && tam > 0 && nombre != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(nombre, lista[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int hardcodearClientes(eCliente lista[], int tam, int cant, int* pLegajo)
{
    int cantidad = 0;

    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pLegajo != NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            lista[i].id = *pLegajo;
            (*pLegajo)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].sexo = sexos[i];
            strcpy(lista[i].localidad, localidades[i]);
            lista[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;
}
int cargarLocalidadDeCliente(int id, eCliente lista[], int tam, char localidad[])
{
    int todoOk = 0;
    if(lista != NULL && tam > 0 && localidad != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(localidad, lista[i].localidad);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
int ordenarLocalidadesALfabeticamente(eCliente lista[], int tam)
{
    eCliente auxCliente;
    int flag = 0;
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            if(strcmp(lista[i].localidad, lista[j].localidad) > 0)//criterio de ordenamiento
            {
                auxCliente = lista[i];
                lista[i] = lista[j];
                lista[j] = auxCliente;
            }
            flag = 1;
        }
    }
    mostrarClientes(lista, tam);
    return flag;
}
int localidadMasPopular(eCliente lista[], int tam)
{
    int todoOk = 0;
    int contador[tam];
    int mayor = 0;


    for(int i = 0; i < tam; i++)
    {
        contador[i] = 0;
        for(int j = 0; j < tam; j++)
        {
            if(lista[j].isEmpty == 0 && (lista[j].localidad == lista[i].localidad))
            {
                contador[i]++;
            }
        }
        if(i == 0 || mayor < contador[i])
        {
            mayor = contador[i];
        }
    }
    printf("************** Localidad Mas populares **************\n");
    printf("Con la cantidad de: %d\n", mayor);
    for(int k = 0; k <tam; k++)
    {
        if(mayor == contador[k])
        {
            mostrarCliente(lista[k]);
        }
    }

    return todoOk;
}
int mostrarLocalidadesIngresadas(eCliente lista[], int tam)
{
    int todoOk = 0;
    printf("Lista de localidades \n");
    printf("Localidad\n");
    for(int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarLocalidad(lista[i]);
            todoOk = 1;
        }
    }
    return todoOk;
}
void mostrarLocalidad(eCliente cliente)
{
    printf("%-20s\n",cliente.localidad);
}

