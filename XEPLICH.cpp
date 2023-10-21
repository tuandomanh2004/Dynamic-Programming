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
	const int MAXN = 107;
	const int MAXD = 107;
	const int mod = 1e9 + 7;
	ll dp[MAXN][MAXD],f[107][107];
	int main() {
		ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		// https://ntucoder.net/Problem/Details/5678 //
		int n, k; 
		cin >> k >> n; 
		f1(i, k) {
			f1(j, n) {
				cin >> f[i][j]; 
			}
		}
		// goi dp[i][j] la max cong viec hoan thanh cua i  lop dau neu lop thu i chon cong viec j // 

		f1(i, n) {
			dp[1][i] = f[1][i]; 
		}
		for (int i = 2; i <= k; i++) {
			f1(j, n) {
				for (int l = 1; l <= j-1 ; l++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][l] + f[i][j]); 
				}
			}
		}
		/*f1(i, k) {
			f1(j, n) {
				cout << dp[i][j] << " "; 
			}
			cout << endl; 
		}*/
		cout << *max_element(dp[k] + 1, dp[k] + 1 + n); 
	}
