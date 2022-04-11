/*
 * 
 * En este codigo se implementan los procedimientos remotos
 * 
 */

#include "suma.h"

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp) //funcion para hacer las operaciones correspondientes
{
	static int  result; //variable estatica para el resultado

	/*
	 * insert server code here
	 */

	printf("Server response to client...\n");
	printf("parameters: %d, %d\n", argp->a, argp->b);
	result = argp->a + argp->b;
	printf("returning: %d\n", result);

	return &result;//variable de retorno para el resultado
}
