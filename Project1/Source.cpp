#include <iostream>
#include <cstdlib>
#include <fstream>



using namespace std;

const int n = 5, m = 5;
double A[n][m], B[m][n], v[n], d[n], C[n][n];


void FillMatrix(double A1[n][m]) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			A1[i][j] = rand()%100;

		}

	}

}

void FillVector(double v1[n]) {

	for (int j = 0; j < m; j++) {
			v1[j] = rand() % 100;

	}

}

void Matrix_Peremnoj(double A1[n][m], double B1[m][n]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C[i][j] += A1[i][k] * B1[k][j];
			}
		}
	}
}
void Matrix_Peremnoj_na_vector(double A1[n][m], double v1[n]) {

	for (int i = 0; i < n; i++) {
		d[i] = 0;
		for (int j = 0; j < m; j++) {
			d[i] += v1[i] * A1[i][j];
		}
	}
}


int main() {

	FillMatrix(A);
	FillMatrix(B);
	FillVector(v);

	ofstream File1("Matrix_1.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			File1 << A[i][j]<< " ";

		}
		File1 << endl;
	}
	File1.close();

	ofstream File2("Matrix_2.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			File2 << B[i][j] << " ";

		}
		File2 << endl;
	}
	File2.close();

	Matrix_Peremnoj(A, B);

	ofstream File3("Matrix_3.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			File3 << C[i][j] << " ";

		}
		File3 << endl;
	}
	File3.close();



	ofstream File4("Vector_1.txt");
	for (int i = 0; i < n; i++)
	{
		File4 << v[i]<< endl;
	}
	File4.close();

	Matrix_Peremnoj_na_vector(A, v);
	ofstream File5("Vector_2.txt");
	for (int i = 0; i < n; i++)
	{
		File5 << d[i] << endl;
	}
	File5.close();

	return 1;
}
