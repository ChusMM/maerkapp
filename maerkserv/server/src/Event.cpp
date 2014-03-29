/* Event implementation
 * J.Manuel Muñoz, Ingeniería informática */

#include <stdio.h>
#include <stdlib.h>
#include <IceE/IceE.h>
#include <Monitor.h>

using namespace std;
using namespace Loconet;

#define LOG "/home/root/maerkserv/server/log/eventlog.log"
#define PTH "/home/root/maerkserv/server/bin"
 
/*#define LOG "/home/napster/PFC/maerkapp/maerkserv/server/log/eventlog.log"
#define PTH "/home/napster/PFC/maerkapp/maerkserv/server/bin"*/

int run(int argc, char* argv[], FILE *fp, const Ice::CommunicatorPtr& communicator) {

	int loc, sen;
	
	Ice::PropertiesPtr properties = communicator->getProperties();
    const char* proxyProperty = "OA.Proxy";
	
	string proxy = properties -> getProperty(proxyProperty);

	if(proxy.empty()) {
		
		fprintf(fp, "%s: property `%s' not set\n", argv[0], proxyProperty);
		return EXIT_FAILURE;
    }

	Ice::ObjectPrx base = communicator->stringToProxy(proxy);
    MonitorPrx twoway = MonitorPrx::checkedCast(base -> ice_twoway() -> ice_timeout(-1));

	if(!twoway) {
		
		fprintf(fp, "%s: invalid proxy\n", argv[0]);
		return EXIT_FAILURE;
    }

	loc = (int) strtol(argv[1], NULL, 0);
	sen = (int) strtol(argv[2], NULL, 0);
	
	twoway -> Register(loc, sen);

	return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {

	FILE *fp;
    int status;
    Ice::CommunicatorPtr communicator;

	if(chdir(PTH) == -1) {
		fprintf(stderr, "Error: changing working directory \n");
		return EXIT_FAILURE;
	}

	if((fp = fopen(LOG, "w+")) == NULL) {
		fprintf(stderr, "Error: open event file \n");
		return EXIT_FAILURE;
	}

    try {
		
    	Ice::InitializationData initData;
		initData.properties = Ice::createProperties();
        initData.properties->load("../config/confmon");
		communicator = Ice::initialize(argc, argv, initData);
		status = run(argc, argv, fp, communicator);
    }
    catch(const Ice::Exception& ex) {
		fprintf(fp, "%s\n", ex.toString().c_str());
		status = EXIT_FAILURE;
    }

    if(communicator) {
		try {
			
	    	communicator->destroy();
		}
		catch(const Ice::Exception& ex) {
	    	fprintf(fp, "%s\n", ex.toString().c_str());
	    	status = EXIT_FAILURE;
		}	
	}
	fclose(fp);
    return status;
}
