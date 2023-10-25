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
	const int MAXN = 407;
	const int MAXD = 1e5 + 7;
	const int mod = 1e9 + 7;
	unsigned long long dp[MAXN][MAXN]; ll a[MAXN] , p[MAXN];
	void PrefixS(ll p[] , int n) {
		f1(i, n) {
			if (i == 1) p[i] = a[i];
			else p[i] = p[i - 1] + a[i]; 
		}
	}
	int main() {
		ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		// https://oj.vnoi.info/problem/atcoder_dp_n //
		int n; 
		cin >> n; 
		f1(i, n) { 
			cin >> a[i]; 
		}
		// dp[i][j] : min cost khi ghep tu slime tu i->j // 

		/*4
		10 20 30 40*/
		PrefixS(p, n); 
		for (int i = n; i  >=  1; i--) {
			for (int j = i + 1; j <= n; j++) {
				if (i == j) dp[i][j] = 0;
				else if (i + 1 == j) dp[i][j] = a[i] + a[j]; 
				else{ 
					dp[i][j] = ULONG_MAX; 
					for (int k = j; k > i; k--) {
						dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j] + (p[j] - p[i - 1])); 
					}
				}
			}
		}
		/*f1(i, n) {
			f1(j, n) {
				cout << dp[i][j] << " "; 
			}
			cout << endl; 
		}*/
		cout << 1ll*dp[1][n] << endl; 
	}
