#include "draw.h"
#include <ctime>
#include <cstdlib>
#include <vector>


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
	log_file.open("2048.log");

	this->Set_win_x(10);
	this->Set_win_y(10);
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
	log_file.open("2048.log");

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

bool Ui_2048::Up_active()
{

	std::vector<int> value;
	for (int i = 0; i < UI2048W; ++i)
	{	
		log_file << "i:" << i << std::endl;
		if(!value.empty())
			value.clear();
		int pushflag = 0;
		for (int j = 0; j < UI2048H; ++j)
		{
			log_file << "j:" << j << std::endl;
			
			if(boxof2048[i + j * UI2048W].Get_box_value_is_set())
			{

				log_file << "value is set" << std::endl;

				if(!value.empty())
				{
					if(value.back() == boxof2048[i + j * UI2048W].Get_box_value() && pushflag == 0)
					{
						log_file << "value = box_value" << " value :" << value.back() << std::endl;
						value.pop_back();
						value.push_back(boxof2048[i + j * UI2048W].Get_box_value() * 2);
						pushflag = 1;
					}
					else
					{	
						log_file << "value != box_value" << std::endl;
						value.push_back(boxof2048[i + j * UI2048W].Get_box_value());	
						pushflag = 0;
					}
				}				
				else
				{	
					log_file << "value != box_value" << std::endl;
					value.push_back(boxof2048[i + j * UI2048W].Get_box_value());	
					pushflag = 0;
				}
				boxof2048[i + j * UI2048W].Set_box_value(0);
				boxof2048[i + j * UI2048W].Set_box_value_is_set(false);
			}
		}

		int count = value.size();

		log_file << "SET Box  SIZE: " <<count << std::endl;

	    for (int j = 0; j < count; j++)
	    {
	    	log_file << "SET Box" << std::endl;
	    	boxof2048[i + j * UI2048W].Set_box_value(value[j]);
	        boxof2048[i + j * UI2048W].Set_box_value_is_set(true);
	    }

	}

	return true;
}

bool Ui_2048::Down_active()
{
	std::vector<int> value;
	for (int i = 0; i < UI2048W; ++i)
	{
		if(!value.empty())
			value.clear();

		int pushflag = 0;
		for (int j = 0; j < UI2048H; ++j)
		{
			
			if(boxof2048[i + (UI2048H - j - 1) * UI2048W].Get_box_value_is_set())
			{

				if(!value.empty())
				{
					if(value.back() == boxof2048[i + (UI2048H - j - 1) * UI2048W].Get_box_value() && pushflag == 0)
					{
						value.pop_back();
						value.push_back(boxof2048[i + (UI2048H - j - 1) * UI2048W].Get_box_value() * 2);
						pushflag = 1;
					}
					else
					{
						value.push_back(boxof2048[i + (UI2048H - j - 1) * UI2048W].Get_box_value());	
						pushflag = 0;
					}	

				}
				else
				{
					value.push_back(boxof2048[i + (UI2048H - j - 1) * UI2048W].Get_box_value());	
					pushflag = 0;
				}
				boxof2048[i + (UI2048H - j - 1) * UI2048W].Set_box_value(0);
				boxof2048[i + (UI2048H - j - 1) * UI2048W].Set_box_value_is_set(false);
			}
		}

		int count = value.size();

	    for (int j = 0; j < count; j++)
	    {
	    	boxof2048[i + (UI2048H - j -1) * UI2048W].Set_box_value(value[j]);
	        boxof2048[i + (UI2048H - j -1) * UI2048W].Set_box_value_is_set(true);
	    }

	}

	return true;	
}

bool Ui_2048::Left_active()
{
	std::vector<int> value;
	for (int i = 0; i < UI2048H; ++i)
	{	
		log_file << "i:" << i << std::endl;
		if(!value.empty())
			value.clear();
		int pushflag = 0;
		for (int j = 0; j < UI2048W; ++j)
		{
			log_file << "j:" << j << std::endl;			
			if(boxof2048[i * UI2048W + j].Get_box_value_is_set())
			{


				log_file << "value is set" << std::endl;

				if(!value.empty())
				{
					if(value.back() == boxof2048[i * UI2048W + j].Get_box_value() && pushflag == 0)
					{
						log_file << "value = box_value" << " value :" << value.back() << std::endl;
						value.pop_back();
						value.push_back(boxof2048[i * UI2048W + j].Get_box_value() * 2);
						pushflag = 1;
					}	
					else
					{	
						log_file << "value != box_value" << std::endl;
						value.push_back(boxof2048[i * UI2048W + j].Get_box_value());	
						pushflag = 0;
					}
				}				
				else
				{	
					log_file << "value != box_value" << std::endl;
					value.push_back(boxof2048[i * UI2048W + j].Get_box_value());	
					pushflag = 0;
				}
				boxof2048[i * UI2048W + j].Set_box_value(0);
				boxof2048[i * UI2048W + j].Set_box_value_is_set(false);
			}
		}

		int count = value.size();

	    for (int j = 0; j < count; j++)
	    {
	    	log_file << "SET Box" << std::endl;
	    	boxof2048[i * UI2048W + j].Set_box_value(value[j]);
	        boxof2048[i * UI2048W + j].Set_box_value_is_set(true);
	    }

	}

	return true;
}

