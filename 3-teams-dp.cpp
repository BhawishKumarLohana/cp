#include <bits/stdc++.h>
using namespace std;


bool balance3_dp(const vector<int>& vals, int T) {
    int n = vals.size();
    int target = T / 3;
    vector<vector<vector<bool>>> dp(
        target + 1,
        vector<vector<bool>>(target + 1, vector<bool>(target + 1, false))
    );
    dp[0][0][0] = true;
    for (int v : vals) {
        vector<vector<vector<bool>>> newdp = dp;
        for (int s1 = 0; s1 <= target; s1++) {
            for (int s2 = 0; s2 <= target; s2++) {
                for (int s3 = 0; s3 <= target; s3++) {
                    if (!dp[s1][s2][s3]) continue;
                    if (s1 + v <= target)
                        newdp[s1 + v][s2][s3] = true;
                    if (s2 + v <= target)
                        newdp[s1][s2 + v][s3] = true;
                    if (s3 + v <= target)
                        newdp[s1][s2][s3 + v] = true;
                }
            }
        }

        dp.swap(newdp);
    }
    cout << "Answer" <<dp[target][target][target];
    return dp[target][target][target];
}

int main(){
    vector<int> values = {4, 4, 4, 4, 4, 4};
    int T = 24;
    cout << balance3_dp(values,T);

}