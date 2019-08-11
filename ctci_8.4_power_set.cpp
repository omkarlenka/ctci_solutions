//
//  main.cpp
//  ctci_8.4_power_set
//
//  Created by omlenka on 11/08/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printPowerSet(string s, int n)
{
    int counter = pow(2,n);
    int one = pow(2,n-1);
    vector<string> v;
    
    for(int i = 0; i< counter; i++)
    {
        string set = "";
        int index = 0;
        int j = i;
        while(j != 0 && j < counter)
        {
            if(j & one)
            {
                set.push_back(s[index]);
                j = j & (~one);
            }
            
            j = j << 1;
            index ++;
        }
        if (!set.empty())
            v.push_back(set);
    }
    sort(v.begin(), v.end());
    vector<string>::iterator itr;
    for(itr=v.begin();itr<v.end();itr++)
        cout << *itr << " ";
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int n;
        string s;
        cin >> n >> s;
        
        printPowerSet(s, n);
    }
    return 0;
}
