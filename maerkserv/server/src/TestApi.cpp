/* Test de la API que interactuar con una maqueta de tren digital modelo Märklin
 * J.Manuel Muñoz Mazuecos - Ingeniería informática */

#include <stdio.h>
#include "Args.h"
#include "Api_marklin.h"

#define ZERO 0x00000000

int checkFail(unsigned long command);
int setLocom(ApiMarklin *api);
int funTest(ApiMarklin *api);
int soleTest(ApiMarklin *api);

int checkFail(unsigned long command) {
	if(command == ZERO) {
		return 0;
	} else {
		return command;
	}
}

int checkCorrect(unsigned long command) {
	if(command != ZERO) {
		return command;
	} else {
		return 0;
	}
}

int locTest(ApiMarklin *api) {

	unsigned long command;
	int i, j, k;

	printf("ApiTest: Valores fuera de rango para control de locomotoras, se espera fallo \n");
	/* SetLocom */
	/* Locom Range Limits */
	command = checkFail(api -> setLocom(MIN_LOCOM - 1, 1, 1));
	if(command) return -1;
	api -> printU32(command);
	
	command = checkFail(api -> setLocom(MAX_LOCOM + 1, 1, 1));
	if(command) return -1;
	api -> printU32(command);

	/* Vel Range Limits */
	command = checkFail(api -> setLocom(1, MIN_VEL - 1, 1));
	if(command) return -1;
	api -> printU32(command);
	
	command = checkFail(api -> setLocom(1, MAX_VEL + 1, 1));
	if(command) return -1;
	api -> printU32(command);

	/* Dir Range Limits */
	command = checkFail(api -> setLocom(1, 1, DIR_C + 1));
	if(command) return -1;
	api -> printU32(command);
	
	command = checkFail(api -> setLocom(1, 1, DIR_O -1));
	if(command) return -1;
	api -> printU32(command);
	
	printf("ApiTest: Comandos posibles de control de locomotoras, no se espera fallo \n");
	for(i = MIN_LOCOM; i <= MAX_LOCOM; i++) {
		for(j = MIN_VEL; j <= MAX_VEL; j++) {
			for(k = DIR_O; k <= DIR_C; k++) {
				command = checkCorrect(api -> setLocom(i, j, k));
				if(!command) return -1;
			}	
		}
	}
	return 0;
}

int funTest(ApiMarklin *api) {

	unsigned long command;
	int i, j, k;

	printf("ApiTest: Valores fuera de rango para funciones, se espera fallo \n");
	/* SetFunc */
	/* Locom Range Limits */
	command = checkFail(api -> setFunc(MIN_LOCOM - 1, 1, 1));
	if(command) return -1;
	api -> printU32(command);
	
	command = checkFail(api -> setFunc(MAX_LOCOM + 1, 1, 1));
	if(command) return -1;
	api -> printU32(command);

	/* Fun Range Limits */
	command = checkFail(api -> setFunc(1, MIN_FUN - 1, 1));
	if(command) return -1;
	api -> printU32(command);
	
	command = checkFail(api -> setFunc(1, MAX_FUN + 1, 1));
	if(command) return -1;
	api -> printU32(command);

	/* ON/OFF Range Limits */
	command = checkFail(api -> setFunc(1, 1, ON + 1));
	if(command) return -1;
	api -> printU32(command);
	
	command = checkFail(api -> setFunc(1, 1, OFF - 1));
	if(command) return -1;
	api -> printU32(command);
	
	printf("ApiTest: Generar todos los comandos de funciones, no se espera fallo \n");
	for(i = MIN_LOCOM; i <= MAX_LOCOM; i++) {
		for(j = MIN_FUN; j <= MAX_FUN; j++) {
			for(k = OFF; k <= ON; k++) {
				command = checkCorrect(api -> setFunc(i, j, k));
				if(!command) return -1;
			}	
		}
	}
	return 0;
}

int soleTest(ApiMarklin *api) {

	unsigned long command;
	int i, j;

	printf("ApiTest: Valores fuera de rango para solenoides, se espera fallo \n");
	
	/* SetSole*/
	/* Locom Range Limits */
	command = checkFail(api -> setSole(MIN_SOLE - 1, 1));
	if(command) return -1;
	api -> printU32(command);
	
	command = checkFail(api -> setSole(MAX_SOLE + 1, 1));
	if(command) return -1;
	api -> printU32(command);

	/* OPEN/CLOSE Range Limits */
	command = checkFail(api -> setSole(1, OPEN + 1));
	if(command) return -1;
	api -> printU32(command);
	
	command = checkFail(api -> setSole(1, CLOSE -1));
	if(command) return -1;
	api -> printU32(command);
	
	printf("ApiTest: Generar todos los comandos de solenoides, no se espera fallo \n");
	for(i = MIN_SOLE; i <= MAX_SOLE; i++) {
		for(j = CLOSE; j <= OPEN; j++) {
			command = checkCorrect(api -> setSole(i, j));
			if(!command) return -1;
		}	
	}
	return 0;
}

int main(void) {

	int ret;
	ApiMarklin *api;
	
	api = ApiMarklin::Instance();

	/*unsigned long command;
	command = checkCorrect(api -> setLocom(1, 10, 1));
	if(!command) return -1;*/

	ret = locTest(api);
	if(ret == -1) {
		printf("ApiTest: Test de control de locomotoras fallido \n");
	} else {
		printf("ApiTest: Test de control de locomotoras correcto \n");
	}

	ret = funTest(api);
	if(ret == -1) {
		printf("ApiTest: Test de funciones de locomotoras fallido \n");
	} else {
		printf("ApiTest: Test de funciones de locomotoras correcto \n");
	}

	ret = soleTest(api);
	if(ret == -1) {
		printf("ApiTest: Test de solenoides fallido \n");
	} else {
		printf("ApiTest: Test de solenoides correcto \n");
	}

	return 0;
}
