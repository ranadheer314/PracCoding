
#include <iostream>
#include<vector>

using namespace std;

#define n 3

int ans = 0;

bool checkMS(vector<vector<int>> ar) {
    cout << 1 << endl;
    int s = ar.size();
    int sum = 0;

    for (int i = s-1; i >=0; i--) {
        sum += ar[s - i - 1][i];
    }
    //cout << sum << endl;

    for (int i = 0; i < s; i++) {
        int temp = 0;
        for (int j = 0; j < s; j++) {
            temp += ar[i][j];
        }
        if (temp != sum)
            return false;
    }

    for (int i = 0; i < s; i++) {
        int temp = 0;
        for (int j = 0; j < s; j++) {
            temp += ar[j][i];
        }
        if (temp != sum)
            return false;
    }

    int temp = 0;
    for (int i = 0; i < s; i++) {
        temp += ar[i][i];

    }
    if (temp != sum)
        return false;

    return true;

}

int cost(vector<vector<int>> ar, vector<vector<int>> ip) {
    int val = 0;

    for (int i = 0; i < ar.size(); i++) {
        for (int j = 0; j < ar.size(); j++) {
            val =val+ abs(ar[i][j] - ip[i][j]);
        }
    }

    return val;
}
void fillMS(vector<vector<int>> ar,vector<vector<int>> ip, bool taken[],int i,int j,int s) {

    if (i == s - 1 && j == s - 1) {

        if (checkMS(ar))
            ans = min(ans, cost(ar, ip));
        return;

    }
    else {
        for (int k = 1; k < 10; k++) {
            //cout << taken[k] << endl;
            if (taken[k] == false) {

                ar[i][j] = k ;
                taken[k] = true;
                if (j < s - 1)
                    fillMS(ar, ip, taken, i, j++, s);
                else
                    fillMS(ar, ip, taken, i++, j, s);
                taken[k] = false;
            }

        }
    }

}


void printvector(vector<vector<int>> a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> ar(3),ip(3),test(3);
    int load[n][n] = { 5,3,4,1,5,8,6,4,2 };
    int load2[n][n] = { 8,3,4,1,5,9,6,7,2 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ar[i].push_back(0);
            ip[i].push_back(load[i][j]);
            test[i].push_back(load2[i][j]);
        }
    }



    bool taken[10];

    for (int i = 0; i < 10;  i++) {
        taken[i]=false;
    }

    //cout << checkMS(test);


    fillMS(ar, ip,taken, 0, 0, n*n);

    cout << ans << endl;

    return 0;
}
