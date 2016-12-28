void zero_fin(int row,int coloumn,char grid[row][coloumn],char value[row][coloumn])
{
    int i,k,j,l;
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            if(value[i][k]=='f')
            {
                value[i][k]='0';
                grid[i][k]='0';
                for(j=i-1;j<=i+1;j++)
                {
                    for(l=k-1;l<=k+1;l++)
                    {
                        if(grid[j][l]=='F'||grid[j][l]=='?'||value[j][l]=='f'||j<0||j>=row||l<0||l>=coloumn)
                            continue;

                        else
                            grid[j][l]=value[j][l];
                    }
                }
            }
        }
    }
}
