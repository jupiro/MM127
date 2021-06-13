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

int main() 
{

  int n, K;
  cin >> n;
  cin >> K;

  std::string out="";
  std::string result;
  std::getline(cin, result); // read the endline

  std::vector<int> id(n);
  for (int i=0; i<n; i++) id[i]=i;

  //selection sort
  for (int i=0; i<n; i++)
  {
    int pos=i;      
    for (int k=i+1; k<n; k++)
    {       
      std::string race=std::to_string(id[pos])+" "+std::to_string(id[k]);
      cout << race << endl;
      cout.flush();

      std::getline(cin, result);
      if (result[0]=='1') pos=k;
    }
    out+=std::to_string(id[pos]);
    if (i<n-1) out+=" ";      

    std::swap(id[i],id[pos]);
  }
  cout << out << endl;
  cout.flush();
}