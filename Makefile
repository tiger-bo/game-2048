game_2048:game_2048.o draw.o
	g++ -o game_048 game-2048.o draw.o
game_2048.o:game_2048.cpp draw.h
	g++ -c game_2048.cpp
draw.o:draw.cpp draw.h
	g++ -c draw.cpp -lncruses 

make clean:
	rm *.o