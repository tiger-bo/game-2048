#include "draw.h"


int main() 
{	
	int ch = 0;

	Ui_2048 test;


	while( (ch = getch()) != 0x1b)
	{	

		test.Active(ch);
		test.Draw();
	}
	
	endwin();
	return 0;
}