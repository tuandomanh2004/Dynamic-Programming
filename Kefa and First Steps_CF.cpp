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
const int MAXN = 1e5 + 7; 
const int MAXD = 205;
const int mod = 1e9 + 7;
ll dp[MAXN], a[MAXN]; 
int main() {
	//	https://codeforces.com/problemset/problem/580/A // 
	int n; 
	cin >> n;
	f1(i, n) {
		cin >> a[i]; 
		dp[i] = 1; 
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] >= a[i - 1]) dp[i] = ++dp[i - 1]; 
	}
	cout << *max_element(dp + 1, dp + 1 + n); 
}