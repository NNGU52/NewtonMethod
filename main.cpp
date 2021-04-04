#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <vector>
#define _USE_MATH_DEFINES

using namespace std;

// функция F(x, y)
double F(double x, double y)
{
	return tan(x * y) - pow(x, 2);
}

// функция G(x, y)
double G(double x, double y)
{
	return x + log(y / 15.0);
}

// частная производная от F(x, y) по x
double dF(double x , double y)
{
	double dx = 1e-6;
	return (F(x + dx, y) - F(x , y)) / dx;
}

// частная производная от G(x, y) по x
double dG(double x, double y)
{
	double dx = 1e-6;
	return (G(x + dx, y) - G(x, y)) / dx;
}

// частная производная от F(x, y) по y
double dF1(double x, double y)
{
	double dy = 1e-6;
	return (F(x, y + dy) - F(x, y)) / dy;
}

// частная производная от G(x, y) по y
double dG1(double x, double y)
{
	double dy = 1e-6;
	return (G(x, y + dy) - G(x, y)) / dy;
}

// функция для вывода якобиана
void print(vector<vector<double>> W0, int count = 5, int number = 9) 
{

	int m = W0.size();
	int n = W0[0].size();

	cout.setf(ios::right);  // установка флага вывода ; выравнивание по правой границе(по умолчанию)
	cout.setf(ios::fixed);  // установка флага вывода ; вывод чисел с плавающей точкой в фиксированной форме(по умолчанию)
	cout << setprecision(count);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0)
			{
				cout << setw(number) << W0[i][j];
			}
			if (i == 0 && j == 1)
			{
				cout << setw(number) << W0[i][j];
			}
			if (i == 1 && j == 0)
			{
				cout << setw(number) << W0[i][j];
			}
			if (i == 1 && j == 1)
			{
				cout << setw(number) << W0[i][j];
			}  
		}
		cout << endl;
	}

	cout << endl;
}

// метод Гаусса
vector<double> Gauss(int n, int m, vector<vector<double>> matrix_original)
{
	vector<vector<double>> matrix(n, vector<double>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = matrix_original[i][j];
		}
	}

	double tmp;
	int k;
	vector<double> xx(m);

	for (int i = 0; i < n; i++)
	{
		tmp = matrix[i][i];
		for (int j = n; j >= i; j--)
			matrix[i][j] /= tmp;
		for (int j = i + 1; j < n; j++)
		{
			tmp = matrix[j][i];
			for (k = n; k >= i; k--)
				matrix[j][k] -= tmp * matrix[i][k];
		}
	}
	/*обратный ход*/
	xx[n - 1] = matrix[n - 1][n];
	for (int i = n - 2; i >= 0; i--)
	{
		xx[i] = matrix[i][n];
		for (int j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
	}

	return xx;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int k_max = 50;
	double eps = 1e-6;
	int n = 2;
	int m = 2;
	double x0;
	double y0;
	
	cout << " Введите x0: ";
	cin >> x0;
	cout << " Введите y0: ";
	cin >> y0;
	cout << endl;
	double x, y, x_, y_;
	x = x0;
	y = y0;
	for (int k = 1; k <= k_max; k++)
	{
		vector<vector<double>> W0(n, vector<double>(m, 0));
		W0[0][0] = dF(x, y);
		W0[0][1] = dF1(x, y);
		W0[1][0] = dG(x, y);
		W0[1][1] = dG1(x, y);

		vector<vector<double>> slau = { { W0[0][0], W0[0][1], -1 * F(x, y) }, { W0[1][0], W0[1][1], -1 * G(x, y) } };
		vector<double> result(2);
		result = Gauss(n, m+1, slau);

		x_ = x + result[0];                                                          // уточнение приближенного значения x
		y_ = y + result[1];                                                          // уточнение приближенного значения y
	
		//cout << endl;

		if ((abs(x_ - x) < eps) && (abs(y_ - y) < eps))
		{
			cout << setprecision(7) << " x:" << " " << x << endl << setprecision(7) << " y:" << " " << y << endl;  // вывод x, y (при выполнении 1 условия)
			cout << " Кол-во итераций: " << k << endl;
			break;
		}
		if (k > k_max)
		{
			cout << " K > Kmax " << endl;
			cout << setprecision(7) << " x: " << x << endl << setprecision(7) << " y: " << y << endl;   // вывод x, y (при выполнении 2 условия)
			cout << " Кол-во итераций: " << k << endl;
			break;
		}

		x = x_;
		y = y_;
	}

	getchar(); getchar();
}
