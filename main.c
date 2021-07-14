#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "mascota.h"
#include "tipo.h"
#include "colores.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"


#define TAM 11
#define TAMTIP 5
#define TAMCOL 5
#define TAMSER 3
#define TAMTRAB 15
#define TAMCLIENTE 3
/** \brief muestra el menu de opciones
 *
 * \return int retorna la opcion ingresada por el usuario
 *
 */
int menuOpciones();
int main()
{
    eMascota mascota[TAM];
    eTrabajo trabajo[TAMTRAB];
    int respuesta;
    int opcion;
    char salir;
    int idMascota=4000;
    int idTrabajo=3000;
    eMascota masJoven;
    int totalColorTipo;
    int totalColor;
    float totalServicio;
    int flag= 0;

    eTipo tipo[TAMTIP]=
    {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Gato"},
        {1003, "Roedor"},
        {1004, "Pez"}
    };

    eColor color[TAMCOL]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    eServicio servicio[TAMSER]=
    {
        {2000, "Corte",250},
        {2001, "Desparasitado",300},
        {2002, "Castrado",400},
    };

    eCliente cliente[TAMCLIENTE]=
    {
        {500, "Carlos",'m'},
        {501, "Viviana",'f'},
        {502, "Silvia",'f'},
    };

    if(inicializarMascota(mascota, TAM)==0)
    {
        printf("LISTA MASCOTA INICIALIZADA ------- ");
    }

    if(inicializarTrabajo(trabajo, TAMTRAB)==0)
    {
        printf(" LISTA TRABAJO INICIALIZADA\n");
    }

    if(hardcodearMascota(mascota, TAM, 10, &idMascota)>0)//numero cantidad de mascota q van a entrar hardcodeado
    {
        printf(" Hardcodeo  mascota cargado ------ ");
    }

    if(hardcodearTrabajo(trabajo, TAMTRAB, 10, &idTrabajo)>0)//numero cantidad de trabajo q van a entrar hardcodeado
    {
        printf(" Hardcodeo trabajo cargado\n");
    }

    do
    {
        switch(menuOpciones())
        {
        case 1:
            printf("\n-----Alta Mascota-----\n");
            if(cargarMascota(mascota, TAM,&idMascota,tipo,TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
            {
                if(mostrarArrayMascota(mascota, TAM, tipo, TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
                {
                    printf("Carga exitosa\n");
                }
                flag = 1;
                system("pause");
            }
            break;
        case 2:
            system("cls");
            printf("\n-----Modificar Mascota-----\n");
            if(modificarMascota(mascota,TAM,tipo,TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
            {
                printf("Modificacion exitosa\n");
            }
            else
            {
                printf("Cancelacion exitosa\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n-----Baja Mascota-----\n");
            if(bajaMascota(mascota, TAM,tipo,TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
            {
                printf("Baja exitosa\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\n-----Listar Mascota-----\n");
            if(mostrarArrayMascota(mascota,TAM,tipo,TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
            {
                printf("\n");
            }
            else
            {
                printf("ERROR\n");
            }
            system("pause");
            break;
        case 5:
            system("cls");
            printf("\n-----Listar Tipo-----\n");
            if(mostrarArrayTipo(tipo, TAMTIP)==0)
            {
                printf("\n");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            printf("\n-----Listar Colores-----\n");
            if(mostrarArrayColor(color, TAMCOL)==0)
            {
                printf("\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            printf("\n-----Listar Servicios-----\n");
            if(mostrarArrayServicio(servicio, TAMSER)==0)
            {
                printf("\n");
            }
            system("pause");
            break;
        case 8:
            system("cls");
            printf("\n-----Alta Trabajo-----\n");
            if(cargarTrabajo(trabajo, TAMTRAB, &idTrabajo, servicio, TAMSER, mascota, TAM, tipo, TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
            {
                if(mostrarArrayTrabajo(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM)==0)
                {
                    printf("Carga exitosa\n");
                }
            }
            system("pause");
            break;
        case 9:
            system("cls");
            printf("\n-----Listar Trabajo-----\n");
            if(mostrarArrayTrabajo(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM)==0)
            {
                printf("\n");
            }
            system("pause");
            break;
        case 10:
            system("cls");
            printf("\n-----Mostrar mascotas por color-----\n");
            if(mostrarColorDeMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE)==0)
            {
                printf("\n");
            }
            system("pause");
            break;
        case 11:
            system("cls");
            printf("\n-----Mostrar mascotas por tipos-----\n");
            if(mostrarTipoDeMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE)==0)
            {
                printf("\n");
            }
            system("pause");
            break;
        case 12:
            system("cls");
            printf("\n-----Mascota mas joven-----\n");
            if(mascotaMasJoven(mascota, TAM, &masJoven, tipo, TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
            {
                if(masJoven.edad>0)
                {
                    printf("Las mascotas %s con %d de edad es la mas joven\n",masJoven.nombre, masJoven.edad);
                }
            }
            system("pause");
            break;
        case 13:
            system("cls");
            printf("\n-----Mostrar todas mascotas por tipos-----\n");
            if(mostrarTodosTiposDeMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE)==0)
            {
                printf("\n");
            }
            system("pause");
            break;
        case 14:
            system("cls");
            printf("\n-----Mascota de un mismo color y tipo-----\n");
            if(contadorTipoColorMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE, &totalColorTipo)==0)
            {
                if(masJoven.edad>0)
                {
                    printf("Hay %d mascotas del mismo color y tipo\n",totalColorTipo);
                }
            }
            system("pause");
            break;
        case 15:
            system("cls");
            printf("\n-----Mascota mascota con mayor cantidad de color-----\n");
            if(contadorColorMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE, &totalColor)==0)
            {
                if(totalColor>0)
                {
                    printf("Hay %d mascotas del mismo color y tipo\n",totalColor);
                }
            }
            system("pause");
            break;
        case 16:
            system("cls");
            trabajosAMascotas(mascota, TAM, trabajo, TAMTRAB, tipo, TAMTIP, color, TAMCOL, servicio, TAMSER, cliente, TAMCLIENTE);
            system("pause");
            break;
        case 17:
            system("cls");
            printf("\n-----Total de servicios por mascota-----\n");
            if(promedioTrabajosMascota(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM, tipo, TAMTIP, color, TAMCOL, cliente, TAMCLIENTE, &totalServicio)==0)
            {
                printf("total %.2f\n",totalServicio);
            }
            system("pause");
            break;
        case 18:
            system("cls");
            servicioRealizadoMascota(mascota, TAM, trabajo, TAMTRAB, tipo, TAMTIP, color, TAMCOL, servicio, TAMSER, cliente, TAMCLIENTE);//fijarse que corregir
            system("pause");
            break;
        case 19:
            system("cls");
            servicioAMascotasYFecha(mascota, TAM, tipo, TAMTIP, color, TAMCOL, servicio, TAMSER, trabajo, TAMTRAB);
            system("pause");
            break;
        case 20:
            system("cls");
            serviciosRealizadosFecha(mascota, TAM, trabajo, TAMTRAB, tipo, TAMTIP, color, TAMCOL, servicio, TAMSER);
            system("pause");
            break;
        case 21:
            printf("Confirma salida?: ");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("Opcion invalida\n");
            system("pause");
        }
    }
    while(salir == 'n');

    return 0;
}
int menuOpciones()
{
    int opcion;
    system("cls");
    printf("Menu de opciones\n\n");
    printf("1-Alta Mascotas\n");
    printf("2-Modificar Mascotas\n");
    printf("3-Baja Mascotas\n");
    printf("4-Listar  Mascotas\n");
    printf("5-Listar Tipos \n");
    printf("6-Listar Colores\n");
    printf("7-Listar Servicios\n");
    printf("8-Alta Trabajos\n");
    printf("9-Listar Trabajos \n");
    printf("10-Mostrar mascota por color(informe 1)\n");
    printf("11-Mostrar mascotas por tipo(informe 2)\n");
    printf("12-Mascota Menor edad(informe 3)\n");
    printf("13-Listar Mascotas separadas por Tipo(informe 4)\n");
    printf("14-Mostrar Mascotas de un Color y Tipo(informe 5)\n");
    printf("15-Mostrar color con mas mascotas(informe 6)\n");
    printf("16-Mostrar Trabajos a mascotas(informe 7)\n");
    printf("17-Mostrar Total Trabajos a mascotas(informe 8)\n");
    printf("18-Servicios realizados a mascotas(informe 9)\n");
    printf("19-Pedir servicio y mostrar a las mascotas que se le realizaron el servicio y la fecha(informe 10)\n");
    printf("20-Servicios realizados por fecha(informe 11)\n");
    printf("21-Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
