#include<iostream>
#include<cmath>

#define eps 0.001

//using namespace std;

int count_iteration_MIG = 0;
int count = 0;

double f1(double x) {
	return sqrt(abs(20 * x * x)) + 0.01 * sin(x);
}

void function() {
	double t1 = 2 / (1 + sqrt(5));
	double t2 = 1 - t1;
	double a1, a2, a3, a4, F3, F4, D;
	a1 = -10; //	left limit
	a2 = 10; //		right limit
	D = a2 - a1; // длина отрезка
	a3 = a1 + t2 * D;
	a4 = a1 + t1 * D;
	F3 = f1(a3);
	F4 = f1(a4);
	while (D > eps) {
		count++;
		count_iteration_MIG++;
		std::cout << "a1 = " << a1 << "\ta2 = " << a2 << std::endl;
		if (F4 < F3) {
			a1 = a3;
			a3 = a4;
			D = a2 - a1;
			F3 = F4;
			a4 = a1 + t1 * D;
			F4 = f1(a4);

		}
		else {
			a2 = a4;
			a4 = a3;
			D = a2 - a1;
			a3 = a1 + t2 * D;
			F4 = F3;
			F3 = f1(a3);
		}
	}
	double ao = (a1 + a2) / 2;
	std::cout << "aopt = " << ao << "\tF(aopt)= " << f1(ao) << std::endl;
	std::cout << "count = " << count << std::endl;
}

int main() {
	function();
	std::cout << "count_iteration_MIG = " << count_iteration_MIG << std::endl;
}