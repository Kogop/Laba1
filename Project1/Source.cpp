#include <iostream>
#include <cstdlib>
#include <fstream>



using namespace std;

const int n = 5, m = 5;
double A[n][m], B[m][n], v[n], d[n], C[n][n];


void FillMatrix(double A[n][m]) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			A[i][j] = rand();

		}

	}


}

void Matrix_Peremnoj(double A[n][m], double B[m][n]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
}
void Matrix_Peremnoj_na_vector(double A[n][m], double v[n]) {

	for (int i = 0; i < n; i++) {
		d[i] = 0;
		for (int j = 0; j < m; j++) {
			d[i] += v[i] * A[i][j];
		}
	}
}


int main() {

	FillMatrix(A);

	ofstream File1("Matrix_1.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			File1 << A[i][j]<< " ";

		}
		File1 << endl;
	}

	
	File1.close();

	return 1;
}
