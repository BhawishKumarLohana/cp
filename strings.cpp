#include <bits/stdc++.h>
using namespace std;


int main(){

    string s = "hello";
    s.size();                     // Get length
    s.length();                   // Same as size()

    s += " world";                // Concatenate
    s.append("abc");              // Append
    s.substr(0, 3);               // Substring [0,3)
    s.find("ll");                 // Find "ll" (returns position or npos)
    s.erase(2, 1);                // Erase character at position 2
    reverse(s.begin(), s.end());  // Reverse string

    stoi("123");                  // String to int
    to_string(123);               // int to string
    char c = s[1];                // Access character

	
}
