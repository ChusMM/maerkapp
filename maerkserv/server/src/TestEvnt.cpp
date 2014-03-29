/* Tester del programa de notificación */

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

int main() {

	int fd = -1;
	int count = 0;
	char buf[COMM_LEN];

	if((fd = open(COMM_CHARDEV, O_RDWR)) < 0) {
		printf("Error: opening char device, open \n");
	}
	

	printf("Generar 10 eventos, uno por 1 segundo \n");
	while(count < 10) {
		if(ioctl(fd, READ_IOCTL, buf) < 0) {
			printf("Error: reading on char device, read_ioctl \n");
		}
		sleep(1);
		count ++;
	}

	count = 0;
	printf("Generar 20 eventos, dos por segundo \n");
	while(count < 10) {

		if(ioctl(fd, READ_IOCTL, buf) < 0) {
			printf("Error: reading on char device, read_ioctl \n");
		}
		if(ioctl(fd, READ_IOCTL, buf) < 0) {
			printf("Error: reading on char device, read_ioctl \n");
		}
		sleep(1);
		count ++;
	}

	count = 0;
	printf("Generar 100 eventos seguidos a velocidad de cómputo \n");
	while(count < 10) {
		if(ioctl(fd, READ_IOCTL, buf) < 0) {
			printf("Error: reading on char device, read_ioctl \n");
		}
		count ++;
	}

	//pause();
	
	close(fd);
}