include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int main()
{
       /* int key;
        do
        {*/

            cout << "           1" << endl;
            cout << "Enter the value of n!\n";
            int nb;
            cin >> nb;
            int value = 0;
            for (int i = 0; i < nb; i++)
            {
                if (i == 0)
                value = 1;
                value *= 2;
            }
            cout << "2 ^(-" << nb << ") = " << 1.0 / value << endl << endl;

            cout << "           2" << endl;
            cout << "Enter the value of n!" << endl;
            int n;
            cin >> n;
            int factorial = 2 * n - 1;
            int b = factorial - 2;
            while (b > 0)
            {
                factorial *= b;
                b -= 2;
            }
            cout << "(2n-1)!! = " << factorial << endl << endl;

            cout << "           3" << endl;
            cout << "Enter the value of n!" << endl;
            int na;
            cin >> na;
            int i = 1;
            double value1 = 0;
            do
            {
                value1 += i - (1.0 / (i * i * i));
            } 
            while (++i <= na);
            cout << "Value of expression: " << value1 << endl << endl;

            cout << "           4" << endl;
            cout << "Enter the accuracy!" << endl;
            double e = 0;
            cin >> e;
            cout << "Enter an argument!" << endl;
            double x;
            cin >> x;
            if (e > 0 && e < 1)
            {
                cout << "Argument        Function       Accuracy       Sum" << endl;
                double function = (exp(x) + exp(-x)) / 2;
                double sum = 1;
                double d = 1; 
                for (int n = 1; d > e; n++)
                {
                    double factorial1 = (2 * n);
                    double q = factorial1 - 1;
                    while (q > 0)
                    {
                        factorial1 *= q;
                        q--;
                    }
                    d = pow(x, 2 * n) / factorial1;/*(pow(x, (2 * n) - 2) / factorial) * ((x * x) / (((2 * n) - 1) * (2 * n)));*/
                    sum += d;
                }
                cout << x << "               " << function << "       " << e << "           " << sum << endl << endl;
            }
            else
            {
                cout << "Accuracy should be in the range: (0, 1)" << endl << endl;
            }


            cout << "           Homework" << endl;
            cout << "Enter the starting limit!" << endl;
            double n1;
            cin >> n1;
            cout << "Enter the end limit!" << endl;
            double n2;
            cin >> n2;
            if (n2 > n1 && n1 > 0)
            {
                double sum1 = 0;
                for (int k = n1; k <= n2; k++)
                {
                    double ak = (k + pow(-1, k) * k * k) / (k * k + k + 3);
                    sum1 += ak;
                }
                cout << "Sum : " << sum1 << endl;
            }
            else
                cout << "The value of end limit must be greater than value of starting limit!" << endl;

         /*   key = getch();
        }
        while (key != 27);
        system("PAUSE");*/
}
