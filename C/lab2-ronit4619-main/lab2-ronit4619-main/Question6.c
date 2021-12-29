#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	int i;
	int j;
	j=0;

	for(i=0;i<size;i++){
		//if val in source[] does not equal 0 then val stores in val and pos []
		if(source[i]!=0){
			val[j] = source[i];
			pos[j]=i;
			j=j+1;
		}
	}
	

}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
	int i;
//source at position set to value
	for(i =0;i<n;i++){
		source[pos[i]]=val[i];

	}

    
	

}
