//Practicing merge sort algorithm in C

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void merge( int num[], int low ,int mid, int high )
{
    int n=high-low+1;

    int temp[n];

    for ( int i=0 ; i<n ; i++ )
    {
        temp[i]=num[low+i];
    }

    int i=0;
    int j=mid-low+1;
    int k=low;

    while ( i <=mid-low && j<n )
    {
          if ( temp[i]<=temp[j] )
          {
              num[k]=temp[i];
              i++;
              k++;
          }
          else
          {
            num[k]=temp[j];
            j++;
            k++;
          }
    }

    while ( i<=mid-low )
    {
        num[k]=temp[i];
        i++;
        k++;
    }
    while ( j<n )
    {
        num[k]=temp[j];
        j++;
        k++;
    }
}


void mergesort(int num[], int low , int high )
{
    if ( low < high )
    {
        int mid=(low+high)/2;

        mergesort(num,low,mid);
        mergesort(num,mid+1,high);
        merge(num,low,mid,high);
    }
}

int main()
{
    int n;

    printf("\nEnter the size of the array: ");
    scanf("%d",&n);

    if ( n > 0 )
    {
        int num[n];

        srand(time(0));

        for ( int i=0 ; i<n ; i++ )
        {
            num[i]=rand()%100;
        }

        printf("\nThe array :\n");
        for ( int i=0 ; i<n ; i++ )
        {
            printf("\t%d",num[i]);
        }

        mergesort(num,0,n-1);

        printf("\nThe array after mergesort: \n");
        for ( int i=0 ; i<n ; i++ )
        {
            printf("\t%d",num[i]);
        }
    }
    else
    {
        printf("\nEnter valid size of the array.");
    }
    return 0;
}
