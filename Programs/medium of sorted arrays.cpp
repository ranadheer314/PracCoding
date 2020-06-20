#include<stdio.h>
#include<iostream>
#define MAXINT 9999999999;
using namespace std;

/*int mid(int A[],int s) {
	return s%2==0 ? A[(s / 2) - 1]: A[(int)(s / 2)];
}*/

int mid(int A[], int s) {
	return s % 2 == 0 ? ((s / 2) - 1) : ((int)(s / 2));
}

/*int median(int ar1[], int ar2[],int s1,int s2,int st1,int end2) {
	int m1 = mid(ar1, s1);
	int m2 = mid(ar2, s2);

	if (m1 < m2) {
		median(ar1, ar2,m1,m2,st1,end2);
	}

}*/

/*--------------------------------------------------------------------

even ---- size=8
		  elements=0....7 |||| indexes=0,1,2,3,4,5,6,7,8
		  mid=size/2 ==== 4 i.e 4  is in the middle
		  mid=size-1/2=== 3 i.e 3 is in the middle

odd----- size=9
		 elements=0....8 |||| indexes=0,1,2,3,4,5,6,7,8,9
		 mid=size/2 ==== 4 i.e 4 is

--------------------------------------------------------------------*/

bool condition(int A1[],int A2[],int pos1,int pos2) {
	if ((A1[pos1] <= A2[pos2 + 1]) && (A2[pos2] <= A1[pos1 + 1]))
		return true;
	else return false;
}

float medium(int A1[], int A2[], int part1, int part2,string str) {
	if (str == "e") {
		float max = A1[part1] > A2[part2] ? A1[part1] : A2[part2];
		float min = A1[part1 + 1] > A2[part2 + 1] ? A2[part2 + 1] : A1[part1 + 1];
		//cout << "11" << endl;
		//cout << max min << endl;
		//cout << (max + min) / 2 << endl;
		return (max + min) / 2;
	}
	else if (str == "o") {
		//cout << "12" << endl;
		return  A1[part1] > A2[part2] ? A1[part1] : A2[part2];
	}
	else
		return MAXINT;
}


float findit(int A1[],int A2[],int size1,int size2) {
	int total = size1 + size2;
	int start = 0;
	int end = size1-1;
	int pos1 = (start+end)/2;
	int pos2 = ((total + 1) / 2 )- (pos1 + 1) - 1;
	//cout <<total<<"\t"<< pos1 << "\t" << pos2 << endl;
	while (!condition(A1, A2, pos1, pos2)) {
		if (A1[pos1] > A2[pos2 + 1]) {
			//start = 0;
			pos1 = (start + pos1) / 2;
			pos2= (total + 1) / 2 - (pos1 + 1) - 1;
			//cout << "1" << endl;

		}
		else if (A2[pos2] < A1[pos1 + 1]) {
			start = pos1 + 1;
			pos1 = (start + pos1) / 2;
			pos2 = (total + 1) / 2 - (pos1 + 1) - 1;
			cout << "2" << endl;
		}
	}

	string str;
	if (total % 2 == 0)
		str = "e";
	else
		str = "o";

	float med = medium(A1, A2, pos1, pos2, str);
	//cout << med;
	return med;
}


int main() {
	int ar1[] = { -5,-4, 3, 6, 12, 15};
	int ar2[] = { -12, -10, -6, -3,2, 4, 10 };
	int s1 = sizeof(ar1) / sizeof(ar1[0]);
	int s2 = sizeof(ar2) / sizeof(ar2[0]);

	float medium = findit(ar1, ar2, s1, s2);
	//cout << medium<<endl ;
	//cout << s1 << s2;
	printf("%f", medium);

	return 0;
}
