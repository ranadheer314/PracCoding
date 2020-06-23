#include<stdio.h>
#include<iostream>
#define MAXINT 9999999999;
using namespace std;

int* preprocess(char s[], int A[], int l) {
	int j = 0;
	A[0] = 0;

	for (int i = 1; i < l; i++) {
		while (1) {
			if (s[i] == s[j]) {
				A[i] = j + 1;
				j++;
				break;
			}
			else {
				if (j == 0) {
					break;
				}
				j = A[j - 1];
			}
		}
	}
	return A;
}

void pattern(char txt[],char s[],int A[],int size,int sizep) {
	int j = 0, i = 0;

	while (i < size) {
		if (txt[i] == s[j]) {
			i++;
			if (j == sizep - 1) {
				cout << "Pattern found at :" << i - j << endl;
				j = A[j - 1];
			}
			else
				j++;

		}
		else {
			if (j > 0) {
				j = A[j - 1];
			}
			if (j == 0) {
				i++;
			}
		}

	}
	/*
	for (int i = 0; i < size; i++) {
		if (txt[i] == s[j]) {
			if (j == sizep-1) {
				cout << "pattern found at: " << i - j << endl;
				j = A[j - 1];
			}
			else
				j++;
		}
		else {
			if (j>0) {
				j = A[j-1];

			}

		}
	}*/
}

int main() {
	char txt[] = "AABAACAADAABAABA";
	char s[] ="AABA";
	int size = sizeof(txt)/sizeof(txt[0]);
	int l = sizeof(s) / sizeof(s[0]);
	size = size - 1;
	l=l-1;
	int A[4];

	/*for (int i = 0; i < size; i++) {
		cout << txt[i] << " ";
	}
	cout << endl;*/

	//cout << size << "\t" << l << endl;

	for (int i = 0; i < l; i++) {
		A[i] = 0;
	}
	preprocess(s, A,l);
	/*for (int i = 0; i < l; i++) {
		printf("%i", A[i]);
	}*/
	pattern(txt, s,A,size,l);
	return 0;
}
