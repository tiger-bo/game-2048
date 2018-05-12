#include "draw"


void Init_curses()
{
	initscr();
	cbreake;
	noecho();
	nonl();
}


bool box::Draw_box()
{
	win = newwin(win_x, win_y, box_high, box_width);
	box(win,DRAW_C,DRAW_R);
	reflash();
	wreflash(win);

	return true;
}
int  box::Set_win_x(int size)
{
	win_x = size;

	return 0;
}
int  box::Set_win_y(int size)
{
	win_y = size;

	return 0;
}
int  box::Set_box_high(int size)
{
	box_high = size;

	return 0;
}
int  box::Set_box_width(int size)
{
	box_width = size;

	return 0;
}

int  box::Get_win_x(int size)
{
	return win_x;
}

int  box::Get_win_y(int size)
{
	return win_y;
}
int  box::Get_box_high(int size)
{
	return box_high;
}
int  box::Get_box_width(int size)
{
	return box_width;
}