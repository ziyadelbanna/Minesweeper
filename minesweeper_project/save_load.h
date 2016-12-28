void save(int row,int coloumn,int time,int flag_no,int question_no,int no_of_moves,char grid[row][coloumn])
{
    FILE* write2=fopen("rc","w");
    fprintf(write2,"%d\n",row);
    fprintf(write2,"%d\n",coloumn);
    fprintf(write2,"%d\n",time);
    fprintf(write2,"%d\n",flag_no);
    fprintf(write2,"%d\n",question_no);
    fprintf(write2,"%d\n",no_of_moves);
    fclose(write2);
    FILE* write1=fopen("save","w");
    int i,k;
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            fprintf(write1,"%c ",grid[i][k]);
        }
        fprintf(write1,"\n");
    }
    fclose(write1);
}
void load_arr(int row,int coloumn,char grid[row][coloumn],char value[row][coloumn])
{
    FILE* read=fopen("save","r");
    int i,k;
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            fscanf(read," %c",&grid[i][k]);
        }
    }
    fclose(read);
    FILE* read1=fopen("value","r");
    for(i=0;i<row;i++)
    {
        for(k=0;k<coloumn;k++)
        {
            fscanf(read1," %c",&value[i][k]);
        }
    }
    fclose(read1);

}
load_r_c(int *row,int *coloumn,int *time,int *flag_no,int *question_no,int *no_of_moves)
{
    FILE* read=fopen("rc","r");
    fscanf(read,"%d",&*row);
    fscanf(read,"%d",&*coloumn);
    fscanf(read,"%d",&*time);
    fscanf(read,"%d",&*flag_no);
    fscanf(read,"%d",&*question_no);
    fscanf(read,"%d",&*no_of_moves);
    fclose(read);
}
