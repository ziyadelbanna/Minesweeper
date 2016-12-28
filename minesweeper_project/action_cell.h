int action_cell(int x,int y,int row,int coloumn,int *flag_no1,int *question_no1,char grid[row][coloumn],char value[row][coloumn])
{
    int static lose1=0;
    char action[2];
    int i,k;
    printf("Please select a valid action: ");
    scanf(" %s",&action);
    if(action[0]=='O'||action[0]=='o'&&action[1]=='\0')
    {
       if(value[x][y]=='*')
       {
           for(i=0;i<row;i++)
           {
               for(k=0;k<coloumn;k++)
               {
                   if(grid[i][k]=='X'&&value[i][k]=='*')
                   grid[i][k]='M';
                   else if(value[i][k]=='*'&&grid[i][k]=='F'||grid[i][k]=='?')
                    grid[i][k]='*';
                   else if(value[i][k]!='*'&&grid[i][k]=='F'||grid[i][k]=='?')
                    grid[i][k]='-';
                   else if(grid[i][k]=='X')
                   grid[i][k]=value[i][k];
               }
           }
           grid[x][y]='!';
           lose1=1;
           print_grid(row,coloumn,grid);
           printf("YOU LOST !!!!!!");
       }
       else if(grid[x][y]==value[x][y])
       {
           int fcount='0';
           for(i=x-1;i<=x+1;i++)
           {
               for(k=y-1;k<=y+1;k++)
               {
                   if(k<0||k>=coloumn||i<0||i>=row||grid[i][k]!='F')
                   continue;
                   else
                    fcount++;
               }
           }
           if(fcount==grid[x][y])
           {
               for(i=x-1;i<=x+1;i++)
               {
                  for(k=y-1;k<=y+1;k++)
                  {
                     if(k<0||k>=coloumn||i<0||i>=row||grid[i][k]=='F')
                       continue;
                     else
                     {
                         if(value[i][k]=='*')
                         {
                             grid[i][k]='!';
                             lose1=1;
                         }
                         else
                         {
                             if(value[i][k]=='0')
                             {
                                 dfs(row,coloumn,grid,value,i,k);
                                 zero_fin(row,coloumn,grid,value);
                             }
                             else
                                grid[i][k]=value[i][k];
                         }
                     }

                  }
               }
           }
           if(lose1==1)
           {
               for(i=0;i<row;i++)
           {
               for(k=0;k<coloumn;k++)
               {
                   if(grid[i][k]=='X'&&value[i][k]=='*')
                   grid[i][k]='M';
                   else if(grid[i][k]=='F'||grid[i][k]=='?'&&value[i][k]=='*')
                    grid[i][k]='*';
                   else if(grid[i][k]=='F'||grid[i][k]=='?'&&value[i][k]!='*')
                    grid[i][k]='-';
                   else if(grid[i][k]=='X')
                   grid[i][k]=value[i][k];
               }
           }
           print_grid(row,coloumn,grid);
           printf("YOU LOST !!!!!!");
           }


       }
       else if(value[x][y]=='0')
       {
           dfs(row,coloumn,grid,value,x,y);
           zero_fin(row,coloumn,grid,value);
       }
       else if(grid[x][y]=='F'||grid[x][y]=='?')
       {
           printf("You entered a wrong action!\n");
           action_cell( x,y,row,coloumn,flag_no1,question_no1,grid,value);
       }

       else
       {

           grid[x][y]=value[x][y];
       }
    }
    else if(action[0]=='F'||action[0]=='f'&&action[1]=='\0')
    {
        if(grid[x][y]=='X')
        {
            grid[x][y]='F';
            *flag_no1=*flag_no1+1;
        }

        else
        {
            printf("Cant perform the action,the chosen cell is open!\n");
            action_cell( x,y,row,coloumn,flag_no1,question_no1,grid,value);
        }
    }
    else if(action[0]=='-'&& action[1]=='\0')
    {
        if(grid[x][y]== 'F')
        {
            grid[x][y]='X';
            *flag_no1=*flag_no1-1;
        }
        else if(grid[x][y]=='?')
        {
            grid[x][y]='X';
            *question_no1=*question_no1-1;
        }
        else
            {
                printf("You entered a wrong action!\n");
                action_cell( x,y,row,coloumn,flag_no1,question_no1,grid,value);
            }

    }
    else if (action[0]=='?'&& action[1]=='\0')
    {
        if(grid[x][y]=='X')
        {
            grid[x][y]='?';
            *question_no1=*question_no1+1;
        }

        else
        {
            printf("You entered a wrong action!\n");
            action_cell( x,y,row,coloumn,flag_no1,question_no1,grid,value);
        }

    }
    else
        {
            printf("You've entered a wrong action!\n");
            action_cell( x,y,row,coloumn,flag_no1,question_no1,grid,value);
        }
    return lose1;

}
