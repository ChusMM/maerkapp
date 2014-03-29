/* API Header file.
 * Jesús Manuel Muñoz Mazuecos - Ingeniería informática */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "Args.h"
#include "Api_marklin.h"

ApiMarklin* ApiMarklin::pInstance = 0;

/* 
 * -----------------------------------------------------------------------------
 * Function: Instance. Constructor based on Singleton design pattern.
 * Return Value: An instance of ApiMarklin 
 * -----------------------------------------------------------------------------
 */
ApiMarklin* ApiMarklin::Instance() {

	if (pInstance == 0) {
		pInstance = new ApiMarklin; 
	}

	return pInstance;
}

/*
 * -----------------------------------------------------------------------------
 * Function: setLocom. It Collects the given command parameters for sending them 
 * to other function which builds an effective command. Then it calls other
 * function which sends the command to kernel space.
 * Parameters:
 *	int idLocom: Locomotive identifier
 *	int vel: Velocity
 *	int dir: Direction
 * Return Value:
 *	0: on error
 *	command value: on success 
 * -----------------------------------------------------------------------------
 */
unsigned long ApiMarklin::setLocom(int idLocom, int vel, int dir) {

	unsigned long command;
	
	command = buildLocom(idLocom, vel, dir);
	return checkSend(command, LOCOMOP);
}

/*
 * -----------------------------------------------------------------------------
 * Function: setFunc. It Collects the given command parameters for sending them 
 * to other function which builds an effective command. Then it calls other
 * function which sends the command to kernel space.
 * Parameters:
 *	int idLocom: Locomotive identifier
 *	int fun: Function identifier
 *	int stat: Function new state, ON/OFF
 * Return Value:
 *	0: on error
 *	command value: on success 
 * -----------------------------------------------------------------------------
 */
unsigned long ApiMarklin::setFunc(int idLocom, int fun, int stat) {

	unsigned long command;
	
	command = buildFunc(idLocom, fun, stat);
	return checkSend(command, FUNCOP);
}

/*
 * -----------------------------------------------------------------------------
 * Function: setSole. It Collects the given command parameters for sending them 
 * to other function which builds an effective command. Then it calls other
 * function which sends the command to kernel space.
 * Parameters:
 *	int idSole: Solenoid identifier
 *	int stat: Solenoid new state, OPEN/CLOSE
 * Return Value:
 *	0: on error
 *	command value: on success 
 * -----------------------------------------------------------------------------
 */
unsigned long ApiMarklin::setSole(int idSole, int stat) {

	unsigned long command;

	command = buildSole(idSole, stat);
	return checkSend(command, SOLEOP);
}

/*
 * -----------------------------------------------------------------------------
 * Function: buildLocom. It builds a locomotive-speed-dir command, according to 
 * the given parameters. Command is also built according to bit masks specified 
 * on the header file.
 * Parameters:
 *	int idLocom: Locomotive identifier
 *	int vel: Velocity
 *	int dir: Direction
 * Return Value:
 *	0: on error
 *	command value: on success 
 * -----------------------------------------------------------------------------
 */
unsigned long ApiMarklin::buildLocom(int idLocom, int vel, int dir) {
	
	unsigned long data;

	if(idLocom < MIN_LOCOM || idLocom > MAX_LOCOM || 
	   vel < MIN_VEL || vel > MAX_VEL || (dir != DIR_C && dir != DIR_O)) {

		   notifyError("Error: buildLocom", -1);
		   return 0;
	}
	
	data = (MASK_LOC * idLocom) | (MASK_VEL * vel) | (MASK_DIR * dir);
	//XIo_Out32(BASE + (4 * (idLocom - 1) ), data);

	return data;
}

/*
 * -----------------------------------------------------------------------------
 * Function: buildFunc. It builds a locomotive-function command, according to
 * the given parameters. Command is also built according to bit masks specified 
 * on the header file.
 * Parameters:
 *	int idLocom: Locomotive identifier
 *	int fun: Function identifier
 *	int stat: Function new state, ON/OFF
 * Return Value:
 *	0: on error
 *	command value: on success 
 * -----------------------------------------------------------------------------
 */
