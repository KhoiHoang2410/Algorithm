#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr = {1,3,5,2,5,3,6,8,9,10,3,4}, tmp, res;
// 2 cách chấm trong thuật toán
// - OI: điểm = số lượng test pass
// - ACM: điểm = số lượng bài pass hết test

void Try(int i) {
  if (arr[i] > tmp.back()) {
    tmp.push_back(arr[i]);
    if (i < arr.size() - 1) Try(i + 1);
  }
  if (tmp.size() > res.size()) res = tmp;
}

int method_2() {
  for (int i = 0; i < arr.size() - 1; ++i) {
    tmp.clear();
    tmp.push_back(arr[i]);
    Try(i + 1);
  }
  return res.size();
}

int main() {
  // c1: sinh ra tất cả dãy: 2^n
  // c2: với mỗi i, mình tìm dãy con tăng dài nhất xuất phát từ i (O(2^n))
  // c3: 
  /*
         x     x   x x x x x
    arr: 1,3,5,2,5,3,6,8,9,10,3,4
    dp[i]: phần tử nhỏ nhất x sao cho tồn tại 1 dãy con tăng kết thúc tại x có độ dài là i
    dp[i]: lưu phần tử cuối của dãy con tăng có độ dài là i

    loop i:=0 => n do 
      ở mỗi i mình có mảng dp cho các số từ arr[0] => arr[i-1]
      dp có length là m

      for (int j = m; j>0; --i)
        if (arr[i] > dp[j])
          dp[j+1] = min(dp[j+1], arr[i]);
    end
 i  1 2 3 4 5 6 7 8 9 10



    arr: 1,3,5,2,5,3,6,8,9,10,3,4

    1 3 10 2 4 5 6


    1
    1 3
    1 3 10
    1 2 10
    1 2 4
    1 2 4 5
    1 2 4 5 6   x

    1 3
    1 5
    3 5
    1 2

    1
    1 3
    1 3 5
    1 2 5
    1 2 5      3
    1 2 3
    1 2 3 6
    1 2 3 6 8
    1 2 3 6 8 9
    1 2 3 6 8 9 10
    1 2 3 6 8 9 10
    1 2 3 4 8 9 10
  */

  
}
