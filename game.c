#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>

#include <time.h>


#define KEY_D 100
#define KEY_A 97
#define KEY_S 115


/*
TODO;
FUNCAO IR PA BAIXO ;)

MAIS TARDE MELHORAR O CODIGO
ver se tem casas livres pa o lado a mover ou se pode somar :P

Agora este codigo de merda serve


*/

void setBufferedInput(bool enable) {
	static bool enabled = true;
	static struct termios old;
	struct termios new;

	if (enable && !enabled) {
		// restore the former settings
		tcsetattr(STDIN_FILENO,TCSANOW,&old);
		// set the new state
		enabled = true;
	} else if (!enable && enabled) {
		// get the terminal settings for standard input
		tcgetattr(STDIN_FILENO,&new);
		// we want to keep the old setting to restore them at the end
		old = new;
		// disable canonical mode (buffered i/o) and local echo
		new.c_lflag &=(~ICANON & ~ECHO);
		// set the new settings immediately
		tcsetattr(STDIN_FILENO,TCSANOW,&new);
		// set the new state
		enabled = false;
	}
}

int main(void)
{

	setBufferedInput(false);
	//printf("wtf\n");
	int field[4][4];
	char ch;
	Load(field);
	int moved = 0;
	//field[0][1] = 4;
	//field[1][1] = 2;

	//GetPlace(field);
	
	GenerateTwoOrFour(field);
	while(1)
	{
		GenerateTwoOrFour(field);
		
		Print(field);
		while(!moved)
		{
			ch = getchar();
			//printf("%d\n\n", ch);
			if(ch == KEY_D)
			{
				int k = MoveRight(field);
				int j = SumRight(field);
			if(j || k)
			{
				break;
			}

			}
			if(ch == KEY_A)
			{
				int k = MoveLeft(field);
				int j = SumLeft(field);
			if(j || k)
			{
				break;
			}

			}
			if(ch == KEY_S)
			{
				int k = MoveDown(field);
				int j = SumDown(field);
			if(j || k)
			{
				break;
			}

			}
			if(ch == 119)
			{
				int k = MoveUp(field);
				int j = SumUp(field);
			if(j || k)
			{
				//printf("%d %d\n\n", j, k);
				break;
			}

			}


			
			

		}
		
		
		
	
		fflush(stdin);
		
		

	}
	return 0;
}