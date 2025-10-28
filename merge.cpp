#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, match, mismatch, gap;
    string a, b;
    cin >> n >> a >> m >> b >> match >> mismatch >> gap;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) dp[i][0] = gap * i * i;
    for(int j = 1; j <= m; ++j) dp[0][j] = gap * j * j;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            // Match/Mismatch
            if(a[i-1] == b[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + match);
            else
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + mismatch);

            // Maximal gaps in a
            for (int k = 1; k <= i; ++k)
                dp[i][j] = max(dp[i][j], dp[i-k][j] + gap * k * k);
            // Maximal gaps in b
            for (int k = 1; k <= j; ++k)
                dp[i][j] = max(dp[i][j], dp[i][j-k] + gap * k * k);
        }
    }
    cout << dp[n][m] << endl;
}