#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  1. Có thể làm theo kiến thức phổ thông
  2. Bắt buộc phải có kiến thức về 1 thuật toán
*/

int main() {
  //                        j  <   i
  /*
    với mỗi i, mình tìm ra được dãy con tăng liên tục dài nhất từ j => i (j < i)


    Cách 1: 2 vòng for (O(n^2)) (baseline)
      dp[i]: dãy con tăng liên tục dài nhất xuất phát bằng i

    Cách 2:
      dp[i]: dãy con tăng liên tục dài nhất kết thúc bằng i
  */
  vector<int> arr = {1,3,5,2,5,3,6,8,9,10,3,4};
  int tmp = 1, res = 1;
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i] <= arr[i-1]) {
      tmp = 0;
    }

    if (++tmp > res) res = tmp;
  }

  cout << res;
}

