/* Class Client header
 * J.Manuel Muñoz, Ingeniería informática */

#include <IceE/IceE.h>
#include <Control.h>
#include <sys/types.h>
#include "Args.h"

#ifndef __Client_H_INCLUDED__
#define __Client_H_INCLUDED__

#define ROW   "../temp/row.txt"
#define OPCON  1
#define OPFUN  2
#define OPSOLE 3
#define LENMSG 256

using namespace Maerklin;

class Client {

	private:
		static Client* pInstance;
		static bool thCreated;
		pthread_t t;
		Client() { };
        Client(const Client& cli) { };
		int opCalling(ControlPrx& twoway, int cop, attr maerkAttr);
		
	public:
		static Client* Instance();
		void readEvent(char *msg);
		int ctrlInvocation(arguments ar, int cop, attr maerkAttr);
		int init(arguments ar);
		int end();
		~Client() { pInstance = 0; }
};
#endif
