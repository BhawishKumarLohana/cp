#include <iostream>
#include <bits/stdc++.h>


using namespace std;

// modular inverse of k modulo p 
// where p is prime
long long modInv(long long a, long long p){
    
    long long b = p ;
    long long u = 1;
    long long v = 0;
    while(b){
        long long T = a / b ;
        a -= (T * b );
        swap(a,b);
        u -= (T * v);
        swap(u,v);
    }
    return (u + p ) % p;
}



int main() {
    int T;
    cin >> T; 
    for (int k = 0 ; k < T ; k++ ){
        
        vector<long long> testCase(7);
        for(int i = 0 ; i < 7 ; i++){
            cin >> testCase[i];
        }
            long long a  = testCase[0];
            long long b =  testCase[1];
            long long p =  testCase[2];
            long long x1 = testCase[3];
            long long y1 = testCase[4];
            long long x2 = testCase[5];
            long long y2 = testCase[6];
            long long lambda; 
            long long x3,y3;
            
            if (x1 == x2 && (y1 + y2) % p == 0) {
            cout << "POINT_AT_INFINITY" << endl;
            continue;
        }
            
            // case 2 
            // p is q
            // Doubling
            if(x1 == x2 && y1 == y2 ){
                long long num = (3 * x1 % p * x1 % p+a) % p ;
                long long de = (2*y1) % p;
                if(de == 0){
                    cout << "POINT_AT_INFINITY" << endl;
                    continue;
                }
                lambda  = (num * modInv(de,p)) % p;
                
            }else{
                // case 1
                // p not q
                long long num = (y2-y1+p) % p;
                long long de = (x2 - x1 +p) % p;
                if(de == 0){
                    cout << "POINT_AT_INFINITY" << endl;
                    continue;
                }
                lambda = (num * modInv(de,p)) % p;
                
                
            }
            
            x3  = (lambda * lambda -x1 -x2 + p +p ) % p ;
            y3 = (lambda * (x1 - x3 + p) - y1 + p) %p;
            
            cout << x3 << " "<< y3 << endl;
        
        
    }
    
    
        
    return 0;
}