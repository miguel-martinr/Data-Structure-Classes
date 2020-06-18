bin/main: src/main.cpp include/dsc_base.hpp
	g++ -g src/main.cpp -o bin/main

.PHONY:
clean:
	rm bin/*