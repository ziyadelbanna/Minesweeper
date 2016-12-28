void generate_values(int row,int coloumn,char a[row][coloumn],int x,int y)
{
    int mines_no,r_mine,c_mine,i,k,flag=0,j,l;
    srand(time(NULL));
    mines_no=1+(row*coloumn)/10;
    for(i=0;i<mines_no;i++)
    {
       c_mine=rand() % coloumn;
       r_mine=rand() % row;
       while(flag==0)
       {
           if(a[r_mine][c_mine]=='*')
           {
              c_mine=rand() % coloumn;
              r_mine=rand() % row;
           }
           else if(r_mine==x&&c_mine==y)
           {
              c_mine=rand() % coloumn;
              r_mine=rand() % row;
           }
           else
            break;
       }
       a[r_mine][c_mine]='*';
    }
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            if(a[i][k]=='*')
            {
                for(j=i-1;j<=i+1;j++)
                {
                    for(l=k-1;l<=k+1;l++)
                    {
                        if(l<0||l>=coloumn||j<0||j>=row||a[j][l]=='*')
                            continue;
                        else
                            a[j][l]++;
                    }
                }
            }
        }
    }
    printf("\n");


}
