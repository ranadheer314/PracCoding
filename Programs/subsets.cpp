#include<stdio.h>
#include<iostream>
#include<vector>
//#define candy_packs 5
using namespace std;
vector<vector<int>> subsetsUtil(vector<int> &ar, vector<int> &subset, vector<vector<int>> &res, int i) {
	for (int j = i; j < ar.size(); j++) {
		subset.push_back(ar[j]);
		res.push_back(subset);
		subsetsUtil(ar, subset, res, j + 1);
		subset.pop_back();
	}
	return res;
}
vector<vector<int>> subsets(vector<int> &v) {
	vector<int> subset;
	vector<vector<int>> res;
	int index = 0;
	subsetsUtil(v, subset, res, index);
	return res;

}

int main() {
	vector<int> ar = { 1,2,3 };

	vector<vector<int>> res = subsets(ar);
	for (int i = 0; i< res.size(); i++) {
		for (int j = 0; j < res[i].size();j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;

	}

	return 0;
}
