#include <iostream>
#include <conio.h>
#include <iomanip>
#include <locale>

using namespace std;

int main()
{
	setlocale(0, "russian");
	cout << "������� ����������� �������" << endl;
	int n;
	cin >> n;
	cout << "������� �������: " << endl;
	double** m = new double* [n], ** l = new double* [n], ** u = new double* [n], ** p = new double* [n];
	for (int i = 0; i < n; ++i) {
		m[i] = new double[n];
		l[i] = new double[n];
		u[i] = new double[n];
		p[i] = new double[n];
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
			l[j][i - 1] = u[j][i - 1] / u[i - 1][i - 1];
			for (int k = 0; k < n; ++k) {

				u[j][k] -= u[i - 1][k] * l[j][i - 1];
			}
		}
	}

	cout << "�������� �������:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(10) << m[i][j] << ' ';
		cout << endl;
	}

	cout << "������� U:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(10) << u[i][j] << ' ';
		cout << endl;
	}

	cout << "������� L:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(10) << l[i][j] << ' ';
		cout << endl;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			p[i][j] = 0;
			for (int k = 0; k < n; ++k)
				p[i][j] += l[i][k] * u[k][j];
		}
	}

	cout << "��������:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(10) << p[i][j] << ' ';
		cout << endl;
	}
}