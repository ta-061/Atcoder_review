#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,int>;

int main() {
  string input;
  cin >> input;

  int count = 0;


  for (int z = input.length() - 1; z >= 0; z--) {
    if (input[z] == '.') {
      count = z;
      break;
    }
  }

  for (int z = count + 1; z < input.length(); z++) {
    cout << input[z];
  }

  cout << endl;

  return 0;
}
