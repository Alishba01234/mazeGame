#include<stdio.h>
#include<stdlib.h>
  char rows= 7;
  char columns =8;

char maze[7][8]={
    {'X','_','_','X','S','X','X','X'},
    {'_','X','X','X','_','_','_','X'},
    {'X','_','X','X','X','X','_','X'},
    {'X','_','X','X','_','X','_','_'},
    {'X','X','_','_','_','_','X','_'},
    {'X','_','X','_','X','_','_','_'},
    {'X','X','X','E','X','X','X','X'},
};

int playerrow,playercol,i,j;
int score=0;
void mazeprinting(){
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            printf("%c", maze[i][j]);
            printf("\t");
            
        }
        printf("\n");
    }
    printf("Your current  score is %d\n",score);
}

int user_action(char direction){
    switch (direction){
        case 'U':
        case 'u':
        if(playerrow>0 && maze[playerrow-1][playercol]!='X'){
          maze[playerrow][playercol]='_';
          playerrow--;
          maze[playerrow][playercol]='$';
          score+=50;
          return 1;
        }
        break;
        case 'D':
        case 'd':
        if(playerrow<rows-1 && maze[playerrow+1][playercol]!='X'){
          maze[playerrow][playercol]='_';
          playerrow++;
          maze[playerrow][playercol]='$';
          score+=50;
          return 1;
        }
        break;
        case 'L':
        case 'l':
        if(playercol>0 && maze[playerrow][playercol-1]!='X'){
          maze[playerrow][playercol]='_';
          playercol--;
          maze[playerrow][playercol]='$';
          score+=50;
          return 1;
        }
        break;
        case 'R':
        case 'r':
        if(playercol<columns-1 && maze[playerrow][playercol+1]!='X'){
          maze[playerrow][playercol]='_';
          playercol++;
          maze[playerrow][playercol]='$';
          score+=50;
          return 1;
        }
        break;
        case 'Q':
        case 'q':
        printf("You quit the game, your final score is %d",score);
        exit(0);
        default:
        printf("Invalid move! please try again:\n");
        return 0 ;
            
    }

    printf("OOPS YOU COLLIDED WITH A WALL, YOU LOST THE GAME:\n");
    exit(0);
    return 0;
}

int main(){
    
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            if(maze[i][j]=='S'){
                playerrow=i;
                playercol=j;
                break;
            }
        }
    }

    char move;
    int success;
         printf("Welcome in my MAZE GAME!\n");
    do{
        
        mazeprinting();
        printf("In the above maze 'X' represent closed path and '_' represent open path:\n");
        printf("Enter your move ('u','U for up 'd','D for down 'l','L' for left , 'r','R' and 'Q','q' for quit):\n");
        scanf(" %c",&move);
        success = user_action(move);
        if(success){
            if( maze[6][3]=='$'){
                printf("CONGRATULATIONS! You have reached the exit:\n");
                printf("Your final score is %d",score);
                break;
            }
            
        }              
    }
    while(1);
    return 0;
}
