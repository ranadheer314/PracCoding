#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXINT 9999999999;
#include<vector>
#include<unordered_set>
using namespace std;

int arrangeCoins(int n) {
	int count = 0;
	long long int p1 = n;
	long long int p2 = ((-1) + sqrt(1 + 8 * p1)) / 2;

	for (int i = 1; i <= n; i++) {
		if(n>200){
			cout<<"too big to print";
			break;
		}
		for (int j = 0; j < i; j++) {
			cout << "*" << " ";
		}
		count++;
		n = n - i;
		cout << endl;
		if (n < i) {
			for (int j = 0; j < n; j++) {
				cout << "*" << " ";
			}
		}
	}
	return p2;
}


int main() {
	vector<int> nums= {7, 2, 5, 10, 8};
	int m = 2500000;

	int f=arrangeCoins(m);
	cout << "\nsize of the staircase is "<<f << endl;

	return 0;
}
