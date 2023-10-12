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
const int MAXN = 107;
const int MAXD = 205;
const int mod = 1e9 + 7;
ll dp[MAXN][MAXN], a[MAXN];
int main() {
	// https://codeforces.com/problemset/problem/1113/A // 
	int n, v; 
	cin >> n >> v; 
	// voi v lit xang ta co the di duoc v km && xuat phat tu 1 thi ta chi can di n-1 km // 
	if (n - 1 <= v) {
		cout << n - 1; 
		return 0; 
	}
	// o tp thu i = 1 mua max v lit xang => ta se di duoc them 1 + v km => de so tien ta tra toi thieu
	 //  => di duoc 1 km den thanh pho i+1 ta lai mua them 1 lit xang // 
	int res = v; 
	for (int i = 2; i <= n - v; i++) {
		res += i; 
	}
	cout << res << endl; 
}