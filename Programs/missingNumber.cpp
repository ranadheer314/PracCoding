#include<stdio.h>
#include<time.h>
#include<iostream>
#include<list>
#include<iterator>
#define SIZE 10
using namespace std;

int findproduct(int a) {
	int pro = 0;
	for (int i = 0; i < a; i++) {
		pro += i;
	}
	return pro;
}



int main() {
	int a[] = { 9,6,4,2,3,5,7,0,1 };
	int size,sum;
	size = sizeof(a) / sizeof(a[0]);
	int val=findproduct(size+1);
	for (int i = 0; i < size; i++) {
		val = val-a[i];
	}
	cout << val;
	return 0;
}
