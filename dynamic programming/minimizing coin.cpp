#include <iostream>
#include <math.h>
using namespace std;
const int inf = 1000007;
int n, x;
int a[105];
int f[2][1000005];

int main (){
    cin >> n >> x;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int j = 0; j <= x; j++){
        f[0][j] = inf;
    }
    
    f[0][0] = 0;
    for (int i = 1; i <= n; i++){
        int temp = i % 2;
        int prev = !temp;
        for (int j = 0; j <= x; j++){
            f[temp][j] = inf;
        }
        for (int j = 0; j <= x; j++){
            f[temp][j] = min(f[temp][j], f[prev][j]);
            if (j >= a[i]){
                f[temp][j] = min(f[temp][j], f[temp][j - a[i]] + 1);
            }
            
        }
    }
    cout << (f[n % 2][x] == inf ? -1 : f[n % 2][x]);
}
