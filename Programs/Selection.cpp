// basic_DS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int a[] = {1,78,256,5,23,0,16,859,23,2};
    int size = sizeof(a) / sizeof(a[0]);
    cout << size << endl;
    int temp;
    for(int i=0;i<size;i++){
        int m = i;
        for (int j = i; j < size; j++) {
            if (a[m] >= a[j]) {
                m = j;
            }
        }
        temp = a[i];
        a[i] = a[m];
        a[m] = temp;
    }
    for (int k = 0; k < size; k++)
        cout << a[k] << "\t";
 
    cout << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
