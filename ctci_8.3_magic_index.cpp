//
//  main.cpp
//  ctci_8.3_magic_index
//
//  Created by omlenka on 04/08/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

void printMagicIndex(int* arr, int s, int e)
{
  if(s > e)
      return;
  int mid = (s+e)/2;

  if(arr[mid] == mid)
    cout << arr[mid] << endl;

  printMagicIndex(arr,s,min(mid-1,arr[mid]));
  printMagicIndex(arr,max(mid+1, arr[mid]), e);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0;i<n;i++)
      cin >> arr[i];

    printMagicIndex(arr,0, n);

    return 0;
}

