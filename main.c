#include <stdio.h>
#include <stdlib.h>

void heading(int gn,int x,int o)

{
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("  _______ _                 _______                    _______         \n");
    printf(" |__   __(_)               |__   __|                  |__   __|        \n");
    printf("    | |   _  ___   ______     | | __ _  ___   ______     | | ___   ___ \n");
    printf("    | |  | |/ __| |______|    | |/ _` |/ __| |______|    | |/ _ \\ / _ \\\n");
    printf("    | |  | | (__              | | (_| | (__              | | (_) |  __/\n");
    printf("    |_|  |_|\\___|             |_|\\__,_|\\___|             |_|\\___/ \\___|\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\n\n\t\t\t\tGame number : %d\n\n\t\t\t\tScore : X----%d  O----%d\n\n",gn,x,o);
}

void win1()
{
    printf("\t\t __   __            _           \n");
    printf("\t\t \\ \\ / /           (_)          \n");
    printf("\t\t  \\ V /   __      ___ _ __  ___ \n");
    printf("\t\t   > <    \\ \\ /\\ / / | '_ \\/ __|\n");
    printf("\t\t  / . \\    \\ V  V /| | | | \\__ \\\n");
    printf("\t\t /_/ \\_\\    \\_/\\_/ |_|_| |_|___/\n\n");
}

void win2()
{
    printf("\t\t   ____              _           \n");
    printf("\t\t  / __ \\            (_)          \n");
    printf("\t\t | |  | |  __      ___ _ __  ___ \n");
    printf("\t\t | |  | |  \\ \\ /\\ / / | '_ \\/ __|\n");
    printf("\t\t | |__| |   \\ V  V /| | | | \\__ \\\n");
    printf("\t\t  \\____/     \\_/\\_/ |_|_| |_|___/\n\n");
}

void draw()
{
    printf("\n\n");
    printf("\t\t  _____                     \n");
    printf("\t\t |  __ \\                    \n");
    printf("\t\t | |  | |_ __ __ ___      __\n");
    printf("\t\t | |  | | '__/ _` \\ \\ /\\ / /\n");
    printf("\t\t | |__| | | | (_| |\\ V  V / \n");
    printf("\t\t |_____/|_|  \\__,_| \\_/\\_/  \n\n");
}

//Function prints the board
void dboard(char b[],int size)
{
    printf("\t\t\t\t");

    for(int i=0;i<9;i++)
    {

        printf("%c",b[i]);
        (i==2||i==5||i==8)?(printf("\n\t\t\t\t")):(printf("|"));

        (i==2||i==5)?(printf("------\n\t\t\t\t")):(printf(""));

    }
}

//Function checks the winning condition returns c=1 if true

int check(char b[],int size,int c)
{
    if(

    (b[0]==b[1]&&b[0]==b[2]&&b[0]!=' ')
       ||
    (b[3]==b[4]&&b[3]==b[5]&&b[3]!=' ')
       ||
    (b[6]==b[7]&&b[6]==b[8]&&b[6]!=' ')
       ||
    (b[0]==b[3]&&b[0]==b[6]&&b[0]!=' ')
       ||
    (b[1]==b[4]&&b[1]==b[7]&&b[1]!=' ')
       ||
    (b[2]==b[5]&&b[2]==b[8]&&b[2]!=' ')
       ||
    (b[0]==b[4]&&b[0]==b[8]&&b[0]!=' ')
       ||
    (b[2]==b[4]&&b[2]==b[6]&&b[2]!=' ')
    )
    {
        c=1;
    }
    return c;
}

void main()
{

    //Integers for counting the number of games played and the individual scores of X and O
    int gn=1,x=0,o=0;
    char g;

    //New game starts here

    newgame:

    heading(gn,x,o);

    printf("\n\n");

    char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};  //Board with 9 elements as spaces

    int p,c=0;
    dboard(board,9);    //Prints board


    printf("\t\t");


    //Main loop

    for(int k=0;k<9;k++)
    {

    printf("\n\n\t\tEnter the position :");
    scanf("%d",&p);

    //Cheat code

    if(p==6699&&k%2==0)
    {
        printf("X wins\n\n");
        win1();        //Print the pattern 'X wins'
        x++;        //Update the score for X
        c++;
        break;
    }

    else if(p==6699&&k%2!=0)
    {
        printf("O wins\n\n");
        win2();    //Print the pattern 'O wins'
        o++;    //Update the score for O
        c++;
        break;

    }

    //Checking for a valid entry

    if(board[p]==' '&&p<=9&&p>=0)
        {
            board[p]= (k%2==0)?('X'):('O');
            system("cls");        //Clear screen to avoid displaying each step of the game
            heading(gn,x,o);        //Decoration
            printf("\n\n");
            dboard(board,9);
        }
    else
    {
        printf("Invalid character\n");
        k--;
        continue;
    }

    //Checking winning condition

    c=check(board,9,c);

    if(c==1&&k%2==0)
    {
        printf("X wins\n\n");
        win1();        //Print the pattern 'X wins'
        x++;        //Update the score for X
        break;
    }
    else if(c==1&&k%2!=0)
    {
        printf("O wins\n\n");
        win2();    //Print the pattern 'O wins'
        o++;    //Update the score for O
        break;

    }

    }

    //Loop runs 9 times with no winner
    (c==0)?(draw()):(printf(""));

    invalidinput:

    //New game

    printf("Do you want to play a new game : (y/n)");
    scanf(" %c",&g);

    if(g=='y'||g=='Y')
    {
        system("cls");
        gn++;
        goto newgame;
    }
    else if (g=='n'||g=='N')
    {
        goto end;
    }
    else{
        printf("\n\nInvalid input\n\n");
        goto invalidinput;
    }


    end:;

}
