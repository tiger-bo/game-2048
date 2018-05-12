#include "draw.h"


int main() 
{	
	int ch = 0;

	Ui_2048 test;


	while( (ch = getch()) != 0x1b)
	{	

		test.Active(ch);

		if (test.Generate_num())
			test.Draw();
		else
			mvwprintw(stdscr, 52 , 30, "game over...");
			test.Draw();
	}
	
	endwin();
	return 0;
}