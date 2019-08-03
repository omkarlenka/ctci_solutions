//
//  main.cpp
//  ctci_8.2_robot_in_a_grid
//
//  Created by omlenka on 03/08/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

void printMatrix(int **G, int r, int c)
{
    for(int i = 0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
            cout << G[i][j] << " ";
        
        cout << endl;
    }
}

int countPaths(int**G, int r, int c)
{
    int **paths = new int*[r];
    for(int i = 0;i<r;i++)
    {
        paths[i] = new int[c];
    }
    
    if(G[0][0] == 0)
        paths[0][0] = 1;
    else
        paths[0][0] = 0;

    for(int i = 0; i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            if(G[i][j] == -1)
            {
                paths[i][j] = 0;
                continue;
            }
            
            if(i == 0 && j > 0)
            {
                paths[i][j] = paths[i][j-1];
            }
            else if(i> 0 && j == 0)
            {
                paths[i][j] = paths[i-1][j];
            }
            else if(i > 0 && j > 0)
            {
                paths[i][j] = paths[i][j-1] + paths[i-1][j];
            }
        }
    }
    
    return paths[r-1][c-1];
}

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int N,M,K;
        cin >> N >> M >> K;
        
        int **G = new int*[N];
        for(int i = 0;i<M;i++)
            G[i] = new int[M];
        
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            {
                G[i][j] = 0;
            }
        }
        
//        printMatrix(G, N, M);
        
        for(int i=0;i<K;i++)
        {
            int r,c;
            cin >> r >> c;
            G[r-1][c-1] = -1;
        }
        
        cout << countPaths(G, N, M);
        
    }
    return 0;
}
