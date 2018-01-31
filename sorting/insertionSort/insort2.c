/* Simple Insertion sort program using function*/

#include <stdio.h>
#include <time.h>
#define ARR_SIZE 100 //global constant; array size

/* Function delcaration */
void printArray(int input_arr[], int arr_start, int arr_len);
void insertionSort(int data_Arr[], int arr_len);

/*-------------------------------------------------------------*/

int main(void){

	/* measuring execution time*/
	clock_t t = clock();	//starting timestamp
	/*----------------------------------------------------------*/

	int arr[ARR_SIZE], NOE, j;

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

	printf("---------------------------------------\n");
	printf("*Unsorted List: \n");


	printArray(arr, 0, NOE); //called to print unsorted array;
	printf("\n-----------------------------------\n");

	/* here the sorting happens: Insertion sort function call*/
	insertionSort(arr, NOE);

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
void printArray(int input_arr[], int arr_start, int arr_len){

	//recursion base condition
	if(arr_start >= arr_len){
		return;
	}
	
	//print current element
	printf("%d\t ", input_arr[arr_start]);

	//recursively call the printArray function to print next elements
	printArray(input_arr, arr_start+1, arr_len);
}


/* Insertion sort function definition */
void insertionSort(int data_arr[], int arr_len){
	int i, j, key;
	for(i=1; i < arr_len; i++){
		key = data_arr[i];
		j = i-1;

		/* 
		Shift the elements of arr[0,1,...., i-1], that are greater than the key,
		to the one position ahead of their current position
		*/

		while(j>0 && data_arr[j]>key){
			data_arr[j+1] = data_arr[j];
			j = j-1;
		}
		data_arr[j+1] = key;
	}
}