/*
 * Biblio.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Isaac
 */

#include "Biblio.h"


float IngresoNumero(char mensaje[], char error [], float minimo)
{
	float numeroIngresado;

	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);


	while(numeroIngresado<minimo)
	{
		printf("%s",error);
		scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;


}

float PrecioConDescuento(float precioOriginal, float porcentajeDescuento)
{
    float precioFinal;
    float aDescontar;

    aDescontar=(precioOriginal*porcentajeDescuento)/100;
    precioFinal=precioOriginal-aDescontar;
    return precioFinal;

}


float PrecioConInteres(float precioOriginal, float porcentajeInteres)
{
    float precioFinal;
    float aSumar;

    aSumar=(precioOriginal*porcentajeInteres)/100;
    precioFinal=precioOriginal+aSumar;
    return precioFinal;

}

float PrecioPorKilometro(float precio, float kilometros)
{
    float precioUnitario;

    precioUnitario=precio/kilometros;

    return precioUnitario;

}

float DiferenciaDePrecios(float precioA,float precioB)
{
    float resultado;

    resultado=precioA-precioB;
    if(precioA<precioB)
    {
       resultado=resultado*(-1);//cambia signo para mostrar siempre una diferencia en positivo
    }

    return resultado;
}

float DePesosABitcoins(float pesosIngresados,float valorBitcoin)
{
    float resultado;

    resultado=pesosIngresados/valorBitcoin;

    return resultado;
}

void ImprimirMensajeConFlotante(char mensaje [],float valor)
{
    printf("%s %.2f",mensaje,valor);//dos numeros despues de la coma
}


void ImprimirMensajeBit(char mensaje [],float valor)
{
    printf("%s %f",mensaje,valor);//varios numeros despues de la coma

}


void MostrarSubMenu(float bit)
{
    printf("\n3. Calcular todos los costos\n");
    printf("\n a)Tarjeta de Debito (descuento del 10 por ciento) ");
    printf("\n b)Tarjeta de credito (interes del 25 por ciento)");
    printf("\n c) Bitcoin (1BTC -> %.2f Pesos Argentinos)",bit);
    printf("\n d)Mostrar precio por KM (precio unitario) ");
    printf("\n e)Mostrar diferencia de precio informada(Latam-Aerolineas)");

}

char Menu(char opcion,int flagUno,int flagDos,float km,float precioUno,float precioDos)
{


        printf("\n------------------------------------------\n");
        printf("\n\t\tMENU PRINCIPAL\n");
        if(flagUno==0)
        {
            printf("1. Ingresar kilometros: (km = x)\n");//cuando no hay dato km
        }
        else
        {
            printf("1. Ingresar kilometros: (km = %.2f)\n",km);//cuado hay dato km
        }
        if(flagDos==0)
        {
            printf("2. Ingresar precio de vuelos: (Aerolineas = y, Latam = z)\n");//cuando no hay dato precios
        }
        else
        {
            printf("2. Ingresar precio de vuelos: (Aerolineas = $%.2f, Latam = $%.2f)\n",precioUno,precioDos);//cunado hay dato precios
        }
        printf("3. Calcular todos los costos:\n");
        printf("4. Informar resultados:\n");
        printf("5. Carga forzada de datos:\n");
        printf("6. Salir\n ");
        printf(" elija una opcion:  ");
        fflush(stdin);
        scanf("%c",&opcion);

        while(opcion!='1'&&opcion!='2'&&opcion!='3'&&opcion!='4'&&opcion!='5'&&opcion!='6')//limite numerico de opciones
        {
            printf("\nSeleccione una opcion valida!!!:\n");
            fflush(stdin);
            scanf("%c",&opcion);
        }
        printf("\n------------------------------------------\n");
        return opcion;

}

