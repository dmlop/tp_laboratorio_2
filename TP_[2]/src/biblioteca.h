

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int myGets(char* cadena,int tam);
int getInt(int* pResultado);
int getFloat(float* pResultado);
int esNumericaInt(char* cadena);
int esNumericaFloat(char* cadena);
void utn_getIntRango(int*pResultado,char*mensaje,char*mensajeError,int minimo, int maximo, int reintentos);
int esTextoBasico(char* cadena);
void utn_getCharNombre(char*,int, char*,char*,int);
int getChar(char* pResultado, int tam);
int PrimerasLetrasMayuscula(char*mensaje);
int utn_getCharSorN(char SorN[],char* mensaje,char* mensajeError);
void utn_getInt(int*pResultado, char* mensaje,char* mensajeError,int reintentos);
void utn_getFloat(float* pResultado, char* mensaje,char* mensajeError,int reintentos);
//FIRMA
void Firma(void);

#endif /* BIBLIOTECA_H_ */
