#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;
	/*write your implementation here*/
	FILE *inputFile = fopen(filename, "r");
	fscanf(inputFile,"%d",sizePtr);

	int num_students = *sizePtr;
	class_list = malloc(num_students *(sizeof(student*)));

	for(int i=0;i<num_students;i++){
		class_list[i] = malloc(sizeof(student));

		fscanf(inputFile,"%d",&class_list[i]->student_id);
		fscanf(inputFile,"%s",class_list[i]->first_name);
		fscanf(inputFile,"%s",class_list[i]->last_name);
//read the id and first and last name of students
	}
	fclose(inputFile);

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	int x = -1;

	for(int i = 0;i<size;i++){
		if(list[i]->student_id==idNo){
			x = i;
			return x;//find and match the identification
		}
	}
	/*write your implementation here and update the return accordingly*/
	return x;
}
void input_grades(char *filename, student **list, int size)
{
	/*write your implementation here*/
	FILE *inputFile = fopen(filename,"r");
	int id;

	for(int i=0;i<size;i++){
		fscanf(inputFile,"%d",&id);
		fscanf(inputFile,"%d",&(list[find(id,list,size)]->project1_grade));
		fscanf(inputFile,"%d",&(list[find(id,list,size)]->project2_grade));
		//read the project 1 and 2 marks
	}
	fclose(inputFile);
}
void compute_final_course_grades(student **list, int size)
{
	/*write your implementation here*/
	for(int i=0;i<size;i++){
		list[i]->final_grade = (((float)(list[i]->project1_grade)+((float)list[i]->project2_grade))/2);
	//average of two project marks and set it to the final mark (final_grade)
	}
}
void output_final_course_grades(char *filename, student **list, int size)
{
	/*write your implementation here*/
	FILE *outputFile = fopen(filename, "w");
	fprintf(outputFile,"%d\n",size);
	for(int i=0;i<size;i++){
		fprintf(outputFile,"%d %f \n",list[i]->student_id,list[i]->final_grade);
	}
	fclose(outputFile);
}
void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int sizeMOne = (*sizePtr-1);
	for(int i=0;i<(sizeMOne);i++){
		if(list[i]->student_id==idNo){
			for(int j =i;j<(sizeMOne);j++){
				list[j]->student_id = list[j+1]->student_id;
				for(int c=0;c<=14;c++){
					list[j]->first_name[c] = list[j+1]->first_name[c];
					list[j]->last_name[c] = list[j+1]->last_name[c];
				}
				free(list[sizeMOne]);
			}
		}
		else{
			printf("error");
		}
	}
}
void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for(int i = 0;i< *sizePtr;i++){
		free(list[i]);
	}
	free(list);
	*sizePtr = 0;
}
//freeing the memory



