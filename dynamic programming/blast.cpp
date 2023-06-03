//
//  blast dp contest.cpp
//  
//
//  Created by Hong Nhung Le on 3/6/23.
//

#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
std::string a, b;
int f[2005][2005];
int k;
int la, lb;

int main(){
    cin >> a >> b;
    cin >> k;
    la = (int) a.size();
    lb = (int) b.size();
    for (int i = 0; i <= la; i++){
        f[i][0] = i * k;
    }
    
    for (int j = 0; j <= lb; j++){
        f[0][j] = j * k;
    }
    
    for (int i = 1; i <= la; i++){
        for (int j = 1; j <= lb; j++){
            f[i][j] = min(f[i - 1][j] + k, min(f[i][j - 1] + k, f[i - 1][j - 1] + abs(a[i - 1] - b[j - 1])));
        }
    }
    cout << f[la][lb];
    return 0;
}
