#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

vector<int> findMax(vector<int> &v, int k) {

  int n = v.size();
  vector<int> ans;

  int i{0}, j{0};

  list<int> maxq;

  while (j < n) {
    while (!maxq.empty() && maxq.back() < v[j]) {
      maxq.pop_back();
    }
    maxq.push_back(v[j]);

    if (j - i + 1 < k) {
      j++;
    } else if (j - i + 1 == k) {
        const int curMax = maxq.front();
        ans.push_back(curMax);

        if (curMax == v[i]) {
            maxq.pop_front();
        }

        i++;
        j++;
    }
  }

  return ans;
}

int main() {

  vector<int> v = {1, 3, 1, 2, 0, 5};
  int k = 3;
  vector<int> ans = findMax(v, k);
  for (const auto x : ans) {

    cout << x << " ";
  }
}
