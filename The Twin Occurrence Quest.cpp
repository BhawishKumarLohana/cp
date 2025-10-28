#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int queryIdx = 0; queryIdx < q; ++queryIdx) {
        int target;
        cin >> target;

        // Find first position where target could be inserted
        auto lowerIt = lower_bound(arr.begin(), arr.end(), target);
        int lowerIndex = lowerIt - arr.begin();

        // If target not found
        if (lowerIndex == n || arr[lowerIndex] != target) {
            cout << "-1 -1\n";
            continue;
        }

        // Find first position greater than target 
        auto upperIt = upper_bound(arr.begin(), arr.end(), target);
        int upperIndex = upperIt - arr.begin();
        int firstPos = lowerIndex + 1;
        int lastPos = upperIndex;

        cout << firstPos << " " << lastPos << "\n";
    }
}