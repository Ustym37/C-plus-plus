#include <iostream>
#include <cmath>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
using namespace std;

//class Figure
//{
//protected:
//    string color;
//public:
//    Figure() //default
//	{
//        cout << "Created <Figure> at 0x" << hex << (unsigned long long)this << dec << endl;
//		color = "orange";
//    }
//    Figure(string p_color) 
//    {
//	color = p_color;
//    }
//    virtual ~Figure()
//	{
//		cout << "Destroyed <Figure> at 0x" << hex << (unsigned long long)this << dec << endl;
//	}
//    
//	virtual void show() 
//	{
//        cout << "Figure of " << color << " color" << endl;
//    }
//};
//
//class Sphere : public Figure
//{
//private:
//    double radius;
//
//public:
//    Sphere(double p_radius) 
//	{
//		cout << "Created <Sphere> at 0x" << hex << (unsigned long long)this << dec << endl;
//        radius = p_radius;
//    }
//    virtual ~Sphere()
//	{
//		cout << "Destroyed <Sphere> at 0x" << hex << (unsigned long long)this << dec << endl;
//	}
//	
//    void show() 
//	{
//        cout << "Sphere of " << color << " color with radius of " << radius << " cm" << endl;
//    }
//    
//	double get_radius() const { return radius; }
//    void   set_radius( double p_radius ){ radius = p_radius; }
//
//    double get_area() const { return (4 * 3.14 * radius * radius); }
//    double get_volume() const { return (4.0 / 3.0 * 3.14 * radius * radius * radius); }
//};  
//
//int main() 
//{
//	//1
//	cout << "Task 1:" << endl;
//	Figure c1 = Figure();
//    c1.show();
//
//    Figure c2 = Figure("green");
//    c2.show();
//	cout << endl;
//	
//	//2.
//	cout << "Task 2:" << endl;
//    Sphere sq = Sphere(11.1);
//    sq.show();
//    cout << endl;
//
//    //3
//	cout << "Task 3:" << endl;
//	sq.set_radius(10.0);
//    sq.show();
//    cout << "Area      = " << sq.get_area() << " cm^2" << endl;
//    cout << "Volume    = " << sq.get_volume() << " cm^3" << endl;
//    cout << endl;
//	
//	//4
//	cout << "Task 4:" << endl;
//	Figure* figures[2];
//	figures[0] = new Figure("blue");
//    figures[1] = new Sphere(20.0);
//    
//	figures[0]->show();
//	figures[1]->show();
//	cout << endl;
//
//	delete figures[0];
//	delete figures[1];
//
//	return 0;
//} 

class Polynom
{
    private:
	int polynom_order;
	int* index_array;

public:
	
	Polynom(int order, int* array)
	{
		polynom_order = order;
		index_array = array;
	}

	void show()
	{
		cout << "\nPolynom: ";
		for (int i = 0; i < polynom_order; i++)
		{
			if (i == 0)
			cout << index_array[i] << "x";
			else
			cout << index_array[i] << "x^" << i + 1;
				if (i < polynom_order - 1)
					cout << " + ";;
		}
	}

	void calculation()
	{
		cout << "\n\nPolinom value: ";
		double polynom = 0;
		for (int i = 0; i < polynom_order; i++)
		{
			polynom += index_array[i] * pow(2, i + 1);
		}
		cout << polynom;
	}

	void derivative()
	{
		cout << "\n\nPolinom derivative: ";
		for (int i = 0; i < polynom_order; i++)
		{
			if (i == 0)
				cout << index_array[i] * (i + 1);
			else if (i == 1)
				cout << index_array[i] * (i + 1) << "x";
			else
			    cout << index_array[i] * (i + 1) << "x^" << i;
			if (i < polynom_order - 1)
				cout << " + ";
		}
	}

	void integral()
	{
		cout << "\n\nPolinom integral: ";
		for (int i = 0; i < polynom_order; i++)
		{
			if (index_array[i] % (i + 2) == 0)
		    	cout << "x^" << i + 2;
			else
				cout << index_array[i] << "/" << (i + 2) << "x^" << i + 2;
			if (i < polynom_order - 1)
				cout << " + ";
		}
	}
};

int main()
{
	cout << "Input array length!\n";
	int n;
	cin >> n;
	int x;
	cout << "\nInput x value!\n";
	cin >> x;
	cout << "\nInput coefficients\n";
	int* array = new int [n];
	int element;
	for (int i = 0; i < n; i++)
	{
		cin >> element;
		array[i] = element;
	}
	Polynom polynom(n, array);
	polynom.show();
	polynom.calculation();
	polynom.derivative();
	polynom.integral();

	cout << endl;

	delete[] array;

	return 0;
}
