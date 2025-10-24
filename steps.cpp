#include <bits/stdc++.h>
using namespace std;


int main(){
    set<int> s;
    s.insert(3);
    s.erase(3);
    bool exists = (s.count(3) != 0);

    auto it = s.find(5);          // Iterator to 5 or s.end()
    s.size();
    s.empty();

    // Multisets allow duplicates:
    multiset<int> ms;
    ms.insert(3);
    ms.erase(ms.find(3));         // Erase just one occurrence

	
}
