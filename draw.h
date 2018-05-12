#include <curses.h>


#define DRAW_C '|'
#define DRAW_R '-'

void Init_curses();

class Box
{
public:	
	Box();
	~Box();
	void Draw_box();
	int Set_win_x(int size);
	int Set_win_y(int size);
	int Set_box_high(int size);
	int Set_box_width(int size);

	int Get_win_x(int size);
	int Get_win_y(int size);
	int Get_box_high(int size);
	int Get_box_width(int size);
private:
	int win_x;
	int win_y;
	int box_high;
	int box_width;
	WINDOW *win;

};



