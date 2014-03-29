/* Tester del programa cliente */

#include <stdio.h>
#include <signal.h>
#include "Args.h"
#include "Client.h"

#define LENMSG 256

void initAttr();
void event(int n);
void setLocAttr(int idLocom, int vel, int dir);
void setFunAttr(int idLocom, int fun, int stat);
void setSolAttr(int idSole, int stat);
int testLoc();
int testFun();
int testSole();
int testCop();

Client *cli;
arguments ar;
attr maerkAttr;

void event(int n) {
	char msg[LENMSG];
	
	cli -> readEvent(msg);
	printf("%s \n", msg);
}

void initAttr() {
	maerkAttr.idConLocom = -1;
	maerkAttr.vel = -1;
	maerkAttr.dir = DIR_C;
	maerkAttr.idFunLocom = -1;
	maerkAttr.fun = -1;
	maerkAttr.fstat = ON;
	maerkAttr.idSole = -1;
	maerkAttr.sstat = CLOSE;
}

void setLocAttr(int idLocom, int vel, int dir) {
	maerkAttr.idConLocom = idLocom;
	maerkAttr.vel = vel;
	maerkAttr.dir = dir;
}

void setFunAttr(int idLocom, int fun, int stat) {
	maerkAttr.idFunLocom = idLocom;
	maerkAttr.fun = fun;
	maerkAttr.fstat = stat;
}

void setSolAttr(int idSole, int stat) {
	maerkAttr.idSole = idSole;
	maerkAttr.sstat = stat;
}

int testLoc() {
	int i, j, k;

	printf("ClientTest: Valores fuera de rango para control de locomotoras, se espera fallo \n");
	setLocAttr(MIN_LOCOM - 1, 1, 1);
	if(cli -> ctrlInvocation(ar, OPCON, maerkAttr) == 0) {
		return -1;
	}

	setLocAttr(MAX_LOCOM + 1, 1, 1);
	if(cli -> ctrlInvocation(ar, OPCON, maerkAttr) == 0) {
		return -1;
	}
	
	setLocAttr(1, MIN_VEL - 1, 1);
	if(cli -> ctrlInvocation(ar, OPCON, maerkAttr) == 0) {
		return -1;
	}
	
	setLocAttr(1, MAX_VEL + 1, 1);
	if(cli -> ctrlInvocation(ar, OPCON, maerkAttr) == 0) {
		return -1;
	}

	setLocAttr(1, 1, DIR_C + 1);
	if(cli -> ctrlInvocation(ar, OPCON, maerkAttr) == 0) {
		return -1;
	}
	
	setLocAttr(1, 1, DIR_O - 1);
	if(cli -> ctrlInvocation(ar, OPCON, maerkAttr) == 0) {
		return -1;
	}

	printf("ClientTest: Comandos posibles de control de locomotoras, no se espera fallo \n");
	for(i = MIN_LOCOM; i <= MAX_LOCOM; i++) {
		for(j = MIN_VEL; j <= MAX_VEL; j++) {
			for(k = DIR_O; k <= DIR_C; k++) {

				setLocAttr(i, j, k);
				if(cli -> ctrlInvocation(ar, OPCON, maerkAttr) == -1) {
					return -1;
				}
			}
		}
	}

	return 0;
}

