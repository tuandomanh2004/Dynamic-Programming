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
ll cash[6] = { 1 , 5 , 10 , 20 ,100 }; 
int main() {
	// https://codeforces.com/problemset/problem/996/A //
	int n,t; 
	cin >> n;
	ll ans = 0; 
	while (n) {
		ll tmp = INT_MAX , pos = INT_MIN ; 
		f(i, 5) {
			if (cash[i] <= n) {
				int t = n / cash[i];
				if (tmp > t) tmp = t, pos = cash[i]; 
			}
		}
		ans += tmp; 
		n -= tmp * pos; 
	}
	cout << ans << endl; 
}
