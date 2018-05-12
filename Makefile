game_2048:game_2048.o draw.o
	g++ -o game_048 game_2048.o draw.o -lncurses -std=c++11
game_2048.o:game_2048.cpp draw.h
	g++ -c game_2048.cpp -std=c++11
draw.o:draw.cpp draw.h
	g++ -c draw.cpp -lncurses -std=c++11

make clean:
	rm *.o