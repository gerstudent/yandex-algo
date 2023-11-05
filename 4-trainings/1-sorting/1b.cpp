#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &vec, int low, int high) {
  int pivotIndex = low + rand() % (high - low);
  int pivot = vec[pivotIndex], i = low, j = high;

  while (low <= high) {
    while (vec[low] < pivot) low++;
    while (vec[high] > pivot) high--;
    if (low >= high) break;
    swap(vec[low++], vec[high--]);
  }
  return high;
}

void quickSort(vector<int> &vec, int low, int high) {
  if (low < high) {
    int p = partition(vec, low, high);
    quickSort(vec, low, p);
    quickSort(vec, p + 1, high);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  quickSort(vec, 0, n - 1);
  for (auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}