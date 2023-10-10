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
const int MAXN = 507;
const int MAXD = 205;
const int mod = 1e9 + 7;
ll dp[MAXN][MAXN], a[MAXN];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // https://cses.fi/problemset/task/1744 //
    int a, b; 
    cin >> a >> b;
    // goi dp[i][j] la so cach cat it nhat de cat hinh chu nhat kich thuoc ixj thanh hinh vuong //
    f1(i, a) {
        f1(j, b) {
            dp[i][j] = INT_MAX; 
            if (i == j) dp[i][j] = 0; 
            f1(w, i - 1) dp[i][j] = min(dp[i][j], dp[w][j] + dp[i-w][j] + 1); // cat ngang // 
            f1(h, j - 1) dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j - h] + 1); // cat doc // 
        }
    }
    cout << dp[a][b]; 
}