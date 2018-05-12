#include "draw.h"
#include <ctime>
#include <cstdlib>


bool Box::Draw()
{
	win = newwin(box_high, box_width, win_y, win_x);
	box(win,DRAW_C,DRAW_R);
	if (Get_box_value_is_set())
	{
		mvwprintw(win, Get_box_high() / 2 - 1, (Get_box_width() - 4) / 2, "%d",Get_box_value());
	}
	
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

int  Box::Set_box_value(int size)
{
	box_value = size;

	return 0;
}

bool Box::Set_box_value_is_set(bool done)
{
	box_value_is_set = done;

	return true;
}

int  Box::Get_win_x()
{
	return win_x;
}

int  Box::Get_win_y()
{
	return win_y;
}
int  Box::Get_box_high()
{
	return box_high;
}
int  Box::Get_box_width()
{
	return box_width;
}

int  Box::Get_box_value()
{
	return box_value;
}

bool Box::Get_box_value_is_set()
{
	return box_value_is_set;
}

Ui_2048::Ui_2048()
{
	initscr();
	cbreak();
	noecho();
	nonl();
	raw();
	keypad(stdscr,TRUE);

	this->Set_win_x(80);
	this->Set_win_y(15);
	this->Set_box_high(10 * UI2048H);
	this->Set_box_width(10* UI2048W);

	srand((unsigned)time(NULL));
	int rad = 0;
	for (int i = 0; i < BEGIN_SET; ++i)
	{
		rad = rand() % (UI2048W * UI2048H);
		while (boxof2048[rad].Get_box_value_is_set())
		{
			rad = rand() % UI2048W * UI2048H;
		}
		boxof2048[rad].Set_box_value(2);
		boxof2048[rad].Set_box_value_is_set(true);
	}

	
	Draw();
}

Ui_2048::Ui_2048(int x, int y, int size)
{
	initscr();
	cbreak();
	noecho();
	nonl();
	raw();
	keypad(stdscr,TRUE);

	this->Set_win_x(x);
	this->Set_win_y(y);
	this->Set_box_high(size * UI2048H);
	this->Set_box_width(size * UI2048W);

	srand((unsigned)time(NULL));
	int rad = 0;
	for (int i = 0; i < BEGIN_SET; ++i)
	{
		rad = rand() % (UI2048W * UI2048H);
		while (boxof2048[rad].Get_box_value_is_set())
		{
			rad = rand() % UI2048W * UI2048H;
		}
		boxof2048[rad].Set_box_value(2);
		boxof2048[rad].Set_box_value_is_set(true);
	}

	
	Draw();
}




bool Ui_2048::Draw()
{
	

	for (int i = 0; i < (UI2048W * UI2048H); ++i)
	{
		boxof2048[i].Set_win_y(Get_win_y() + (i / UI2048W) * Get_box_high() / UI2048H - i / UI2048W);
		boxof2048[i].Set_win_x(Get_win_x() + (i % UI2048W) * Get_box_width() / UI2048W - i % UI2048W);
		boxof2048[i].Set_box_high(Get_box_high() / UI2048H);
		boxof2048[i].Set_box_width(Get_box_width() / UI2048W);

		boxof2048[i].Draw();
	}

	refresh();
}

bool Ui_2048::Active(int ch)
{
	erase();
	switch(ch)
	{
		case KEY_UP:
			mvwprintw(stdscr, 50 , 30, "ch: %c",ch);
			break;
		case KEY_DOWN:
			mvwprintw(stdscr, 50 , 30, "ch: %c",ch);
			break;
		case KEY_LEFT:
			mvwprintw(stdscr, 50 , 30, "ch: %c",ch);
			break;
		case KEY_RIGHT:
			mvwprintw(stdscr, 50 , 30, "ch: %c",ch);
			break;
	}

	return true;
}