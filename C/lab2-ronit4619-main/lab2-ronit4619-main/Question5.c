#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){
	//for loop goes up till end where"\0" is from source to destination up to n
	for(int i=0;i<(n-1);i++){
		if(source[i]=='\0'){

			break;
		}
		//letting destination[i] be equal to the source[i]
		destination[i]=source[i];
	}
}
