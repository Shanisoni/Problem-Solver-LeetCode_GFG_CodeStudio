#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

string isSubset(int a1[], int a2[], int n, int m) {
      unordered_map<int, int> frequency;

    // Count the frequency of each element in the first array
    for (int i = 0; i < n; i++) {
        frequency[a1[i]]++;
    }

    // Check if all elements of the second array are present in the first array
    for (int i = 0; i < m; i++) {
        if (frequency.find(a2[i]) == frequency.end() || frequency[a2[i]] == 0) {
            return "No";
        }
        frequency[a2[i]]--;
    }