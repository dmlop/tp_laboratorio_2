
#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int InitEmployee(Employee vList[],int tam);
int addEmployee(Employee* vList, int tam, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* vList, int tam,int id);
int removeEmployee(Employee* vList, int tam, int id);
int sortEmployees(Employee* vList, int tam, int order);
int printEmployees(Employee vListaEmployee[],int tam);
void ListSalaryGenerate(Employee vListaEmployee[],int tam,float*acumulador, int altas,float*promedioSalary,int*contadorEmpleadoSalarioMayorQuePromedio);
void AgregarEmpleado(Employee* vList,int*id,int tam );

#endif /* ARRAYEMPLOYEE_H_ */
