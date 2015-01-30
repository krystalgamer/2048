#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Print(int field[4][4]);
int MoveRight(int field[4][4]);

int GetNumMoveUp(int field[4][4],int x,int y)// Ve se é possivel mover o numero de cima para baixo
{
	int num = 0;
	for(int xs = x; xs<=3; xs++)// COMMENNTS NEEDED
	{
		//printf("X:%d Y:%d %d\n\n", xs,y,num);
		if(field[xs][y])
		{
			num++;
		}
	}
	return num;// >0 Pode mover

}
int MoveUp(int field[4][4])// Move pa esquerda
{
	int moved = 0;
	for(int y = 3; y >=0; y--)
	{
		for(int x = 0;x<=3; x++)// A pos 3  n conta
		{
			
			//printf("\n\n X:%d TESTE\n\n", x);
			
			int pos = x;
			while(field[x][y] == 0)// Enquanto n tiver nada no quadrado
			{
				//printf("OLA\n");
				//printf("OI :P\n\n");
				
				if(GetNumMoveUp(field, x,y))// Ve se pode mover pa la algo
				{

					//printf("OI xP\n\n");
				if(pos == 3)//Recursivo, faz com que o loop de mover os nº volte ao inicio
				{
					//printf("\n\n %d y\n\n",y);
					pos = x;
				}
				//printf("\n\n X:%d Y:%d\n\n", x,y);
				field[pos][y] = field[pos+1][y];
				field[pos+1][y] = 0;
				pos++;
				moved++;
					
				
				}
				else
				{
					break;//Nao pode mover ;(
				}
			}
		}
	}
	//SumRight(field);
	//printf("\nX:%d\n",moved);
	return moved;
}
int SumUp(int field[4][4])// Soma esquerda
{
	int moved = 0;
	for(int y = 0; y <4; y++)
	{
		for(int x = 0;x<3; x++)
		{
			if(x != 3)
			{
				if(field[x][y] == field[x+1][y])//Ve se o a seguir é igual
				{
					if(field[x][y] != 0)
					{
					field[x][y] = field[x][y] * 2;//Soma-os :P
					field[x+1][y] = 0;//Coloca 0 para não haver multiplicaçoes
					MoveUp(field);//Move se não era mt chato fazer manualmente
					moved++;
				}
				}

			}

		}
			
			

		}
		//printf("\n\nSum: %d\n", moved);
	
	return moved;
}

/* FUNCOES PARA MOVER PA BAIXO*/
int GetNumMoveDown(int field[4][4],int x,int y)// Ve se é possivel mover o numero de cima para baixo
{
	int num = 0;
	for(int xs = x; xs>=0; xs--)// COMMENNTS NEEDED
	{
		//printf("X:%d Y:%d %d\n\n", xs,y,num);
		if(field[xs][y])
		{
			num++;
		}
	}
	return num;// >0 Pode mover

}
int MoveDown(int field[4][4])// Move pa esquerda
{
	int moved = 0;
	for(int y = 3; y >=0; y--)
	{
		for(int x = 3;x>0; x--)// A pos 3  n conta
		{
			
			int pos = x;
			while(field[x][y] == 0)// Enquanto n tiver nada no quadrado
			{
				//printf("OI :P\n\n");
				
				if(GetNumMoveDown(field, x,y))// Ve se pode mover pa la algo
				{
					//printf("OI xP\n\n");
				if(pos == 0)//Recursivo, faz com que o loop de mover os nº volte ao inicio
				{
					//printf("\n\n %d y\n\n",y);
					pos = x;
				}
				field[pos][y] = field[pos-1][y];
				field[pos-1][y] = 0;
				pos--;
				moved++;
			}
				else
				{
					break;//Nao pode mover ;(
				}
			}
		}
	}
	//SumRight(field);
	
	return moved;
}
int SumDown(int field[4][4])// Soma esquerda
{
	int moved = 0;
	for(int y = 0; y <4; y++)
	{
		for(int x = 3;x>0; x--)
		{
			if(x)
			{
				if(field[x][y] == field[x-1][y])//Ve se o a seguir é igual
				{
					if(field[x][y] != 0)
					{
					field[x][y] = field[x][y] * 2;//Soma-os :P
					field[x-1][y] = 0;//Coloca 0 para não haver multiplicaçoes
					MoveDown(field);//Move se não era mt chato fazer manualmente
					moved++;
				}
				}

			}

		}
			
			

		}
		//printf("\n\nSum: %d\n", moved);
	
	return moved;
}


/* FUNCOES PA MOVER PARA A ESQUERDA*/

