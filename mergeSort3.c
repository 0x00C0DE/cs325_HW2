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
    	int count = 1;
    	char c = 0;
    	char filechar[40], chr;
	char str1[100], str2[100], str3[100], str4[100];
	int integerArr1[] = {}, integerArr2[] = {}, integerArr3[] = {}, integerArr4[] = {}, integerArr5[] = {};
    	fileptr = fopen("data.txt", "r");
	fp = fopen("merge3.txt", "w");
	
	//reads in the number of lines in a text file and stores it as count
	for (c = getc(fileptr); c != EOF; c = getc(fileptr))
	{
		if (c == '\n')
		{
			count++;
		}
	}

	//rewinds the textfile to be read again from the start

	rewind(fileptr);
	int numOfIntsInStr = 0;
	int x = 0;
	int z = 0;
	char * tokensOfInts;
	//loops through the number of lines that were counted
	for(int i = 0; i < count; i++)
	{	
		//if the str array is empty, the current line gets copied to the str array
		//then the str array is parsed to get the digits seperately and stored into
		//a int array to be then sorted.
		if(strcmp(str1, "") == 0)
		{
			//copies the current line from the textfile into the str array
			fgets(str1, 100, fileptr);

			//parses the str array
			tokensOfInts = strtok(str1, " ");
			
			//copies and converts the parsed token into a useable integer, into integerArr1
			integerArr1[x] = atoi(tokensOfInts);
			x++;

			while(tokensOfInts != NULL)
			{	
				//copies onverts the parsed token into a useable integer, into integerArr1
				integerArr1[x] = atoi(tokensOfInts);
				x++;			
				
				numOfIntsInStr++;
				tokensOfInts = strtok(NULL, " ");
			}
			numOfIntsInStr -= 1;
			
			//shifts the elements in the array down a position
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
			
			//merge Sort3 method
			mergeSort3(integerArr2, numOfIntsInStr);
			
			//writes to insert.txt	
			for(int i = 0; i < numOfIntsInStr; i++)
			{
				fprintf(fp, "%d ", integerArr2[i]);
			}
			fprintf(fp, "\n");

			//simple funct to see if merge sorted correctly
			//printArr(integerArr2, numOfIntsInStr);	

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
