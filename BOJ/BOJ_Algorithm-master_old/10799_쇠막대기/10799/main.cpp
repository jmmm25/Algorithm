//
//  main.cpp
//  10799
//
//  Created by JEONGMIN on 2017. 1. 2..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    stack<char> st;
    string pipe;
    int result = 0;
    cin >> pipe;
    
    for (int i=0; i<pipe.length(); i++) {
        if(pipe[i] == '(') {
            st.push(pipe[i]);
        }
        
        else {
            st.pop();
            if(pipe[i-1] == ')') {
                result += 1;
            }
            else {
                result += st.size();
            }
        }
    }
    
    cout << result << endl;
    return 0;
}
