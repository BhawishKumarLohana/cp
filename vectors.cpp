#include <bits/stdc++.h>
using namespace std;

// Vector of size n, all zeros
int main(){
    vector<int> v = {3, 1, 2};        // Initialization
    v.push_back(5);                   // Add 5 at end
    v.pop_back();                     // Remove last element
    int x = v.back();                 // Get last element
    v.size();                         // Get size
    v.empty();                        // True if vector is empty

    v.resize(10);                     // Resize vector
    v.clear();                        // Remove all elements

    sort(v.begin(), v.end());         // Sort vector
    reverse(v.begin(), v.end());      // Reverse vector

    auto it = find(v.begin(), v.end(), 5); // Finds 5, returns iterator
    int cnt = count(v.begin(), v.end(), 3); // Count occurrences of 3

    long long sum = accumulate(v.begin(), v.end(), 0LL); // Sum up vector

}
