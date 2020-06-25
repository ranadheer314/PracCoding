#include<stdio.h>
#include<iostream>
#define MAXINT 9999999999;
#include<vector>
using namespace std;
bool areDistinct(string str, int i, int j) {
	vector<bool> visited(26);
	for (int k = i; k <= j; k++) {
		if (visited[str[k] - 'a'] == true)
			return false;
		visited[str[k] - 'a'] = true;
	}
	return true;
}

void testing(vector<int>& nums) {
	cout << nums.size();
}
int main() {

	string s = "abcdef";
	vector<bool> visited(26);
	//cout << s[2] - 'a';
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(59);
	testing(num);

	return 0;
}
