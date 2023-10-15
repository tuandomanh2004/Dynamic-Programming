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
const int MAXN = 1e5 + 7;
const int MAXD = 1e3 + 7;
const int mod = 1e9 + 7;
ll dp[MAXN][4], a[MAXN], b[MAXN], c[MAXN]; 
int main() {
	// https://oj.vnoi.info/problem/atcoder_dp_c // 
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; 
	cin >> n; 
	f1(i, n) cin >> a[i] >> b[i] >> c[i];
	// goi dp[i][j] la max_point cua i ngay dau neu chon hoat dong thu j o ngay thu i //
	f1(i, n) {
		f1(j , 3) {
			if (j == 1) dp[i][j] = max(dp[i - 1][j + 1], dp[i - 1][j + 2]) + a[i];
			else if (j == 2) dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j + 1]) + b[i];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j - 2]) + c[i]; 
		}
	}
	cout << *max_element(dp[n] + 1 , dp[n] + 4 );
}