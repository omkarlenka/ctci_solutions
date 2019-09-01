//
//  ctci_8.9_parens.cpp
//  ctci_8.9_parens
//
//  Created by omlenka on 02/09/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;

void printParens_util(string str, int leftRem, int rightRem, int index, vector<string> &v)
{
    if(leftRem < 0 || rightRem < leftRem)
        return;
    
    if(leftRem == 0 && rightRem == 0)
    {
        v.push_back(str);
    }
    else
    {
        if(leftRem > 0)
        {
            
            str.push_back('(');
            printParens_util(str, leftRem-1, rightRem, index+1, v);
            str.pop_back();
        }
        if(rightRem > leftRem)
        {
            str.push_back(')');
            printParens_util(str, leftRem, rightRem-1, index+1, v);
        }
    }
}

void printParens(int n)
{
    vector<string> v;
    string str;
    
    printParens_util(str, n, n, 0, v);
    
    vector<string>::iterator itr;
    
    for(itr = v.begin();itr<v.end();itr++)
    {
        cout << *itr << " ";
    }
    
}
int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    
    printParens(n);

    return 0;
}
