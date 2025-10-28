#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int>> Group;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> Mat(N, vector<char>(M));
    string row;
    getline(cin,row); // absorb the newline after N M

    for (int i = 0; i < N; i++) {
        getline(cin, row);
        for (int j = 0; j < M; j++) {
            Mat[i][j] = row[j];
        }
    }

    // verify the non-blocked cells
    vector<vector<bool>> nonBlocked(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            nonBlocked[i][j] = (Mat[i][j] != '.');

    // Group identification
    vector<Group> groups;
    // Horizontal palindromes
    for (int i = 0; i < N; ++i) {
        int l = 0;
        while (l < M) {
            while (l < M && Mat[i][l] == '.') l++;
            int r = l;
            while (r < M && Mat[i][r] != '.') r++;
            int len = r - l;
            if (len >= 2) {
                for (int k = 0; k < len / 2; ++k) {
                    Group g;
                    g.push_back({i, l + k});
                    g.push_back({i, r - 1 - k});
                    groups.push_back(g);
                }
            }
            l = r;
        }
    }
    // Vertical palindromes
    for (int j = 0; j < M; ++j) {
        int l = 0;
        while (l < N) {
            while (l < N && Mat[l][j] == '.') l++;
            int r = l;
            while (r < N && Mat[r][j] != '.') r++;
            int len = r - l;
            if (len >= 2) {
                for (int k = 0; k < len / 2; ++k) {
                    Group g;
                    g.push_back({l + k, j});
                    g.push_back({r - 1 - k, j});
                    groups.push_back(g);
                }
            }
            l = r;
        }
    }

    // Merge overlapping groups (robust version)
    vector<vector<pair<int,int>>> mergedGroups;
    auto addToGroup = [&](int x, int y, size_t groupId) {
        // Only push if not already present
        for (auto& p : mergedGroups[groupId]) {
            if (p.first == x && p.second == y)
                return;
        }
        mergedGroups[groupId].push_back({x, y});
    };

    for (auto& g : groups) {
        size_t groupId = mergedGroups.size(); // sentinel invalid value
        for (auto& p : g) {
            int x = p.first, y = p.second;
            for (size_t id = 0; id < mergedGroups.size(); ++id) {
                for (auto& q : mergedGroups[id]) {
                    if (q.first == x && q.second == y) {
                        groupId = id;
                        goto found;
                    }
                }
            }
        }
    found:
        if (groupId != mergedGroups.size()) {
            for (auto& p : g) addToGroup(p.first, p.second, groupId);
        } else {
            mergedGroups.push_back(g);
        }
    }

    // Add all single non-blocked ones in their own group
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        if (!nonBlocked[i][j]) continue;
        bool already = false;
        for (auto& grp : mergedGroups) {
            for (auto& pq : grp)
                if (pq.first == i && pq.second == j) {
                    already = true;
                    break;
                }
            if (already) break;
        }
        if (!already)
            mergedGroups.push_back(Group{{i,j}});
    }

    // Minimal change assignment
    vector<vector<char>> newMat = Mat;
    for (auto& grp : mergedGroups) {
        int minCost = INT_MAX;
        char bestDigit = '0';
        for (char d = '0'; d <= '9'; ++d) {
            int cost = 0;
            for (auto& p : grp) {
                char cur = Mat[p.first][p.second];
                cost += abs(cur - d);
            }
            if (cost < minCost) {
                minCost = cost;
                bestDigit = d;
            }
        }
        for (auto& p : grp)
            newMat[p.first][p.second] = bestDigit;
    }

    // Output
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cout << newMat[i][j];
        cout << '\n';
    }
    return 0;
}