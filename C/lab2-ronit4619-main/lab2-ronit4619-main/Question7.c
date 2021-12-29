#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){

	int count;
	count = 0;
	int i;
	i= 0;
	int j;
	j= 0;
	while(i<k1){
		while(pos2[j]<pos1[i]){
			val3[count]=val2[j];
			pos3[count]=pos2[j];
			count++;
			j++;
			//val two affects pos
		}
		if((val2[j]+val1[i])==0){
			j++;
			i++;
			//situation where sum is 0
		}
		else if((val1[i]+val2[j])!=0 && (pos2[j]==pos1[i])){
			val3[count]=val2[j]+val1[i];
			pos3[count]=pos2[j];
			count++;
			j++;
			i++;
			//both have same pos and dont add to zero --> main attention is focused here per the question
		}
		else  {
			val3[count]=val1[i];
			pos3[count]=pos1[i];
			count++;
			i++;
				}
			}
	while (j<k2){
		val3[count]=val2[j];
		pos3[count]=pos2[j];
		count++;
		j++;
		//for all of the rest of val2
			}

		}
