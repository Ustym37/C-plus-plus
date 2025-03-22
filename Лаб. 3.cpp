#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <ctime>

//int main()
//{
   /* srand(time(0));*/
    //Аудиторна робота

    //1
   /* cout << "    Task 1" << endl;
    int res = 8192;
    int i = 12;
    while (res > 16)
    {
        res = res >> 1;
        printf("2^%d = \t%d\thex form = 0x%003X\n", i, res, res);
        i--;
    }
    cout << endl;*/

    //2
    //cout << "    Task 2" << endl;
    //unsigned int a = rand() % 225;
    //unsigned int bit;
    //int unit = 0;
    //cout << "Random number: " << a << endl << "Binary form:   ";
    //for (int i = 7; i >= 0 ; i--) // у трицифровому числі 8 бітів
    //{
    //    bit = (a >> i) & 0x1;
    //    cout << bit;
    //    if (bit == 1) unit++;
    //}
    //cout << endl;
    //cout << "Number of units: " << unit;
    //cout << endl << endl;

    ////3
    //cout << "    Task 3" << endl;
    //unsigned int mask = 0xF0;
    //unsigned int n = rand() % 64;
    //unsigned int bit1;
    //cout << "Random number: " << n << endl << "Binary form: ";
    //for (int i = 16; i >= 0; i--)
    //{
    //    bit1 = (n >> i) & 0x1;
    //    cout << bit1;
    //}
    //n = n ^ mask;
    //cout << "\nn ^ mask (F0) = " << n << endl << "Binary form: ";
    //for (int i = 16; i >= 0; i--)
    //{
    //    bit1 = (n >> i) & 0x1;
    //    cout << bit1;
    //}
    //cout << endl << endl;

    ////4
  /*  cout << "    Task 4" << endl;
    cout << "Input 16-bit number: ";
    unsigned int number;
    unsigned int bit2;
    cin >> number;
    cout << "Musk = 0xAAAA (43690)" << endl;
    cout << "Binary form of " << number << " :                   ";
    for (int i = 15; i >= 0; i--)
    {
        bit2 = (number >> i) & 0x1;
        cout << bit2;
        if ((i % 4) == 0) cout << "  ";
    }
    number = number | 0xAAAA;
    cout << "\nAfter musk: number = " << number << "  binary form: ";
    for (int i = 15; i >= 0; i--)
    {
        bit2 = (number >> i) & 0x1;
        cout << bit2;
        if ((i % 4) == 0) cout << "  ";
    }
    cout << endl << endl;*/

    //Домашня робота
    
   void printbits(unsigned int n)
   {
       unsigned int bit;
       for (int i = 15; i >= 0; i--)     
       {
           bit = (n >> i) & 0x1;
           cout << bit;
           if ((i % 4) == 0) cout << "  ";
       }
   }
   int main()
   {
       cout << "    Homework" << endl;
       unsigned int x;
       cout << "Input x: ";
       cin >> x;
       unsigned int y;
       cout << "Input y: ";
       cin >> y;

       cout << "Binary form of " << x << " : ";
       printbits(x);
       cout << "\nBinary form of " << y << " : ";
       printbits(y);

       unsigned int p;
       cout << "\n\nInput p: "; // Номер біта, починаючи з якого міняємо біти
       cin >> p;
       unsigned int n;        // Кількість бітів, які потрібно замінити
       cout << "Input n: ";
       cin >> n;
       if (p >= 0 && n > 0)
       {
       unsigned int number_x = x >> (p + n);  // Зсуваємо введене число на n + p бітів

       unsigned int musk = 1;
       for (int i = 0; i < n - 1; i++) // Створюємо число, внутрішнім представленням якого є n одиниць
           musk = musk * 2 + 1;

       unsigned int number_y = musk & ~y; // Інвертуємо праві біти числа Y
       for (int i = 0; i < p; i++)
           number_y = number_y << 1;

       number_x = number_x << (n + p); // Незмінні біти числа
       number_x += number_y;           // Інвертовані біти числа Y

       musk = 1;
       for (int i = 0; i < p - 1; i++)     // Створюємо число, внутрішнім представленням якого є p одиниць
           musk = musk * 2 + 1;
       number_x = number_x + (x & musk);                 // Незмінні біти
       cout << "\nnumber = " << number_x;
       cout << "\nBinary form of number: "; // Двійкове представлення
       printbits(number_x);
       cout << "" << endl;
       }
    else
    cout << "incorrect input";

    
       return 0;
   }