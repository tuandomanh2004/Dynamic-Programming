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
ll dp[MAXN];
int main() {
    // https://cses.fi/problemset/task/1637/ // 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    // goi dp[i] la so buoc it nhat de bien doi tu i->0 // 
    dp[0] = 0;
    f1(i, n) {
        dp[i] = 1e9;
        int j = i;
        while (j) {
            int digit = j % 10;
            dp[i] = min(dp[i], dp[i - digit] + 1);
            j /= 10;
        }
    }
    cout << dp[n];
}