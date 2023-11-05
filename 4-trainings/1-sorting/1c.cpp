#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &left, vector<int> right) {
  vector<int> result;
  int l = 0, r = 0;

  while (l < left.size() && r < right.size()) {
    if (left[l] < right[r]) {
      result.push_back(left[l]);
      l++;
    } else {
      result.push_back(right[r]);
      r++;
    }
  }

  while (l < left.size()) {
    result.push_back(left[l]);
    l++;
  }
  while (r < right.size()) {
    result.push_back(right[r]);
    r++;
  }
  return result;
}

vector<int> mergeSort(vector<int> &vec) {
  if (vec.size() <= 1) {
    return vec;
  }

  int mid = vec.size() / 2;
  vector<int> left(vec.begin(), vec.begin() + mid);
  vector<int> right(vec.begin() + mid, vec.end());

  left = mergeSort(left);
  right = mergeSort(right);
  return merge(left, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> sortedArray = mergeSort(arr);
  for (auto i : sortedArray) {
    cout << i << " ";
  }
  return 0;
}