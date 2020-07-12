#include<stdio.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

string longest(string s) {
    int n = s.size();
    if(n==0){
            return "";
        }
    bool table[n][n];
    memset(table, 0, sizeof(table));
    int longest = 1;
    int start = 0;
    for (int i = 0; i < n; i++) {
        table[i][i] = 1;
    }

    for (int k = 0; k < n-1; k++) {
        if (s[k] == s[k + 1]) {
            table[k][k + 1] = 1;
            start = k;
            longest = 2;
        }
    }
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < n-i+1; j++) {
            int p = j + i - 1;
            if (table[j+1][p-1] && s[j]==s[p]) {
                table[j][p] = 1;
                if(longest<i){
                start = j;
                longest = i;
            }
          }
        }
    }
    string s1=s.substr(start,longest);
    return s1;

}

int main() {
    string s = "dhjafhdasjghjdasASHCJVXAVCXSACVSDaghjgsdahgjfdgshfdghfddfhfgdhdfdgsgfdsjahfgaskjfdgfdsajhgasfhdfhj";
    int i = s.length();
    string str = longest(s);
    cout<<str<<endl;
    return 0;
}
