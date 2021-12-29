#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	//this for loop completes the vector addition where the third vector equals the sum of the first two vectors
	for(int i=0;i<size;i++){
		vector3[i] = vector2[i]+vector1[i];
	}
	
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
    //finds the product of the vectors and adds to prod variable
	for(int i = 0;i<size;i++){
    	prod += vector2[i]*vector1[i];
	}

	
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;

	//write your code here
	// you should call function scalar_prod().
    //loops and takes the square root using sqrt() while calling scalar_prod
	for(int i = 0;i<size;i++){
		L2 = sqrt(scalar_prod(vector1,vector1,size));
	}
	//finally, return the L2 norm 
    return L2;
}
