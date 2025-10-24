#include <bits/stdc++.h>
using namespace std;


int climbStairs(int n,int* cost){
    
    // way 1 
    // to reach staircase 1, go from n - 1 
    // the cost is (min cost to be at n-1) + cost(n-1)
    // or we can say the PREV COST  + COST(n-1)
    
    // way 2
    // go there from n-2 
    // PREV COST + (cost(n-2))

    // base cases
    // index  0  = 0 
    // index 1 = 0 

    vector<int> dp (n+1);


    dp[0]  = 0;
    dp[1] = 0;
    for(int i = 2 ; i <= n ; i++){
        int op1 = dp[i-1] + cost[i-1];
        int op2 = dp[i-2] + cost[i-2];
        dp[i] = min(op1,op2);
    }
    return dp[n];






}

int main(){
    vector<int> cost = {10,20,30,40};
    cout << climbStairs(cost.size(),cost.data());

	
}
