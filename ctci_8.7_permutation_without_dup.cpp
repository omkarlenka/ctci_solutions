//
//  ctci_8.7_permutation_without_dup.cpp.cpp
//  ctci_8.7_permutation_without_dup
//
//  Created by omlenka on 24/08/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap_chars(string &s, int a, int b)
{
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

void printPermutation_util(string s, int start, int len,string prefix, vector<string> &res)
{
    if(len == 1)
    {
        string permutation;
        if(!prefix.empty())
        {
            prefix.push_back(s[start]);
            permutation = prefix;
        }
        else
        {
            permutation = s[start];
        }
        
        res.push_back(permutation);
        
        return;
    }
    
    for(int i = start;i < start+len; i++)
    {
        swap_chars(s,i,start);
        prefix.push_back(s[start]);
        printPermutation_util(s, start+1, len-1, prefix, res);
        swap_chars(s,i,start);
        prefix.pop_back();
    }
}

vector<string> printPermutation(string s)
{
    vector<string> res;
    string prefix;
    
    printPermutation_util(s, 0, s.length(), prefix, res);
    
    return res;
}

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        string s;
        cin >> s;
        
        vector<string> v = printPermutation(s);
        sort(v.begin(),v.end());
        vector<string>::iterator itr;
        
        for(itr = v.begin();itr<v.end();itr++)
            cout << *itr << " ";
        
        cout << endl;
    }
    return 0;
}
