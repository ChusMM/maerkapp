/* Tester del módulo del kernel */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "Args.h"

/* ioctl paramenters */
#define MY_MACIG 'G'
#define READ_IOCTL _IOR  (MY_MACIG, 0, int)
#define WRITE_IOCTL _IOW (MY_MACIG, 1, int)

/* Char devices location */
#define COMM_CHARDEV "/dev/command_chardev"

#define INVCOP  "0x0a0100005"
#define VALCOP1 "0x0a0100003"
#define VALCOP2 "0x0a0100001"

int main() {

	int fd = -1;
	int i;
	char overflow[COMM_LEN * 2];

	for(i = 0; i < COMM_LEN * 2; i++) {
		overflow[i] = 'a';
	}

	printf("Test, de desbordamiento de buffer \n");

	if((fd = open(COMM_CHARDEV, O_RDWR)) < 0) {
		printf("Error: opening char device, open \n");
	}

	if(ioctl(fd, WRITE_IOCTL, overflow) < 0) {
		printf("Error: writing on char device, write_ioctl \n");
	}

	printf("Test, de código de operación inválido \n");

	if(ioctl(fd, WRITE_IOCTL, INVCOP) < 0) {
		printf("Error: writing on char device, write_ioctl \n");
	}

	printf("Test, de código de operación válido \n");

	if(ioctl(fd, WRITE_IOCTL, VALCOP1) < 0) {
		printf("Error: writing on char device, write_ioctl \n");
	}

	if(ioctl(fd, WRITE_IOCTL, VALCOP2) < 0) {
		printf("Error: writing on char device, write_ioctl \n");
	}

	close(fd);

	printf("Test del módulo del kernel finalizado, comprueba el fichero de log ($ dmesg) \n");
}