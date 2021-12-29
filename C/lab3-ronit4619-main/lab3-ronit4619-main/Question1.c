#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"


char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;

	/*write your implementation here*/

	z = (char *)calloc(strlen(str1) + strlen(str2) + 1,sizeof(char));

	//+1 for null after concatenating str1 and str2

	//add string 1 and string 2
    for (int i = 0; i < strlen(str1); i++)
    {
        (z[i] = str1[i]);
    }
    for (int i = 0; i < strlen(str2); i++)
    {
        (z[strlen(str1)+i] = str2[i]);
    }

	  /* finally, return the string*/
    z[(strlen(str1))+(strlen(str2))+1]="\0";
	return z;

}


//strcpy(z, str1);
//strcat(z,str2);


