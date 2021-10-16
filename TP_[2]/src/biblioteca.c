
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <string.h>
#include <ctype.h>
#include <windows.h>

/// @brief pide al usuario ingresar caracteres y de forma segura se guardan en una variable.
///
/// @param cadena - es el vector char en la cual se guarda lo que el usuario ingreso
/// @param tam - es el tamaño del vector char, usado para que no desborde el vector
/// @return
int myGets(char* cadena,int tam){
	fflush(stdin);
	fgets(cadena,tam,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}
/// @brief pide al usuario ingresar caracteres, los lee y checkea que que tenga un formato numero ENTERO
///
/// @param pResultado - el puntero por el cual devuelve el entero ingresado y validado.
/// @return - retorna 1 si el si lo que ingreso el usuario es convertible a int, sino retorna 0
int getInt(int* pResultado){
	int retorno=1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0&&esNumericaInt(buffer)&&strlen(buffer)>0){
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}
/// @brief pide al usuario ingresar caracteres, los lee y checkea que que tenga un formato de numero FLOAT
///
/// @param pResultado - el puntero por el cual devuelve el float ingresado y validado.
/// @return - retorna 1 si el si lo que ingreso el usuario es convertible a float, sino retorna 0
int getFloat(float* pResultado){
	int retorno=1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0&&esNumericaFloat(buffer)&&strlen(buffer)>0){
		retorno=0;
		*pResultado=atof(buffer);
	}

	return retorno;
}
/// @brief Usa lo ingresado por el usuario y checkea si es "texto basico", aceptando solo: ESPACIOS, a-z,A-Z,ñ-Ñ.
///
/// @param pResultado - el puntero por el cual devuelve el vector char ingresado y validado.
/// @param tam - es el tamaño del vector char, usado para que no desborde el vector
/// @return retorna 0 si algun caracter no es "basico", y 1 si todos los todos los caracteres son basicos.
int getChar(char* pResultado, int tam){
	int retorno=0;
	char buffer[4096];

	if(myGets(buffer,tam)==0&&esTextoBasico(buffer)==1&&strlen(buffer)>0){
		retorno=1;
		strncpy(pResultado,buffer,tam);
	}

	return retorno;
}
/// @brief toma una cadena de caracteres y checkea que sea numerica del tipo Int
///
/// @param cadena - la cadena de caracteres a checkear
/// @return - retorna 1 si la cadena es numerica del tipo int y 0 si algun caracter no es valido para una variable int.
int esNumericaInt(char* cadena){
	int retorno= 1;
	int i=0;
	if(cadena[0]=='-'){
		i=1;
	}
	for(;cadena[i]!='\0';i++){
		if(cadena[i]<'0'||cadena[i]>'9'){
			retorno=0;
			break;
		}
	}
	return retorno;
}
/// @brief toma una cadena de caracteres y checkea que sea numerica del tipo float
///
/// @param cadena - la cadena de caracteres a checkear
/// @return - retorna 1 si la cadena es numerica del tipo float y 0 si algun caracter no es valido para una variable float.
int esNumericaFloat(char* cadena){
	int retorno= 1;
	int i=0;//inicializo la variable i aca para modificarla en el if de abajo, y no le meto nada en ese sector del for
	int contadorPunto=0;
	int esNegativo=0;
	if(cadena[0]=='-'){//checkeo si la poss 0 es un "-", si es asi, el for comienza desde 1 y no desde 0
		i=1;			//ya que la unica posicion valida para un menos en el la poss 0
		esNegativo=1;//pongo una vandera de que el numero es negativo
	}
	for(;cadena[i]!='\0';i++){//dejo vacio el primer argumento, por q ya esta definido arriba

		if(cadena[i]<'.'||(cadena[i]>'.'&&cadena[i]<'0')||cadena[i]>'9'){//ya descartado el "-" solo filtro numeros y punto
			//para entender el if este tenes q mirar el ascii
			retorno=0;//devuelve 0 si se encontro algo que no va y rompe
			break;
		}
		else{//si no es caracter invalido va a saltear el if y entrar aca

			if(cadena[i]=='.'){//aca le pregunto espesificamente si es un punto, y si es q lo cuente
				contadorPunto++;
				if(contadorPunto>1||(esNegativo==0&&i==0)||(esNegativo==1&&i==1)){//aca filtro el punto si hay mas de uno
					retorno=0;//y tambien la posicion que tiene en la cadena, no puede estar adelante de todo
					break;//si esta adelante de todo o hay mas de un punto retorno 0(error) y break.
				}
			}
		}
	}
	return retorno;
}
/// @brief checkea si es "texto basico", aceptando solo: ESPACIOS, a-z,A-Z,ñ-Ñ.
///
/// @param cadena - la cadena de caracteres a checkear
/// @return retorna 1 si la cadena es denominada como "texto basico" sino retorna 0.
int esTextoBasico(char* cadena){
	int retorno= 1;
		int i;

		for(i=0;cadena[i]!='\0';i++){
			if(cadena[i]<32||(cadena[i]>32&&cadena[i]<65)||(cadena[i]>90&&cadena[i]<97)||(cadena[i]>122&&cadena[i]<164)||cadena[i]>165){
				retorno=0;
				break;
			}
		}
	return retorno;
}
/// @brief funcion final para pedir un entero, utilizando varias funciones que le dan seguridad y otros agregando parametros como Rango y Reintentos.
///
/// @param pResultado - puntero donde se guardara el numero ingresado por el usuario
/// @param mensaje	- mensaje en pantalla antes de pedir al usuario ingresar el numero.
/// @param mensajeError - mensaje de error por si el usuario no ingresa un numero valido.
/// @param minimo - el minimo valor aceptado.
/// @param maximo - el maximo valor aceptado
/// @param reintentos - la cantidad de reintentos por si falla constantemente.
void utn_getIntRango(int* pResultado, char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos){

	int buffer;
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&minimo<=maximo&&reintentos>=0){
		do{
			printf("%s",mensaje);
			if(getInt(&buffer)==0&&buffer>=minimo&&buffer<=maximo){
				*pResultado=buffer;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}

}
/// @brief funcion final para pedir un Nombre o Apellido, utilizando varias funciones que le dan seguridad y otros agregando parametros como mensaje, mensaje de error y Reintentos.
///
/// @param pResultado - el puntero donde se guarde lo ingresado por el usuario
/// @param tam - tamaño del puntero, para asegurarnos de no desbordar el vector.
/// @param mensaje	mensaje que vera el usuario antes de pedirle que ingrese datos
/// @param mensajeError - el mensaje que se mostrara si el usuario no ingresa datos validos.
/// @param reintentos - la cantidad de reintentos por si falla constantemente.
void utn_getCharNombre(char*pResultado,int tam, char* mensaje,char* mensajeError, int reintentos){
	char buffer[4096];
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0){
		do{
			printf("%s",mensaje);
			if(getChar(buffer,tam)==1){
				PrimerasLetrasMayuscula(buffer);
				strncpy(pResultado,buffer,tam);
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
}
/// @brief toma una cadena de caracteres y devuelve la misma cadena con la primer letra de cada palabra mayuscula
///
/// @param mensaje - el vector char que se modificara
/// @return
int PrimerasLetrasMayuscula(char*mensaje){
	int i;
	mensaje[0]=toupper(mensaje[0]);
	for(i=1;mensaje[i]!='\0';i++){
		mensaje[i]=tolower(mensaje[i]);
		if(mensaje[i-1]==32){
			mensaje[i]=toupper(mensaje[i]);
		}
	}
	return 1;
}



/// @brief funcion final para pedir un numero int, utilizando varias funciones que le dan seguridad y otros agregando parametros como mensaje, mensaje de error y Reintentos.
///
///
/// @param pResultado - puntero que devuelve el numero ingresado
/// @param mensaje - mensaje que se le muestra al usuario antes de pedirle un numero
/// @param mensajeError - mensaje de error que se le muestra al usuario si ingresa algun caracter fuera de los permitidos
/// @param reintentos - cuantos intentos tiene el usuario de poder llegar a ingresar un numero correctamente
void utn_getInt(int*pResultado, char*mensaje,char*mensajeError, int reintentos){
	int buffer;
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0){
		do{
			printf("%s",mensaje);
			if(getInt(&buffer)==0){
				*pResultado=buffer;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
}
/// @brief funcion final para pedir un numero float, utilizando varias funciones que le dan seguridad y otros agregando parametros como mensaje, mensaje de error y Reintentos.
///
///
/// @param pResultado - puntero que devuelve el numero ingresado
/// @param mensaje - mensaje que se le muestra al usuario antes de pedirle un numero
/// @param mensajeError - mensaje de error que se le muestra al usuario si ingresa algun caracter fuera de los permitidos
/// @param reintentos - cuantos intentos tiene el usuario de poder llegar a ingresar un numero correctamente

void utn_getFloat(float*pResultado,char*mensaje,char*mensajeError, int reintentos){

	float buffer;
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0){
		do{
			printf("%s",mensaje);
			if(getFloat(&buffer)==0){
				*pResultado=buffer;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
}
/// @brief funcion final para pedir un Nombre o Apellido, utilizando varias funciones que le dan seguridad y otros agregando parametros como mensaje, mensaje de error y Reintentos.
///
/// @param pResultado - el puntero donde se guarde lo ingresado por el usuario
/// @param tam - tamaño del puntero, para asegurarnos de no desbordar el vector.
/// @param mensaje	mensaje que vera el usuario antes de pedirle que ingrese datos
/// @param mensajeError - el mensaje que se mostrara si el usuario no ingresa datos validos.
/// @param reintentos - la cantidad de reintentos por si falla constantemente.
int utn_getCharSorN(char SorN[],char* mensaje,char* mensajeError){
	char buffer[3];

	int bandera=0;
	if(mensaje!=NULL&&mensajeError!=NULL){
		do{
			printf("%s",mensaje);
			if(getChar(buffer,3)==1){
				buffer[0]=toupper(buffer[0]);
			}
			if(buffer[0]=='S'|| buffer[0]=='N'){
				bandera=1;
				strncpy(SorN,buffer,3);
				break;
			}
			printf("%s",mensajeError);


		}while(bandera==0);
	}
	return bandera;
}
//FIRMA
void Firma(void){

	printf("========================================DANIEL MANRESA========================================\n");
	printf("||  ::::::::  :::::::::: ::::::::::   :::::::::  :::::::::: :::::::::   ::::::::  :::   ::: ||\n");
	printf("|| :+:    :+: :+:        :+:          :+:    :+: :+:        :+:    :+: :+:    :+: :+:   :+: ||\n");
	printf("|| +:+    +:+ +:+        +:+          +:+    +:+ +:+        +:+    +:+ +:+         +:+ +:+  ||\n");
	printf("|| +#+    +:+ :#::+::#   :#::+::#     +#++:++#+  +#++:++#   +#++:++#:  +#+          +#++:   ||\n");
	printf("|| +#+    +#+ +#+        +#+          +#+        +#+        +#+    +#+ +#+           +#+    ||\n");
	printf("|| #+#    #+# #+#        #+#          #+#        #+#        #+#    #+# #+#    #+#    #+#    ||\n");
	printf("||  ########  ###        ###          ###        ########## ###    ###  ########     ###    ||\n");
	printf("========================================DANIEL MANRESA========================================\n");
	Sleep(5000);
}
