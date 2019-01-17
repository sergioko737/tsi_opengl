#include <iostream>
#include <math.h>
#include <conio.h>
#include <iomanip>
using namespace std;

//Function to find f (x) = 0.
double f(double x)
{
	return (x *pow(2,3*x) - 22);
}

//Method of bisection.
int Bisection(double a, double b, double * c, double eps)
{
	int k = 0;
	do
	{
		*c = (a + b) / 2;
		if (f(*c) * f(a) < 0) {
			b = *c;
			cout << "(f(*c) * f(a) < 0) true B = " << b << " f*(c) = " << f(*c) << " f(a) = " << f(a) << endl;
		}
		else { 
			a = *c;
			cout << "(f(*c) * f(a) < 0) false A = " << b << " f*(c) = " << f(*c) << " f(a) = " << f(a) << endl;
		}
		k++;
	} while (k < 6);// while (fabs(a - b) >= eps);
	return k;
}

//Method of chords.
int Chord(double a, double b, double * c, double eps)
{
	int k = 0;
	do
	{
		*c = a - f(a) / (f(b) - f(a)) * (b - a);
		if (f(*c) * f(a) >0) {
			a = *c;
			cout << "(f(*c) * f(a) < 0) true A = " << b << " f*(c) = " << f(*c) << " f(a) = " << f(a) << endl;
		}
		else {
			b = *c;
			cout << "(f(*c) * f(a) < 0) false A = " << b << " f*(c) = " << f(*c) << " f(a) = " << f(a) << endl;
		}
		k++;
	} while (k < 6); //while (fabs(f(*c)) >= eps);
	return k;
}

double f1(double x) //First derivative of the function f (x).
{
	return (3*pow(2, 3*x)*x*log(2)+pow(2,3*x));
}

double f2(double x) //Second derivative of the function f (x).
{
	return (3 * pow(2, 3 * x)*(3*x*log(2) + 2)*log(2));
}

//Newton method
int Newton(double a, double b, double * c, double eps)
{
	int k = 0;
	* c = 2.5;
	cout << "Initial guess = " << *c << endl;
	do
	{
		*c = *c - f(*c) / f1(*c);
		cout << "Iteration " << k << " " << *c << " f(c) = " << f(*c) << " f1(c) = " << f1(*c) << endl;
		k++;
	} while (k < 6); //while (fabs(f(*c)) >= eps);
	return k;
}
double fi(double x, double L) 
{
	return (x + L* f(x));
}
//A function that implements a simple iteration method.
int Iteration(double *x, double L, double eps)
{
	cout << "*x = " << *x << endl;
	cout << "eps = " << eps << endl;
	cout << "stability check f1(x0) = " << L*f1(2.5) << " L = " << L << endl;
	int k = 0; double x0;
	do
	{
		cout << "Iteration " << k ;
		x0 = *x;
		cout << " x" << k << " =" << setprecision(5) << x0 << endl;
		*x = fi(x0, L);
		k++;
	} while (k < 6);
	//while (fabs(x0 - *x) >= eps);
	return k;
}
int main()
{
	double A, B, X, P;
	double ep = 0.0001; //Precision.
	int K;
	A = 1; //range
	B = 2;
	cout << "Solve equation ---x*pow(2,3*x)-22=0--- " << endl;

	cout << endl << "Bisection method:" << endl;
	K = Bisection(A, B, &X, ep);
	cout << "Found x = " << X;
	cout << ", number of iterations k = " << K << endl;

	cout << endl << "Method of chords:" << endl;
	K = Chord(A, B, &X, ep);
	cout << "Found x = " << X;
	cout << ", number of iterations k = " << K << endl;

	cout << endl << "Newton method:" << endl;	
	K = Newton(A, B, &X, ep);
	cout << " Found x = " << X;
	cout << ", number of iterations k = " << K << endl;

	cout << endl << "Method of simple iterations:" << endl;
	X = 1.2; //initial guess
	cout << "X = " << X << endl;
	P = -0.02;
	K = Iteration(&X, P, ep);
	cout << " Found x = " << X << endl;
	cout << ", number of iterations k = " << K << endl;

	system("pause");
	return 0;
}