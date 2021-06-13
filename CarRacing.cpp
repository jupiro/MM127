#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <array>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>
#include <chrono>
#include <valarray>
#include <bitset>
using ll = long long;
using std::cin;
using std::cout;
using std::endl;
// std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;

void ask(std::vector<int> &v, std::vector<int> &gomi)
{
  if((int)v.size() <= 1)
    return;
  auto tv = v;
  gomi.clear();
  for (int i = 0; i < (int)v.size(); ++i)
  {
    cout << v[i] << " \n"[i + 1 == (int)v.size()];
  }
  cout.flush();
  std::string s;
  std::getline(cin, s);
  std::stringstream ss;
  ss << s;
  while(!ss.eof())
  {
    ss >> s;
    gomi.emplace_back(stoi(s));
  }

  for (int i = 0; i < (int)gomi.size(); ++i)
  {
    v[gomi[i]] = tv[i];
  }
}
int n, K, D;
std::vector<int> gomi, tmp;
void calc(std::vector<int> &v)
{
  if((int)v.size() <= K)
  {
    ask(v, gomi);
    return;
  }
  tmp.clear();
  for (int i = 0; i < K; ++i)
  {
    tmp.emplace_back(v[i]);
  }
  ask(tmp, gomi);
  gomi.clear();
  std::vector<std::vector<int>> vv(D + 1);
  std::vector<int> s;
  for (int i = 0; i < (int)tmp.size(); i++)
  {
    if(i % 2 == 0)
      s.emplace_back(tmp[i]);
    else
      vv[(i + 1) / 2].emplace_back(tmp[i]);
  }
  tmp = s;
  for (int i = K; i < (int)v.size(); ++i)
  {
    tmp.emplace_back(v[i]);
    if(i + 1 == (int)v.size() or (int)tmp.size() == K)
    {
      ask(tmp,gomi);
      int cur = 0;
      for (const auto &e : tmp)
      {
        if(cur < (int)s.size() and e == s[cur])
        {
          cur += 1;
        }
        else
        {
          vv[cur].emplace_back(e);
        }
      }
      tmp = s;
    }
  }
  for (int i = 0; i < (int)vv.size(); ++i)
  {
    calc(vv[i]);
  }
  v.clear();
  for (int i = 0; i < (int)vv.size(); ++i)
  {
    for(const auto &e : vv[i])
    {
      v.emplace_back(e);
    }
    if(i < (int)s.size())
    {
      v.emplace_back(s[i]);
    }
  }
}
void solve()
{
  cin >> n;
  cin >> K;
  D = (K + 1) / 2;
  std::string result;
  std::getline(cin, result); // read the endline

  std::mt19937 rnd(89);
  std::vector<int> order(n);
  for (int i = 0; i < n; ++i)
  {
    order[i] = i;
  }
  std::shuffle(order.begin(), order.end(), rnd);
  calc(order);
  for (int i = 0; i < (int)order.size(); ++i)
  {
    cout << order[i] << " \n"[i + 1 == (int)order.size()];
  }
  cout.flush();
}
int main() 
{
  solve();
  return 0;

}