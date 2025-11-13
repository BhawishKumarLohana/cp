#include <bits/stdc++.h>
using namespace std;

/*
    Recursive function to try assigning each student to one of two teams
    so that total CGPA sums become equal.
    It returns true if a valid split exists and fills `team1` and `team2`.
*/

bool balance(int i, int sum1, int sum2,
             const vector<int>& vals, int T,
             vector<int>& t1, vector<int>& t2) {
    int n = vals.size();
    if (i == n) {
        return sum1 == sum2;
    }
    if (sum1 > T / 2 || sum2 > T / 2)
        return false;
    t1.push_back(vals[i]);
    if (balance(i + 1, sum1 + vals[i], sum2, vals, T, t1, t2))
        return true;  
    t1.pop_back();   

    t2.push_back(vals[i]);
    if (balance(i + 1, sum1, sum2 + vals[i], vals, T, t1, t2))
        return true;  
    t2.pop_back();   
    return false;
}

int main() {
    vector<int> vals = {6, 5, 4, 3, 2};
    int T = accumulate(vals.begin(), vals.end(), 0);

    vector<int> team1, team2;

    bool ok = balance(0, 0, 0, vals, T, team1, team2);

    if (ok) {
        cout << " Equal partition found!\n";
        cout << "Team 1: ";
        for (int v : team1) cout << v << " ";
        cout << "\nTeam 2: ";
        for (int v : team2) cout << v << " ";
        cout << "\n";
    } else {
        cout << " No equal partition possible.\n";
    }
    return 0;
}
