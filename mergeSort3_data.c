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

//
//


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

void mergeSort3Way(int Arr[], int n)  
{  
	if (n == 0)  
        	return; 
	int tempArr[n];

	for (int i = 0; i < n; i++)  
        {
		tempArr[i] = Arr[i]; 
	}
	mergeSort3Recurs(tempArr, Arr, 0, n); 

   	for (int i = 0; i < n; i++)  
        {
		Arr[i] = tempArr[i];  
	}
}  

int main ()
{
	FILE *fileptr;
    	FILE *fp;
    	int count = 1;
    	char c = 0;
    	char filechar[40], chr;
	char str1[100], str2[100], str3[100], str4[100];
	int integerArr1[] = {}, integerArr2[] = {}, integerArr3[] = {}, integerArr4[] = {}, integerArr5[] = {};
    	fileptr = fopen("data.txt", "r");
	fp = fopen("merge3.txt", "w");
	
		for (c = getc(fileptr); c != EOF; c = getc(fileptr))
	{
		if (c == '\n')
		{
			count++;
		}
	}

	rewind(fileptr);
	int numOfIntsInStr = 0;
	int x = 0;
	int z = 0;
	char * tokensOfInts;

	for(int i = 0; i < count; i++)
	{	
		if(strcmp(str1, "") == 0)
		{
			fgets(str1, 100, fileptr);
			tokensOfInts = strtok(str1, " ");
			
			integerArr1[x] = atoi(tokensOfInts);
			x++;

			while(tokensOfInts != NULL)
			{	
					integerArr1[x] = atoi(tokensOfInts);
				x++;			
				
				numOfIntsInStr++;
				tokensOfInts = strtok(NULL, " ");
			}
			numOfIntsInStr -= 1;
			
			for(int i = 0; i <= numOfIntsInStr; i++)
			{
				integerArr2[i-1] = integerArr1[i+1];
			}
			int sizeOfIntArr = sizeof(integerArr2)/sizeof(integerArr2[0]);
			int intElements = numOfIntsInStr;
			int intArr = sizeof(integerArr1[0]);
			for(int m = 0; m < numOfIntsInStr; m++)
			{
				integerArr5[m] = integerArr2[m];
			}
		
			printf("before mergeSort3\n");
			printArr(integerArr5, numOfIntsInStr);
			printf("..");
			
			mergeSort3Way(integerArr2, numOfIntsInStr);
				
			//mergeSort3Recurs(integerArr5, integerArr2, 0, numOfIntsInStr);
			
			/*	
			for(int h = 0; h < numOfIntsInStr; h++)
			{
				integerArr2[h] = integerArr5[h];
			}
			*/

				for(int i = 0; i < numOfIntsInStr; i++)
			{
				fprintf(fp, "%d ", integerArr2[i]);
			}
			fprintf(fp, "\n");

			printArr(integerArr2, numOfIntsInStr);	

			int sizeOfStr = sizeof(str1)/sizeof(str1[0]);
			for(int i = 0; i < sizeOfStr; i++)
			{
				str1[i] = '\0';
			}
			numOfIntsInStr = 0;
			x = 0;
			z = 0;
					
		}
	}

	return 0;
}
