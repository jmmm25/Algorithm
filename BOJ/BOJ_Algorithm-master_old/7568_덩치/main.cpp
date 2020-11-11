//
//  main.cpp
//  7568_덩치
//
//  Created by JEONGMIN on 2018. 1. 30..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Info {
  // x is weight, y is height
  int x;
  int y;
}info;

int N, ranked[51];
vector<Info> v;

void sol(int num) {
  for (int i = 0; i < N; i++) {
    if (num == i) {
      continue;
    }
    else if (v[num].x < v[i].x && v[num].y < v[i].y ) {
      ranked[num]++;
    }
  }
  // cout << "num : " << num << "  : " << ranked[num] << endl;
}

int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  Info info;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> info.x >> info.y;
    v.push_back(info);
  }

  //print
  for (int i = 0; i < v.size(); i++) {
    // cout << v[i].x << ", " << v[i].y << endl;
    sol(i);
  }

  for (int i = 0; i < N; i++) {
    cout << ranked[i] + 1 << " ";
  }
  return 0;
}
