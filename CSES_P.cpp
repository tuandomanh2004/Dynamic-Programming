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
#define endl "\n"
using namespace std;
const int MAXN = 1e5 + 7 ;
const int MAXD = 205; 
const int mod = 1e9 +  7 ;
ll dp[MAXN][102], a[MAXN];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    // goi dp[i] la so luong day max thoa man de bai tu dau den vi tri i khi thay doi den gia tri j    //
    // gap vi tri i co a[i] = 0 chay vong for thay doi gia tri // 
    f1(i, n) cin >> a[i];
    f1(j, m) {
        if (a[1] == 0 || a[1] == j) {
            dp[1][j] = 1; 
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            f1(j, m) {
                dp[i][j] += dp[i - 1][j - 1] % mod;
                dp[i][j] += dp[i - 1][j] % mod; 
                dp[i][j] += dp[i - 1][j + 1] % mod; 
            }
        }
        else {
            dp[i][a[i]] += dp[i - 1][a[i] - 1] % mod; 
            dp[i][a[i]] += dp[i - 1][a[i]] % mod ;
            dp[i][a[i]] += dp[i - 1][a[i] + 1] % mod; 
        }
        } 
   /* f1(i, n) {
        f1(j, m) {
            cout << dp[i][j] << " "; 
        }
        cout << endl; 
    }*/
    ll ans = 0; 
    f1(j, m) {
        ans += dp[n][j] % mod; 
    }
    cout << ans % mod; 
}