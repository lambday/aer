default:
	g++ -g -fPIC -rdynamic -shared -std=c++11 -I./src -o libaer.so src/aer/**/*.cpp -ldl
	g++ -g -fPIC -rdynamic -shared -std=c++11 -I./src -o plugin.so test_lib_src/library.cpp -L./ -laer
	g++ -std=c++11 -I./src -L. -o main main.cpp -Wall -laer
	LD_LIBRARY_PATH=. ./main
