#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

/// @brief Menu que mostrara el programa constantemente y pide ingresar la opcion que usuario quiera
///
/// @param pResultado - puntero que devolvera la opcion que el usuario haya ingresado.
/// @param banderaA - bandera del numero A.
/// @param banderaB - bandera del numero B.
/// @param A - puntero del primer operador.
/// @param B - puntero del segundo operador.
void Menu(int*pOpcion){
	printf("\n=================MENU=================\n");
	printf("||1.Dar alta Empleado.\n");
	printf("||2.Modificar datos Empleados.\n");
	printf("||3.Dar baja empleado.\n"
			"||4.Mostrar Listas.\n"
			"||5.Salir.\n"
			"=======================================\n");

	utn_getIntRango(pOpcion,"Ingrese la opcion elegida: ","ERROR! NUMERO INVALIDO!\n",1,5,99);
}
/// @brief Menu que mostrara el programa constantemente y pide ingresar la opcion que usuario quiera
/// @param pOpcion la opcion elejida por el usuario
void MenuModificacion(int*pOpcion){

	printf("\n============MENU=MODIFICACION===========\n");
	printf("||1.Nombre.\n");
	printf("||2.Apellido.\n");
	printf("||3.Salario.\n");
	printf("||4.Sector.\n");
	printf("||5.Volver.\n");
	printf("=======================================\n");

	utn_getIntRango(pOpcion,"Ingrese el numero de la modificacion deseada: ","ERROR! NUMERO INVALIDO!\n",1,5,99);
}
/// @brief Menu que muestra de Listados
///
/// @param pOpcion la opcion elejida por el usuario
void MenuListado(int*pOpcion){

	printf("\n============MENU=LISTADO===========\n");
	printf("||1.Lista informacion Empleados.\n");
	printf("||2.Lista informacion Salarios.\n");
	printf("||3.Volver.\n");
	printf("=======================================\n");

	utn_getIntRango(pOpcion,"Ingrese el numero de la opcion deseada: ","ERROR! NUMERO INVALIDO!\n",1,3,99);
}
/// @brief Muestra Menu de la seccion de Ordenamiento
///
/// @param pOpcion la opcion elejida por el usuario
void MenuOrdenamiento(int*pOpcion){

	printf("\n============MENU=ORDENAMIENTO===========\n");
	printf("||1.Listado ordenado de forma Ascendente.\n");
	printf("||2.Listado ordenado de forma Descendente.\n");
	printf("||3.Volver.\n");
	printf("=======================================\n");

	utn_getIntRango(pOpcion,"Ingrese el Ordenamiento deseado: ","ERROR! NUMERO INVALIDO!\n",1,2,99);
}
