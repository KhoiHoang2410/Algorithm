#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/*
  Cho 1 dãy số nguyên A có độ dài N. Có câu lệnh truy vấn Q cho L và R, 
  yêu cầu phải tính tổng từ A[L] đến A[R].

  Cấu trúc dữ liệu:
    N Q
    dãy A
    các câu truy vấn L R

  Input:
    12 3
    1 3 5 2 5 3 6 8 9 10 3 4
    1 3
    3 5
    4 12

  Output:
    9
    12
    50

  Diều kiện:
    1 < N, Q < 10^5
    -10^9 < A[i] < 10^9
*/

/* 
  Hint 1
  Create array sum[i] = sum from index 0 into i.
*/

/* 
  Hint 2
  Create array sum[i] = sum from index 0 into i.
*/

int main() {
  vector<int> arr = {1,3,5,2,5,3,6,8,9,10,3,4};
  vector<int> left = {1,3,4}, right = {3,5,12};
  int n = arr.size(), q = left.size(), res;

  vector<int> sum = {arr[0]}, result = {};

  for (int i = 0; i < arr.size(); ++i) {
    sum.push_back(sum[i-1] + arr[i]);
  }

  for (int i = 0; i < q; ++i) {
    if (left[i] == 0) {
      result.push_back(sum[right[i]]);
    } else {
      result.push_back(sum[right[i]] - sum[left[i - 1]]);
    }
  }

  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << endl;
  }
}
