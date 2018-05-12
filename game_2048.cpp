#include "draw.h"


int main() 
{
	Box test;

	Init_curses();

	test.Set_win_x(0);
	test.Set_win_x(0);
	test.Set_win_x(30);
	test.Set_win_x(30);

	test.Draw_box();

	return 0;
}