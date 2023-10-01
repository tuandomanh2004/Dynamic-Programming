#include <iostream>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <string>
#include <sstream>
#include <iomanip> 
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime> 
#define ll long long 
#define del delete
#define fi first
#define se second 
#define f(i,n) for(int i = 0; i < n ; i++)
#define f1(i,n) for(int i = 1 ; i <= n ; i++)
using namespace std;
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
ll dp[1005][1005]; char F[1005][1005];
int main() {
    // https://cses.fi/problemset/task/1638/ //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    f1(i, n) {
        f1(j, n) {
            cin >> F[i][j];
        }
    }
    f1(i, n) {
        f1(j, n) {
            if (F[i][j] != '*') {
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n][n];
}