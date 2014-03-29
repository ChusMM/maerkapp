/* Aplication parameters
 * Jesús Manuel Muñoz Mazuecos - Ingeniería informática */

#include <sys/types.h>

#ifndef __Args_H_INCLUDED__
#define __Args_H_INCLUDED__

/* API value ranges constants*/
#define MAX_LOCOM 10
#define MIN_LOCOM  1

#define MAX_VEL 14
#define MIN_VEL  0
#define DIR_C 1
#define DIR_O 0

#define MAX_FUN 4
#define MIN_FUN 1
#define ON  1
#define OFF 0

#define MAX_SOLE 10
#define MIN_SOLE  1
#define OPEN  1
#define CLOSE 0

#define COMM_LEN 12

typedef struct {
	int argc;
	char **argv;
	pid_t pid;
} arguments;

typedef struct {
	int idConLocom;
	int vel;
	int dir;
	int idFunLocom;
	int fun;
	int fstat;
	int idSole;
	int sstat;
} attr;
#endif
