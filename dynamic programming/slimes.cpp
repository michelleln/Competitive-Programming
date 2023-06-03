#include <iostream>
#include <math.h>
using namespace std;
int N;
long long a[405];
long long f[405][405];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> a[i];
        f[i][i] = 0;
    }
    for (int i = 1; i + 1 <= N; i++){
        f[i][i + 1] = a[i] + a[i + 1];
    }
    for (int i = 0; i <= N - 1; i++){
        for (int j = i + 2; j < N; j++){
            for (int temp = i; temp < j; temp++){
                f[i][j] = min(f[i][j], f[i][temp] + f[temp + 1][j]);
            }
        }
    }
    cout << f[1][N];
}
