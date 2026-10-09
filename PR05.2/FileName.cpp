#include<iostream>
#include< cmath>
#include<iomanip>

using namespace std;
void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main() {
	double xp, x, xk, dx, eps, exact, s;
	int n = 0;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;

	cout << "------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << "   |"
		<< setw(10) << "exact" << "  |"
		<< setw(7) << "S" << "    |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "------------------------------------------" << endl;



	x = xp;
	while (x <= xk) {

		S(x, eps, n, s);

		exact = 0.5 * log((x + 1) / (x - 1));

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << exact << "  |"
			<< setw(10) << setprecision(5) << s << " |"
			<< setw(5) << n << " |"
			<< endl;

		x += dx;
	}
	cout << "------------------------------------------" << endl;

	return 0;
}
void S(const double x, const double eps, int& n, double& s)
{
	n = 0;
	double a = 1.0 / x;
	s = a;
	do {
		n++;
		A(x, n, a);
		s += a;
	} while (fabs(a) >= eps);
}
void A(const double x, const int n, double& a)
{
	double R = (2.0 * n - 1) / ((2.0 * n + 1) * x * x);
	a *= R;
}