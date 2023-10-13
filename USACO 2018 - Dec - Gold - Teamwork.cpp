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
	/*
		Y TUONG
	- Goi dp[i] la tong ki nang lon nhat co the dat duoc voi i con bo dau tien
	-Theo de, ta thay co the lap nhom toi da k con bo lien tiep => o moi vi tri i ta co toi da j trang thai (1 <= j <= k )
	-O trang thai thu j ta co the lap 1 day j con bo lien tiep voi con bo thu i la con cuoi cung trong day
	=> dap an la dp[n] : max ki nang sau khi duyet qua het toan bo con bo */

	/*
		THUAT TOAN
	- Su dung 2 vong for long nhau voi 2 bien i,j ( i la bien duyet theo thu tu bo , j la trang thai cua i )
	-Khoi tao j = i - 1 , j se chay toi vi tri toi da j = i - k 
	-  Gia su ta co  n  = 3 (1,7,15),k = 3 va i hien tai = 3  
	+ Theo y tuong con bo thu i co the lap nhom toi da k con bo lien tiep => Ta co cac truong hop 
	+ Lap nhom 1 con bo la con bo thu 3 => dp[3] = dp[2] + 1*a[3] 
	+ Lap nhom 2 con bo  ={2,3} => dp[3] = dp[1] + 2*max(a[2] , a[3] )
	+ Lap nhom 3 con bo  ={1,2,3} => dp[3] = dp[0] + 3*max(a[1],a[2],a[3])
	=> Ta se lay trang thai ma thu duoc max_kinhnghiem
	=> CTTQ : dp[i] = max(dp[i] , dp[j] + max_exp*(i - j ))
	*/
}
