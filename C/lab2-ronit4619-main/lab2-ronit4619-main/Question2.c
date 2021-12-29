#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	int i;
	int j;
	int sum;
	sum= 0;
	int absValue;
	int stValue;
	//loop to determine if mat is diag. dominant
	for(i=0;i<N2;i++){
		for(j=0;j<N2;j++){
			//takes absolute value using abs(), same as fabs() but only for integers
			absValue = abs(mat[i][j]);
			if(i==j){
				stValue = absValue;
			}
			else{
				sum += absValue;
			}

		}
		//if stvalue is greater than sum then the matrix is diagonally dominant, sets to 1 if it is, otherwise to zero
		if(stValue>sum){
			isDiag = 1;
		}
		else{
			isDiag = 0;
			break;
		}
	}
    return isDiag;
}
