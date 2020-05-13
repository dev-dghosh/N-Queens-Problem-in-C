/**
 ** Author - Dipendu Ghosh
 ** Program - NQueens Problem
 **/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// add other header files as per your requirement


/** Function 1 : Write a function here that will take the solution vector, the row number and
 ** and the column number as input and check if the next queen can be placed at that row number
 ** and column number. If the queen can be placed at that row and column, then it will return
 ** true, otherwise it will return false. This function assusmes that queens at all the previous
 ** rows have been placed in a valid position
 **/
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


/** Function 2 : Write a function here that will take the solution vector, row number where the
 ** next queen will be placed and the size of the board as input and implement the backtracking
 ** algorithm for solving the n-queens problem. This method will return NULL if a valid assignment
 ** of queen is not possible. From the method, you have to call the bounding function with proper
 ** parameters which you have to implement in <<Function 1>>.
 **/
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


/** Function 3 : Write a function here that will take the solution vector populated with valid queen
 ** positions and the size of the board as input, and print the board configuration for the solution.
 ** It will print a '-' in every cell of the board where the cell is empty. And, it will print a 'X'
 ** or 'Q' in the cells where a queen is placed. For example, for solution vector (1, 2, 3, 4) this
 ** function should print the below configuration -
 **									X---	|	Q---
 **									-X--	|	-Q--
 **									--X-	|	--Q-
 **									---X	|	---Q
 **/
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
    /** Get the input from the user. Take a single integer, n, as input, which will denote the
	 ** size of the n x n chess board.
	 **/
    printf("\nEnter number of Queens : ");
    scanf("%d",&n);

	/** Dynamically create an array X of length n, which represents the solution vector of our
	 ** problem.
	 **/
	 int *x=calloc(n+1,sizeof(int));

	/** Pass the solution vector X, first row number and the size of the board n to <<Function 2>>
	 ** which implements the backtracking algorithm for solving n-queens problem. This function will
	 ** return either a valid solution vector if a solution exists, otherwise it will return NULL.
	 **/
	 int *y=NQueens(x,0,n);

	/** If <<Function 2>> returns NULL, then print a message "IMPOSSIBLE!". Otherwise, pass the solution
	 ** vector and the size of the board to <<Function 3>> which will print the board configuration using
	 ** the solution vector.
	 **/
    if(y==NULL)
        printf("\n\n>>> IMPOSSIBLE!");
    else
        print(x,n);

    printf("\n\n");
    return 0;
}
