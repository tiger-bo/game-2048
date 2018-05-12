#include "draw.h"

#define ESC 0x1b

int main() 
{	
	int ch = 0;

	Ui_2048 test;


	while( (ch = getch()) != ESC)
	{	

		test.Active(ch);

		if (test.Generate_num())
		{
			test.Draw();
		}
		else
		{
			mvwprintw(stdscr, 52 , 30, "game over...");
			test.Draw();
			break;
		}
			
	}
	while( (ch = getch()) != ESC)
		;
	
	endwin();
	return 0;	

	
}