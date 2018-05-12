#include "draw.h"

void Init_curses()
{
	initscr();
	cbreak();
	noecho();
	nonl();
}


bool Box::Draw_box()
{
	win = newwin(box_high, box_width, win_y, win_x);
	box(win,DRAW_C,DRAW_R);
	refresh();
	wrefresh(win);

	return true;
}
int  Box::Set_win_x(int size)
{
	win_x = size;

	return 0;
}
int  Box::Set_win_y(int size)
{
	win_y = size;

	return 0;
}
int  Box::Set_box_high(int size)
{
	box_high = size;

	return 0;
}
int  Box::Set_box_width(int size)
{
	box_width = size;

	return 0;
}

int  Box::Get_win_x(int size)
{
	return win_x;
}

int  Box::Get_win_y(int size)
{
	return win_y;
}
int  Box::Get_box_high(int size)
{
	return box_high;
}
int  Box::Get_box_width(int size)
{
	return box_width;
}