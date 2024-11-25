#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a,int *b )
{
	int temp=*a;
	*a=*b;
	*b=temp;
}



int partition(int num[],int low, int high )
{

	int pivot=num[low];

	int i=low;
	int j=high;

	while ( i < j )
	{
		while ( num[i]  <= pivot )
		{
			i++;
		}
		while ( num[j] > pivot )
		{
			j--;
		}
		if ( i < j )
		{
			swap( &num[i],&num[j] ); 
		}
	}
	swap(&num[low],&num[j]);
	return j;

}


void quicksort(int num[],int low, int high )
{
	if ( low<high )
	{
		int part=partition(num,low,high);

		quicksort(num,low,part-1);
		quicksort(num,part+1,high);
	}
}

int main()
{

	int num[5];
	srand(time(0));

        for ( int i=0 ; i<5 ; i++ )
        {
                num[i]=rand()%100;
        }
         
	printf("\nThe array:\n");
	for ( int i=0 ; i < 5 ; i++ )
	{
                 printf("\t%d",num[i]);
	}

	quicksort(num,0,4);

	printf("\nSorted array:\n");
        for ( int i=0 ; i<5 ; i++ )
	{
		printf("\t%d",num[i]);
	}
        printf("\n");
	return 0;
}
