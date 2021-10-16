

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#include "ArrayEmployee.h"
/// @brief Inicia el vector de empleados en estado Libre
///
/// @param vList vector de empleados
/// @param tam tamaño del vector
/// @return
int InitEmployee(Employee vList[],int tam){
	for(int i=0;i<tam;i++){
		vList[i].isEmpty=1;
	}
	return 0;
}
/// @brief Usa los parametros pasados para agregar un empleado a la lista
///
/// @param vList- vector de empleados
/// @param tam -tamaño del vector
/// @param id -id que se le asigna al nuevo empleado
/// @param name - nombre del nuevo empleado
/// @param lastName - apellido del nuevo empleado
/// @param salary - salario asignado al nuevo empleado
/// @param sector - sector asignado al nuevo empleado
/// @return
int addEmployee(Employee* vList, int tam, int id, char name[],char lastName[],float salary,int sector){
	int retorno=-1;
	int i;
	for(i=0;i<tam;i++){
		if(vList[i].isEmpty==1){
			break;
		}
	}

	vList[i].id=id;
	strncpy(vList[i].name,name,51);
	strncpy(vList[i].lastName,lastName,51);
	vList[i].salary=salary;
	vList[i].sector=sector;
	vList[i].isEmpty=0;


	return retorno;
}
/// @brief Pide al usuario los dagos a guardar en un nuevo empleado
///
/// @param vList - vector de empleados
/// @param id - el contador de id unico
/// @param tam - tamaño del vector
void AgregarEmpleado(Employee *vList,int *id,int tam ){
	Employee aux;
	*id=*id+1;
	aux.id=*id;
	utn_getCharNombre(aux.name, 51, "Ingrese el Nombre del empleado: ", "ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n", 5);
	utn_getCharNombre(aux.lastName, 51, "Ingrese el Apellido del empleado: ", "ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n", 5);
	utn_getFloat(&aux.salary, "Ingrese el sueldo del empleado: ", "ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n",5);
	utn_getInt(&aux.sector,"Ingrese el sector asiganado para el empleado: ","ERROR! CARACTER INVALIDO! INTENTE DENUEVO!\n" , 5);
	addEmployee(vList, tam, aux.id, aux.name, aux.lastName, aux.salary, aux.sector);
}
/// @brief Usa el id pasado por parametro para buscar un empleado espesifico
///
/// @param vList - vector de empleados
/// @param tam - tamaño del vector
/// @param id - id del empleado a buscar
/// @return devuelve la posicion del empleado en vector lista de empleado
int findEmployeeById(Employee* vList, int tam,int id)
{

	int i;
	int posicion;
	for(i=0;i<tam;i++){
		if(vList[i].id==id&&vList[i].isEmpty==0){
			posicion=i;
			break;
		}
		else{
			if(i==tam-1&&vList[i].id!=id&&vList[i].isEmpty==1){
				posicion=-1;
				break;
			}
		}
	}
	return posicion;
}
/// @brief remueve a un empleado de forma logica del programa
///
/// @param vList - vector de empleados
/// @param tam - tamaño del vector
/// @param id - id del empleado a remover
/// @return
int removeEmployee(Employee* vList, int tam, int id){
	int retorno;
	int i;
	i=findEmployeeById(vList,tam,id);

	if(i!=-1){
		retorno=-1;
	}
	else{
		if(vList[i].isEmpty==1){
			retorno=0;
		}
		else{
			vList[i].isEmpty=1;
			retorno=1;
		}
	}

	return retorno;
}
/// @brief Ordena la informacion de los empleados de forma ascendente o descendente, por apellido y sector
///
/// @param vList - vector de empleados
/// @param tam - tamaño del vector
/// @param order - parametro de odenamiento; 0 para descendente y 1 para ascendente
/// @return
int sortEmployees(Employee* vList, int tam, int order){
	int i;
	int j;
	int retorno=0;
	Employee aux;
	if(order==1){
		for(i=0;i<tam-1;i++){
			for(j=i+1;j<tam;j++){
				if(vList[i].isEmpty==0 && vList[j].isEmpty==0 &&(strcmp(vList[i].lastName,vList[j].lastName)==1)){
					aux=vList[i];
					vList[i]=vList[j];
					vList[j]=aux;
				}
				else{
					if(vList[i].isEmpty==0 && vList[j].isEmpty==0 &&(strcmp(vList[i].lastName,vList[j].lastName)==0)&&(vList[i].sector>vList[j].sector)){
						aux=vList[i];
						vList[i]=vList[j];
						vList[j]=aux;
					}
				}
			}
		}
	}
	else{
		if(order==0){
			for(i=0;i<tam-1;i++){
				for(j=i+1;j<tam;j++){
					if(vList[i].isEmpty==0 && vList[j].isEmpty==0 &&(strcmp(vList[i].lastName,vList[j].lastName)==-1)){
						aux=vList[i];
						vList[i]=vList[j];
						vList[j]=aux;
					}
					else{
						if(vList[i].isEmpty==0 && vList[j].isEmpty==0 &&(strcmp(vList[i].lastName,vList[j].lastName)==0)&&(vList[i].sector<vList[j].sector)){
							aux=vList[i];
							vList[i]=vList[j];
							vList[j]=aux;
						}
					}
				}
			}
		}
		else{
			retorno=-1;
		}
	}
 return retorno;
}
/// @brief imprime la informacion de todos los empleados en alta
///
/// @param vListaEmployee - vector de empleados
/// @param tam - tamaño del vector
/// @return
int printEmployees(Employee vListaEmployee[],int tam){
	int retorno=0;
	int i;
	for(i=0;i<tam;i++){
		if(vListaEmployee[i].isEmpty==0){

			printf(" %d   %s\t%s  U$D %.2f\t%d\n",vListaEmployee[i].id,vListaEmployee[i].name,
					vListaEmployee[i].lastName,vListaEmployee[i].salary,vListaEmployee[i].sector);


		}
		else{
			if(i==tam-1&&vListaEmployee[i].isEmpty!=1){
				retorno=-1;
			}
		}
	}
	return retorno;
}
/// @brief Generador de toda la informacion sobre los Salarios de los empleados
///
/// @param vListaEmployee - Vector de empleados
/// @param tam - tamaño del vector
/// @param acumulador - acumulador de salarios
/// @param altas - cantidad de empledos cargados
/// @param promedioSalary - promedio de salario
/// @param contadorEmpleadoSalarioMayorQuePromedio -contador de empleados con salario mayor o igual al promedio
void ListSalaryGenerate(Employee vListaEmployee[],int tam,float*acumulador, int altas,float*promedioSalary,int*contadorEmpleadoSalarioMayorQuePromedio){
	int contadorIf=0;
	int posAltas[1000];
	*contadorEmpleadoSalarioMayorQuePromedio=0;
	*acumulador=0;
	*promedioSalary=0;

	for(int i=0;contadorIf<altas;i++){
		if(vListaEmployee[i].isEmpty==0){
			*acumulador=*acumulador+vListaEmployee[i].salary;
			posAltas[contadorIf]=i;
			contadorIf++;
		}
	}
	*promedioSalary=*acumulador/altas;
	for(int i=0;i<altas;i++){
		if(vListaEmployee[posAltas[i]].salary>*promedioSalary){
			*contadorEmpleadoSalarioMayorQuePromedio=*contadorEmpleadoSalarioMayorQuePromedio+1;
		}
	}
}




