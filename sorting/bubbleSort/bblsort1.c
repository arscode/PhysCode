/*Simple Bubble sort code using swap variable and an arbitrary large array*/
/*sorting done in ascending order*/

#include <stdio.h>
#include <time.h>

int main(void){

	/* measuring execution time*/
	clock_t t = clock();	//starting timestamp
	/*----------------------------------------------------------*/

	int arr[100], NOE, j, k, temp; //NOE = Number Of Elements

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
	for(j=0; j<(NOE-1); j++){

		for(k=0; k<(NOE-j-1); k++){

			if(arr[k] > arr[k+1]){
				temp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = temp;
			}
		}
	}

	printf("-----------------------------------\n");
	printf("Sorted List(Ascending order): \n");

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