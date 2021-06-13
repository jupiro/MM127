// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() 
{
  int N;
  int K;

  cin >> N;
  cin >> K;

  string out="";
  string result;
  getline(cin, result); // read the endline

  vector<int> id(N);
  for (int i=0; i<N; i++) id[i]=i;

  //selection sort
  for (int i=0; i<N; i++)
  {
    int pos=i;      
    for (int k=i+1; k<N; k++)
    {       
      string race=to_string(id[pos])+" "+to_string(id[k]);
      cout << race << endl;
      cout.flush();

      getline(cin, result);
      if (result[0]=='1') pos=k;
    }
    out+=to_string(id[pos]);
    if (i<N-1) out+=" ";      

    std::swap(id[i],id[pos]);
  }
  cout << out << endl;
  cout.flush();
}