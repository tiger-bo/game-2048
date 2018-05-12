#include "2048.h"


int init_framework(char (*fw)[FW_X])
{
	uint16_t weight = 0;
	uint16_t hight = 0;
	uint8_t interval_x = 5;
	uint8_t interval_y = 2;
	for (hight; hight < FW_Y; hight++)
	{
		for (weight = 0; weight < FW_X; weight++)
		{
			if( !(hight / interval_y) )
			{	
				if(hight == 0 || hight == 8)
				{
					fw[hight][weight] = '-';
				}else {

					if( !(weight / interval_x) )
					{
						fw[hight][weight] = '|';

					}else{

						fw[hight][weight] = '-';
					}
				}
			}else{

				if( !(weight / interval_x) )
				{
					fw[hight][weight] = '|';

				}else{

					fw[hight][weight] = ' ';
				}
			}

		}
	}
	//printf("\n");
}

int dispaly_framework(char (*fw)[FW_X])
{
	uint16_t weight = 0;
	uint16_t hight = 0;

	for(hight = 0; hight < HIGHT; hight++)
	{
		for(weight = 0; weight < WEIGHT; weight++)
		{
			printf("%c", fw[hight][weight]);
		}
		printf("\n");
	}
}

int main()
{
	char Framework[HIGHT][WEIGHT] = {'0'};
	init_framework(Framework);
	dispaly_framework(Framework);	
}
