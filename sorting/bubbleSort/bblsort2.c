/*Simple Bubble sort code using swap variable and an arbitrary large array*/
/*hence we will use function to sort the data*/
/*also we will learn function recursion call*/
/*sorting done in ascending order*/

#include <stdio.h>
#include <time.h>
#define ARR_SIZE 100 //global constant; array size

/* Function delcaration */
void printArray(long input_arr[], int arr_start, int arr_len);
void bubbleSort(long data_list[], int data_list_len);

int main(void){

	clock_t t = clock(); // starting timestamp
	/*---------------------------------------------------------------*/

	long arr[ARR_SIZE]; 
	/*long also a integer data type but with high range; Google for more*/

	int NOE, j;
	/*NOE = Number Of Elements; temp = swapping variable*/

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
		scanf("%ld", &arr[j]);
	}

	printf("---------------------------------------\n");
	printf("*Unsorted List: \n");

	printArray(arr, 0, NOE); //called to print unsorted array;

	printf("\n---------------------------------------\n");

	/* here the sorting happens: Bubble sort function call*/
	bubbleSort(arr, NOE);

	printf("*Sorted List(Ascending order):\n");
	printArray(arr, 0, NOE); //called to print sorted array;

	printf("\n---------------------------------------\n");	

	printf("Execution Time: ");
	t = clock() - t; //end timestamp
	double exec_time = ((double)t)/CLOCKS_PER_SEC;
	printf("%f secs.\n", exec_time);	
	
	return 0;


}

/* Array printing function. Using recursion technique */
void printArray(long input_arr[], int arr_start, int arr_len){

	//recursion base condition
	if(arr_start >= arr_len){
		return;
	}
	
	//print current element
	printf("%ld\t ", input_arr[arr_start]);

	//recursively call the printArray function to print next elements
	printArray(input_arr, arr_start+1, arr_len);
}


/* Bubble sort function*/
void bubbleSort(long data_list[], int data_list_len){
	int i, j, swap;

	for(i=0; i<(data_list_len - 1); i++){

		for(j=0; j<(data_list_len - i - 1); j++){

			if(data_list[j] > data_list[j+1]){
				/*swapping happens here*/
				 swap = data_list[j];
				 data_list[j] = data_list[j+1];
				 data_list[j+1] = swap;
			}
		}
	}

}
