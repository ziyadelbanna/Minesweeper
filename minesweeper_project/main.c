#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "Welcomedisplay.h"
#include "generate.h"
#include "action_cell.h"
#include "print_grid.h"
#include "DFS.h"
#include "win.h"
#include "zero_fin.h"
#include "print_win.h"
#include "save_load.h"
#include "leaderboards.h"
#include "checkint.h"
void print_grid(int row,int coloumn,char b[row][coloumn]);
void generate_values(int row,int coloumn,char a[row][coloumn],int x,int y);
void startgame();
int action_cell(int x,int y,int row,int coloumn,int *flag_no,int *question_no,char grid[row][coloumn],char value[row][coloumn]);
int static lose=0;
int static win2=0;
void main()
{
    system ("MODE 250 , 250");
    int userInput,lose3;
    Welcomescreen();
    getchar();
    system("cls");
    FILE* lost1=fopen("lost","r");
    fscanf(lost1,"%d",&lose3);
    if(lose3==1)
    {
        MainMenu1();
        checkInt();
        scanf("%d",&userInput);
        system("cls");
        if (userInput==1){startgame();}
        else if(userInput==2){print();}
    }
    else
    {
        MainMenu();
        checkInt();
        scanf("%d",&userInput);
        system("cls");
        if (userInput==1){startgame();}
        else if(userInput==2){load_game();}
        else if(userInput==3){print();}
    }

}



