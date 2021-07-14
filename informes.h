#ifndef INFORMES_H_
#define INFORMES_H_


#include "servicio.h"
#include "mascota.h"
#include "tipo.h"
#include "colores.h"
#include "trabajo.h"
#include "cliente.h"

/** \brief imprime el listado de mascota elegido por el usuario por tipo
 * \param mascota eMascota
 * \param lenMas int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarTipoDeMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente);////mostrarTipoDeMascota


/* \brief imprime el listado de mascota elegido por el usuario por color
 * \param mascota eMascota
 * \param lenMas int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarColorDeMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente);////mostrarColorDeMascota


/** \brief imprime el listado de mascota por tipos
 * \param mascota eMascota
 * \param lenMas int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarTodosTiposDeMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol,eCliente cliente[], int lenCliente);//mostrarTodosTiposDeMascota


int mostrarTrabajoDeMascotas(eTrabajo trabajo[],int lenTrab, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);

int mascotaMasJoven(eMascota mascota[], int lenMas, eMascota* masMenor,eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);


int contadorTipoColorMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente, int* total);

/*\brief Busca el servicio mas barato, devuelve por la estructura servMenor el servicios más baratos ne caso de haber dos devuelve -1 en el precio de la misma
 * \param eServicio servicio
 * \param lenSer int
 * \param leServicio* servMenor
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int contadorColorMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente, int* total);


/*- Pedir una mascota e informar la suma de los trabajos le hicieron a la
misma*/

/** \brief imprime el listado de trabajo por mascotas que el usuario ingrese devolviendo el total y promedio de las mismas
 * \param trabajo eTrabajo
 * \param lenTrab int
 * \param eServicio servicio
 * \param lenSer int
 * \param eMascota mascota
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \param float* total
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int promedioTrabajosMascota(eTrabajo trabajo[],int lenTrab, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas, eTipo tipo[], int lenTip, eColor color[], int lenCol,eCliente cliente[], int lenCliente, float* total);
/** \brief pide al usuario una mascota y muestra los trabajos realizados a esa mascota
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamM int tamanio del array de mascotas
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamT int tamanio del array de trabajos
 * \param tipos[] eTipo array de tipos
 * \param tamTip int tamanio del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int tamanio del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamS int tamanio del array de servicios
 * \return int retorna 1 si pudo mostrar los trabajos a esa mascota y 0 si no
 *
 */
int trabajosAMascotas(eMascota mascotas[], int tamM, eTrabajo trabajos[], int tamT, eTipo tipos[], int tamTip, eColor colores[], int tamC, eServicio servicios[], int tamS, eCliente clientes[], int tamClien);
/** \brief el usuario ingresa un servicio y se muestra las mascotas que recibieron ese servicio
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamM int tamanio del array de mascotas
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamT int tamanio del array de trabajos
 * \param tipos[] eTipo array de tipos
 * \param tamTip int tamanio del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int tamanio del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamS int tamanio del array de servicios
 * \return int retorna 1 si pudo mostrarlo y 0 si no
 *
 */
int servicioRealizadoMascota(eMascota mascotas[], int tamM, eTrabajo trabajos[], int tamT, eTipo tipos[], int tamTip, eColor colores[], int tamC, eServicio servicios[], int tamS, eCliente clientes[], int tamClien);
/** \brief el usuario ingresa una fecha y muestra los trabajos realizados esa fecha
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamM int tamanio del array de mascotas
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamT int tamanio del array de trabajos
 * \param tipos[] eTipo array de tipos
 * \param tamTip int tamanio del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int tamanio del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamS int tamanio del array de servicios
 * \return int retorna 1 si pudo mostrar los servicios por fecha y 0 si no
 *
 */
int serviciosRealizadosFecha(eMascota mascotas[], int tamM, eTrabajo trabajos[], int tamT, eTipo tipos[], int tamTip, eColor colores[], int tamC, eServicio servicios[], int tamS);
int servicioAMascotasYFecha(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTra);
#endif /* INFORMES_H_ */
