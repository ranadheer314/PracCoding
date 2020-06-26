#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAXINT 9999999999;
#include<vector>
#include<unordered_set>
using namespace std;

vector<vector<int>> testing(vector<int>& nums) {
	vector<vector<int>> store;
	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		if (i != 0 && nums[i] == nums[i - 1]) continue;
		int j = i + 1;
		int k = nums.size() - 1;
		while (j < k) {
			if (nums[i] + nums[j] + nums[k] == 0) {
				store.push_back({ nums[i],nums[j],nums[k] });
				j++;
				while (j < k && nums[j] == nums[j - 1]) ++j;
			}
			else if (nums[i] + nums[j] + nums[k] < 0) {
				++j;
			}
			else {
				--k;
			}
		}
	}
	return store;
}

int main() {

	vector<int> num; //-1, 0, 1, 2, -1, -4
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(-4);
	vector<vector<int>> store = testing(num);
	for (int i = 0; i < store.size(); i++) {
		cout << "[";
		for (auto j = store[i].begin(); j != store[i].end(); j++) {
			cout << *j << ",";
		}
		cout << "]" << endl;
	}





	return 0;
}
