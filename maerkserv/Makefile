# Main server side makefile

all:
	(cd ./server && $(MAKE) $@)
	(cd ./module && $(MAKE) $@)

clean:
	(cd ./server && $(MAKE) clean)
	(cd ./module && $(MAKE) clean)

copy_cf:
	sudo cp -rf ../maerkserv /media/3a6c9a92-e6a1-44db-86c8-4efca5fcbfa4/home/root/
