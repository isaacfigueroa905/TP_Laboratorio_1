/*
 ============================================================================
 Name        : Tp1AgenciaDeViajes.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblio.h"



#define DESCUENTO 10
#define INTERES 25
#define BTC 4680912.20 //precio de 1bitcon en pesos al 14-04-22 00hs



int main(void) {

	setbuf(stdout,NULL);
	char opcion;
	float kilometrosIngresados;
	float precioAerolineas;
	float precioLatam;
	float aerolineasDebito;
	float latamDebito;
	float aerolineasCredito;
	float latamCredito;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferencia;
	float precioEnBtcAerolineas;
	float precioEnBtcLatam;
	int banderaPrimerOpcion=0;
	int banderaSegundaOpcion=0;
	int banderaTerceraOpcion=0;

    do
    {

        opcion=Menu(opcion,banderaPrimerOpcion,banderaSegundaOpcion,kilometrosIngresados,precioAerolineas,precioLatam);

        switch(opcion)
        {
            case '1'://ingreso de Kms

                banderaPrimerOpcion=1;
                kilometrosIngresados=IngresoNumero("\tIngrese km= ","error, ingrese una distancia valida(mayor a 0)",1);

            break;

            case '2'://ingreso de precios
                banderaSegundaOpcion=1;
                precioAerolineas=IngresoNumero("\tPrecio vuelo Aerolineas= ","error, ingrese un precio valido",0);
                precioLatam=IngresoNumero("\tPrecio vuelo Latam= ","error, ingrese un precio valido",0);

            break;

            case '3'://calculos a realizar

                MostrarSubMenu(BTC);
                if(banderaPrimerOpcion==1&&banderaSegundaOpcion==1)
                {
                    banderaTerceraOpcion=1;
                    aerolineasDebito=PrecioConDescuento(precioAerolineas,DESCUENTO);
                    latamDebito=PrecioConDescuento(precioLatam,DESCUENTO);
                    aerolineasCredito=PrecioConInteres(precioAerolineas,INTERES);
                    latamCredito=PrecioConInteres(precioLatam,INTERES);
                    precioEnBtcAerolineas=DePesosABitcoins(precioAerolineas,BTC);
                    precioEnBtcLatam=DePesosABitcoins(precioLatam,BTC);
                    precioUnitarioAerolineas=PrecioPorKilometro(precioAerolineas,kilometrosIngresados);
                    precioUnitarioLatam=PrecioPorKilometro(precioLatam,kilometrosIngresados);
                    diferencia=DiferenciaDePrecios(precioLatam,precioAerolineas);
                    printf("\n\t\t calculo realizado exitosamente!...\n");//exito

                }
                else
                {
                    if(banderaPrimerOpcion==0&&banderaSegundaOpcion==0)
                    {
                    	printf("\n faltan cargar los datos para poder calcular (opcion 1 y 2)\n");// error faltan cargar los dos datos

                    }
                    else
                    {
                    	if(banderaPrimerOpcion==1)
                    	{
                    		printf("\n \n es necesario ingresar precios (opcion 2)para poder calcular\n"); //error solo se ingreso km
                    	}
                    	else
                    	{
                    		printf("\n \n es necesario ingresar Kms (opcion 1) para poder calcular\n");//error solo se ingreso precios
                    	}
                    }
                }


            break;

            case '4'://informes
                if(banderaTerceraOpcion==1)
                {
                    ImprimirMensajeConFlotante("\nKms ingresados: ",kilometrosIngresados);
                    ImprimirMensajeConFlotante("\n\nPrecio Aerolineas: $",precioAerolineas);
                    ImprimirMensajeConFlotante("\na- Precio con tarjeta de debito: $",aerolineasDebito);
                    ImprimirMensajeConFlotante("\nb- Precio con tarjeta de credito: $",aerolineasCredito);
                    ImprimirMensajeBit("\nc- Precio pagando con bitcoin: $",precioEnBtcAerolineas);
                    ImprimirMensajeConFlotante("\nd- Mostrar precio unitario: $",precioUnitarioAerolineas);

                    ImprimirMensajeConFlotante("\n\nPrecio Latam: $",precioLatam);
                    ImprimirMensajeConFlotante("\na- Precio con tarjeta de debito: $",latamDebito);
                    ImprimirMensajeConFlotante("\nb- Precio con tarjeta de credito: $",latamCredito);
                    ImprimirMensajeBit("\nc- Precio pagando con bitcoin: $",precioEnBtcLatam);
                    ImprimirMensajeConFlotante("\nd- Mostrar precio unitario: $",precioUnitarioLatam);

                    ImprimirMensajeConFlotante("\nla diferencia de precio es: $",diferencia);

                    //el proximo menu principal se muestra en cero
                    banderaPrimerOpcion=0;
                    banderaSegundaOpcion=0;

                }
                else
                {
                    printf("\nfalta calcular (opcion 3)...\n");
                }

            break;

            case '5'://hardcodeo
                kilometrosIngresados=7090;
                precioAerolineas=162965;
                precioLatam=159339;

                aerolineasDebito=PrecioConDescuento(precioAerolineas,DESCUENTO);
                latamDebito=PrecioConDescuento(precioLatam,DESCUENTO);
                aerolineasCredito=PrecioConInteres(precioAerolineas,INTERES);
                latamCredito=PrecioConInteres(precioLatam,INTERES);
                precioEnBtcAerolineas=DePesosABitcoins(precioAerolineas,BTC);
                precioEnBtcLatam=DePesosABitcoins(precioLatam,BTC);
                precioUnitarioAerolineas=PrecioPorKilometro(precioAerolineas,kilometrosIngresados);
                precioUnitarioLatam=PrecioPorKilometro(precioLatam,kilometrosIngresados);
                diferencia=DiferenciaDePrecios(precioLatam,precioAerolineas);

                ImprimirMensajeConFlotante("\n\nKms ingresados: ",kilometrosIngresados);
                ImprimirMensajeConFlotante("\nPrecio Aerolineas: $",precioAerolineas);
                ImprimirMensajeConFlotante("\na- Precio con tarjeta de debito: $",aerolineasDebito);
                ImprimirMensajeConFlotante("\nb- Precio con tarjeta de credito: $",aerolineasCredito);
                ImprimirMensajeBit("\nc- Precio pagando con bitcoin: $",precioEnBtcAerolineas);
                ImprimirMensajeConFlotante("\nd- Mostrar precio unitario: $",precioUnitarioAerolineas);


                ImprimirMensajeConFlotante("\n\nPrecio Latam: $",precioLatam);
                ImprimirMensajeConFlotante("\na- Precio con tarjeta de debito: $",latamDebito);
                ImprimirMensajeConFlotante("\nb- Precio con tarjeta de credito: $",latamCredito);
                ImprimirMensajeBit("\nc- Precio pagando con bitcoin: $",precioEnBtcLatam);
                ImprimirMensajeConFlotante("\nd- Mostrar precio unitario: $",precioUnitarioLatam);

                ImprimirMensajeConFlotante("\nla diferencia de precio es: $",diferencia);

                //el proximo menu principal se muestra en cero
                banderaPrimerOpcion=0;
                banderaSegundaOpcion=0;
            break;


        }


    }while(opcion!='6');

	return EXIT_SUCCESS;
}

