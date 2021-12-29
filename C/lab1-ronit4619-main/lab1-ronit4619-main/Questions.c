
#include "Questions.h"



int Q1_for(){
	
	// calculate your sum below..this has to use for loop
	int i;
	int sum=0;
	// calculate your sum below..this has to use for loop
	for(i=30; i<=1000;i++){
		if(i%4==0){
			sum+=i;
		}
		else{
		}
	}
	// here, we return the calculated sum:
	return sum;
}
int Q1_while(){
	int i=30;
	int sum=0;
	// calculate your sum below..this has to use while loop
	while(i<=1000){
		if((i%4)==0){
			sum+=i;
		}
		i++;
	}
	// here, we return the calculated sum:
	return sum;
}
int Q1_do(){
		// calculate your sum below..this has to use do-while loop
	int i = 30;
	int sum = 0;
	    do {
	        if ((i%4) == 0){
	            sum += i;
	        }
	        i ++;
	    }
	    while (i<=1000);
	// here, we return the calculated sum:
	    return sum;
	   }
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit;
	
	// Do your coding below to check
	if (((Q2_input<100000) && (Q2_input>=10000))||((Q2_input<=-10000) && (Q2_input>-100000))){ //less than 6 digits&more than 4 digits for +ve and -ve input
		IsFiveDigit = 1;
	}
	else{
		IsFiveDigit = 0;
	}
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program should return -1
*/	
	// this is the variable that holds the out value to return
	float GPA;
	
	// Do your coding below to calculate the GPA variable value
	if (Q3_input>=90){
		if(Q3_input<=100){
			GPA = 4;
		}
	}
	else if(Q3_input>=80){
		if(Q3_input<=89){
			GPA = 3;
		}
	}
	else if(Q3_input>=70){
		if(Q3_input<=79){
			GPA = 2;
		}
	}
	else if(Q3_input>=60){
		if(Q3_input<=69){
			GPA = 1;
		}
	}
	else if(Q3_input>=0){
		if(Q3_input<=59){
			GPA = 0;
		}
	}
	else{
		GPA = -1;
	}
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the variable that holds the pi value to return
	double pi=0;
	
	
	// Do your coding below to calculate the pi value
	double i;
	int x = 1;
	if(Q4_input>0){
		for(i=1;i<=Q4_input;i++){
			pi = pi+x*4/((2*i)+1);
			x =(-1)*x;

		}
	}
	else{ //if value is not +ve then else is used for improper input
		pi = -1;
	}

	   
	
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/
	int hypotenuse;
	int side1;
	int side2;

	for(hypotenuse=1;hypotenuse<=400;hypotenuse++){
		for(side1=1;side1<=400;side1++){
			for(side2=side1;side2<=400;side2++){
				if((((side1)*(side1))+((side2)*(side2))) == (hypotenuse*hypotenuse)){
					totNumTribles+=;

				}
			}
		}
	}
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
		//counts is the variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;
		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    int i;
	    int k;
	    int sum;
	    
	    for(i=2;i<=Q6_input;i++){
	    	sum = 0;
	    	for(k=1;k<i;k++){
	    		if(i%k == 0){
	    			sum+=k;
	    		}
	    	}
	    	if(sum==i){ //adding perfect num to perfect[]array
	    		perfect[counts] = i; 
	    		counts+=1;
	    	}
	    }
	   return counts;
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	int inputNum;
	int reverseNum;
	int specificVal;
	int remainingNum;
	int num;
	inputNum = 1000000; //7 digit
	reverseNum = 1;
	remainingNum = Q7_input;
	
	for (num=0;num<7;num++){
		specificVal = remainingNum/inputNum;
		remainingNum%=inputNum;
		reverseNum +=(specificVal*reverseNum);
		inputNum/=10;
		reverseNum*=10;
	}

		return reversedInt;
	
}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	int inputNum;
	int reverseNum;
	int specificVal;
	int remainingNum;
	int num;
	int numDigits;
	numDigits = 1;
	inputNum = 1; 
	reverseNum = 1;
	remainingNum = Q7b_input;
	
	while(Q7b_input/inputNum>=10){
		numDigits++;
		inputNum*=10;
	}//finds num of digits for us
	for (num=0;num<7;num++){
			specificVal = remainingNum/inputNum;
			remainingNum%=inputNum;
			reverseNum +=(specificVal*reverseNum);
			inputNum/=10;
			reverseNum*=10; //same loop as in part a
		}
	return reversedInt;

	
	
	
}
