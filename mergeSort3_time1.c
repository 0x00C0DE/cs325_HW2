/*
 * Name:Braden Lee
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

void merge3(int Arr[], int sortedArr[], int left, int mid1, int mid2, int right) 		
{
    	//variables to help determine the three segments we are splitting
	int i = left;
   	int x = mid1;
   	int z = mid2;
   	int e = left;
 
	//picks the smallest value among the three segments 
	while((i < mid1) && (x < mid2) && (z < right))    
	{ 
        	if(Arr[i] < Arr[x])						
        	{
            		if(Arr[i] < Arr[z])
            		{
                		sortedArr[e++] = Arr[i++];		
            		}
            		else
            		{
                		sortedArr[e++] = Arr[z++];		
            		}
        	}
        	else
        	{
            		if(Arr[x] < Arr[z])
            		{
                		sortedArr[e++] = Arr[x++];			
            		}
            		else
            		{
                		sortedArr[e++] = Arr[z++];			
            		}
        	}
	}
	//picks the smallest value within the segments 1 and 2
	while ((i < mid1) && (x < mid2)) 
    	{ 
        	if(Arr[i] < Arr[x])
        	{
           		 sortedArr[e++] = Arr[i++];			
        	}
        	else
        	{
            		sortedArr[e++] = Arr[x++];			
        	}
    	} 
 	//picks the smallest value within the segment 2 and 3
     	while ((x < mid2) && (z < right)) 
    	{ 
        	if(Arr[x] < Arr[z])
        	{
            		sortedArr[e++] = Arr[x++];			
        	}
        	else
        	{
            		sortedArr[e++] = Arr[z++];			
        	} 
    	} 
	//picks the smallest value within the segment 1 and 3
	while ((i < mid1) && (z < right)) 
    	{ 
        	if(Arr[i] < Arr[z])
        	{
            		sortedArr[e++] = Arr[i++];			
        	}
        	else
        	{
            		sortedArr[e++] = Arr[z++];		
        	} 
    	} 

	/*
 		when out of elements, makes copies of any remaining elements from each segment to Arr.
 	*/
  	while (i < mid1)
	{ 
        	sortedArr[e++] = Arr[i++]; 		
  	}
	while (x < mid2)
	{ 
        	sortedArr[e++] = Arr[x++]; 
	}
	while (z < right)
	{ 
        	sortedArr[e++] = Arr[z++];
	}
}

 
 
//function solely for printing the array of elements to the screen from i to n
void printArr (int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
		printf("\n");
	}
}


void mergeSort3Recurs(int Arr[], int sortedArr[], int left, int right)
{	
	//base case cannot split less than 2							
	if(right-left < 2)
	{
		return;							
	}
	
	//splits into thirds (index)
	int mid1 = left+((right-left)/3);
	int mid2 = left+2*((right-left)/3)+1;
	
	//recursive calls to mergeSort3Recurs
	mergeSort3Recurs(sortedArr, Arr, left, mid1);
	mergeSort3Recurs(sortedArr, Arr, mid1, mid2);
	mergeSort3Recurs(sortedArr, Arr, mid2, right);

	//finally merges the three parts together
	merge3(sortedArr, Arr, left, mid1, mid2, right);
}

void mergeSort3(int Arr[], int n)  
{  
	if( n==0)
	{
		return;
	}
	//temp array to copy the data before using merge sort
	int tempArr[n];

	for (int i = 0; i < n; i++)  
        tempArr[i] = Arr[i]; 

	mergeSort3Recurs(tempArr, Arr, 0, n); 

   	for (int i = 0; i < n; i++)  
        Arr[i] = tempArr[i];  
}  

int main ()
{
	FILE *fileptr;
    	FILE *fp;
	int count_lines = 0;
    	int count = 1;
    	char c = 0;
    	char filechar[40], chr;
	char str1[100], str2[100], str3[100], str4[100];
	int x = 0;
	int z = 0;
	char * tokensOfInts;
	int integerArr1[1000000] = {};
	int integerArr2[] = {}, integerArr3[] = {}, integerArr4[] = {};
	float total, average;    	
	
	fileptr = fopen("merge3TimesAvg.txt", "w");

	//N size of the array, max 50k, incremented by 5k, starts at 0
	for(int i = 0; i <= 500000; i=i+50000)
	{
		fprintf(fileptr, "%d ", i);
		printf("%d ", i);
		total = 0;
		average = 0;

		//performs 9 trial runs for the Nth size of array
		for(int k = 1; k <= 9; k++)
		{

		
			srand(time(NULL));
			//assigns a random num 0-10k to each element up to the i'th index, starting from 0
			for(int x = 0; x < i; x++)
			{
				integerArr1[x] = rand () % 10000;
			}
		
			clock_t start, end;
			start = clock();
			
			//performs the actual merge operation
			mergeSort3(integerArr1, i);
			
			end = clock();
			
			//calculates the time taken to execute the merge operation and adds it to the total
			float time_takenSec = (float)(end - start) / (float)(CLOCKS_PER_SEC);
			total += time_takenSec;
			printf(", %f ", time_takenSec);
			fprintf(fileptr, " %f, ",time_takenSec);
		}
		//at the end of 9 trial runs, averages by dividing by the num of trials
		average = total/9;
		printf(" average %f \n", average);
		fprintf(fileptr, " %f \n", average);
	}
	fclose(fileptr);
	

	return 0;
}
