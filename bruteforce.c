#include "bruteforce.h"
#include "util.h"
#include <stdlib.h>
#include <assert.h>

int* knn(int k, int d, int n, const double *points, const double* query) {

  int *closest = (int*)malloc(sizeof(int)*k);
  for (int j = 0; j < k; j++){
    closest[j] = -1;
  }

  int i;
  
   for(i = 0; i < n; i++) { 
     insert_if_closer(k, d, points, closest, query, i); 
   } 
   return closest; 
}


