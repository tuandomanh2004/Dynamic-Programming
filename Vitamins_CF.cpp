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
map <string, ll> mp; 
pair <ll, string> p[MAXN]; 
// a , b ,c , ab , bc , ac ,abc //
// 1   2  3    4    5    6   7 // 
string xuli(vector <char > v ) {
    string ans = ""; 
    sort(v.begin(), v.end()); 
    f(i, v.size()) {
        ans += v[i]; 
    }
    return ans; 
}
int main() {
    vector<vector<pair<ll, string> >> vvp(8); 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // https://codeforces.com/problemset/problem/1042/B  // 
    mp["A"] = mp["B"] = mp["C"] = mp["AB"] = mp["AC"] = mp["BC"] = mp["ABC"] = INT_MAX;
    int n; 
    cin >> n; 
    string s; 
    vector <string> ve; 
    ll mina, minb, minc, minab, minac, minbc, minabc; 
    f1(i, n) {
        cin >> p[i].first >> p[i].second ;
        vector <char> str;
        f(j, p[i].second.size()) {
            str.push_back(p[i].second[j]);
        }
        p[i].second = xuli(str); 
    }
    /*fe(it, ve) {
        cout << it << " "; 
    }*/
    f1(i, n) {
        mp[p[i].second] = min(mp[p[i].second], p[i].first);
    }
    mina = mp["A"]; 
    minb = mp["B"];
    minc = mp["C"]; 
    minab = mp["AB"]; 
    minac = mp["AC"]; 
    minbc = mp["BC"]; 
    minabc = mp["ABC"]; 
    ll ans = INT_MAX; 
   // cout << minab + minc << " " << minac + minb << " " << mina + minbc << " " << mina + minb + minc << " " << minabc << endl; 
    ans = min({ minab + minc , minac + minb , mina + minbc , mina + minb + minc , minabc , minab + minbc , minab + minac , minbc + minac });
  //  cout << ans << endl;  
    if (ans > 1e8) cout << "-1";
    else cout << ans; 
}