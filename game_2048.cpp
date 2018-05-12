#include "draw.h"


int main() 
{
	Box test;

	Init_curses();

	test.Set_win_x(1);
	test.Set_win_y(1);
	test.Set_box_high(30);
	test.Set_box_width(30);

	test.Draw_box();
	
	getchar();
	endwin();
	return 0;
}