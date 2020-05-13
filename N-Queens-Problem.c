/**
 ** Author - Dipendu Ghosh
 ** Program - NQueens Problem
 **/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Place(int x[],int k,int i)
{
    int j;
    for(j=1;j<k;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
            return 0;
    }
    return 1;
}

 int* NQueens(int x[],int k,int n)
{
    int *y=NULL,i;
    for(i=1;i<=n;i++)
    {
        if(Place(x,k,i))
        {
            x[k]=i;
            if(k==n)
                return x;
            y=NQueens(x,k+1,n);
            if(y!=NULL)
                break;
        }
    }
    return y;
}

void print(int x[],int n)
{
    int i,j;
    printf("\n\n>>> Solution :\n\n");
    printf("\t");
    for(i=1;i<=n;++i)
        printf("\t%d",i);
    for(i=1;i<=n;++i)
    {
        printf("\n\n\t%d",i);
        for(j=1;j<=n;++j)
        {
            if(x[i]==j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
}


int main()
{
    int n;
    printf("\nEnter number of Queens : ");
    scanf("%d",&n);
	 int *x=calloc(n+1,sizeof(int));
	 int *y=NQueens(x,0,n);
    if(y==NULL)
        printf("\n\n>>> IMPOSSIBLE!");
    else
        print(x,n);

    printf("\n\n");
    return 0;
}
