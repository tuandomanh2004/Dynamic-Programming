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
#define fe(it,v) for(auto it : v)
using namespace std;
const int MAXN = 1e4 + 7;
const int MAXD = 1e3 + 7;
const int mod = 1e9 + 7;
ll dp[MAXN], a[MAXN];
int main() {
	// https://oj.vnoi.info/problem/usaco18dg_teamwork // 
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; 
	cin >> n >> k; 
	// goi dp[i] max ki nang goi qua cua i chu bo dau tien  // 
	f1(i, n) {
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++) {
		 ll max_val = a[i]; 
		for (int j = i - 1; j >= max(i - k, 0); j--) {
			dp[i] = max(dp[i], dp[j] + max_val * (i - j ));
			max_val = max(max_val, a[j]); 
		}
	}
	cout << dp[n]; 
}