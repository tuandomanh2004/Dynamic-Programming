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
    const int MAXN = 5001;
    const int MAXD = 205;
    const int mod = 1e9 + 7;
    ll dp[MAXN][MAXN], a[MAXN];
    int main() {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        // https://cses.fi/problemset/task/1639 // 
        string s, p; 
        cin >> s >> p; 
        f(i, p.size() + 1 ) {
            dp[0][i] = i; 
        }
        f(i, s.size() + 1) {
            dp[i][0] = i; 
        }
        // goi dp[i][j] la so buoc bien doi it nhat de chuyen chuoi tu 0->i cua xau S thanh chuoi tu 0->j cua xau p  // 
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                    dp[i][j] = INT_MAX;
                    if (s[i-1] == p[j-1]) dp[i][j] = dp[i - 1][j - 1];
                    else {
                        dp[i][j] = 1 + min({ dp[i - 1][j - 1] , dp[i - 1][j] , dp[i][j - 1] });
                        /* dp[i-1[j-1] : replace
                         dp[i][j-1] : insert
                         dp[i-1][j] : delete*/
                    }
            }
        }
        cout << dp[s.size()][p.size()]; 
    }