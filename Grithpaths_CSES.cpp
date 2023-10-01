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
ll dp[100001], b[1005], p[1005];
int main() {
    //https://cses.fi/problemset/task/1638 // 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    f1(i, n) {
        cin >> p[i];
    }
    f1(i, n) cin >> b[i];
    // goi dp[j] la so trang sach max co the mua voi tong so tien j//
    f1(i, n) {
        for (int j = x; j >= p[i]; j--) {
            dp[j] = max(dp[j], dp[j - p[i]] + b[i]);
        }
    }
    cout << dp[x];
}