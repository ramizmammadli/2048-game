#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randomnumbers[3]={2,4};
int check;
int main() {
	int matrix[5][5], i, j, tmp, tmp2, game=1, N, M, score=0, highscore=0, count=0, tmpmatrix[5][5], action;
	int highscoreallow = 0;
	char d;
    srand(time(NULL));
	printf("Welcome to the 2048 game.");
	printf("\n");
	printf("\n");
	printf(" 'W' is upward direction. ");
	printf("\n");
	printf(" 'S' is downward direction. ");
	printf("\n");
	printf(" 'A' is leftward direction. ");
	printf("\n");
	printf(" 'D' is rightward direction. ");
	printf("\n");
	printf(" Press 'E' to exit the game\n");
	printf(" Press 'X' to reset the game\n");
	printf("\n");
	printf(" If you can reach 2048, you will win the game. Good luck!!");
	printf("\n\n");
	printf("Press anything to start the game ...");
	getch();
	system("cls");
	//Our main matrix, which the game is played on, is matrix[i][j]
	for(i=1;i<=4; i++){
		for(j=1; j<=4; j++){
			matrix[i][j]=0;
		}
	}
	for(i=1;  i<=4; i++){
		for(j=1; j<=4; j++){
			tmpmatrix[i][j]=0;
		}
	}
	// Here, for the beginning, two random numbers, which can be 2 or 4, are included to the the game.
	int A, B, e1, e2, e3, e4;
	A=rand()%2;
	B=rand()%2;
	e1=rand()%4+1;
	e2=rand()%4+1;
	e3=rand()%4+1;
	e4=rand()%4+1;
	// tmpmatrix[i][j] is used as a temporary matrix, which can be useful in upcoming steps.
		matrix[e1][e2] = randomnumbers[A];
		matrix[e3][e4] = randomnumbers[B];
		
		tmpmatrix[e1][e2] = randomnumbers[A];
		tmpmatrix[e3][e4] = randomnumbers[B];
		//including score and highscore.
		printf("                                score = 0");
		printf("\n");
		printf("                                high score = 0");
	printf("\n");
	printf("\n");
	//Game starts with this while loop.
    while (game==1){
    
		printf("\n");
    	printf("Please enter the direction(W-up, S- down, A-left, D-right)");
    	printf("\n");
    	
    //The beginning form of the matrix is printed here.	
	printf("\n");
	printf("-------------------------------------");
	printf("\n");
	for(i=1;i<=4; i++){
		for(j=1; j<=4; j++){
			if(matrix[i][j]==0){
				char s = ' '; // char s is used to replace zeros in the matrix.
				printf("|  %4c  ", s);
			}
			
			else if (matrix[i][j] == 3 || matrix[i][j] == 5) { //this else if is used to detect the new added random number and add asteriks to it.
				matrix[i][j] -= 1;
				printf("|  %4d* ", matrix[N][M]);
			}
			else
				printf("|  %4d  ", matrix[i][j]);
		}
			printf("|\n");
			printf("-------------------------------------");
			printf("\n");
	}
	//getch() is used to apply functions without enter button. 
    d=getch();
    	/* whenever the 'w' button is pressed, this algorithm detects if there is space on the number or not. 
		If there is, it changes the numbers' places with the respective spaces.*/
    if(d=='w' || d=='W'){ 
        for(i=2; i<=4; i++){
            for(j=1; j<=4; j++){
                if(matrix[i][j]!=0){
                    tmp=i;
                    while(tmp> 1 && matrix[tmp-1][j]==0){
                        tmp--;
                    }
	
                    tmp2=matrix[i][j];
                    matrix[i][j]=matrix[tmp][j];
                    matrix[tmp][j]=tmp2;
					check = 0;
					
                    if (tmp > 1 && matrix[tmp][j]==matrix[tmp-1][j]){
                        matrix[tmp-1][j]=matrix[tmp][j]+matrix[tmp-1][j];
                        score=score+matrix[tmp-1][j];
                        matrix[tmp][j]=0;
                        check = 1;
                    }
                }
            }
        }
    }
     
     /* whenever the 's' button is pressed, this algorithm detects if there is space under the number or not. 
		If there is, it changes the numbers' places with the respective spaces.*/
    else if(d=='s' || d=='S'){
        for(i=3; i>=1; i--){
            for(j=1; j<=4; j++){
                if(matrix[i][j]!=0){
                    tmp=i;
                    while(tmp<4 && matrix[tmp+1][j]==0){

                        tmp++;
                    }
                    tmp2=matrix[i][j];
                    matrix[i][j]=matrix[tmp][j];
                    matrix[tmp][j]=tmp2;
					check = 0;
                    if (tmp <4 && matrix[tmp][j]==matrix[tmp+1][j]){
                        matrix[tmp+1][j]=matrix[tmp][j]+matrix[tmp+1][j];
                        score=score+matrix[tmp+1][j];
                        matrix[tmp][j]=0;
                    	check = 1;
                    }
                }
            }
        }
    }
    /* whenever the 'a' button is pressed, this algorithm detects all the respective spaces to the rightward of the numbers.  
		If there is, it changes the numbers' places with the respective spaces.*/
    else if (d=='a' || d=='A'){
        for(i=1; i<=4; i++){
            for(j=2; j<=4; j++){
                if(matrix[i][j]!=0){
                    tmp=j;
                    while(tmp>1 && matrix[i][tmp-1]==0){
                        tmp--;
                    }
                    tmp2=matrix[i][j];
                    matrix[i][j]=matrix[i][tmp];
                    matrix[i][tmp]=tmp2;
					check = 0;
                    if(tmp > 1 && matrix[i][tmp]==matrix[i][tmp-1]){
                        matrix[i][tmp-1]=matrix[i][tmp-1]+matrix[i][tmp];
                        score+=matrix[i][tmp-1];
                        matrix[i][tmp]=0;
                        check = 1;
                    }
                }
            }
        }
    }
    /* whenever the 'd' button is pressed, this algorithm detects all the respective spaces to the leftward of the numbers.  
		If there is, it changes the numbers' places with the respective spaces.*/
    else if(d=='d' || d=='D'){
        for(i=1; i<=4; i++){
            for(j=3; j>=1; j--){
                if(matrix[i][j]!=0){
                    tmp=j;
                    while(tmp<4 && matrix[i][tmp+1]==0){
                        tmp++;
                    }
                    tmp2=matrix[i][j];
                    matrix[i][j]=matrix[i][tmp];
                    matrix[i][tmp]=tmp2;
					check = 0;
                    if(tmp<4 && matrix[i][tmp]==matrix[i][tmp+1]){

                        matrix[i][tmp+1]=matrix[i][tmp+1]+matrix[i][tmp];
                        score+=matrix[i][tmp+1];
                        matrix[i][tmp]=0;
                        check = 1;
                    }
                }
            }
        }
    }
    // If the player presses 'e' button, the main while loop stops with game=2 insertion and the final score is shown on the screen. 
    else if(d=='e' || d=='E'){
    	printf("\n");
        printf(" Game is stopped, your score is: %d", score);
        printf("\n");
        game=2;
    }
    else if(d=='x' || d=='X'){ //'x' button resets the game and the score, and includes new 2 or 4 to the random places.
    	    printf("\n Game is reset\n");
		for(i=1; i<=4; i++){
    		for(j=1; j<=4; j++){
    			matrix[i][j]=0;
			}
		}
		matrix[rand()%4+1][rand()%4+1] = randomnumbers[rand()%2];
		matrix[rand()%4+1][rand()%4+1] = randomnumbers[rand()%2];
	score=0;
	}
    
    else { // if the player presses the other buttons, this warning appears on the screen. 
    	printf("\n");
    	printf("						---Unknown button!!!---  ");
    	printf("\n");
	}
	// this if is for updating the highscore.
	if (score > highscore)
		highscore = score;
	// if one of the directions is pressed, the score and highscore will appear on the screen.
	if (d=='a'|| d=='A' || d=='s' || d=='S' || d=='d' || d=='D' || d=='w' || d=='W'){

	printf("\n");
	printf("                               score = %d", score);
	printf("\n");
	
	
	printf("                              highscore = %d", highscore);
	printf("\n");
    }
      // this bulky if detects either there is movement of the numbers or not. If there is, the algorithm includes another random number to the randomly chosen space of the matrix. 
	if(check || ( (d == 'd' || d == 'D') && (matrix[1][4] == 0 || matrix[2][4] == 0 || matrix[3][4] == 0 || matrix[4][4] == 0) ) || ( (d == 'w' || d == 'W') && (matrix[1][1] == 0 || matrix[1][2] == 0 || matrix[1][3] == 0 || matrix[1][4] == 0) ) || ( (d == 'a' || d == 'A') && (matrix[1][1] == 0 || matrix[2][1] == 0 || matrix[3][1] == 0 || matrix[4][1] == 0) ) || ( (d == 's' || d == 'S') && (matrix[4][1] == 0 || matrix[4][2] == 0 || matrix[4][3] == 0 || matrix[4][4] == 0) ))
	{
			N=rand()%4+1;
    		M=rand()%4+1;
	
	
   	 		while(matrix[N][M]!=0){
       		N=rand()%4+1;
        	M=rand()%4+1;
    		}
		matrix[N][M]=randomnumbers[rand()%2];
		matrix[N][M]++;
    
    
	} 
    // if the player reaches 2048, he or she wins.
	
	// P.S. I do think that this sentence will never appear :) :). 
    for(i=1; i<=4; i++){
    	for(j=1; j<=4; j++){
    		if(matrix[i][j]==2048){
    			printf("Congratulations, you won the game!!!");
    			game=2;
			}
		}
	}
	}
	return 0;

}
