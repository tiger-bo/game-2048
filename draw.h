#ifndef __DRAW_H__
#define __DRAW_H__

#include <ncurses.h>
#include <iostream>
#include <fstream>


#define DRAW_C '|'
#define DRAW_R '-'
#define BEGIN_SET 3
#define UI2048H 4
#define UI2048W 4

void Init_logfile();

class Box
{
public:	
	Box(){};
	~Box(){};
	bool Draw();
	int Set_win_x(int size);
	int Set_win_y(int size);
	int Set_box_high(int size);
	int Set_box_width(int size);
	int Set_box_value(int value);
	bool Set_box_value_is_set(bool done);

	int Get_win_x();
	int Get_win_y();
	int Get_box_high();
	int Get_box_width();
	int Get_box_value();
	bool Get_box_value_is_set();
private:
	int win_x = 0;
	int win_y = 0;
	int box_high = 0;
	int box_width = 0;
	int box_value = 0;
	bool box_value_is_set = false;

	WINDOW *win;

};


#endif


class Ui_2048:public Box
{
public:
	Ui_2048();
	Ui_2048(int x, int y, int size);
	~Ui_2048(){ log_file.close();};

	bool Draw();
	bool Active(int ch);
	bool Generate_num();
	
private:
	bool up_active();
	bool down_active();
	bool left_active();
	bool right_active();
	bool game_over_check();
	Box boxof2048[UI2048W * UI2048H];
	std::ofstream log_file;
	uint Scores = 0;
};


