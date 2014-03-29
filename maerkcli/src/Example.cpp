/* Programa C++ que se vale de la funcionalidad de la librería de desarrollo de
   la clase cliente */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "Args.h"       //Argumentos y parametros del proyecto
#include "Client.h"     //Clase cliente

Client *cli; // Clase Cliente

// Manejador de senal para capturar los eventos de monitorizacion
void event(int n) { 	
	char msg[LENMSG];

	cli -> readEvent(msg); // Leer informacion del evento recibido
	printf("%s", msg);     // Mostrarla por pantalla
}

int main(int argc, char **argv) {
	
	int status;
	arguments ar;    // Tipo Argumentos
	attr maerkAttr;  // Tipo Atributos de control

	ar.argc = argc;
	ar.argv = argv;
	ar.pid = getpid(); // Pid del proceso principal

	signal(SIGALRM, event);  // Instalar un manejador para SIGALARM
	cli = Client::Instance();

	if(cli -> init(ar)) {   // Lanzar el hilo cliente
		printf("Error al lanzar el hilo cliente");
		return -1;
	}

	maerkAttr.idConLocom = 3; // Locomotora 3
	maerkAttr.vel = 10;       // Velocidad 10
	maerkAttr.dir = DIR_C;    // Sentido Horario

	cli -> ctrlInvocation(ar, OPCON, maerkAttr); // Enviar orden de control (OPCON)
	
	maerkAttr.idFunLocom = 8; // Locomotora 8
	maerkAttr.fun = 4;        // Funcion 4
	maerkAttr.fstat = ON;     // Estado ON

	cli -> ctrlInvocation(ar, OPFUN, maerkAttr); // Enviar orden de funcion adicional (OPFUN)
	
	maerkAttr.idSole = 10;    // Cambio 10
	maerkAttr.sstat = CLOSE;  // Estado cerrado

	cli -> ctrlInvocation(ar, OPSOLE, maerkAttr); // Enviar orden de cambio de via (OPSOLE)
	pause();

	status = cli -> end();

	return status;
}
