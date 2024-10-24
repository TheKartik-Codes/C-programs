//A program to sort the array using quick sort algorithm

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap( int *a, int *b )
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


int partition(int num[], int low, int high )
{
	int pivot=num[low];

	int i=low;
	int j=high;

	while ( i < j )
	{
		while ( i < high && num[i]<=pivot )
		{
			i++;
		}
		while ( j > low && num[j]>pivot )
		{
			j--;
		}
		if ( i < j )
		{
			swap(&num[i],&num[j]);
		}
	}

	swap(&num[low],&num[j]);
	return j;
}

void quicksort(int num[],int low, int high )
{
	if ( low < high )
	{
		int part=partition(num,low,high);

		quicksort(num,low, part-1 );
		quicksort(num,part+1,high);
	}
}

int main()
{
	int n;

	printf("\nEnter the size of the integer array: ");
	scanf("%d",&n);

	if ( n > 0 )
	{
		int num[n];

		srand(time(0));

		for ( int i=0 ; i<n ; i++ )
		{
			num[i]=rand()%100;
		}

		printf("\n\nThe array:\n");
		for ( int i=0 ; i<n ; i++ )
		{
			printf("\t%d",num[i]);
		}

		quicksort(num,0,n-1);

		printf("\n\nThe array after quick sort:\n");
		for ( int i=0 ; i<n ; i++ )
		{
			printf("\t%d",num[i]);
		}

		printf("\n");

	}
	else
	{
		printf("\nEnter valid size of the array.");
	}
	return 0;
}
