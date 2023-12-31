#include <iostream>
#include <iomanip>
#include <locale>
#include <exception>
#include "Fraction.h"

using namespace std;

template <class T>
void lu_decompisition(T** m, T** l, T** u, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			u[i][j] = m[i][j];
			if (i == j) l[i][j] = 1;
			else if (j > i) l[i][j] = 0;
		}
	}

	for (int i = 1; i < n; ++i) {
		if (u[i - 1][i - 1] == 0) throw exception("������� �� ����, LU ���������� �� ����������!");
		for (int j = i; j < n; ++j) {
			l[j][i - 1] = u[j][i - 1] / u[i - 1][i - 1];
			for (int k = 0; k < n; ++k)
				u[j][k] -= u[i - 1][k] * l[j][i - 1];
		}
	}
}

int main()
{
	setlocale(0, "russian");
	cout << "������� ����������� �������" << endl;
	int n;
	cin >> n;
	cout << "������� �������: " << endl;
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
		}
	}

	try {
		lu_decompisition(m, l, u, n);
	}
	catch (exception& e) {
		cout << e.what() << endl;
		cout << "������� enter, ����� �����...";
		cin.get();
		cin.get();
		return 0;
	}

	cout << "�������� �������:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(12) << m[i][j] << ' ';
		cout << endl;
	}

	cout << "������� U:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(12) << u[i][j] << ' ';
		cout << endl;
	}

	cout << "������� L:" << endl;
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

	cout << "��������:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(12) << p[i][j] << ' ';
		cout << endl;
	}
}