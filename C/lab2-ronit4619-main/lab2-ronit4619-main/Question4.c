#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	int i;
	int j;
	i = 0;
	//obtaining characters from the word word
	while(word[i]!='\0'){
		//finds how often a char arises
		for(j=0;j<26;j++){
			char x =  65+j;
			char y = 97+j;
			if(word[i]==x || word[i] ==y){
				freq[j]++;
			}
		}
		i++;
	}
	}

	


