#include <stdio.h>

static void sort(int *a, int n)
{
	int temp = 0, i = 0, j= 0;

	for ( i = 0; i < n - 1 ; i++ )
	{
		for ( j = i + 1; j < n;  j++ )
		{
			if ( *(a+i) > *(a+j) )
			{
				temp = *(a+i);
				*(a+i) = *(a+j);
				*(a+j) = temp;				
			}
		} 
	}
}

static void binarySearch(int *a, int n, int sel)
{
	int top = 0, bot = n-1, mid = (top+bot) / 2;
	int sc = 0;
	int i = 0;

	for ( ; ; )
	{
		mid = (top+bot) / 2;

		if ( a[mid] == sel )
		{
			sc++;
			//printf("%d", sc);
			for ( i = mid + 1 ; a[i] == sel && i <= bot ; sc++, i++ );
			//printf("%d", sc);
			for ( i = mid - 1 ; a[i] == sel && i >= top ; sc++, i-- );
			//printf("%d", sc);

			break;
		}

		if ( top == mid )
		{
			if ( a[bot] == sel )
				sc++;
			break;
		}

		if ( a[mid] > sel )
		{
			bot = mid;	
		}
		else
		{
			top = mid;
		}
	}

	printf("Search element [%d] is found [%d] times.\n", sel, sc);
}

int main()
{
	int a[] = { 50, 40, 30, 20, 100, 100, 100, 100, 120 };
	int n = sizeof(a) / sizeof(int);

	printf("Size of array - %d\n", n);

	printf("Sorting the array...\n");
	sort(a, n);
	int i = 0;

	for ( i = 0; i < n ; i++ )
	{
		printf("%d\t", a[i]);
	}

	printf("\n");
	binarySearch(a, n, 100);
}
