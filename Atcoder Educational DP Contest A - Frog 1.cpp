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
ll dp[MAXN], a[MAXN]; 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// https://oj.vnoi.info/problem/atcoder_dp_a //
	int n; 
	cin >> n; 
	f1(i, n) {
		cin >> a[i]; 
	}
	dp[1] = 0; 
	dp[2] = abs(a[2] - a[1]); 
	for (int i = 3; i <= n; i++) {
		dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2])); 
	}
	cout << dp[n]; 
}
