#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
const int wall = 11;
int snake[1024][2] ,bait[2];
int kill = 0 , tail = 1;
int direction = 0,UP = 1,DOWN = 2,LEFT = 3,RIGHT=4;
void delay(){
	int i,j,k;
	for(i = 0 ; i <= 20000 ; i++){
			for(j = 0 ; j <= 10000 ; j++)
				k = 0;	
	}
}
void hit(){
	if (snake[0][0] <= 0 ){
		snake[0][0] = wall-1;
	}
	if (snake[0][0] >= wall ){
		snake[0][0] = 1;
	}
	if (snake[0][1] <= 0 ){
		snake[0][1] = wall-1;
	}
	if (snake[0][1] >= wall ){
		snake[0][1] = 1;
	}
	int i;
	for(i = 2;i<=tail;i++)
		if(snake[i][0] == snake[0][0] && snake[i][1] == snake[0][1] )
			kill = 1;
}
void input(){
	if(_kbhit()){
		switch(_getch()){
			case 'W':
			case 'w':
				if (direction != DOWN)
				direction = UP;
				break;
			case 'S':
			case 's':
				if (direction != UP)
				direction = DOWN;
				break;
			case 'A':
			case 'a':
				if (direction != RIGHT)
				direction = LEFT;
				break;
			case 'D':
			case 'd':
				if (direction != LEFT)
				direction = RIGHT;
				break;
		}	
	}
			if (direction == UP)
				snake[0][1]--;
			if (direction == DOWN)
				snake[0][1]++;
			if (direction == LEFT)
				snake[0][0]--;
			if (direction == RIGHT)
				snake[0][0]++;
}
void length(){
int i;
for (i = tail;i >= 1 ; i--){
	snake[i][0] = snake[i-1][0];
	snake[i][1] = snake[i-1][1];
}
}
void screen2(int x,int y){
	int i,j;
	for (i = 0;i<=wall*wall;i++){
		if (snake[i][0] == x && snake[i][1] == y){
			printf("o"); break;
		}
		if (i == wall*wall) printf(" ");	
	}
}
void screen(){
	system("cls");
	int x,y,i,j;
	for(y = 0; y <= wall ; y++){
		for(x = 0; x <= wall ; x++){
			if (y == 0 || x == 0 || x == wall || y == wall)
				printf("#");
			else if(bait[0] == x && bait[1] == y)
				printf("+");
			else screen2(x,y);
			printf(" ");
		}	
	printf("\n");	
	}
	printf("Score : %d",tail);
}
int main(){
	srand(time(NULL));
	bait[0] = rand()%(wall-1)+1;
	bait[1] = rand()%(wall-1)+1;
	system("mode con:cols=24 lines=13");
	snake[0][0] = wall/2;
	snake[0][1] = wall/2;
	while(1){
		if (snake[0][0] == bait[0] && snake[0][1] == bait[1]){
			bait[0] = rand()%(wall-1)+1;
			bait[1] = rand()%(wall-1)+1;
			tail++;
		}
		delay();
		input();
		hit();
		length();
		screen();
		if(kill == 1)
			break;	
	}
	system("cls");
	printf("YOUR SCORE : %d",tail);
	int i;
	for (i = 0 ; i < 10 ; i++)
		_getch();
}
