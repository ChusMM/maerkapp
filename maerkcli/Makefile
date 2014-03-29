# Client Makefile

CPP  = g++
CPPX = powerpc-4xx-softfloat-g++

CC = $(CPP)

IFLAGS = -lIceE -lrt -lpthread -fpermissive
CFLAGS = -c -Wall

TRANSL = slice2cppe
SLICEC = Control.ice
SLICEM = Monitor.ice

DIRINC = /opt/IceE-1.3.0/include
DIRLIB = /opt/IceE-1.3.0/lib

DIRINCPPC = /opt/IceEppc-1.3.0/include
DIRLIBPPC = /opt/IceEppc-1.3.0/lib

GTKCFLAGS = `pkg-config gtkmm-3.0 --cflags`
GTKLIBS   = `pkg-config gtkmm-3.0 --libs`

INC = $(DIRINC)
LIB = $(DIRLIB)

DIRSRC = src/
DIROBJ = obj/
DIRBIN = bin/
DIRSLC = slices/
DIRTEST = test/

CLI  = Client
TESTCLI = CliTest
EX = Example

all: $(TESTCLI) $(CLI) $(EX)

$(CLI): Monitor.o Control.o Client.o Gui.o
		$(CC) -o $(DIRBIN)$(CLI) $(DIROBJ)Monitor.o $(DIROBJ)Control.o $(DIROBJ)Client.o $(DIROBJ)Gui.o -L $(LIB) $(IFLAGS) $(GTKLIBS)

$(TESTCLI): Monitor.o Control.o Client.o ClientTest.o
		    $(CC) -o $(DIRTEST)$(TESTCLI) $(DIROBJ)Monitor.o $(DIROBJ)Control.o $(DIROBJ)Client.o $(DIROBJ)ClientTest.o -L $(LIB) $(IFLAGS)

$(EX): Monitor.o Control.o Client.o Example.o
	   $(CC) -o $(DIRBIN)$(EX) $(DIROBJ)Monitor.o $(DIROBJ)Control.o $(DIROBJ)Client.o $(DIROBJ)Example.o -L $(LIB) $(IFLAGS)

Gui.o: $(DIRSRC)Gui.cpp
	   $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)Gui.o $(DIRSRC)Gui.cpp $(GTKCFLAGS)

ClientTest.o: $(DIRSRC)ClientTest.cpp
		      $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)ClientTest.o $(DIRSRC)ClientTest.cpp

Example.o: $(DIRSRC)Example.cpp
		   $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)Example.o $(DIRSRC)Example.cpp

 
Client.o: $(DIRSRC)Client.cpp
	      $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)Client.o $(DIRSRC)Client.cpp

Control.o: $(DIRSRC)Control.cpp
		   $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)Control.o $(DIRSRC)Control.cpp

Monitor.o: $(DIRSRC)Monitor.cpp
		   $(CC) $(CFLAGS) -I $(INC) -I $(DIRSRC) -o $(DIROBJ)Monitor.o $(DIRSRC)Monitor.cpp 

slice:
	(cd $(DIRSRC) && $(TRANSL) $(DIRSLC)$(SLICEC))
	(cd $(DIRSRC) && $(TRANSL) $(DIRSLC)$(SLICEM))

clean:
	rm -rf $(DIROBJ)* $(DIRBIN)* $(DIRTEST)*
	