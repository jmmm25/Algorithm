//
//  main.cpp
//  1725
//
//  Created by JEONGMIN on 2017. 1. 26..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include<iostream>
#include<stack>
using namespace std;

int Histogram();

int n,arr[100001];
stack<int> st;

int main(void){
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    cout << Histogram() << "\n";
    
    return 0;
}

int Histogram(){
    int maxWidth = -1;
    int width = 0,height = 0;
    
    for (int i=0; i<n; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]){
            //if(arr[st.top()] > arr[i]){
            width = i;
            height = arr[st.top()];
            st.pop();
            if (!st.empty()) {
                width = i - st.top() - 1;
            }
            maxWidth = max(maxWidth, width * height);
            //}
        }
        st.push(i);
    }
    while(!st.empty()){
        height = arr[st.top()];
        st.pop();
        width = n;
        if(!st.empty()){
            width = n - st.top() - 1;
        }
        maxWidth = max(maxWidth, width * height);
    }
    
    return maxWidth;
}