unsigned long ApiMarklin::buildFunc(int idLocom, int fun, int stat) {

	unsigned long data;

	if(idLocom < MIN_LOCOM || idLocom > MAX_LOCOM || 
	   fun < MIN_FUN || fun > MAX_FUN || (stat != ON && stat != OFF) ) {

		   notifyError("Error: buildFunc", -1);
		   return 0;
	}

	data = (MASK_LOC * idLocom) | (MASK_FUN * fun) | (MASK_STAT * stat);

	return data;
}

/*
 * -----------------------------------------------------------------------------
 * Function: buildSole. It builds a solenoid-state command, according to the 
 * given parameters. Command is also built according to bit masks specified on 
 * the header file.
 * Parameters:
 *	int idSole: Solenoid identifier
 *	int stat: Solenoid new state, OPEN/CLOSE
 * Return Value:
 *	0: on error
 *	command value: on success 
 * -----------------------------------------------------------------------------
 */
unsigned long ApiMarklin::buildSole(int idSole, int stat) {
	
	unsigned long data;

	if(idSole < MIN_SOLE || idSole > MAX_SOLE || (stat != OPEN && stat != CLOSE) ) {

		   notifyError("Error: buildSole", -1);
		   return 0;
	}

	data = (MASK_SOLE * idSole) | (MASK_STATSOLE * stat);

	return data;

}

/*
 * -----------------------------------------------------------------------------
 * Function: checkSend. It checks wether a command previously built is correct
 * or not. In case of success it calls other function which sends the command
 * to kernel space.
 * Parameters:
 *	unsigned long comm: command value
 * Return Value:
 *	0: on error
 *	command value: on success 
 * -----------------------------------------------------------------------------
 */
unsigned long ApiMarklin::checkSend(unsigned long comm, int op) {

	if(comm) {
		
		sendCommand(comm, op);
		return comm;
	} 
	else {
		return 0;
	}
}

/*
 * -----------------------------------------------------------------------------
 * Function: sendCommand. It sends any given command to kernel space in order to
 * be computed by the Märklin hardware specification. Commands are sent trough
 * a character device which is handled by a Linux kernel device module.
 * Parameters:
 *	unsigned long comm: command value
 * Return Value:
 *	-1: on error
 *	 0: on success 
 * -----------------------------------------------------------------------------
 */
void ApiMarklin::sendCommand(unsigned long comm, int op) {

	int fd = -1;
	char buf[COMM_LEN];

	snprintf(buf, COMM_LEN, "0x%08lx%d", comm, op);

	if((fd = open(COMM_CHARDEV, O_RDWR)) < 0) {
		notifyError("Error: opening char device, open", -2);
	}

	if(ioctl(fd, WRITE_IOCTL, buf) < 0) {
		notifyError("Error: writing on char device, write_ioctl", -3);
	}
	
	/*if(ioctl(fd, READ_IOCTL, buf) < 0) {
		notifyError("Error: reading on char device, read_ioctl", -3);
	}*/
	close(fd);
}

/*
 * -----------------------------------------------------------------------------
 * Function: printU32. it prints an unsigned long value on the console accoding
 * to the format: 0x00000000.
 * Parameters:
 *	unsigned long comm: command value
 * -----------------------------------------------------------------------------
 */
void ApiMarklin::printU32(unsigned long val) {

	printf("u32 value: 0x%08lx \n", val);
}

/*
 * -----------------------------------------------------------------------------
 * Function: notifyError. It registers an error message and an error code into
 * the standard error output.
 * Parameters:
 *	const char *message: error message
 *	int errno: error code
 * -----------------------------------------------------------------------------
 */
void ApiMarklin::notifyError(const char *msg, int errno) {

	fprintf(stderr, "%s. Error code: %d \n", msg, errno);
}
