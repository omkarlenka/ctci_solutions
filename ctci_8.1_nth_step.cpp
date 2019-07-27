//
//  main.cpp
//  ctci_8.11_nth_step
//
//  Created by omlenka on 27/07/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

#define ll long long
#define MAX_N 100000

const unsigned int MAX = 1000000007;

ll cache[MAX_N+1] = {0};

int current = 2;

ll countWays(ll n)
{
    if(cache[n] != 0)
        return cache[n];
    
    int i;
    
    for(i = current+1;i<=n;i++)
    {
        cache[i] = (cache[i-1] + cache[i-2]) % MAX;
    }
    current = i-1;
    return cache[n];
}

int main() {
    
    int T;
    cin >> T;
    
    cache[1] = 1;
    cache[2] = 2;
    
    while(T--)
    {
        ll n;
        cin >> n;
        
        cout << countWays(n) << endl;
    }
    return 0;
}
