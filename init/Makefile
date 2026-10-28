all:
	@echo "CXX init.cpp"
	@g++ init.cpp -o init
	@echo "CXX initctl.cpp"
	@g++ initctl.cpp -o initctl

clean:
	@echo "RM init"
	@rm -rf init
	@echo "RM initctl"
	@rm -rf initctl

clear:
	@echo "RM init"
	@rm -rf init
	@echo "RM initctl"
	@rm -rf initctl

install:
	@echo "INSTALL init"
	@install -m 755 init /usr/local/bin/init
	@echo "INSTALL initctl"
	@install -m 755 initctl /usr/local/bin/initctl