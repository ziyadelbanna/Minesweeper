void dfs(int row,int coloumn,char grid[row][coloumn],char value[row][coloumn],int x,int y)
{
    if(value[x+1][y]=='0'&&y>=0&&y<coloumn&&x>=0&&x<row)
    {
        value[x][y]='v';
        x=x+1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x-1][y]=='0'&&y>=0&&y<coloumn&&x>=0&&x<row)
    {
        value[x][y]='v';
        x=x-1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x][y+1]=='0'&&y+1>=0&&y+1<coloumn&&x>=0&&x<row)
    {
        value[x][y]='v';
        y=y+1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x][y-1]=='0'&&y-1>=0&&y-1<coloumn&&x>=0&&x<row)
    {
        value[x][y]='v';
        y=y-1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x-1][y-1]=='0'&&y-1>=0&&y-1<coloumn&&x>=0&&x<row)
    {
        value[x][y]='v';
        x=x-1;
        y=y-1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x-1][y+1]=='0'&&y+1>=0&&y+1<coloumn&&x>=0&&x<row)
    {
        value[x][y]='v';
        x=x-1;
        y=y+1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x+1][y-1]=='0'&&y-1>=0&&y-1<coloumn&&x>=0&&x<row)
    {
        value[x][y]='v';
        x=x+1;
        y=y-1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x+1][y+1]=='0'&&y+1>=0&&y+1<coloumn&&x>=0&&x<row)
    {
        value[x][y]='v';
        x=x+1;
        y=y+1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else
    {
        value[x][y]='f';
    }




   if(value[x+1][y]=='v'&&y>=0&&y<coloumn&&x>=0&&x<row)
    {
        x=x+1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x-1][y]=='v'&&y>=0&&y<coloumn&&x>=0&&x<row)
    {
        x=x-1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x][y+1]=='v'&&y+1>=0&&y+1<coloumn&&x>=0&&x<row)
    {
        y=y+1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x][y-1]=='v'&&y-1>=0&&y-1<coloumn&&x>=0&&x<row)
    {
        y=y-1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x-1][y-1]=='v'&&y-1>=0&&y-1<coloumn&&x>=0&&x<row)
    {
        x=x-1;
        y=y-1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x-1][y+1]=='v'&&y+1>=0&&y+1<coloumn&&x>=0&&x<row)
    {
        x=x-1;
        y=y+1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x+1][y-1]=='v'&&y-1>=0&&y-1<coloumn&&x>=0&&x<row)
    {
        x=x+1;
        y=y-1;
        dfs(row,coloumn,grid,value,x,y);
    }
    else if(value[x+1][y+1]=='v'&&y+1>=0&&y+1<coloumn&&x>=0&&x<row)
    {
        x=x+1;
        y=y+1;
        dfs(row,coloumn,grid,value,x,y);
    }
}



