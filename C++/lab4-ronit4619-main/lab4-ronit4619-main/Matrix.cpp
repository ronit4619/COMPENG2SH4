#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;

 matrixData=NULL;

 matrixData = (int**)malloc(rowsNum*sizeof(int*));
    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }
    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )

    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){
	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/
	matrixData = NULL;

	if(row < 0) // check if num rows less than zero
		row = 3; //set rows to three

	if(col <= 0) //check if num of columns less than zero
		col =3; // set columns to equal three

	rowsNum = row;
	colsNum = col;

	matrixData = (int**) malloc(rowsNum* sizeof(int* )); //allocate row space

	for (int i = 0; i < rowsNum; ++i) {
		matrixData[i] = (int*) malloc(colsNum* sizeof(int )); //allocate column space
	}
	//setting matrix to equal zero
	for (int i = 0; i < rowsNum; i++) {
		for (int j = 0; j < colsNum; j++) {

			matrixData[i][j] = 0;
		}
	}

}

Matrix::Matrix(int row, int col, int** table){
	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/
	// reset the matrix to NULL
	matrixData = NULL;

	if (row <= 0){  // check if num rows less than or equal zero
			rowsNum = 3;//set rows to three
		}

	if (col <= 0){ //check if num of columns is less than or equal to zero
			colsNum = 3; // set columns to equal three
		}

	rowsNum = row;
	colsNum = col;

	matrixData = (int**) malloc(rowsNum*sizeof(int* ));

	for (int i = 0 ; i < row ; ++i) {
			matrixData[i] = (int*) malloc(colsNum*sizeof(int));
		}

	for (int i = 0 ; i < row ; ++i ) {
		    	for (int j = 0 ; j < col ; ++j ) {
		    		matrixData[i][j] = table[i][j];//set elements to elements in TABLE
		    	}
		}
}

int Matrix::getElement(int i, int j) {
	if (i < 0 || j<0 || i >= rowsNum|| j >= colsNum)
		throw out_of_range("Invalid indexes.");

	    return matrixData[i][j];
}

bool Matrix::setElement(int x, int i, int j){
	if (i < 0 || i >= rowsNum || j < 0 || j >= colsNum){
		return false;
	}
    matrixData[i][j] = x;
    return true;
}

Matrix Matrix::copy() {
	/* fix the code and write your implementation below */
	Matrix fullCopy = Matrix (rowsNum,colsNum);

	//go through each element of the matrix and then copy each element using nested for loop
	for (int i = 0; i < rowsNum; i++) {
		for(int j = 0; j < colsNum; j++) {
			fullCopy.matrixData [i][j] = matrixData [i][j];
	    	}
	    }
	    return fullCopy;
}

void Matrix::addTo( Matrix m ) {

    if (m.rowsNum != rowsNum || m.colsNum != colsNum){
        throw std::invalid_argument("Invalid operation");
    }
    else{ //if valid operation then all elements will be gone through using nested for loops to add them to each other
    	for (int i = 0; i < rowsNum; i++) {
    		for (int j = 0; j < colsNum; j++) {
    			//add matrices elements together
    			matrixData[i][j] += m.matrixData[i][j];
    		}
    	}
    }
}

Matrix Matrix::subMatrix(int i, int j) {

	/* The exception detail message should read: "Submatrix not defined"*/

	/* fix the code and write your implementation below */

    Matrix subMatrix = Matrix(i+1, j+1, matrixData);
//checking if subMatrix is defined
    if (i + 1 >= rowsNum || j + 1 >= colsNum) {
    	throw std:: out_of_range("Submatrix not defined"); // message for exception where submatrix is not defined
    }

    for (int x =0; x< 1; x++) {
    	for (int y =0; y< 1; y++) {
    		subMatrix.matrixData[x][y] = matrixData[x][y]; //copy elements to submatrix
    	}
    }

    return subMatrix;
}

int Matrix::getsizeofrows() {

	/* update below return */
	int numRow = sizeof(matrixData)/sizeof(matrixData[0]);

	return numRow;
}

int Matrix::getsizeofcols() {

	/* update below return */
	int numCol = sizeof(matrixData[0])/sizeof(int);

	return numCol;
}

bool Matrix::isUpperTr() {

	/* write your implementation here and update return accordingly */
    int n = min(rowsNum, colsNum);
    // nested for loop checks for matrix element equal to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
        if (matrixData[i][j] != 0)
            return false;
        }
    }
    return true;
}

string Matrix::toString() {
	/* returns a string representing the matrix,
	 with each row on a line, and the elements in each row being
	separated by 2 blank spaces. */

    string output = "";

    for (int i = 0; i < rowsNum; i++) {
        for (int j = 0; j < colsNum; j++) {
        	//add each element to output from the matrix
        	output += to_string(matrixData[i][j]);
            output += " ";
        }

        output += "\n"; //new line to move to matrix next row
    }
    //return output;

    return output;
}