int testFun() {
	int i, j, k;

	printf("ClientTest: Valores fuera de rango de las funciones, se espera fallo \n");
	setLocAttr(MIN_LOCOM - 1, 1, 1);
	if(cli -> ctrlInvocation(ar, OPFUN, maerkAttr) == 0) {
		return -1;
	}

	setFunAttr(MAX_LOCOM + 1, 1, 1);
	if(cli -> ctrlInvocation(ar, OPFUN, maerkAttr) == 0) {
		return -1;
	}
	
	setFunAttr(1, MIN_FUN - 1, 1);
	if(cli -> ctrlInvocation(ar, OPFUN, maerkAttr) == 0) {
		return -1;
	}
	
	setFunAttr(1, MAX_FUN + 1, 1);
	if(cli -> ctrlInvocation(ar, OPFUN, maerkAttr) == 0) {
		return -1;
	}

	setFunAttr(1, 1, ON + 1);
	if(cli -> ctrlInvocation(ar, OPFUN, maerkAttr) == 0) {
		return -1;
	}
	
	setFunAttr(1, 1, OFF - 1);
	if(cli -> ctrlInvocation(ar, OPFUN, maerkAttr) == 0) {
		return -1;
	}

	printf("ClientTest: Comandos posibles de funciones, no se espera fallo \n");
	for(i = MIN_LOCOM; i <= MAX_LOCOM; i++) {
		for(j = MIN_FUN; j <= MAX_FUN; j++) {
			for(k = OFF; k <= ON; k++) {

				setFunAttr(i, j, k);
				if(cli -> ctrlInvocation(ar, OPFUN, maerkAttr) == -1) {
					return -1;
				}
			}
		}
	}

	return 0;
}

int testSole() {
	int i, j;

	printf("ClientTest: Valores fuera de rango de los solenoides, se espera fallo \n");
	setSolAttr(MIN_SOLE - 1, 1);
	if(cli -> ctrlInvocation(ar, OPSOLE, maerkAttr) == 0) {
		return -1;
	}

	setSolAttr(MAX_SOLE + 1, 1);
	if(cli -> ctrlInvocation(ar, OPSOLE, maerkAttr) == 0) {
		return -1;
	}
	
	setSolAttr(1, OPEN + 1);
	if(cli -> ctrlInvocation(ar, OPSOLE, maerkAttr) == 0) {
		return -1;
	}
	
	setSolAttr(1, CLOSE - 1);
	if(cli -> ctrlInvocation(ar, OPSOLE, maerkAttr) == 0) {
		return -1;
	}

	printf("ClientTest: Comandos posibles de funciones, no se espera fallo \n");
	for(i = MIN_LOCOM; i <= MAX_LOCOM; i++) {
		for(j = CLOSE; j <= OPEN; j++) {

			setSolAttr(i, j);
			if(cli -> ctrlInvocation(ar, OPSOLE, maerkAttr) == -1) {
				return -1;
			}
		}
	}
	return 0;
}

int testCop() {

	printf("ClientTest: Valores fuera de rango para el código de operación, se espera fallo \n");
	setLocAttr(1, 1, 1);
	if(cli -> ctrlInvocation(ar, OPCON - 1, maerkAttr) == 0) {
		return -1;
	}

	setLocAttr(1, 1, 1);
	if(cli -> ctrlInvocation(ar, OPCON - 1, maerkAttr) == 0) {
		return -1;
	}

	setSolAttr(1, 1);
	if(cli -> ctrlInvocation(ar, OPSOLE + 1, maerkAttr) == 0) {
		return -1;
	}

	setSolAttr(1, 1);
	if(cli -> ctrlInvocation(ar, OPSOLE + 1, maerkAttr) == 0) {
		return -1;
	}
	return 0;
}

int main(int argc, char **argv) {

	int ret;

	signal(SIGALRM, event);
	
	ar.argc = argc;
	ar.argv = argv;
	ar.pid = getpid();

	cli = Client::Instance();

	if(!cli -> init(ar)) {

		ret = testLoc();
		if(ret == -1) {
			printf("ClientTest: test de control de locomotoras fallido \n");
		} else {
			printf("ClientTest: test de control de locomotoras correcto \n");
		}

		ret = testFun();
		if(ret == -1) {
			printf("ClientTest: test de funciones fallido \n");
		} else {
			printf("ClientTest: test de funciones correcto \n");
		}

		ret = testSole();
		if(ret == -1) {
			printf("ClientTest: test de solenoides fallido \n");
		} else {
			printf("ClientTest: test de solenoides correcto \n");
		}

		ret = testCop();
		if(ret == -1) {
			printf("ClientTest: test de cod operación fallido \n");
		} else {
			printf("ClientTest: test de cod operación correcto \n");
		}
	}
	else {
		printf("Fallo al lanzar el hilo del cliente \n");
	}

	printf("Pulsa Ctrl-c para salir \n");
	pause();
	cli -> end();
	
	return 0;
}
	