#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, cnt = 0;
  vector<int> arr;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }
  cin >> x;
  for (int i = 0; i < n; i++) {
    if (arr[i] < x) {
      cnt++;
    }
  }
  cout << cnt << endl << n - cnt << endl;
  return 0;
}