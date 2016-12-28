
void print_grid(int row,int coloumn,char b[row][coloumn])
{
    int i,k;
    for(i=0;i<=coloumn;i++)
    {if (i==0){printf("%c%c",'n','>');continue;}

        if(i<10)
        printf("%d     ",i);
        else  printf("%d    ",i);}
    printf("\n\n");
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            printf("  %c   ",b[i][k]);
        }
        printf(" %d\n\n\n",i+1);
    }
}
