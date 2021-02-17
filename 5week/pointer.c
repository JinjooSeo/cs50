#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[6][5]);

int main(void){
		int arr[6][5] = {{1, 2, 3, 4, 5}, 
						 {6, 7, 8, 9, 10}, 
						 {11, 12, 13, 14, 15}, 
						 {16, 17, 18, 19, 20}, 
						 {21, 22, 23, 24, 25}, 
						 {26, 27, 28, 29, 30}};

		printArray(arr);
		
		//return 1;
}

void printArray(int arr[6][5]){
		
		int *ptr= (int *)arr; 
		//ptr = (int**) malloc(sizeof(int*)*6);
		//for(int i=0; i<6; i++) ptr[i] = (int*) malloc(sizeof(int)*5);
		
		for(int i=5; i!=-1; i--){
				for(int j=0; j<5; j++){
						printf("%i ",*(ptr+i*5 +j));
				}
				printf("\n");
		}
		
	//	for (int i=0; i<6; i++) free(ptr[i]);
	//	free(ptr);
		
		return;
}
