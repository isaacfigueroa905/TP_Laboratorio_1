/*
 * Biblio.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Isaac
 */

#ifndef BIBLIO_H_
#define BIBLIO_H_
#include <stdio.h>


/// @brief muestra un mensaje y un numero editable flotante con varios decimales
///
/// @param char [] mensaje en pantalla.
/// @param float numero editable con coma.
void ImprimirMensajeBit(char [],float );

/// @brief muestra un mensaje y un numero editable flotante con dos decimales
///
/// @param char [] mensaje en pantalla.
/// @param float numero editable con coma.
void ImprimirMensajeConFlotante(char[],float );

///
/// @brief transfoma un valor de pesos a bitcoins.
///
/// @param float valor ingresado.
/// @param float valor del btc
/// @return el precio equivalente en btc.
float DePesosABitcoins(float,float);

/// @brief se ingresa un mensaje principal, un mensaje en caso de error y un valor minimo.
///
/// @param char [] mensaje principal.
/// @param char [] mensaje de error.
/// @param float valor flotant minimo.
/// @return
float IngresoNumero(char[], char [], float);

/// @brief obtiene un precio con un descuento editable
///
/// @param float precio de inicio.
/// @param float porcentaje de descuento.
/// @return float precio final.
float PrecioConDescuento(float, float);

/// @brief obtiene un precio con un interes editable.
///
/// @param float precio de inicio.
/// @param float porcentaje de interes.
/// @return float precio final.
float PrecioConInteres(float, float);

/// @brief  calcula el precio por kilometro
///
/// @param float precio del viaje.
/// @param float kilometros del viaje.
/// @return float precio unitario del viaje.
float PrecioPorKilometro(float, float);



/// @brief calcula la diferencia entre dos precios
///
/// @param float primer precio ingresado
/// @param float segundo precio ingresado
/// @return float retorna la diferencia entre precios
float DiferenciaDePrecios(float,float);

/// @brief inicia un menu de opciones
///
/// @param char opcion numerica de tipo char para descartar rompimiento en caso
/// de ingreso de letra si opcion fuese del tipo int
///
/// @param int primer bandera
/// @param int segunda bandera
///
/// @param float para mostrar, editar kms
/// @param float para mostrar, editar primer precio
/// @param float para mostra, editar segundo precio
/// @return char retorna la opcion seleccionada
char Menu(char,int,int,float,float,float);

/// @brief muestra un desplegable  con los calculos a realizar
///
/// @param float editable a mostrar dentro del submenu
void MostrarSubMenu(float);


#endif /* BIBLIO_H_ */
