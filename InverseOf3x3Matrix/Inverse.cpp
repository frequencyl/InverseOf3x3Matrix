//INVERSE OF 3X3 MATRIX
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
	const int ROW = 3;
	const int COLUMN = 3;
	srand(time(NULL));
	int A[ROW][COLUMN];
	double transpose[ROW][COLUMN];
	double adjoint[ROW][COLUMN];
	double inverse[ROW][COLUMN];

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			A[i][j] = rand() % 10 + 1;
		}
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << left << setw(3) << A[i][j];
		}
		cout << endl;
	}
	//CALCULATING ADJOINT
	//FIRSTLY TRANSPOSE
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			transpose[j][i] = A[i][j];

		}
		cout << endl;

	}
	cout << "TRANSPOSE OF MATRIX" << endl;

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << left << setw(2) << transpose[i][j];

		}
		cout << endl;

	}
	cout << endl;
	cout << endl;
	//CALCULATE COFACTOR ALL OF THE ELEMENTS
	adjoint[0][0] = (transpose[1][1] * transpose[2][2]) - (transpose[1][2] * transpose[2][1]);
	adjoint[0][1] = -((transpose[1][0] * transpose[2][2]) - (transpose[1][2] * transpose[2][0]));
	adjoint[0][2] = (transpose[1][0] * transpose[2][1]) - (transpose[1][1] * transpose[2][0]);
	adjoint[1][0] = -((transpose[0][1] * transpose[2][2]) - (transpose[0][2] * transpose[2][1]));
	adjoint[1][1] = (transpose[0][0] * transpose[2][2]) - (transpose[0][2] * transpose[2][0]);
	adjoint[1][2] = -((transpose[0][0] * transpose[2][1]) - (transpose[0][1] * transpose[2][0]));
	adjoint[2][0] = (transpose[0][1] * transpose[1][2]) - (transpose[1][1] * transpose[0][2]);
	adjoint[2][1] = -((transpose[0][0] * transpose[1][2]) - (transpose[0][2] * transpose[1][0]));
	adjoint[2][2] = (transpose[0][0] * transpose[1][1]) - (transpose[0][1] * transpose[1][0]);
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << left << setw(4) << adjoint[i][j];

		}
		cout << endl;
	}
	int determinant;
	determinant = A[0][0] * ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1])) - A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0])) + A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0]));
	cout << "Determinant of matrix" << determinant << endl;
	if (determinant == 0) {
		cout << endl;
		cout << "This matrix's inverse does not exist";
		system("pause");
	}
	//INVERSE OF A MATRIX= ADJOINT/DETERMINANT

	cout << endl << "INVERSE OF MATRIX";
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			inverse[i][j] = adjoint[i][j] / determinant;
		}
		cout << endl;
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << left << setw(15) << inverse[i][j];
		}
		cout << endl;
	}
	//OZAN GUL




}