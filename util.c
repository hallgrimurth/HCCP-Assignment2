#include "util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



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

  
  double dist = distance(d, query, &points[candidate*d]);
  if (dist != 0) {
    
    //double *pointvec = malloc(d*sizeof(double));
    
    for (int i = 0; i < k; i++) {

      if(closest[i] == -1){
	closest[i] = candidate;
	return 1;
      }

      if (dist < distance(d, query, &points[d*closest[i]])){
	  for ( int l = k; l > i; l--) {
	    closest[l] = closest[l - 1];
	    
	  }
	 
	  closest[i] = candidate;
	  return 1;
	}
    
    }
  
  }
  return 0;
}

      

 /* int main() */
 

/*   int k = 2; */
/*   double x[] = {1.0, 2.0}; */
/*   double y[] = {9.0, 5.0}; */
/*   double z[] = {6.0, 3.0}; */
/*   double q[] = {8.0, 6.0}; */
/*   double a = distance(2, x, y); */
/*   double b = distance(2, x, z); */
/*   double c = distance(2, x, q); */
  
  

/*   int d = 2; */
/*   double points[] = {1.0, 2.0, 9.0, 5.0, 6.0, 3.0, 8.0, 6.0}; */
/*   int closest[] = {2, 1}; */
/*   double query[] = {1.0, 2.0}; */
/*   int candidate = 3; */

  
/*   insert_if_closer(k, d, points, closest, query, candidate); */

/*   printf("%f distance from x, y\n",a); */
/*   printf("%f distance from x, z\n",b); */
/*   printf("%f distance from x, q\n",c); */

  
/*   printf("%d %d \n", closest[0],closest[1]); */
  
 
  
/*   return 0; */

/* } */
