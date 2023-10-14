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
ll a[107];
bool dp[MAXN]; 
int main() {
	int n, t; 
	// https://codeforces.com/problemset/problem/1472/B // 
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// tim day con co tong bang k ( 1 <= k <= sum( a  + 1 , a + 1 + n ) ) // 
	cin >> t; 
	dp[0] = 1;  
	while (t--) {
		cin >> n; 
		ll sum = 0; 
		f1(i, n) {
			cin >> a[i];
			sum += a[i]; 
		}
		memset(dp, 0, n + 1);
		dp[0] = 1; 
		f1(i, sum) {
			f1(j, n) {
				if (a[j] <= i && dp[i - a[j]]) dp[i] = 1; 
			}
		}
			/*f1(i, sum) {
				if (dp[i]) cout << i << " ";  
			}*/
		bool ok = 0; 
		f1(i, sum) {
			if (dp[i] && 2*i == sum) {
				cout << "YES\n"; 
				ok = 1; 
				break; 
			}
		}
		if (!ok) cout << "NO\n"; 
		
	}
	
}