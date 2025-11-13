#include <bits/stdc++.h>
using namespace std;

bool balance3(int i,
              int sum1, int sum2, int sum3,
              const vector<int>& vals, int T) {
    int n = vals.size();
    int target = T / 3;

    if (i == n) {
        return (sum1 == target && sum2 == target && sum3 == target);
    }
    if (sum1 > target || sum2 > target || sum3 > target)
        return false;
    if (balance3(i + 1, sum1 + vals[i], sum2, sum3, vals, T))
        return true;
    if (balance3(i + 1, sum1, sum2 + vals[i], sum3, vals, T))
        return true;
    if (balance3(i + 1, sum1, sum2, sum3 + vals[i], vals, T))
        return true;

    return false;
}

int main() {
    vector<int> values = {10, 9, 8, 7};
    int T = 34;

    // For 3 equal teams, total must be divisible by 3
    if (T % 3 != 0) {
        cout << "No equal 3-partition possible (sum not divisible by 3).\n";
        return 0;
    }
    bool ok = balance3(0, 0, 0, 0, values, T);

    if (ok) {
        cout << "Equal 3-partition found!\n";
    } else {
        cout << "No equal 3-partition possible.\n";
    }
    return 0;
}