void startgame()
{
    int row,coloumn,i,k,flag_no=0,question_no=0;
    struct leaderboards target;
    FILE* lost=fopen("lost","w");
    fprintf(lost,"0");
    fclose(lost);
    clock_t start,end;
    int time,score=0,no_of_moves=1;
    printf("Enter number of rows(max size=30/min size=2): ");
    checkInt ();
    scanf("%d",&row);
    while (row>30||row<2)
    {printf("please choose row size within the given boundary: ");
    checkInt();
    scanf("%d",&row);}
    printf("Enter number of coloumns(max size=30/min size=2): ");
    checkInt ();
    scanf("%d",&coloumn);
    while (coloumn>30||coloumn<2)
    {printf("please choose row size within the given boundary: ");
    checkInt();
    scanf("%d",&coloumn);}
    char grid[row][coloumn];
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            grid[i][k]='X';
        }
    }
    char value[row][coloumn];
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            value[i][k]='0';
        }
    }
    print_grid(row,coloumn,grid);
    int  r_read,c_read;
    printf("Enter n: ");
    checkInt ();
    scanf("%d",&c_read);
    while (c_read>coloumn||c_read<0)
    {printf("please choose a coloumn number within the grid\n");
    printf("Enter n: ");
    checkInt();
    scanf("%d",&c_read);}
    start=clock();
    printf("Enter y: ");
    checkInt ();
    scanf("%d",&r_read);
      while (r_read>row||r_read<0)
    {printf("please choose a row number within the grid\n");
    printf("Enter y: ");
    checkInt();
    scanf("%d",&r_read);}

    r_read--;
    c_read--;
    generate_values(row,coloumn,value,r_read,c_read);
    FILE* write=fopen("value","w");
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            fprintf(write," %c",value[i][k]);
        }
        fprintf(write,"\n");
    }
    fclose(write);
    lose=action_cell(r_read,c_read,row,coloumn,&flag_no,&question_no,grid,value);
    end=clock();
    time=(end-start)/CLOCKS_PER_SEC;
     if(time==0)
            time=1;
    save(row,coloumn,time,flag_no,question_no,no_of_moves,grid);
    win2=win(row,coloumn,grid,value);
        if(win2==1)
        {
            lose=1;
            FILE* lost=fopen("lost","w");
            fprintf(lost,"%d",lose);
            fclose(lost);
            print_win(row,coloumn,value);
            score=(pow(row,4)*pow(coloumn,4))/(time*no_of_moves);
            printf("\ntime:%d  score:%d  number of moves:%d\n",time,score,no_of_moves);
            printf("Enter your name:");
            scanf(" %[^\n]s",target.name);
            i=0;
            while(target.name[i]!='\0')
            {
                target.name[i]=(char)tolower(target.name[i]);
                i++;
            }
            target.score=score;
            query(target);
        }
    while(lose==0)
    {

        system("cls");
        print_grid(row,coloumn,grid);
        printf("\ntime:%d  flags used:%d  question marks used:%d  number of moves:%d",time,flag_no,question_no,no_of_moves);
        printf("\nEnter x: ");
        checkInt ();
        scanf("%d",&c_read);
        printf("Enter y: ");
        checkInt ();
        scanf("%d",&r_read);
        no_of_moves++;
        r_read--;
        c_read--;
        lose=action_cell(r_read,c_read,row,coloumn,&flag_no,&question_no,grid,value);
        end=clock();
        time=(end-start)/CLOCKS_PER_SEC;

        if(lose==1)
        {
            printf("\ntime:%d  number of moves:%d",time,no_of_moves);
            FILE* lost=fopen("lost","w");
            fprintf(lost,"%d",lose);
            fclose(lost);
        }

        save(row,coloumn,time,flag_no,question_no,no_of_moves,grid);
        win2=win(row,coloumn,grid,value);
        if(win2==1)
        {
            lose=1;
            FILE* lost=fopen("lost","w");
            fprintf(lost,"%d",lose);
            fclose(lost);
            print_win(row,coloumn,value);
            score=(pow(row,4)*pow(coloumn,4))/(time*no_of_moves);
            printf("\ntime:%d  score:%d  number of moves:%d\n",time,score,no_of_moves);
            printf("Enter your name:");
            scanf(" %[^\n]s",target.name);
            i=0;
            while(target.name[i]!='\0')
            {
                target.name[i]=(char)tolower(target.name[i]);
                i++;
            }
            target.score=score;
            query(target);
        }
    }
}
void load_game()
{
    int row,coloumn,c_read,r_read,time,flag_no,question_no,no_of_moves,score,time1,i;
    struct leaderboards target;
    clock_t start,end;
    load_r_c(&row,&coloumn,&time,&flag_no,&question_no,&no_of_moves);
    char grid[row][coloumn],value[row][coloumn];
    load_arr(row,coloumn,grid,value);
    print_grid(row,coloumn,grid);
        printf("\ntime:%d  flags used:%d  question marks used:%d  number of moves:%d",time,flag_no,question_no,no_of_moves);
        printf("\nEnter n: ");
        checkInt ();
        scanf("%d",&c_read);
        start=clock();
        printf("Enter y: ");
        checkInt ();
        scanf("%d",&r_read);
        no_of_moves++;
        r_read--;
        c_read--;
        lose=action_cell(r_read,c_read,row,coloumn,&flag_no,&question_no,grid,value);
        end=clock();
        time1=time+(end-start)/CLOCKS_PER_SEC;

        if(lose==1)
        {
            printf("\ntime:%d   number of moves:%d",time1,no_of_moves);
            FILE* lost=fopen("lost","w");
            fprintf(lost,"%d",lose);
            fclose(lost);
        }

        save(row,coloumn,time1,flag_no,question_no,no_of_moves,grid);
        win2=win(row,coloumn,grid,value);
        if(win2==1)
        {
            lose=1;
            FILE* lost=fopen("lost","w");
            fprintf(lost,"%d",lose);
            fclose(lost);
            print_win(row,coloumn,value);
            score=(pow(row,4)*pow(coloumn,4))/(time1*no_of_moves);
            printf("\ntime:%d  score:%d  number of moves:%d\n",time1,score,no_of_moves);
            printf("Enter your name:");
            scanf(" %[^\n]s",target.name);
            i=0;
            while(target.name[i]!='\0')
            {
                target.name[i]=(char)tolower(target.name[i]);
                i++;
            }
            target.score=score;
            query(target);
        }
    while(lose==0)
    {

        system("cls");
        print_grid(row,coloumn,grid);
        printf("\ntime:%d  flags used:%d  question marks used:%d  number of moves:%d",time1,flag_no,question_no,no_of_moves);
        printf("\nEnter n: ");
        scanf("%d",&c_read);
        printf("Enter y: ");
        scanf("%d",&r_read);
        no_of_moves++;
        r_read--;
        c_read--;
        lose=action_cell(r_read,c_read,row,coloumn,&flag_no,&question_no,grid,value);
        end=clock();
        time1=time+(end-start)/CLOCKS_PER_SEC;

        if(lose==1)
        {
            printf("\ntime:%d  number of moves:%d",time1,no_of_moves);
            FILE* lost=fopen("lost","w");
            fprintf(lost,"%d",lose);
            fclose(lost);
        }

        save(row,coloumn,time1,flag_no,question_no,no_of_moves,grid);
        win2=win(row,coloumn,grid,value);
        if(win2==1)
        {
            lose=1;
            FILE* lost=fopen("lost","w");
            fprintf(lost,"%d",lose);
            fclose(lost);
            print_win(row,coloumn,value);
            score=(pow(row,4)*pow(coloumn,4))/(time1*no_of_moves);
            printf("\ntime:%d  score:%d  number of moves:%d\n",time1,score,no_of_moves);
            printf("Enter your name:");
            scanf(" %[^\n]s",target.name);
            i=0;
            while(target.name[i]!='\0')
            {
                target.name[i]=(char)tolower(target.name[i]);
                i++;
            }
            target.score=score;
            query(target);
        }
    }
}
