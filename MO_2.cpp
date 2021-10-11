#include<iostream>
#include<cmath>

#define eps 0.001

using namespace std;

double x1, x2, x3, x4;

double definition_value_F1(double x) {
	return (pow(x, 2) - x);
}

double definition_value_F2(double x) {
	return (sqrt(abs(20 * pow(x, 2))) + 0.01 * sin(x));
}

double sign_definition(double h, double x) {
	double f0, fl, fr;

	f0 = definition_value_F1(x);
	fl = definition_value_F1(x - h);
	fr = definition_value_F1(x + h);
	if (fl >= f0 && f0 >= fr) {
		cout << "h=" << h << endl;
		return h;
	}
	else if (fl <= f0 && f0 <= fr) {
		cout << "h=" << -h << endl;
		return (-h);
	}
	else { cout << "error" << endl; }
}

double k = 0, f1 = 0, f2;

double uncertainty_interval(double x, double h) {
	f1 = f2;
	x = x + h * pow(2, k);
	k++;
	cout << "X=" << x << endl;
	f2 = definition_value_F1(x);
	cout << endl << "F2=" << f2 << endl;
	if (f1 >= f2) {
		x = uncertainty_interval(x, h);
	}
	return x;
}

void value_inline(double h, double x) {
	x1 = x;
	x2 = x - h * pow(2, k - 2);
	x3 = x - h * pow(2, k - 1);
	x4 = x3 - h * pow(2, k - 2);
	cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3 << " x4 = " << x4 << endl;
}

void define_uncertainty_interval() {
	double a, b, X1, X2;
	a = x4;
	b = x1;
	X1 = x2;
	X2 = x3;
	if (definition_value_F1(X1) > definition_value_F1(X2)) {
		cout << "uncertainty_interval [a,b] = " << a << ", " << X1 << endl;
	}
	else if (definition_value_F1(X1) < definition_value_F1(X2)) {
		cout << "uncertainty_interval [a,b] = " << X2 << ", " << b << endl;
	}
	else {
		cout << "uncertainty_interval [a,b] = " << X1 << ", " << X2 << endl;
	}
}

void function() {
	double t1 = 2 / (1 + sqrt(5));
	double t2 = 1 - t1;
	double a1, a2, a3, a4, F3, F4, D;
	a1 = x4;
	a2 = x1;
	D = a2 - a1;
	a3 = a1 + t2 * D;
	a4 = a1 + t1 * D;
	F3 = definition_value_F1(a3);
	F4 = definition_value_F1(a4);
	while (D > eps)
	{
		cout << "a1 =" << a1 << "\ta2=" << a2 << endl;
		if (F4 < F3) {
			a1 = a3; a3 = a4; D = a2 - a1;
			F3 = F4; a4 = a1 + t1 * D; F4 = definition_value_F1(a4);
		}
		else {
			a2 = a4; a4 = a3; D = a2 - a1;
			a3 = a1 + t2 * D; F4 = F3; F3 = definition_value_F1(a3);
		}
	}
	double ao = (a1 + a2) / 2;
	cout << "aopt = " << ao << "F(aopt)= " << definition_value_F1(ao) << endl;
}

int main() {
	double x = 0, h = 1;
	h = sign_definition(h, x);
	f2 = definition_value_F1(x);
	x = uncertainty_interval(x, h);
	cout << "XXXXX=" << x << endl;
	value_inline(h, x);
	function();
	cout << endl;
	define_uncertainty_interval();
}