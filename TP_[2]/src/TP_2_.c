/*
 * DANIEL MANRESA
 * DIVICION C
 * DNI 34940336
 ============================================================================
 1 Enunciado
Una empresa requiere un sistema para administrar su nómina de
empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
Datos:
int id - char name[51] - char lastName[51] - float salary - int sector - int isEmpty

El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se
detallan las funciones que esta biblioteca debe tener.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include "ArrayEmployee.h"
#include "biblioteca.h"
#include "menu.h"

#define TAM 1000

int main(void){
	setbuf(stdout,NULL);
	int opcion;
	int opcionModificacion;
	int opcionListado;
	int crecienteDecreciente;
	int posicion;
	int id=0;
	int contadorAltas=0;
	char sOrN[3];
	float acumuladorSalary=0;
	float promedioSalary;
	int employeePromSalary=0;
	int auxId;

	Employee listEmployee[TAM];


	if(InitEmployee(listEmployee,TAM)==0){
		printf("======PROGRAMA=INICIADO=======");
	}

	do{
		Menu(&opcion);// FUNCION MENU EN "menu.c"

		switch(opcion){
		case 1:				// 1- DAR ALTA EMPLEADO
			system("cls");
			if(contadorAltas!=TAM){ // SI EL PROGRAMA NO ESTA LLENO
				printf("============ALTA=EMPLEADOS============\n");
				AgregarEmpleado(listEmployee,&id,TAM );
				printf("==========FIN=ALTA=EMPLEADOS==========\n");
				contadorAltas++; // CUENTO LOS EMPLEADOS EN ALTA
			}
			else{
				printf("============PROGRAMA=LLENO============\n");
			}
			break;
		case 2: // 2- MODIFICAR DATOS DE EMPLEADOS.
			system("cls");
			if(id==0){
				printf("======NO=HAY=EMPLEADOS=CARGADOS=======");
			}
			else{
				if(contadorAltas==0){
					printf("======NO=HAY=EMPLEADOS=EN=ALTA=======");
				}
				else{
					do{//PIDO ID DEL EMPLEADO A MODIFICAR
						utn_getInt(&auxId,"Ingrese el id del empleado a modificar: ","ERROR! ID INVALIDO INTENTE DENUEVO!\n" , 5);
						posicion=findEmployeeById(listEmployee, TAM, auxId);
						if(posicion==-1){
						printf("===NO=SE=ENCONTRO=UN=EMPLEADO=CON=ESE=ID===\n");
						}
					}while(posicion==-1);
					do{//MENU MODIFICACION
						MenuModificacion(&opcionModificacion);
						switch(opcionModificacion){
							case 1://NOMBRE
								system("cls");
								utn_getCharNombre(listEmployee[posicion].name, 51, "Ingrese el NUEVO Nombre del empleado: ", "ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n", 5);
								break;
							case 2://APELLIDO
								system("cls");
								utn_getCharNombre(listEmployee[posicion].lastName, 51, "Ingrese el NUEVO Apellido del empleado: ", "ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n", 5);
								break;
							case 3://SALARIO
								system("cls");
								utn_getFloat(&listEmployee[posicion].salary, "Ingrese el NUEVO sueldo del empleado: ", "ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n",5);
								break;
							case 4://SECTOR
								system("cls");
								utn_getInt(&listEmployee[posicion].sector,"Ingrese el NUEVO sector asiganado para el empleado: ","ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n" , 5);
								break;
							case 5://VOLVER/ATRAS
								printf("==========ATRAS===========\n");
								break;
							}
					}while(opcionModificacion!=5);
				}
			}
			break;
		case 3://DAR DE BAJA UN EMPLEADO
			system("cls");
			if(id==0){
				printf("======NO=HAY=EMPLEADOS=CARGADOS=======");
			}
			else{
				if(contadorAltas==0){
					printf("======NO=HAY=EMPLEADOS=EN=ALTA=======");
				}
				else{
					do{//PIDO ID DEL EMPLEADO A MODIFICAR
						utn_getInt(&auxId,"Ingrese el ID del empleado a dar de baja: ","ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n" , 5);
						posicion=findEmployeeById(listEmployee, TAM, auxId);
						if(posicion==-1){
							printf("No existe un empleado con ese ID\n");
						}
						else{
							if(listEmployee[posicion].isEmpty==1){
								printf("El empleado con ese ID ya estaba dado de baja.\n");

							}
							else{//PREGUNTO SI ESTA SEGURO
								if(utn_getCharSorN(sOrN, "¿Esta seguro de dar la baja? <s/n>\n", "ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n")==1){
									if(sOrN[0]=='S'){
										listEmployee[posicion].isEmpty=1;
										contadorAltas--;
										printf("====EMPLEADO=DADO=DE=BAJA====\n");
									}
									else{
										printf("=========BAJA=CANCELADA=========\n");
									}
								}

							}
						}
					}while(posicion==-1);

				}
			}
			break;
		case 4://4-MOSTRAR LISTAS
			system("cls");
			if(id==0){
				printf("======NO=HAY=EMPLEADOS=CARGADOS=======");
			}
			else{
				if(contadorAltas==0){
					printf("======NO=HAY=EMPLEADOS=EN=ALTA=======");
				}
				else{
					do{//MENU LISTADO
						MenuListado(&opcionListado);
						switch(opcionListado){
						case 1://1-LISTA DE EMPLEADOS
							system("cls");
							MenuOrdenamiento(&crecienteDecreciente);
							switch(crecienteDecreciente){
								case 1://ORDEN ASCENDENTE
									system("cls");
									if(sortEmployees(listEmployee, TAM, 1)==0){
										printf("============LISTA=EMPLEADOS============\n");
										printf("=ID==NOMBRE=====APELLIDO===SALARIO====SECTOR=\n");
										printEmployees(listEmployee, TAM);
									}
									break;
								case 2://ORDEN DESCENDENTE
									system("cls");
									if(sortEmployees(listEmployee, TAM, 0)==0){
										printf("============LISTA=EMPLEADOS============\n");
										printf("=ID==NOMBRE=====APELLIDO===SALARIO====SECTOR=\n");
										printEmployees(listEmployee, TAM);
									}
									break;
							}
							break;
						case 2://LISTA INFORMACION SALARIOS
							system("cls");
							ListSalaryGenerate(listEmployee, TAM, &acumuladorSalary, contadorAltas,&promedioSalary,&employeePromSalary);
							printf("==============LISTA=INFO=SALARIOS================\n");
							printf("====SALARIO=TOTAL===PROMEDIO===SOBRE=PROMEDIO====\n");
							printf("    %.2f             %.2f        %d\n",acumuladorSalary,promedioSalary,employeePromSalary);
							printf("================FIN=INFO=SALARIOS===============\n");
							break;
						case 3:
							system("cls");
							printf("==========ATRAS==========\n");
							break;
						}
					}while(opcionListado!=3);


				}
			}
			break;
		case 5://SALIR
			system("cls");
			Firma();
			break;
		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}
