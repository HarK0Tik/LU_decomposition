#include <iostream>
#include <conio.h>
#include <iomanip>
#include <locale>
#include <math.h>
#include "Fraction.h"

using namespace std;

int main()
{
	setlocale(0, "russian");
	cout << "Введите размерность матрицы" << endl;
	int n;
	cin >> n;
	cout << "Введите матрицу: " << endl;
	Fraction** m = new Fraction * [n],
		** l = new Fraction * [n],
		** u = new Fraction * [n],
		** p = new Fraction * [n];
	int tmp;
	for (int i = 0; i < n; ++i) {
		m[i] = new Fraction[n];
		l[i] = new Fraction[n];
		u[i] = new Fraction[n];
		p[i] = new Fraction[n];
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			m[i][j] = Fraction(tmp, 1);
			u[i][j] = m[i][j];
			if (i == j) l[i][j] = 1;
			else if (j > i) l[i][j] = 0;
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = i; j < n; ++j)
		{
			l[j][i - 1] = u[j][i - 1] / u[i - 1][i - 1];
			for (int k = 0; k < n; ++k) {

				u[j][k] -= u[i - 1][k] * l[j][i - 1];
			}
		}
	}

	cout << "Исходная матрица:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(12) << m[i][j] << ' ';
		cout << endl;
	}

	cout << "Матрица U:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(12) << u[i][j] << ' ';
		cout << endl;
	}

	cout << "Матрица L:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(12) << l[i][j] << ' ';
		cout << endl;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			p[i][j] = 0;
			for (int k = 0; k < n; ++k)
				p[i][j] += l[i][k] * u[k][j];
		}
	}

	cout << "Проверка:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(12) << p[i][j] << ' ';
		cout << endl;
	}
}