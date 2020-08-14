#include<stdio.h>
#include<iostream>
#include<vector>
//#define candy_packs 5
using namespace std;
bool checkbit(int i, int j) {
	if (((i >> j) & 1) == 1)
		return true;
	else return false;
}

int main() {
	vector<int> ar= { 10,20, 20, 30, 20, 10, 10 };
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		int ones = 0;
		int zeros = 0;
		for (int j = 0; j < ar.size(); j++) {
			if (checkbit(ar[j], i))
				ones++;
			else zeros++;
		}
		if (ones % 3 == 1) {
			ans += (1 << i);
		}
	}
	cout << ans;

	return 0;
}
