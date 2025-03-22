#include <iostream>
using namespace std;
#include <cmath>

int main ()
{
   	cout << "Imput name!" << endl;
	char name [200];	
    cin >> name;
	cout << "Imput age!" << endl;
	int age;
	cin >> age;
	cout << "Name - " << name << endl;
	cout << "Age - " << age;
	
    cout << "Imput value!" << endl;
	double a;
	cin >> a;
	double z1 = sin(1/5 * M_PI + a)*sin(1/5 * M_PI + a);
	cout << "z1 = " << z1 << endl;
	double z2 = 40 * sqrt(3) * (sin(a)+sin(2*a)+sin(3*a+M_PI/4));
	cout << "z2 = " << z2 << endl;
	double z3 = tan(a/3)*sin(3*a+1)-(a*a*a);
	cout << "z3 = " << z3 << endl;
	
	cout << "Impute x" << endl;
	double x;
	cin >> x;
	double y;
	if (x >= 5)
	{
		int f = 0;
		cout << "y = " << f << endl;
	}
	else if (x>=2 && x<5)
	{
		int f = x;
		cout << "y = x = " << f << endl;
	}
	else if (x>=0 && x<2)
	{
		int f = x*x;
		cout << "y = x^2 = " << f << endl;
	}
	else if (x<0)
	{
		int f = 1-x;
		cout << "y = 1 - x = " << f << endl;
	}
	
	cout << "Imput x!" << endl;
	int x;	
    cin >> x;
	cout << "Imput y!" << endl;
	int y;	
    cin >> y;
	cout << "Imput a!" << endl;
	int a;	
    cin >> a;
    if (a*x*x==y)
    {
    	cout << "point belongs to graph " << endl;
	}
	if (a*x*x!=y)
    {
    	cout << "point don't belong to graph " << endl;
	}
	
    cout << "   " << endl;
    cout << "R - radius of the circle" << endl;
    cout << "Input radius!\n";
    double R;
    cin >> R;
    double area = R * R * 3 * sqrt(3) / 4;
    cout << "Area of triangle: " << area << endl;
    cout << "All angles of this triangle are 60°" << endl;
	
	return 0;
}
