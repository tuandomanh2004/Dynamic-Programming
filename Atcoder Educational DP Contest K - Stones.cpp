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
	const int MAXD = 1e5 + 7;
	const int mod = 1e9 + 7;
	bool dp[MAXD]; ll a[MAXN];
	int main() {
		ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		//  https://oj.vnoi.info/problem/atcoder_dp_k //
		int n , k ; 
		cin >> n >> k ; 
		f1(i, n) {
			cin >> a[i]; 
		}
		// goi dp[i] kha nang Taro co the thang khi co i vien da va Taro di dau // 
		f1(i, k) {
			f1(j, n) {
				if (i >= a[j] && !dp[i - a[j]]) {
					/* neu Taro boc  a[j] vien da = > Luot tiep theo se la Jiro boc trong(i - a[j]) vien da
					=> Taro chi win khi trong (i-a[j]) vien da con lai Taro thua (vi da di luot dau tien a[j])
					*/				
					dp[i] = true;
				}
			}
		}
		if (dp[k]) {
			cout << "First\n"; 
			return 0;
		}
		cout << "Second\n"; 
	}
