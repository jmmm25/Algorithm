//
//  main.cpp
//  10942
//
//  Created by JEONGMIN on 2017. 1. 24..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//
#include<iostream>
using namespace std;

int arr[2001];
int result[2001];

int Pal(int start, int end){
    if (start == end){
        return 1;
    }
    
    for (int j = start; j < ((start + end) / 2); j++){
        if (arr[start++] != arr[end--])
            return 0;
    }
    return 1;
}

int main()
{
    int N, M, start, end;
    
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    cin >> M;
    
    for (int i = 0; i < M; i++){
        cin >> start >> end;
        cout << Pal(start, end) << "\n";
    }
    
    return 0;
}
