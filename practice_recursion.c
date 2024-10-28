#include <stdio.h>

int count(int x[],int n)
{
    if (n==0)
       return 1;
    
    return 1+count(x,n-1);
}

int sum( int x[],int n )
{
    if (n==0)
        return x[n] ;
    
    return x[n] + sum(x,n-1);
}

int max( int x[], int n )
{
    if (n==0)
        return x[0];
    
    int pick=max(x,n-1);
    
    return x[n-1] > pick  ? x[n-1] : pick;
}

int main()
{
    int x[]={1,2,3,4,5};
    int add=sum(x,4);
 
    int total=count(x,4);
    
    int maximum=max(x,5);
    
    printf("\nSum : %d.",add);
    
    printf("\ncount : %d.",total);
    
    printf("\nMax : %d.",maximum);
    return 0;
}