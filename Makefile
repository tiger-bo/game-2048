game_2048:game_2048.o draw.o
	g++ -o game_048 game_2048.o draw.o -lncurses 
game_2048.o:game_2048.cpp draw.h
	g++ -c game_2048.cpp
draw.o:draw.cpp draw.h
	g++ -c draw.cpp -lncurses 

make clean:
	rm *.o