bool Ui_2048::Right_active()
{
	std::vector<int> value;
	for (int i = 0; i < UI2048H; ++i)
	{	
		log_file << "i:" << i << std::endl;
		if(!value.empty())
			value.clear();
		int pushflag = 0;
		for (int j = 0; j < UI2048W; ++j)
		{
			log_file << "j:" << j << std::endl;
			
			if(boxof2048[i * UI2048W + UI2048W - j - 1].Get_box_value_is_set())
			{

				log_file << "value is set" << std::endl;

				if(!value.empty())
				{
					if(value.back() == boxof2048[i * UI2048W + UI2048W - j - 1].Get_box_value() && pushflag == 0)
					{
						log_file << "value = box_value" << " value :" << value.back() << std::endl;
						value.pop_back();
						value.push_back(boxof2048[i * UI2048W + UI2048W - j - 1].Get_box_value() * 2);
						pushflag = 1;
					}
					else
					{	
						log_file << "value != box_value" << std::endl;
						value.push_back(boxof2048[i * UI2048W + UI2048W - j - 1].Get_box_value());	
						pushflag = 0;
					}	
				}				
				else
				{	
					log_file << "value != box_value" << std::endl;
					value.push_back(boxof2048[i * UI2048W + UI2048W - j - 1].Get_box_value());	
					pushflag = 0;
				}
				boxof2048[i * UI2048W + UI2048W - j - 1].Set_box_value(0);
				boxof2048[i * UI2048W + UI2048W - j - 1].Set_box_value_is_set(false);
			}
		}

		int count = value.size();

	    for (int j = 0; j < count; j++)
	    {
	    	boxof2048[i * UI2048W + UI2048W - j - 1].Set_box_value(value[j]);
	        boxof2048[i * UI2048W + UI2048W - j - 1].Set_box_value_is_set(true);
	    }

	}

	return true;
}


bool Ui_2048::Generate_num()
{
	std::vector<int> pos;
	int rad = 0;
	for (int i = 0; i < (UI2048W * UI2048H); ++i)
	{
		log_file << " box_value  "<< boxof2048[i].Get_box_value() << " box set " << boxof2048[i].Get_box_value_is_set() << " i " << i << std::endl;

		if (!boxof2048[i].Get_box_value_is_set())
		{

			pos.push_back(i);
		}
	}
	
	srand((unsigned)time(NULL));

	if (pos.size() == 0)
	{
		return false;
	}
	rad = rand() % pos.size();

	log_file << " tmp_boxs size "<< pos.size() << " rad " << rad << std::endl;

	boxof2048[pos[rad]].Set_box_value(2);
	boxof2048[pos[rad]].Set_box_value_is_set(true);

	return true;

/*	for (int i = 0; i < (UI2048W * UI2048H); ++i)
	{
		log_file << " box_value  "<< boxof2048[i].Get_box_value() << " box set " << boxof2048[i].Get_box_value_is_set() << " i " << i << std::endl;
	}
*/
}

bool Ui_2048::Active(int ch)
{
	erase();
	switch(ch)
	{
		case KEY_UP:
			Up_active();
			mvwprintw(stdscr, 50 , 30, "UP");			
			break;
		case KEY_DOWN:
			Down_active();
			mvwprintw(stdscr, 50 , 30, "DOWN");
			break;
		case KEY_LEFT:
			Left_active();
			mvwprintw(stdscr, 50 , 30, "LEFT");
			break;
		case KEY_RIGHT:
			Right_active();
			mvwprintw(stdscr, 50 , 30, "RIGHT");
			break;
	}
	Scores ++;
	mvwprintw(stdscr, 51 , 30, "SCORES: %d",Scores);
	return true;
}