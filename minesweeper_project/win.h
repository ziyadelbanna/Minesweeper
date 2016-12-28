
int win(int row,int coloumn,char grid[row][coloumn],char value[row][coloumn])
{
    int static win1=0;
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<coloumn;j++)
        {
            if(value[i][j]=='*')
            {
                if(grid[i][j]=='F'||grid[i][j]=='X'||grid[i][j]=='?')
                {
                    continue;
                }
                else
                {
                    return;
                }
            }
            else if(value[i][j]==grid[i][j])
            {
                continue;
            }
            else
                return;

        }
    }
    return 1;

}
