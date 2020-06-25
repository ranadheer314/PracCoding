#include<stdio.h>
#include<iostream>
#define MAXINT 9999999999;
#include<vector>
using namespace std;

int testing(vector<int>& nums) {
	auto j = nums[0];
	for (auto i=nums.begin(); i!= nums.end(); ++i) {
		if (i == nums.begin()) {
			continue;
		}
		if (*i == j) {
			nums.erase(i);
		}
		else
			j = *i;
	}
	return nums.size();
}
int main() {

	string s = "abcdef";
	vector<bool> visited(26);
	//cout << s[2] - 'a';
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(2);
	num.push_back(29);
	int len=testing(num);
	printf("%i", len);

	return 0;
}
