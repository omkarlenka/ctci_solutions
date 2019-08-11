//
//  main.cpp
//  ctci_8.5_recursive_multiplication
//
//  Created by omlenka on 11/08/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

int recursiveMultiply_Util(int smaller, int bigger)
{
    if(smaller == 0)
        return 0;
    if(smaller == 1)
        return bigger;
    
    int result;
    int result_half;
    int half = smaller >> 1;
    int remainder = smaller - (half << 1);
    
    result_half = recursiveMultiply_Util(half, bigger);
    
    if(remainder == 0)
    {   //even
        result = result_half << 1;
    }
    else
    {
        result = (result_half << 1) + bigger;
    }
    
    return result;
}

int recursiveMultiply(int a, int b)
{
    int smaller = (a > b) ? b : a;
    int bigger = (a < b) ? b : a;
    
    return recursiveMultiply_Util(smaller, bigger);
}

int main() {
    int a,b;
    cin >> a >> b;
    
    cout << recursiveMultiply(a, b);
    
    return 0;
}
