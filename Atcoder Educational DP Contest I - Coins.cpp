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
#include <cstring>
#include <ctime> 
#define ll long long 
#define del delete
#define fi first
#define se second 
#define f(i,n) for(int i = 0; i < n ; i++)
#define f1(i,n) for(int i = 1 ; i <= n ; i++)
#define endl "\n"
#define fe(it,v) for(auto it : v)
using namespace std;
const int MAXN = 3000;
const int MAXD = 1e3 + 7;
const int mod = 1e9 + 7;
double dp[MAXN][MAXN], p[MAXN]; 
int main() {
	// https://oj.vnoi.info/problem/atcoder_dp_i/editorial // 
	int n;
	cin >> n;
	f1(i, n) cin >> p[i]; 
	// goi dp[i][j] la xac suat cua i dong xu dau tien voi j mat ngua (j <= i) //
	dp[0][0] = 1.0; 
	f1(i, n) {
		for (int j = 0; j <= i; j++) {
			if (j) {
				dp[i][j] += dp[i - 1][j - 1] * p[i]; // TH1 : i la mat ngua // 
				dp[i][j] += dp[i - 1][j] * (1 - p[i]); // TH2 : i la mat sap // 
			}
			else dp[i][j] = dp[i - 1][j] * (1 - p[i]); 
		}
	}
	double ans = 0; 
	/*f1(i, n) {
		f(j, n + 1) {
			cout << dp[i][j] << " "; 
		}
		cout << endl;  
	}*/
	for (int i = n; i >= n / 2 + 1; i--) {
		ans += dp[n][i]; 
	}
	cout << setprecision(9) << ans << endl;
}
