#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){
	int i;
	int counter;
	int row;
	int col;
	//counter keeps track of index
	for(i=0;i<N3;i++){
		row = i;
		for(int col = 0;col<=i;col++){
			arr[counter] = mat[row][col]; //changes row by 1 up and col by 1 right
			counter++;//increase counter index for arr
			row--;
		}
	}
	//when first diagonal is in last row
	for(i=1;i<N3;i++){
		row = N3-1;
		for(col=i;col<=N3;col++){
			arr[counter] = mat[row][col];
			counter++;
			row--;

		}

	}

}
