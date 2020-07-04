#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXINT 9999999999;
#include<vector>
#include<unordered_set>
using namespace std;


int main() {
	int testCases;
	cin >> testCases;
	int Cnum;
	while (testCases) {
		cin >> Cnum;
		if (!(Cnum % 2)) {
			cout << Cnum / 2<<endl;
		}
		else {
			cout << Cnum / 2 + 1<<endl;
		}
		testCases--;
	}


	return 0;
}
