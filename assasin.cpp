
/*
// this c++ prgram calculates total no of possibility of placing n queens on nxn board
. means placling a queen is possible
*  means placling a queen is not possible
........
........
..*.....
........
........
.....**.
...*....
........



o/p - 65


*/




#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define rep(i,x,y) for(long long i=x; i<=y; i++)
const int mod = 1e9 + 7;

bool b[15];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int ans = 0;
  string s[8];
  for (int i = 0; i < 8; ++i)cin >> s[i];
  int p[8];
  for (int i = 0; i < 8; i++)p[i] = i;

// every time p[i] is changing
  do {

    bool ok = 1;

    for (int i = 0; i < 8; i++)
      if (s[i][p[i]] != '.')ok = 0; // if u place a queen here but it is not allowed

    memset(b, 0, 15); // make all as unvisited or o
    for (int i = 0; i < 8; i++) {
      if (b[i + p[i]]) // filled //bottom left to right
        ok = 0; // all same diagonal have same i+p[i]
      b[i + p[i]] = 1;
    }

    memset(b, 0, 15); // bottom right to top left
    for (int i = 0; i < 8; i++) {
      if (b[i + 7 - p[i]]) // filled
        ok = 0;
      b[i + 7 - p[i]] = 1;
    }
    ans += ok;

  } while (next_permutation(p, p + 8));

  cout << ans << endl;
}