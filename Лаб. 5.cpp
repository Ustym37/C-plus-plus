#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

//    struct Good
//    {
//	string Good;
//	string Weight;
//	double Price;
//    };
//#define Number_of_goods 10
//Good Good_Array[Number_of_goods];

//int main()
//{
//	//1
//    ifstream fin;  
//    fin.open("numbers.txt");
//    
//    int number; 
//    int product = 1;
//    cout << "Task 1\nNumbers in txt-document:\n";
//    while(!fin.eof())
//    {
//    	fin >> number;
//    	cout << number << endl;
//    	product *= number;
//    }
//    fin.close();
//    cout << "\nProduct of numbers:   " << product << "\n\n";
//    
    //3
//    cout << "Task 3\nWrite words to file:\n";
//    ofstream fout; 
//    fout.open("words.txt", ofstream::out | ofstream::trunc);
//    
//	string word; 
//    for(int i = 0; i < 4; i++)
//    {
//		cout << "Input word: ";
//    	cin >> word;
//    	if (i % 2 == 0)      
//    	fout << word << endl;
//	}
//    fout.close();
//    
// Task 4.
//    cout << "\nTask 4\n";
//    cout << "Fill in the array\n";
//    for( int i = 0; i < Number_of_goods; i++ )
//    {
//    	cout << "Good " << i+1 << " name:      ";
//    	cin >> Good_Array[i].Good;
//    	cout << "Good " << i+1 << " weight:    ";       //Заповнення масиву товарами, значеннями їх маси та ціною
//    	cin >> Good_Array[i].Weight;
//    	cout << "Price for " << i+1 << " good: ";
//    	cin >> Good_Array[i].Price;
//    }
//    
////    fout1.open("stock.txt", ofstream::out | ofstream::trunc);
////	for( int i = 0; i < Number_of_goods; i++ )
////    {
////		fout1 << Good_Array[i].Good << Good_Array[i].Weight << Good_Array[i].Price;  //Запис даних у файл
////	}
////    fout1.close();
//    
//    cout << "=======================================" << endl;
//    cout << "Good           Waight         Price" << endl;
//    cout << "=======================================" << endl;
//    for( int i = 0; i < Number_of_goods; i++ )
//    {
//    	cout.width(14);
//		cout << left << Good_Array[i].Good;
//		cout << " ";                                                                          //Виведення таблиці
//		cout.width(5);
//		cout << left << Good_Array[i].Weight;
//		cout.width(9);
//		cout << left << "Kg";
//		cout << " ";
//		cout << setprecision(2) << fixed << Good_Array[i].Price << " Usd" << endl;
//	}
//	cout << "=======================================" << endl;
//	
//	ofstream fout1; 
//	fout1.open("stock.txt", ofstream::out | ofstream::trunc);
//	fout1 << "\n=======================================" << endl;
//    fout1 << "Good           Waight         Price" << endl;
//    fout1 << "=======================================" << endl;
//    for( int i = 0; i < Number_of_goods; i++ )
//    {
//    	fout1.width(14);
//		fout1 << left << Good_Array[i].Good;                                                            // Виведення даних із файлу
//		fout1 << " ";
//		fout1.width(5);
//		fout1 << left << Good_Array[i].Weight;
//	    fout1.width(9);
//		fout1 << left << "Kg";
//		fout1 << " ";
//		fout1 << setprecision(2) << fixed << Good_Array[i].Price << " Usd" << endl;
//	}
//	fout1 << "=======================================" << endl;
//	fout1.close();
//    cout << endl;
    
    
//    struct Age
//{
//	int year;
//	int month;
//	int day;
//};
//
//string calculation(int year1, int month1, int day1, int year2, int month2, int day2)
//{
//	string name;
//	if (year1 > year2)
//		name = "Person_2";
//	else if (year1 < year2)
//		name = "Person_1";
//	else if (year1 == year2)
//	{
//		if (month1 > month2)
//			name = "Person2";
//		else if (month1 < month2)
//			name = "Person1";
//		else if (month1 == month2)
//		{
//			if (day1 > day2)
//				name = "Person_2";
//			else if (day1 < day2)
//				name = "Person_1";
//		}
//	}
//	else
//		name = "0";
//
//	return name;
//}
//
//int main()
//{
//	Age person_1;
//	cout << "Input date of born of person 1!\n\n";
//    cout << "Year ";
//	cin >> person_1.year;
//	cout << "Month ";
//	cin >> person_1.month;
//	cout << "Day ";
//	cin >> person_1.day;
//
//	cout << endl;
//
//	Age person_2;
//	cout << "Input date of born of person 2!\n\n";
//	cout << "Year ";
//	cin >> person_2.year;
//	cout << "Month ";
//	cin >> person_2.month;
//	cout << "Day ";
//	cin >> person_2.day;
//
//	cout << endl;
//	string name;
//	name = calculation(person_1.year, person_1.month, person_1.day, person_2.year, person_2.month, person_2.day);
//	if (name != "0")
//		cout << name << " was born first\n";
//	else
//		cout << "Persons are the same age\n" << endl;
//
//	return 0;
//}
    
    int main()
{
    cout << "\nWrite symbols to file:\n";
    ofstream fout;
    fout.open("symbols.txt", ofstream::out | ofstream::trunc);            //Заповнюємо символами перший файл
    string symbol;           
    cout << "Input symbols:\n";
    for (int i = 0; i < 8; i++)
    {
        cin >> symbol;
        fout << symbol << endl;
    }
    fout.close();

    ifstream fin;
    fin.open("symbols.txt");
    string symbol1;
    cout << "\nSymbols in file:\n";                           //Зчитуємо символи
    while (!fin.eof())  
    {
        fin >> symbol1;
        cout << symbol1 << endl;
    }
    fin.close();

    ifstream fin1;
    fin1.open("symbols.txt");
    string symbols_array[8];
    symbol1 = "0";
    for (int i = 7; i >= 0; i--)                           //Заповнюємо масив символами у зворотньому порядку
    { 
          fin1 >> symbols_array[i];
    }
    fin1.close();

    ofstream fout1;
    fout1.open("symbols1.txt", ofstream::out | ofstream::trunc);   //Записуємо елементи масива у файл
    for (int i = 0; i < 8; i++)
    {
        fout1 << symbols_array[i] << endl;
    }
    fout1.close();

    ifstream fin2;
    fin2.open("symbols1.txt");
    symbol1 = "0";
    cout << "\nSymbols in new file:\n";                           //Виводимо вміст файлу
    while (!fin2.eof())
    {
        fin2 >> symbol1;
        cout << symbol1 << endl;
    }
    fin1.close();

    return 0;
}
    
