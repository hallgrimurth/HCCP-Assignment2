#include "util.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>

int idx2_rowmajor(int n, int m, int i, int j) {
  assert(i >= 0 && i < n);
  assert(j >= 0 && j < m);
  return i * m + j;
}

double distance(int d, const double *x, const double *y) {
  double result = 0.0;
  double a;
  for (int i = 0; i < d; i++){
    a = (y[i] - x[i]) * (y[i] - x[i]);
    result = result + a;
			      
  }	    
  return sqrt(result);
}

int insert_if_closer(int k, int d,
                     const double *points, int *closest, const double *query,
                     int candidate) {

  double dist = distance(d, points, query);
  if (dist < distance(d, points, query) || closest[0] == -1) {
    for ( int i = 0; i < k; i++){
      double temp = closest[i];
      closest[i] = candidate;
      candidate = temp;
    }
    return 1;
  } else {
    return 0;
  }
}

int main(){

  int k = 1;
  double x[] = {1.0, 2.0, 2.0};
  double y[] = {10.0, 3.0, 5,0};
  double a = distance(3, x, y);
  printf("%f\n",a);

  int d = 3;
  double points[] = {1.0, 2.0, 9.0};
  int closest[] = {-1, -1, -1};
  double query[] = {points[1]};
  int candidate = 2;

  insert_if_closer(k, d, points, closest, query, candidate);
  printf("%d\n",closest[0]);
  printf("%d\n", idx2_rowmajor(2, 5, 1, 3));
  return 0;
}
