#include "util.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>



double sumvec (int n , const double *vector) {
double sum = 0 ;
 for ( int i = 0 ; i < n ; i ++) {
   sum += vector[ i ] ;
 }
 return sum ;
}

void sumrows ( int n , int m, const double *matrix , double *vector ) {
for (int i = 0; i < n; i ++) {
  vector[i] = sumvec(m, &matrix[i *m] ) ;
 }
}

int insertSorted(int arr[], int n, int key, int capacity)
{
    // Cannot insert more elements if n is already
    // more than or equal to capacity
    if (n >= capacity)
        return 1;
  
    int i;
    for (i = n - 1; (i >= 0 && arr[i] > key); i--)
        arr[i + 1] = arr[i];
  
    arr[i + 1] = key;
  
    
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
  double candivec[d];
  if (d < 2) {
    memcpy(candivec, &points[candidate], d*sizeof(double));
  } else {
    memcpy(candivec, &points[candidate*((int)d)], d*sizeof(double));
  }
  
  double dist = distance(d,candivec, query);
  for (int i; i < d; i++) {
    double pointvec[d];
    if (d < 2) {
	memcpy(pointvec, &points[closest[i]], d*sizeof(double));
      } else {
      memcpy(pointvec, &points[closest[i]*((int)d)], d*sizeof(double));
    }
    if (dist < distance(d, pointvec, query)) {
      
      for (int j = d - 1; i < j; j--){
        
	closest[j] = closest[j - 1]; 
	    }
      
      closest[i] = candidate;
      return 1;
      }
    return 0;
  }
}

int main(){

  int k = 2;
  double x[] = {1.0, 2.0};
  double y[] = {9.0, 5.0};
  double z[] = {6.0, 3.0};
  double q[] = {8.0, 6.0};
  double a = distance(2, x, y);
  double b = distance(2, x, z);
  double c = distance(2, x, q);
  
  

  int d = 2;
  double points[] = {1.0, 2.0, 9.0, 5.0, 6.0, 3.0, 8.0, 6.0};
  int closest[] = {3, 1};
  double query[] = {1.0, 2.0};
  int candidate = 2;

  
  insert_if_closer(k, d, points, closest, query, candidate);

  printf("%f distance from x, y\n",a);
  printf("%f distance from x, z\n",b);
  printf("%f distance from x, q\n",c);

  
  printf("%d %d \n", closest[0],closest[1]);
  
 
  
  return 0;

}
