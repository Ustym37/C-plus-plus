#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//int get_min_element(char* p1, int lenght)
//{
//    int min = *p1;
//
//    for (int i = 1; i < lenght; i++)
//    {
//        if (p1[i] < min) min = p1[i];
//    }
//    return min;
//}
//
////void get_min_element(char* p1, int lenght, char* p_min)
////{
////    int min = *p1;
////
////    for (int i = 1; i < lenght; i++)
////    {
////        if (p1[i] < min) min = p1[i];
////    }
////     *p_min = min;
////    }
//
int main()
{
//    srand(time(0));
//    // 1
//    char* p;
//
//    // 2
//    char val;
//    p = &val;
//
//    // 3
//    val = 65;
//    cout << "Task 3\n Val = " << val << " Pointer = " << hex << p << " *Pointer = " << *p << endl;
//    cout << endl;
//
//    // 4
//    p = new char;
//    *p = 65;
//    cout << "Task 4\n Val = " << val << " Pointer = " << hex << p << " *Pointer = " << *p << endl;
//    cout << endl;
//
//    //5
//    cout << "Task 5\n";
//    delete p;
//    cout << "Task 5\n Val = " << val << " Pointer = " << hex << p << " *Pointer = " << *p << endl;
//    cout << endl;
//
//    //6
//    cout << "Task 6\n";
//    p = (char*)malloc(10 * sizeof(char));
//    for (int i = 0; i < 10; i++)
//    {
//        *(p + i) = 10.0 + char(i);
//        for (int i = 0; i < 10; i++)
//            cout << "element: " << p[i] << "    address: " << p << endl;
//    }
//    free(p);
//    cout << endl;
//
//    //6
////    p = (char*)malloc(sizeof(char) * 10);
////
////    for (int i = 0; i < 10; i++)
////	  p[i] = i;
////
////    for (int i = 0; i < 10; i++)
////	  cout << "element: " p[i] << "    address: " << p << "\n";
////
////    free(p);
//
//    //7
//    cout << "Task 7\n";
//    p = new char[10];
//
//    for (int i = 0; i < 10; i++)
//        p[i] = i;
//
//    for (int i = 0; i < 10; i++)
//        cout << "element: " << p[i] << "    address: " << p << endl;
//
//    delete[] p;
//    cout << endl;
//
//    //8
//    cout << "Task 8\n";
//    char** p_2dim = new char* [3];
//    p_2dim[0] = new char[3];
//    p_2dim[1] = new char[3];
//    p_2dim[2] = new char[3];
//
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            p_2dim[i][j] = rand() % 40;
//        }
//    }
//
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            cout << p_2dim[i][j] << endl;
//        }
//    }
//    cout << endl;
//
//    delete[] p_2dim[0];
//    delete[] p_2dim[1];
//    delete[] p_2dim[2];
//    delete[] p_2dim;
//    cout << endl;
//
//    //9
//    cout << "Task 3\n";
//    int lenght;
//    cout << "Input array value: ";
//    cin >> lenght;
//
//    char* p1 = new char[lenght];
//
//    for (int i = 0; i < lenght; i++)
//    {
//        cout << "  " << i + 1 << "  : ";
//        cin >> p1[i];
//        cout << endl;
//    }
//    cout << " : " << get_min_element(p1, lenght);
//
    //delete[] p1;

cout << "Homework\n";
int lenght;
cout << "Input array value: ";
cin >> lenght;
int* array = new int[lenght];
for (int i = 0; i < lenght; i++)
{
    cin >> array[i];
}
cout << "Elements: ";
int element;
for (int i = 0; i < lenght; i++)
{
    bool uniq = true;
    element = array[i];
    for (int j = 0; j < lenght; j++)
    {
        if (element == array[j] && i != j)
            uniq = false;
    }
    if (uniq == true)
        cout << element << "  ";
}

    return 0;
}