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
const int MAXN = 1007;
const int MAXD = 205;
const int mod = 1e9 + 7;
ll dp[MAXN][MAXN], DP[MAXN][MAXN] ,  f[MAXN][MAXN];
int main() {
	// https://oj.vnoi.info/problem/qbsquare // 
	int n, m; 
	cin >> m >> n; 
	f1(i, m) {
		f1(j, n) {
			cin >> f[i][j]; 
		}
	}
	// goi dp[i][j] la hinh vuong lon nhat chua toan so 1 ket thuc tai vi tri (i,j) //
	// foi DP[i][j] la hinh vuong lon nhat chua toan so 0 ket thuc tai vi tri (i , j) // 
	f1(i, m) {
		f1(j, n) {
			if (f[i][j] == 1) {
				dp[i][j] = min({ dp[i - 1][j] , dp[i][j - 1] , dp[i - 1][j - 1] }) + 1; 
			}
			else {
				DP[i][j] = min({ DP[i - 1][j] , DP[i][j - 1] , DP[i - 1][j - 1] }) + 1; 
			}
		}
	}
	 ll max1 = INT_MIN , max0 = INT_MIN;
	 f1(i, m) {
		 f1(j, n) {
			 max1 = max(max1, dp[i][j]); 
			 max0 = max(max0, DP[i][j]); 
		 }
	 }
	 cout << max(max1,max0) << endl;
	 //f1(i, m) {
		// f1(j, n) {
		//	 cout << DP[i][j] << " "; 
		// }
		// cout << endl;
	 //}
}