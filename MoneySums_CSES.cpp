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
using namespace std;
const int MAXN = 1e5 + 7;
const int MAXD = 205;
const int mod = 1e9 + 7;
bool dp[107][MAXN]; ll a[107];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // https://cses.fi/problemset/task/1745 // 
    int n;
    set <int> se;
    ll sum = 0;
    cin >> n;
    f1(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    dp[0][0] = true;
    f1(i, n) {
        dp[i][a[i]] = true;
    }
    f1(i, n) {
        f1(j, sum) {
            f1(k, i - 1) {
                if (dp[k][j - a[i]]) {
                    dp[i][j] = true;
                }
            }
        }
    }
    /*    f1(i, n) {
            f1(j, sum) {

              cout << dp[i][j] << " ";
          }
          cout << endl;
        }*/
    f1(i, n) {
        f1(j, sum) {
            if (dp[i][j]) se.insert(j);
        }
    }
    cout << se.size() << endl;
    for (auto it : se) {
        cout << it << " ";
    }
}