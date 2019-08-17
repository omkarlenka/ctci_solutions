//
//  main.cpp
//  ctci_8.6_tower_of_hanoi
//
//  Created by omlenka on 17/08/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

void toh_util(stack<int> &S, stack<int> &U, stack<int> &D, int plates, vector<tuple<int,int>> &moves, int S_NUM, int U_NUM, int D_NUM)
{
    if (plates == 1)
    {
        int top = S.top();
        S.pop();
        D.push(top);
        tuple<int,int> t(S_NUM,D_NUM);
        moves.push_back(t);
        return;
    }
    
    if(!S.empty())
        toh_util(S, D, U, plates-1, moves, S_NUM, D_NUM, U_NUM);
    
    int top = S.top();
    S.pop();
    D.push(top);
    tuple<int,int> t(S_NUM,D_NUM);
    moves.push_back(t);
    
    if(!U.empty())
        toh_util(U, S, D, plates-1, moves, U_NUM, S_NUM, D_NUM);
}

vector<tuple<int,int>> toh(int plates)
{
    stack<int> S;  //source
    stack<int> U;  //utility
    stack<int> D;  //destination
    
    int n = plates;
    
    while(n>0)
    {
        S.push(n--);
    }
    
    vector<tuple<int,int>> moves;
    int S_NUM = 1;
    int U_NUM = 2;
    int D_NUM = 3;
    
    toh_util(S,U,D,plates,moves,S_NUM,U_NUM,D_NUM);
    
    return moves;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int plates,move;
        cin >> plates >> move;
        
        vector<tuple<int,int>> moves = toh(plates);
        //find out move from moves
        
       // vector<tuple<int,int>>::iterator itr;
        
//        for(itr = moves.begin();itr<moves.end();itr++)
//        {
//            cout << get<0>(*itr) << "->" << get<1>(*itr) << " ";
//        }
        
        cout << get<0>(moves[move-1]) << " " << get<1>(moves[move-1]) << endl;
    }
    return 0;
}
