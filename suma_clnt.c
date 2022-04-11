/*
 *
 * Este es el stub del programa, su funcion es serializar los parametros para despues llamar
 * al procedimiento remoto y poder devolver los resultados
 * 
 */

#include <memory.h> /* for memset */
#include "suma.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };//tiempo para que el servidor responda

int *
suma_1(dupla_int *argp, CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	//funcion para llamar al procedimiento remoto
	if (clnt_call (clnt/*apuntador para llamar a la funcion de creacion del cliente*/, SUMA,   
		(xdrproc_t) xdr_dupla_int, (caddr_t) argp,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
