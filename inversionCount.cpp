#include <bits/stdc++.h>

using namespace std;
//long ans=0;

vector<string> split_string(string);

// Complete the countInversions function below.


long count(int ar[], int low, int high,long ans) {

    int mid = (low + high) / 2;
    int i=0, j=0, k=low;

    int n1 = mid - low + 1;
    int n2 = high - mid;
    int tc = n1;
    int *arr1 = new int[n1];
    int* arr2 = new int[n2];

    for (int p = 0; p < n1; p++) {
        arr1[p] = ar[low + p];
    }
    for (int p = 0; p < n2; p++) {
        arr2[p] = ar[mid + 1+p];
    }

    while (i < n1 && j < n2) {

        if (arr1[i] > arr2[j]) {
            ar[k] = arr2[j];
            ans+=tc;
            j++;
            k++;
        }
        else {
            ar[k] = arr1[i];
            tc--;
            i++;
            k++;
        }

    }
    while (i < n1) {
        ar[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        ar[k] = arr2[j];
        j++;
        k++;
    }
    return ans;

}


long countInv(int load[],int low,int high,long ans) {
    if (low == high) return ans;

    else {
        int mid = (low + high) / 2;
        long c1=countInv(load, low, mid,ans);
        long c2=countInv(load, mid + 1, high,ans);
        ans=c1+c2+count(load, low, high,ans);
    }
    return ans;


}


long countInversions(vector<int> arr) {
    int siz = arr.size();

    int ar[siz];
    for(int i=0;i<siz;i++){
        ar[i]=arr[i];
    }
    long ans=0;

    ans=countInv(ar, 0, siz - 1,ans);

    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