int GetNumMoveLeft(int field[4][4],int x,int ys)// Ve se é possivel mover o numero da direita pa esquerda
{
	int num = 0;
	for(int y = ys; y<=3; y++)// Verifica ao contrario 
	{
		if(field[x][y])
		{
			num++;
		}
	}
	return num;// >0 Pode mover

}
int MoveLeft(int field[4][4])// Move pa esquerda
{
	int moved = 0;
	for(int x = 0; x <4; x++)
	{
		for(int y = 0;y<4; y++)// A pos 3  n conta
		{
			
			int pos = y;
			while(field[x][y] == 0)// Enquanto n tiver nada no quadrado
			{
				
				if(GetNumMoveLeft(field, x,y))// Ve se pode mover pa la algo
				{
					
				if(pos == 3)//Recursivo, faz com que o loop de mover os nº volte ao inicio
				{
					//printf("\n\n %d y\n\n",y);
					pos = y;
				}
				field[x][pos] = field[x][pos+1];
				field[x][pos+1] = 0;
				pos++;
				moved++;
			}
				else
				{
					break;//Nao pode mover ;(
				}
			}
		}
	}
	//SumRight(field);
	
	return moved;
}
int SumLeft(int field[4][4])// Soma esquerda
{
	int moved = 0;
	for(int x = 0; x <4; x++)
	{
		for(int y = 0;y<4; y++)
		{
			if(y!=3)
			{
				if(field[x][y] == field[x][y+1])//Ve se o a seguir é igual
				{
					if(field[x][y] != 0)
					{
					field[x][y] = field[x][y] * 2;//Soma-os :P
					field[x][y+1] = 0;//Coloca 0 para não haver multiplicaçoes
					MoveLeft(field);//Move se não era mt chato fazer manualmente
					moved++;
				}
				}

			}

		}
			
			

		}
		//printf("\n\nSum: %d\n", moved);
	
	return moved;
}
/* FUNCOES PA MOVER PARA A DIREITA*/

int SumRight(int field[4][4])// Move pa direita
{
	int moved = 0;
	for(int x = 0; x <4; x++)
	{
		for(int y = 3;y>=0; y--)
		{
			if(y)
			{
				if(field[x][y] == field[x][y-1])//Ve se o anterior é igual
				{
					if(field[x][y] != 0)
					{
					field[x][y] = field[x][y] * 2;//Soma-os :P
					field[x][y-1] = 0;//Coloca 0 para não haver multiplicaçoes
					MoveRight(field);//Move se não era mt chato fazer manualmente
					moved++;
				}
				}

			}

		}
			
			

		}
		//printf("\n\nSum: %d\n", moved);
	
	return moved;
}





int GetNumMoveRight(int field[4][4],int x,int ys)// Ve se é possivel mover o numero da esquerda pa direita
{
	int num = 0;
	for(int y = ys; y>=0; y--)// Verifica ao contrario 
	{
		if(field[x][y])
		{
			num++;
		}
	}
	return num;// >0 Pode mover

}
int MoveRight(int field[4][4])// Move pa direita
{
	int moved = 0;
	for(int x = 0; x <4; x++)
	{
		for(int y = 3;y>0; y--)// A pos 0  n conta
		{
			
			int pos = y;
			while(field[x][y] == 0)// Enquanto n tiver nada no quadrado
			{
				
				if(GetNumMoveRight(field, x,y))// Ve se pode mover pa la algo
				{
					
				if(pos == 0)//Recursivo, faz com que o loop de mover os nº volte ao inicio
				{
					//printf("\n\n %d y\n\n",y);
					pos = y;
				}
				field[x][pos] = field[x][pos-1];
				field[x][pos-1] = 0;
				pos--;
				moved++;
			}
				else
				{
					break;//Nao pode mover ;(
				}
			}
		}
	}
	//SumRight(field);
	
	return moved;
}





void GetPlace(int field [4][4],int nums)//Apnha os livres
{
	int frees = 0;
	int x = 0;
	int y = 0;
	int pos [16][2];
	srand(time(NULL));
	//printf("wtxf\n");

	for(x = 0; x< 4; x++)
	{
		//printf("teste:\n");
		for(y = 0; y < 4; y++)
		{
			if(field[x][y] == 0)
			{
				//printf("DISP\n\nX: %d Y:%d\n\n", x, y);
				pos[frees][0] = x;
				pos[frees][1] = y;
				frees++;
			}
		}
	}

	int slot = rand()%frees;
	//printf("%d %d\n\n", frees, slot);

	x = pos[slot][0];
	y = pos[slot][1];
	//printf("%d\n\n",  nums);
	field[x][y]= nums;
	return;

}

void GenerateTwoOrFour(int field[4][4])//Gera 2 ou 4
{

	
	srand(time(NULL));
	int x = rand()%100;
	if(x%2)
	{
		GetPlace(field, 2);
	}
	else
	{

		GetPlace(field, 4);
	}

}

void Load(int field[4][4])
{
	//printf("%p\n", field);
	for(int i = 0; i< 4; i++)
	{
		//printf("teste: %d\n", i);
		for(int j = 0; j < 4; j++)
		{
			//printf("teste2: %d\n", j);
			field[i][j] = 0;
		}
	}
}
void Print(int field[4][4])
{
	system("clear");

	
	for(int i = 0; i< 4; i++)
	{
		printf("|");
		//printf("tste: %d\n", i);
		for(int j = 0; j < 4; j++)
		{
			if(field[i][j])
			{
				printf("%d|", field[i][j]);

			}
			else
			{
				printf(" |");

			}
		}
		printf("\n");
	}

}
