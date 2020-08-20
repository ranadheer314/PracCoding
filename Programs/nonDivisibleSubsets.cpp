#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {
    int cnt[k];
    std::memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] % k]++;
    }
    int siz = 0;
    for (int i = 1; i <= k / 2; i++) {
        siz += max(cnt[i], cnt[k - i]);
    }
    if (cnt[0]) {
        siz += 1;
    }

    if (k % 2 == 0 && cnt[k / 2] != 0) {
        siz = siz + 1 - cnt[k / 2];
    }
    return siz;

}

int main() {
    vector<int> A = { 278 ,576, 496, 727 ,410 ,124, 338 ,149 ,209 ,702 ,282 ,718, 771, 575, 436 };
    int k = 7;
    nonDivisibleSubset(7, A);



    return 0;
}
