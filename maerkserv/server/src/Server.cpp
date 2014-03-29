/* Server implementation
 * J.Manuel Muñoz, Ingeniería informática */

#include <Control.h>
#include <pthread.h>
#include <iostream>
#include "Args.h"
#include "Api_marklin.h"
#include "Server.h"

using namespace std;

int setCommunicator(arguments *ar, Ice::CommunicatorPtr& communicator, const char* cfg);
int freeCommunicator(Ice::CommunicatorPtr& communicator);
void *run(void *params);

void ControlI::Locom(::Ice::Int idLocom,
                     ::Ice::Int vel,
                     ::Ice::Int dir,
                     ::Ice::Int& ret,
                     const Ice::Current& current)
{
	api = ApiMarklin::Instance();
	ret = api -> setLocom(idLocom, vel, dir);
}

void ControlI::Func(::Ice::Int idLocom,
                    ::Ice::Int fun,
                    ::Ice::Int stat,
                    ::Ice::Int& ret,
                    const Ice::Current& current)
{
	api = ApiMarklin::Instance();
	ret = api -> setFunc(idLocom, fun, stat);
}

void ControlI::Sole(::Ice::Int idSole,
                    ::Ice::Int stat,
                    ::Ice::Int& ret,
                    const Ice::Current& current)
{
	api = ApiMarklin::Instance();
	ret = api -> setSole(idSole, stat);
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

void *run(void *params) {

	int status;
	arguments *ar;
	Ice::CommunicatorPtr communicator;

	ar = (arguments *)params;
	status = setCommunicator(ar, communicator, "../config/confctrl");

	if(status == EXIT_SUCCESS) {

		Ice::ObjectAdapterPtr oa = communicator -> createObjectAdapter("OA");

		Maerklin::ControlPtr object = new ControlI;
		Ice::ObjectPrx prx = oa -> add(object, communicator -> stringToIdentity("control"));

		oa -> activate();
		std::cout << communicator -> proxyToString(prx) << std::endl;

		communicator->waitForShutdown();
	}
	
	freeCommunicator(communicator);
	pthread_exit(&status);
}

int main(int argc, char **argv) {
		
	int ret;
	int *status;

	pthread_t t;
	arguments ar;

	ar.argc = argc;
	ar.argv = argv;

	if((ret = pthread_create(&t, NULL, run, &ar))) {
		fprintf(stderr, "Error: Failed server-control thread creation \n");
		return -1;
	}

	pthread_join(t, (void **)&(status));

	return *status;
}
