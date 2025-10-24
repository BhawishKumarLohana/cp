#include <bits/stdc++.h>
using namespace std;


int main(){

    sort(v.begin(), v.end());                    // Sort
    reverse(v.begin(), v.end());                 // Reverse
    unique(v.begin(), v.end());                  // Remove consecutive dupes, use with erase
    lower_bound(v.begin(), v.end(), x);          // First position >= x (sorted vec)
    upper_bound(v.begin(), v.end(), x);          // First position > x (sorted vec)
    binary_search(v.begin(), v.end(), x);        // Returns true if x exists (sorted)
    next_permutation(v.begin(), v.end());        // Permute to next lex ordering
    __gcd(a, b);                                // Greatest Common Divisor

	
}
