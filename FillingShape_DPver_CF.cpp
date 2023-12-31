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
const int MAXN = 2e5 + 7;
const int MAXD = 205;
const int mod = 1e9 + 7;
ll dp[MAXN], ok[257]; 
int main() {
 // https://codeforces.com/gym/302977/problem/B // 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; 
    string s; 
    cin >> n >> k >> s;
    char c; 
    f1(i, k) {
        cin >> c;  
        ok[c] = 1; 
    }
    ll ans = 0; 
    f(i, s.size()) {
        if (i == 0) {
            dp[i] = ok[s[i]];
        }
        else {
            if (ok[s[i]]) {
                dp[i] = dp[i - 1] + 1; 
            }
        } 
        ans += dp[i]; 
    }
    cout << ans << endl ; 
}