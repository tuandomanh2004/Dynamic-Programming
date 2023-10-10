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
const int MAXN = 5007;
const int MAXD = 205;
const int mod = 1e9 + 7;
ll dp[MAXN][MAXN], a[MAXN];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // https://cses.fi/problemset/task/1097 // 
    // goi dp[i][j] la khoang cach lon nhat tu vi tri i->j // 
    int n;
    cin >> n;
    ll total_sum = 0;
    f1(i, n) {
        cin >> a[i];
        total_sum += a[i];
        dp[i][i] = a[i];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            ll choose_first = a[i] - dp[i + 1][j];
            ll choose_last = a[j] - dp[i][j - 1];
            dp[i][j] = max(choose_first, choose_last);
        }
    }
    cout << (total_sum + dp[1][n]) / 2;
}