#include<stdio.h>
#include<time.h>
#include<iostream>
#define SIZE 16
#define MAX 55
using namespace std;

void print(int A[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout<<A[i][j]<<" ";
		}
		cout << endl;
	}
}

void protection(int A[SIZE][SIZE],int p,int q) {
	for (int i = 0; i < SIZE; i++) {
		if (A[p][i] >= 0 && A[p][i] != MAX)
			A[p][i]++;
		if (A[i][q] >= 0 && A[i][q] != MAX)
			A[i][q]++;
		if (A[p + i][q + i] >= 0 && (p + i) >= 0 && (q + i) >= 0 && (p + i) < SIZE && (q + i) < SIZE && A[p + i][q + i]!= MAX) {
			//cout << p + i << "," << q + i << endl;
			A[p + i][q + i]++;
		}
		if (A[p - i][q - i] >= 0 && (p - i) >= 0 && (q - i) >= 0 && (p - i) < SIZE && (q - i) < SIZE && A[p - i][q - i] != MAX) {
			//cout << p - i << "," << q - i << endl;
			A[p - i][q - i]++;
		}
		if (A[p - i][q + i] >= 0 && (p - i) >= 0 && (q + i) >= 0 && (p - i) < SIZE && (q + i) < SIZE && A[p - i][q + i] != MAX) {
			//cout << p - i << "," << q + i << endl;
			A[p - i][q + i]++;
		}
		if (A[p + i][q - i] >= 0 && (p + i) >= 0 && (q - i) >= 0 && (p + i) < SIZE && (q - i) < SIZE && A[p + i][q - i] != MAX) {
			//cout << p + i << "," << q - i << endl;
			A[p + i][q - i]++;
		}
	}
}

void removeprotection(int A[SIZE][SIZE], int p, int q) {
	for (int i = 0; i < SIZE; i++) {
		if (A[p][i]>0 && A[p][i] != MAX)
			A[p][i]--;
		if (A[i][q]>0 && A[i][q] != MAX)
			A[i][q]--;
		if (A[p + i][q + i]>0 && (p + i) >= 0 && (q + i) >= 0 && (p + i) < SIZE && (q + i) < SIZE && A[p + i][q + i] != MAX) {
			//cout << p + i << "," << q + i << endl;
			A[p + i][q + i]--;
		}
		if (A[p - i][q - i]>0 && (p - i) >= 0 && (q - i) >= 0 && (p - i) < SIZE && (q - i) < SIZE && A[p - i][q - i] != MAX) {
			//cout << p - i << "," << q - i << endl;
			A[p - i][q - i]--;
		}
		if (A[p - i][q + i]>0 && (p - i) >= 0 && (q + i) >= 0 && (p - i) < SIZE && (q + i) < SIZE && A[p - i][q + i] != MAX) {
			//cout << p - i << "," << q + i << endl;
			A[p - i][q + i]--;
		}
		if (A[p + i][q - i]>0 && (p + i) >= 0 && (q - i) >= 0 && (p + i) < SIZE && (q - i) < SIZE && A[p + i][q - i] != MAX) {
			//cout << p + i << "," << q - i << endl;
			A[p + i][q - i]--;
		}
	}
}

int placeQueens(int A[SIZE][SIZE], int p, int q,int queens) {
	if (queens == 0) {
		return 1;
	}
	for (int i = p ; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (A[i][j]== 0)
			{
				A[i][j] = MAX;
				protection(A, i, j);
				queens = queens - 1;
				if (placeQueens(A, i + 1, j, queens) == 1) {
					return 1;
				}
				else {
					A[i][j] = 0;
					removeprotection(A, i, j);
					queens = queens + 1;
				}
			}
		}
	}
}
void clean(int A[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (A[i][j] == MAX)
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}
	}
}

int main() {
	int A[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			A[i][j] = 0;
		}
	}
	int queens = SIZE;
	/*print(A);
	cout << "---------------" << endl;

	int p = 5, q = 7;
	A[p][q] = MAX;
	protection(A, p, q);
	print(A);
	cout << "---------------" << endl;
	A[6][5] = MAX;
	protection(A, 6, 5);
	print(A);
	cout << "---------------" << endl;

	A[p][q] = 0;
	removeprotection(A, p, q);
	print(A);*/

	//print(A);
	int p = 0,q = 0;
	int success=placeQueens(A, p, q,queens);
	if (success == 1) {
		clean(A);
		print(A);
	}
	else {
		cout << "something is wrong" << endl;
	}
	cout << "---------------" << endl;
	print(A);
	return 0;
}
