/* 
Bubble sort code without using swap varibale.
Here arithmatic mothods(addition & subtraction) are used.
*/

#include <stdio.h>
#include <time.h>
#define ARR_SIZE 100 //global constant; array size

int main(void){

	/* measuring execution time*/
	clock_t t = clock();	//starting timestamp
	/*----------------------------------------------------------*/

	int arr[ARR_SIZE], NOE, j, k;
	
	printf("Enter number of input elements(integer only): ");
	scanf("%d", &NOE);
	/* hence it is assumed that user will input integers only, so there is no
	   data type checking. It is always welcome to use non supportive data type
	   for experiment, maybe some intersting error patterns waiting for you..!!
	   Error cheking will be added in modified versions, maybe(or will be 
	   given as homework)..!!
	*/		

	printf("Enter %d integers:\n", NOE);

	//taking user inputs into the array using FOR LOOP
	for(j=0; j<NOE; j++){
		scanf("%d", &arr[j]);
	}

	printf("\n-----------------------------------\n");	
	printf("Unsorted List: \n");

	//using loop to print unsorted data
	for(j=0; j<NOE; j++){
		printf("%d\t", arr[j]);
	}
	printf("\n");

	//bubble sort technique implementation using array elements as data set
	for(j=0; j<NOE; j++){

		for(k=j+1; k<NOE; k++){

			if(arr[k] > arr[j]){
			/* addition-subtraction method for swapping without swap variable*/
				arr[j] = arr[j] + arr[k];
				arr[k] = arr[j] - arr[k];
				arr[j] = arr[j] - arr[k];
			}
		}
	}

	/* 
	
	*CAUTION: 
	Arithmatic method may cause arithmatic overflow if the any two 
	array element is quite large so that their additiongoes out of the integer
	range. Same thing could be possible if we use multiplication-division method
	tp solve this.
	*****************************************************************************
	
	*TRY:
	Implement any check or preventive measure to save it from arithmatic overflow.

	*/

	printf("-----------------------------------\n");
	printf("Sorted List(Descending order): \n");

	//Loop using to print sorted list
	for(j=0; j<NOE; j++){
		printf("%d\t", arr[j]);
	}

	printf("\n-----------------------------------\n");

	printf("Execution Time: ");
	t = clock() - t; //end timestamp
	double exec_time = ((double)t)/CLOCKS_PER_SEC;
	printf("%f secs.\n", exec_time);

	return 0;
}