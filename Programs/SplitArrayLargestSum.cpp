#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

bool check(int mid, vector<int>& A, int m, int size) {
	int count = 0, sum=0;
	for (auto i : A) {
		if (i > mid) {
			return false;
		}
		sum += i;
		if (sum > mid) {
			count++;
			sum = i;
		}
	}
	count++;
	if (count <= m) {
		return true;
	}
	return false;
}
int minSumsubarray(vector<int>& A, int m, int size) {
	int sum = 0,mid;
	int start = 1;
	int end=0; 
	int answer = 0;
	for (auto i : A) {
		end += i;
	}

	while (start <= end) {
		mid = (start + end) / 2;
		//cout << mid << endl;
		if (check(mid, A, m, size)) {
			answer = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return answer;
}


int main() {
	vector<int> A = { 7,2,5,10,8 };
	int m = 2;
	int size = 5;
	//cout << size << endl;
	int min_sum = minSumsubarray(A, m, size);
	printf("%i",min_sum);

	return 0;
}
