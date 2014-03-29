# Server Makefile
# export LD_LIBRARY_PATH=/opt/IceE-1.3.0/lib/ for running over native architecture

CPP  = g++
CPPX = powerpc-4xx-softfloat-g++

CC = $(CPPX)

IFLAGS = -lIceE -lrt -lpthread -fpermissive
CFLAGS = -c -Wall

TRANSL = slice2cppe
SLICEC = Control.ice
SLICEM = Monitor.ice

DIRINC = /opt/IceE-1.3.0/include
DIRLIB = /opt/IceE-1.3.0/lib

DIRINCPPC = /opt/IceEppc-1.3.0/include
DIRLIBPPC = /opt/IceEppc-1.3.0/lib

INC = $(DIRINCPPC)
LIB = $(DIRLIBPPC)

DIRSRC = src/
DIROBJ = obj/
DIRBIN = bin/
DIRSLC = slices/
DIRTEST = test/

SERV = Server
EVNT = Event
TESTAPI = TestApi
TESTMOD = TestMod
TESTEVNT = TestEvnt

all: $(SERV) $(EVNT) $(TESTAPI) $(TESTMOD) $(TESTEVNT)

$(SERV): Api_marklin.o Control.o Server.o 
		 $(CC) -o $(DIRBIN)$(SERV) $(DIROBJ)Api_marklin.o $(DIROBJ)Control.o $(DIROBJ)Server.o -L $(LIB) $(IFLAGS)

$(EVNT): Monitor.o Event.o
		 $(CC) -o $(DIRBIN)$(EVNT) $(DIROBJ)Monitor.o $(DIROBJ)Event.o -L $(LIB) $(IFLAGS)

Server.o: $(DIRSRC)Server.cpp 
	      $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)Server.o $(DIRSRC)Server.cpp		

Event.o: $(DIRSRC)Event.cpp
	     $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)Event.o $(DIRSRC)Event.cpp

Control.o: $(DIRSRC)Control.cpp
		   $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)Control.o $(DIRSRC)Control.cpp

Monitor.o: $(DIRSRC)Monitor.cpp
		   $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)Monitor.o $(DIRSRC)Monitor.cpp 

$(TESTAPI): TestApi.o Api_marklin.o
		    $(CC) $(DIROBJ)TestApi.o $(DIROBJ)Api_marklin.o -o $(DIRTEST)$(TESTAPI)

TestApi.o: $(DIRSRC)TestApi.cpp
		   $(CC) $(CFLAGS) $(DIRSRC)TestApi.cpp -o $(DIROBJ)TestApi.o

$(TESTMOD): $(DIRSRC)TestMod.cpp
		    $(CC) -Wall $(DIRSRC)TestMod.cpp -o $(DIRTEST)$(TESTMOD)

$(TESTEVNT): $(DIRSRC)TestEvnt.cpp
		     $(CC) -Wall $(DIRSRC)TestEvnt.cpp -o $(DIRTEST)$(TESTEVNT)

Api_marklin.o: $(DIRSRC)Api_marklin.cpp
			   $(CC) $(CFLAGS) -I $(DIRSRC) $(DIRSRC)Api_marklin.cpp -o $(DIROBJ)Api_marklin.o

slice:
	(cd $(DIRSRC) && $(TRANSL) $(DIRSLC)$(SLICEC))
	(cd $(DIRSRC) && $(TRANSL) $(DIRSLC)$(SLICEM))
	
clean:
	rm -rf $(DIROBJ)* $(DIRBIN)* $(DIRTEST)*
	
