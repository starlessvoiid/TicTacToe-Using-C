#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void board();
bool Win(char cases[]);
bool CheckPos(int position);
bool is_draw(int Played_Positions[]);
char cases[]={'1','2','3',
			  '4','5','6',
			  '7','8','9'};
int Played_Positions[]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
bool player1=true,Game_On=true;
int position=0;
int main()
{
	printf("===================\n");
	printf(" ¤¤ TIC TAC TOE ¤¤ \n");
	printf("===================\n");
	
	while (Game_On){
			player1=true;
			board(cases);
			if (player1){
				printf("Player X choose your position : ");
				scanf("%d",&position);
				while (CheckPos(position)){
					printf("Player X choose your position : ");
					scanf("%d",&position);
				}
				Played_Positions[position]=position;
				cases[position]='X';
				board(cases);
				player1=false;
				if(Win(cases)){
					printf("Player X won !!!\n");
					return false;
				}
				else if(is_draw(Played_Positions)){
					printf("Draw !!!\n");
					return false;
				}
				
			}
			printf("Player O choose your position : ");
			scanf("%d",&position);
			while (CheckPos(position)){
				printf("Player X choose your position : ");
				scanf("%d",&position);
			}
			Played_Positions[position]=position;
			cases[position]='O';
			board(cases);
			if(Win(cases)){
				printf("Player O won !!!\n");
				return false;
			}
			else if(is_draw(Played_Positions)){
					printf("Draw !!!\n");
					return false;
				}	
			}
	
    return 0;

}
void board(char cases[]){
	printf("+---+---+---+\n");
	for (int i=0;i<9;i=i+3){
		printf("| %c | %c | %c |\n",cases[i],cases[i+1],cases[i+2]);
		printf("%s\n",(i==2)?"":"+---+---+---+");
	}
}
bool Win(char cases[]){
//Wins Horizontally:
	if ((cases[0]==cases[1] && cases[1]==cases[2])||(cases[3]==cases[4] && cases[4]==cases[5]) || 
	(cases[6]==cases[7] && cases[7]==cases[8])){
		return true;
	}
//Wins Vertically:
	else if ((cases[0]==cases[3] && cases[3]==cases[6])||(cases[1]==cases[4] && cases[4]==cases[7]) || 
	(cases[2]==cases[5] && cases[5]==cases[8])){
		return true;
	}
//Wins diagonally:
	else if ((cases[0]==cases[4] && cases[4]==cases[8])||(cases[2]==cases[4] && cases[4]==cases[6]))
	{
		return true;
	}
	else{
		return false;
	}
}
bool CheckPos(int position){
	for (int i=0;i<9;i++){
		if (Played_Positions[i]==position){
			return true;
		}
	}
	return false;
}
bool is_draw(int Played_Positions[]){
	for (int i=0;i<9;i++){
		if(Played_Positions[i]==-1){
			return false;
		}
	}
	return true;
}