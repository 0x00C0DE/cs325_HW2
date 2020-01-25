/*
 * Name:Braden Lee
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

void merge3(int Arr[], int sortedArr[], int left, int mid1, 
           int mid2, int right) 		
{ 
   int i = left;
   int j = mid1;
   int k = mid2;
   int l = left; 
  
    //while ((k < right) && (i < mid1) && (j < mid2)) 
	while((i < mid1) && (j < mid2) && (k < right))    
	{ 
        	if(Arr[i] < Arr[j])						
        	{
            		if(Arr[i] < Arr[k])
            		{
                		sortedArr[l++] = Arr[i++];		
            		}
            		else
            		{
                		sortedArr[l++] = Arr[k++];		
            		}
        	}
        	else
        	{
            		if(Arr[j] < Arr[k])
            		{
                		sortedArr[l++] = Arr[j++];			
            		}
            		else
            		{
                		sortedArr[l++] = Arr[k++];			
            		}
        	}
	}

	while ((i < mid1) && (j < mid2)) 
    	{ 
        	if(Arr[i] < Arr[j])
        	{
           		 sortedArr[l++] = Arr[i++];			
        	}
        	else
        	{
            	sortedArr[l++] = Arr[j++];			
        	}
    	} 
 
     	while ((j < mid2) && (k < right)) 
    	{ 
        	if(Arr[j] < Arr[k])
        	{
            	sortedArr[l++] = Arr[j++];			
        	}
        	else
        	{
            		sortedArr[l++] = Arr[k++];			
        	} 
    	} 
	
	while ((i < mid1) && (k < right)) 
    	{ 
        	if(Arr[i] < Arr[k])
        	{
            		sortedArr[l++] = Arr[i++];			
        	}
        	else
        	{
            		sortedArr[l++] = Arr[k++];		
        	} 
    	} 
  	while (i < mid1)
	{ 
        	sortedArr[l++] = Arr[i++]; 		
  	}
	while (j < mid2)
	{ 
        	sortedArr[l++] = Arr[j++]; 
	}
	while (k < right)
	{ 
        	sortedArr[l++] = Arr[k++];
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
	if(right-left < 2)
	{
		return;							
	}
	
	int mid1 = left+((right-left)/3);
	int mid2 = left+2*((right-left)/3)+1;
	
	mergeSort3Recurs(sortedArr, Arr, left, mid1);
	mergeSort3Recurs(sortedArr, Arr, mid1, mid2);
	mergeSort3Recurs(sortedArr, Arr, mid2, right);

	merge3(sortedArr, Arr, left, mid1, mid2, right);
}

void mergeSort3(int Arr[], int n)  
{  
	if (n == 0)  
        	return; 
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
	
	fileptr = fopen("merge31TimesAvg.txt", "w");

	for(int i = 0; i <= 50000; i=i+5000)
	{
		fprintf(fileptr, "%d ", i);
		printf("%d ", i);
		total = 0;
		average = 0;

			for(int k = 1; k <= 9; k++)
		{

		
			srand(time(NULL));

				for(int x = 0; x < i; x++)
			{
				integerArr1[x] = rand () % 10000;
			}
		
			clock_t start, end;
			start = clock();
			

			mergeSort3Way(integerArr1, i);
			
			end = clock();
			

				float time_takenSec = (float)(end - start) / (float)(CLOCKS_PER_SEC);
			total += time_takenSec;
			printf(", %f ", time_takenSec);
			fprintf(fileptr, " %f, ",time_takenSec);
		}

		average = total/9;
		printf(" average %f \n", average);
		fprintf(fileptr, " %f \n", average);
	}
	fclose(fileptr);
	

	return 0;
}
