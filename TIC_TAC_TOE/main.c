#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
    printf("\n\n\t\t\t\tGame number : %d\n\n\t\t\t\tScore : X = %d , O = %d",gn,x,o);
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
    printf("  _____                     \n");
    printf(" |  __ \\                    \n");
    printf(" | |  | |_ __ __ ___      __\n");
    printf(" | |  | | '__/ _` \\ \\ /\\ / /\n");
    printf(" | |__| | | | (_| |\\ V  V / \n");
    printf(" |_____/|_|  \\__,_| \\_/\\_/  \n\n");
}

 char tic[5][5]={

        {' ','|',' ','|',' '},
        {'-','-','-','-','-'},
        {' ','|',' ','|',' '},
        {'-','-','-','-','-'},
        {' ','|',' ','|',' '}

 };


 int c=0,winner,inv=0;

 int gn=1,x=0,o=0;

 char ng1;

 int used[9]={0,0,0,0,0,0,0,0,0};

void display();
void entry(int a,int i);
void newgame1();
void main()
{
    newgame:

    heading(gn,x,o);

    int p;

    //Ending the loop

    for (int k=1;k<=10;k++)
    {
        printf("\n");

        if(inv==1)
        {
            printf("\n\nInvalid Entry\n\n");
            goto input;
        }


        system("cls");

        heading(gn,x,o);

        display();
        if(k==10)
        {
            draw();
            break;
        }


        //Taking input
        input:
        printf("\nEnter the position :");
        scanf("%d",&p);

        //Checking input

        for(int s=0;s<10;s++)
        {
            if(p==used[s]||p<1||p>9)
            {
                invalid:
                printf("\n\nInvalid Entry\n\n");
                inv=1;
                //printf("%d,%d\n",used[s],c+1);

                goto gohere;
                //c--;
            }

                //c++;
        }
        goto comehere;

        gohere:
            k--;
            continue;


        comehere:
            inv=0;
            entry(p,k-1);
            winner=check();
            if(winner==1&&k%2!=0)
            {
                system("cls");
                heading(gn,x,o);
                display();
                printf("\n\n\t\t\t\tPlayer 1 wins\n\n");
                win1();
                x++;
                break;
            }
            else if(winner==1&&k%2==0)
            {
                system("cls");
                heading(gn,x,o);
                display();
                printf("\n\n\t\t\t\tPlayer 2 wins\n\n");
                win2();
                o++;
                break;
            }


    }

    printf("Do you want to play another game : (y/n)");
    scanf("\n%c",&ng1);

    if(ng1=='y'||ng1=='Y')
    {
        newgame1();
        gn++;
        goto newgame;
    }

}





//Function to display the game board

void display ()
{
    printf("\n\n\n\n");
    printf("\t\t\t\t");

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%c",tic[i][j]);
            (j==4)?(printf("\n\t\t\t\t")):(printf(""));
        }
    }
}





//Function to take an entry and update the used array

void entry (int a,int i)
{
    switch(a)
    {
    case 1:
        tic[0][0]=(i%2==0)?('X'):('O');
        break;
    case 2:
        tic[0][2]=(i%2==0)?('X'):('O');
        break;
    case 3:
        tic[0][4]=(i%2==0)?('X'):('O');
        break;
    case 4:
        tic[2][0]=(i%2==0)?('X'):('O');
        break;
    case 5:
        tic[2][2]=(i%2==0)?('X'):('O');
        break;
    case 6:
        tic[2][4]=(i%2==0)?('X'):('O');
        break;
    case 7:
        tic[4][0]=(i%2==0)?('X'):('O');
        break;
    case 8:
        tic[4][2]=(i%2==0)?('X'):('O');
        break;
    case 9:
        tic[4][4]=(i%2==0)?('X'):('O');
        break;
    }

    used[i+1]= a;

}

//Function for checking the winner

int check ()
{
    if(tic[0][0]==tic[0][2]&&tic[0][2]==tic[0][4]&&tic[0][0]!=' ')
    {
        return 1;
    }
    else if(tic[2][0]==tic[2][2]&&tic[2][2]==tic[2][4]&&tic[2][0]!=' ')
    {
        return 1;
    }
    else if(tic[4][0]==tic[4][2]&&tic[4][2]==tic[4][4]&&tic[4][0]!=' ')
    {
        return 1;
    }
    else if(tic[0][0]==tic[2][0]&&tic[0][0]==tic[4][0]&&tic[0][0]!=' ')
    {
        return 1;
    }
    else if(tic[0][2]==tic[2][2]&&tic[0][2]==tic[4][2]&&tic[0][2]!=' ')
    {
        return 1;
    }
    else if(tic[0][4]==tic[2][4]&&tic[0][4]==tic[4][4]&&tic[0][4]!=' ')
    {
        return 1;
    }
    else if(tic[0][0]==tic[2][2]&&tic[0][0]==tic[4][4]&&tic[0][0]!=' ')
    {
        return 1;
    }
    else if(tic[0][4]==tic[2][2]&&tic[0][4]==tic[4][0]&&tic[0][4]!=' ')
    {
        return 1;
    }
}

//Function to start a new game

void newgame1()
{

    int c=0,winner,inv=0;

    for(int k=0;k<10;k++)
    {
        used[k]=0;
    }

 for (int i=0;i<5;i=i+2)
 {
     for(int j=0;j<5;j=j+2)
     {
         tic[i][j]=' ';
     }
 }


}

