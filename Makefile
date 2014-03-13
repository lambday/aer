default:
	g++ -std=c++11 -I./src -o main main.cpp src/aer/**/*.cpp -Wall
	./main
