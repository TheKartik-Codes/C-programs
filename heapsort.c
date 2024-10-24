// Practicing heap sort algorithm using C.

#include<stdio.h>

void swap( int *a , int *b )
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify( int num[], int n, int i )
{
    int largest=i;

    int left=2*i+1;
    int right=2*i+2;

    if ( left < n && num[left] > num[largest] )
    {
        largest=left;
    }
    
    if ( right < n && num[right]> num[largest] )
    {
        largest=right;
    }
    if ( i != largest )
    {
        swap(&num[i],&num[largest]);
        heapify(num,n,largest);
    }


}

void heapsort( int num[], int n )
{
    //A for loop for building a max heap
    for ( int i=(n/2)-1 ; i>=0 ; i-- )
    {
        heapify(num,n,i);
    }

    //A for loop to delete the root and heapifying theroot element.
    for ( int i=n-1; i>=0; i-- )
    {
        swap(&num[i],&num[0] );
        heapify(num,i,0);
    }
}

int main()
{
    int n;

    printf("\nEnter the size of the array:");
    scanf("%d",&n);

    if ( n>0 )
    {
        int num[n];

        printf("\nEnter the array elements:\n");
        for ( int i=0 ; i<n ; i++ )
        {
            scanf("%d",&num[i]);
        }

        printf("\nThe array elements:\n");
        for ( int i=0 ; i<n ; i++ )
        {
            printf("\t%d",num[i]);
        }

        heapsort(num,n);

        printf("\nThe array after heap sort:\n");
        for ( int i=0 ; i<n ; i++ )
        {
            printf("\t%d",num[i]);
        }
        printf("\n");
    }
    else{
        printf("\nEnter valid size of the array.\n");
    }

    return 0;
}