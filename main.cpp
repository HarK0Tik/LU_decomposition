#include <iostream>
#include <conio.h>
#include <iomanip>
#include <locale>

using namespace std;

int main()
{
	setlocale(0, "russian");
	cout << "Введите размерность матрицы" << endl;
	int n;
	cin >> n;
	cout << "Введите матрицу: " << endl;
	double** m = new double*[n], **l = new double* [n], **u = new double* [n];
	for (int i = 0; i < n; ++i) {
		m[i] = new double[n];
		l[i] = new double[n];
		u[i] = new double[n];
		for (int j = 0; j < n; ++j) {
			cin >> m[i][j];
			u[i][j] = m[i][j];
			if (i == j) l[i][j] = 1;
			else if (j > i) l[i][j] = 0;
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = i; j < n; ++j)
		{
			l[j][i-1] = u[j][i-1] / u[i-1][i-1];
			for (int k = 0; k < n; ++k) {

				u[j][k] -= u[i-1][k] * l[j][i-1];
			}
		}
	}

	cout << "Исходная матрица:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(8) << m[i][j] << ' ';
		cout << endl;
	}

	cout << "Матрица U:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(8) << u[i][j] << ' ';
		cout << endl;
	}

	cout << "Матрица L:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(8) << l[i][j] << ' ';
		cout << endl;
	}
}