struct leaderboards
{
    int score;
    char name[30];

};
int load(struct leaderboards *ld)
{
    int counter=0;
    FILE *fp= fopen( "lead.txt", "r" );
    char a;
    fscanf(fp,"%c",&a);
    fclose(fp);
    fp= fopen( "lead.txt", "r" );
    if ( (int)a<97||(int)a>122)
    {
        counter=0;
        return counter;
    }
    else
    {
        /*fp = fopen( "lead.txt", "r" );*/
        while (!feof(fp))
        {
            fscanf(fp,"%[^,]s",&ld[counter].name);
            fscanf(fp,",");
            fscanf(fp,"%d",&ld[counter].score);
            fscanf(fp,"\n");
            counter++;
        }
        fclose(fp);
        return counter;
    }

}
void print()
{
    struct leaderboards ld[100];
    int n,i,k;
    n=load(&ld);
    if(n==0)
    {
        printf("No data found");
    }
    else
    {
        for(i=0; i<n; i++)
        {
            printf("%d-%s  %d\n",i+1,ld[i].name,ld[i].score);
        }
    }

}
void save_lead(struct leaderboards *ld,int n)
{
    FILE* fp=fopen("lead.txt","w");
    int i,k;
    for(i=0; i<n; i++)
    {
        k=0;
        while(ld[i].name[k]!='\0')
        {
            fprintf(fp,"%c",ld[i].name[k]);
            k++;
        }
        fprintf(fp,"%c%d\n",',',ld[i].score);
    }
    fclose(fp);
}
void query(struct leaderboards target)
{
    struct leaderboards ld[100];
    struct leaderboards temp;
    int n,found1,i,j,k,change;
    n=load(&ld);
    if(n==0)
    {
        j=0;
        while(target.name[j]!='\0')
        {
            ld[n].name[j]=target.name[j];
            j++;
        }
        ld[n].name[j]='\0';
        ld[n].score=target.score;
        n+=1;
        save_lead(&ld,n);
    }
    else
    {
        for(i=0; i<n; i++)
    {
        k=0;
        while(target.name[k]!='\0')
        {
            if(target.name[k]==ld[i].name[k])
            {
                found1=1;
                k++;
            }

            else
            {
                found1=0;
                break;
            }

        }
        if(found1==1)
        {
            if(target.score>ld[i].score)
            {
                ld[i].score=target.score;
                while(change)
                {
                    change=0;
                    for(k=0; k<n-1; k++)
                    {
                        if(ld[k].score<ld[k+1].score)
                        {
                            temp=ld[k];
                            ld[k]=ld[k+1];
                            ld[k+1]=temp;
                            change=1;
                        }
                    }
                }

            }
            save_lead(&ld,n);
            break;
        }

    }
    if(found1==0)
    {
        j=0;
        while(target.name[j]!='\0')
        {
            ld[n].name[j]=target.name[j];
            j++;
        }
        ld[n].name[j]='\0';
        ld[n].score=target.score;
        while(change)
                {
                    change=0;
                    for(k=0; k<n; k++)
                    {
                        if(ld[k].score<ld[k+1].score)
                        {
                            temp=ld[k];
                            ld[k]=ld[k+1];
                            ld[k+1]=temp;
                            change=1;
                        }
                    }
                }
        save_lead(&ld,n+1);
    }
    }



}
