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
#define ll long long 
#define del delete
#define fi first
#define se second 
#define f(i,n) for(int i = 0; i < n ; i++)
#define f1(i,n) for(int i = 1 ; i <= n ; i++)
using namespace std;
const int mod = 1e9 + 7;
ll  a[1000007], b[1000007], F[1000007], D[1000007], coin[1000007];
pair<ll, ll> arr[1000007];
bool P2[100][100], P[1000002];
set <int>  se1, se2;
multiset <int> ms;    map <char, int> mp;
char x[1000007];
int  used[100000];
vector <int> vtor;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int  a2[1007][1007], F2[1007][1007], check[1000][1000];
ll dp[1000007];
int main() {
	// https://cses.fi/problemset/task/1635/ // 
	int x, n;
	cin >> n >> x;
	f1(i, n) cin >> a[i];
	dp[0] = 1;
	f1(i, x) {
		f1(j, n) {
			if (i >= a[j]) {
				dp[i] += dp[i - a[j]] % mod;
				dp[i] %= mod;
			}
		}
	}
	cout << dp[x];
}