// hollowdiamonds.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// hollowdiamonds.cpp : Defines the entry point for the console application.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int test_cases;
	cin >> test_cases;
	int d = test_cases;
	while (test_cases) {
		int number;
		cin >> number;
		printf("Case #%d:\n", d + 1 - test_cases);
		for (int i = 0; i < number / 2; i++) {
			int pos1 = number / 2 - i;
			int pos2 = number / 2 + i;
			for (int j = 0; j < number; j++) {
				if ((j == pos1) || (j == pos2))
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
		for (int i1 = number / 2; i1 >= 0; i1--) {
			int pos3 = number / 2 - i1;
			int pos4 = number / 2 + i1;
			for (int j2 = 0; j2<number; j2++) {
				if ((j2 == pos3) || (j2 == pos4))
					printf("*");
				else
					printf(" ");
			}
			printf("\n");

		}
		/*for (int i2 = number / 2; i2 >= 0; i2++) {
		printf("*");
		for (int j2 = 0; j2 <= i2; j2++)
		printf(" ");
		printf("*\n");
		}*/
		test_cases--;
	}
	return 0;
}

