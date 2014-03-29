/* Header de la API para interactuar a través de un módulo de kernel con una maqueta de tren 
 * digital modelo Märklin.
 * Jesús Manuel Muñoz Mazuecos - Ingeniería informática */

#ifndef __ApiMarklin_H_INCLUDED__   
#define __ApiMarklin_H_INCLUDED__ 
/*
 * -----------------------------------------------------------------------------
 * Locomotive-velocity-dir-function mask, from left to right.
 * 	Byte 1 and 2 specifies the locomotive identifier
 * 	Byte 3 and 4 specifies the velocity paramenter
 * 	Byte 5 and 6 specifies the direction paramenter
 * 	Byte 7 specifies the function identifier
 *	Byte 8 specifies the new function state 
 * -----------------------------------------------------------------------------
 */	
#define MASK_LOC  0x01000000
#define MASK_VEL  0x00010000
#define MASK_DIR  0x00000100
#define MASK_FUN  0x00000010
#define MASK_STAT 0x00000001

/*
 * -----------------------------------------------------------------------------
 * Solenoid mask, from left to right.
 * 	Byte 1 and 2 specifies the solenoid identifier.
 *	Byte 3 and 4 specifies the new solenoid state.
 * -----------------------------------------------------------------------------
 */
#define MASK_SOLE     0x01000000
#define MASK_STATSOLE 0x00010000

/* Operations code */
#define LOCOMOP 1
#define FUNCOP  2
#define SOLEOP  3

/* ioctl paramenters */
#define MY_MACIG 'G'
#define READ_IOCTL _IOR  (MY_MACIG, 0, int)
#define WRITE_IOCTL _IOW (MY_MACIG, 1, int)

/* Char devices location */
#define COMM_CHARDEV "/dev/command_chardev"
#define LOCONET_CHARDEV "/dev/loconet_chardev"

class ApiMarklin {

	private:
		static ApiMarklin* pInstance;
		ApiMarklin() { };
        ApiMarklin(const ApiMarklin& api) { };
		unsigned long buildLocom(int idLocom, int vel, int dir);
		unsigned long buildFunc(int idLocom, int fun, int stat);
		unsigned long buildSole(int idSole, int stat);
		unsigned long checkSend(unsigned long command, int op);
		void sendCommand(unsigned long comm, int op);
		void notifyError(const char *msg, int errno);

	public:
		static ApiMarklin* Instance();
		~ApiMarklin() { pInstance = 0; }
		unsigned long setLocom(int idLocom, int vel, int dir);
		unsigned long setFunc(int idLocom, int fun, int stat);
		unsigned long setSole(int idSole, int stat);
		void printU32(unsigned long val);
};
#endif
