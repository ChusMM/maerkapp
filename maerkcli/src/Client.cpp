/* Class client implementation
 * J.Manuel Muñoz, Ingeniería informática */

#include <Monitor.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>
#include <iostream>
#include "Client.h"

#define LHOUR 9

using namespace std;

Client* Client::pInstance = 0;
bool Client::thCreated = false;

void *run(void *params);
int setCommunicator(arguments *ar, Ice::CommunicatorPtr& communicator, const char* cfg);
int freeCommunicator(Ice::CommunicatorPtr& communicator);

class MonitorI : public Loconet::Monitor {

	pid_t pid;

	public:
		MonitorI(pid_t p);
		virtual void Register(::Ice::Int, ::Ice::Int, const Ice::Current&);
};

MonitorI::MonitorI(pid_t p) {
	pid = p;
}

void MonitorI::Register(::Ice::Int idLocom, 
                        ::Ice::Int idSen, 
                        const Ice::Current& current)
{
	FILE *fp;
	int ret;
	
	if((fp = fopen(ROW, "w+")) == NULL) {
	  fprintf(stderr, "Error: opening row file \n");
	}

	if(fp != NULL) {

		fprintf(fp, "Locomotora: %d, pasa por el sensor: %d", idLocom, idSen);
		fclose(fp);

		if((ret = kill(pid, SIGALRM)) == -1) {
			fprintf(stderr, "Error: signal sending \n");
		}
	}
}

void *run(void *params) {

	int status;
	arguments *ar;
    Ice::CommunicatorPtr communicator;
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

	ar = (arguments *)params;
	status = setCommunicator(ar, communicator, "../config/confmon");

	if(status == EXIT_SUCCESS) {

		Ice::ObjectAdapterPtr oa = communicator -> createObjectAdapter("OA");

		Loconet::MonitorPtr object = new MonitorI(ar -> pid);
		Ice::ObjectPrx prx = oa -> add(object, communicator -> stringToIdentity("monitor"));

		oa -> activate();
		std::cout << communicator -> proxyToString(prx) << std::endl;
		
		communicator->waitForShutdown();
	}

	freeCommunicator(communicator);
    return NULL; //pthread_exit(&status);
}

int setCommunicator(arguments *ar, Ice::CommunicatorPtr& communicator, const char* cfg) {

	int status;
	try {
		
		Ice::InitializationData initData;
		initData.properties = Ice::createProperties();
		initData.properties -> load(cfg);
		initData.properties -> setProperty("Ice.Override.Timeout", "100");
		communicator = Ice::initialize(ar -> argc, ar -> argv, initData);
		status = EXIT_SUCCESS;
	}
	catch(const Ice::Exception& ex) {
		fprintf(stderr, "%s\n", ex.toString().c_str());
		status = EXIT_FAILURE;
    }
	return status;
}

int freeCommunicator(Ice::CommunicatorPtr& communicator) {

	int status = EXIT_SUCCESS;

	if(communicator) {	
		try {
	    	communicator -> destroy();
		}
		catch(const Ice::Exception& ex) {
	       fprintf(stderr, "%s\n", ex.toString().c_str());
	 	   status = EXIT_FAILURE;
		}
	}
	return status;
}

Client* Client::Instance() {

	if (pInstance == 0) {
		pInstance = new Client;
	}

	return pInstance;
}

void Client::readEvent(char *msg) {
	
	FILE *fp;
	char buf[LENMSG];

	if((fp = fopen(ROW, "r")) == NULL) {
		fprintf(stderr, "Error: open row file \n");
	}

	if(fgets(buf, LENMSG, fp) == NULL) {
		fprintf(stderr, "Error: nothing retreived from row file \n");
	}
	fclose(fp);
	
	strncpy(msg, buf, LENMSG);
	msg[LENMSG - 1] = '\0';
}

int Client::ctrlInvocation(arguments ar, int cop, attr maerkAttr) {

	int status;
    Ice::CommunicatorPtr communicator;

	status = setCommunicator(&ar, communicator, "../config/confctrl");

	try {

		if(status == EXIT_SUCCESS) {
		
			Ice::PropertiesPtr properties = communicator->getProperties();
    		const char* proxyProperty = "OA.Proxy";
	
			string proxy = properties -> getProperty(proxyProperty);
		
			if(proxy.empty()) {
				fprintf(stderr, "%s: property `%s' not set \n", ar.argv[0], proxyProperty);
				status = EXIT_FAILURE;
    		}

			Ice::ObjectPrx base = communicator->stringToProxy(proxy);
			ControlPrx twoway = ControlPrx::checkedCast(base -> ice_twoway() -> ice_timeout(-1));

			if(!twoway) {
				fprintf(stderr, "%s: invalid proxy \n", ar.argv[0]);
				status = EXIT_FAILURE;
    		}
			status = opCalling(twoway, cop, maerkAttr);
		}	
	} 
	catch(const Ice::Exception& ex) {
		fprintf(stderr, "%s\n", ex.toString().c_str());
		status = EXIT_FAILURE;
    }

	freeCommunicator(communicator);
    return status;
}

int Client::opCalling(ControlPrx& twoway, int cop, attr maerkAttr) {

	int comm;
	Ice::Int& ret = comm;

	switch(cop) {
		case OPCON:
			twoway -> Locom(maerkAttr.idConLocom, maerkAttr.vel, maerkAttr.dir, ret);
			break;
			
		case OPFUN:
			twoway -> Func(maerkAttr.idFunLocom, maerkAttr.fun, maerkAttr.fstat, ret);
			break;
			
		case OPSOLE:
			twoway -> Sole(maerkAttr.idSole, maerkAttr.sstat, ret); 
			break;
			
		default:
			comm = 0;
			fprintf(stderr, "Error: invalid operation code \n");
			break;
	}

	if(ret != 0) {
		return 0;
	}
	else {
		fprintf(stderr, "Invalid command \n");
		return -1;
	}
}

int Client::init(arguments ar) {
	
	int status;

	if(!thCreated) {
		
		if((status = pthread_create(&t, NULL, run, &ar))) {
			fprintf(stderr, "Error: client-monitor thread creation failed \n");
			return status;
		} else {
			thCreated = true;
		}
		
	} else {
		printf("client-monitor thread already created \n");
	}
	return 0;
}

int Client::end() {
	
	int status = 0;

	if(thCreated) {
		
		if((status = pthread_cancel(t)) != 0) {
			fprintf(stderr, "Error: client-monitor thread cancelation failed \n");
			return status;
		}
	
		if((status = pthread_join(t, NULL)) != 0) { //(void **)&(status));
			fprintf(stderr, "Error: client-monitor thread joining failed \n");
		} else {
			thCreated = false;
		}
		
	} else {
		printf("client-monitor thread not created \n");
	}	
	return status;
}
