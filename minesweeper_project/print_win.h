print_win(int row,int coloumn,char value[row][coloumn])
{
    int i,k;
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            if(value[i][k]=='*')
            {
                printf("F ");
            }
            else{printf("%c ",value[i][k]);}
        }
        printf("\n");
    }
    printf("\nYOU WIN!!!!!");
}
