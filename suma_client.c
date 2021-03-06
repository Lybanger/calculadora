/*
 * 
 *Este archivo tiene el main del cliente, hace conexion con el stub y manda los resultados al cliente
 *
 */

#include "suma.h"
#include <stdio.h>


void
suma_prog_1(char *host,int a,int b)//funcion encargada de las variables a utilizar entre el cliente y servidor
{
	CLIENT *clnt;
	int  *result_1;
	dupla_int  suma_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp");//funcion para la creacion del cliente
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	suma_1_arg.a = a;
	suma_1_arg.b = b;

	result_1 = suma_1(&suma_1_arg, clnt);//funcion para el retorno del resultado y llamada al stub
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else {printf("result = %d\n", *result_1);
}

#ifndef	DEBUG
	clnt_destroy (clnt);//mata al cliente
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])//funcion principal del programa
{
char *host;
int a, b;
if (argc != 4) {
printf ("usage: %s server_host num1 num2\n", argv[0]);//imprime los parametros ingresados por el cliente
exit(1);
}
host = argv[1];
if ((a = atoi(argv[2])) == 0 && *argv[2] != '0') {//termina el programa si el parametro ingresado es incorrecto
fprintf(stderr, "invalid value: %s\n", argv[2]);
exit(1);
}
if ((b = atoi(argv[3])) == 0 && *argv[3] != '0') {//termina el programa si el parametro ingresado es incorrecto
fprintf(stderr, "invalid value: %s\n", argv[3]);
exit(1);
}
suma_prog_1(host, a, b);//manda los parametros al servidor para que este haga las operaciones
}

