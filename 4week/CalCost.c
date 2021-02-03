#include <stdio.h>
#include <stdlib.h>

#ifndef min
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif

int static compare (const void* first, const void* second);
int minimumCost(int price[], int n);

int main(){
  int n;
  printf("Enter the size of array : ");
  scanf("%d", &n);
  int price[n];
  for(int i=0; i<n; i++){
    printf("Enter the component : ");
    scanf("%d", &price[i]);
  }

  printf("Total cost is %i to cross the bridge.\n",minimumCost(price, n));

  return 0;
}

//Compare function
int static compare (const void* first, const void* second){
    if (*(int*)first > *(int*)second) return 1;
    else if (*(int*)first < *(int*)second) return -1;
    else return 0;
}

//Calculate the minimum cost
int minimumCost(int price[], int n){
    // Sort the price array
    qsort(price, n, sizeof(int),compare);
    int totalCost = 0;

    printf("Procedure\n");

    for(int i=n-1; i>1; i-=2){
      if((n%2 == 1) && i==2){
        printf("%i and %i\n",price[0],price[i]); // move to right
        totalCost += price[i];
        printf("%i\n",price[0]); // move to left
        totalCost += price[0];
        printf("%i and %i\n",price[0],price[i-1]); // move to right
        totalCost += price[i-1];

        return totalCost;
      }
      
      if(price[1]*2 <= price[0] + price[i-1]){
        printf("%i and %i\n",price[0],price[1]); // move to right
        totalCost += price[1];
        printf("%i\n",price[0]); // move to left
        totalCost += price[0];
        printf("%i and %i\n",price[i-1],price[i]); // move to right
        totalCost += price[i];
        printf("%i\n",price[1]); // move to left
        totalCost += price[1];
      }
      else{
        printf("%i and %i\n",price[0],price[i]); // move to right
        totalCost += price[i];
        printf("%i\n",price[0]); // move to left
        totalCost += price[0];
        printf("%i and %i\n",price[0],price[i-1]); // move to right
        totalCost += price[i-1];
        printf("%i\n",price[0]); // move to left
        totalCost += price[0];
      }
    }
    printf("%i and %i\n",price[0],price[1]);
    totalCost += price[1];

    return totalCost;
}
