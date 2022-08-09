/*
  https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

  "ccaabbb"

  Tạo array A chứa char và frequency
  A { c: 2, a: 2, b: 3 }

  c1 = A[0].first
  c2 = null
  left = 0, right = 0, best_left = 0, best_right = 0

  for i:=1 to A.size do
    if (A[i].first == c1) {
      right++;
    }
    else if (A[i].first == c2 || c2 is null) {
      right++;
    }
    else {
      left = i - 1;
      right = i;
      c1 = A[i-1].first;
      c2 = A[i].first;
    }

    if (sum_frequency(left, right, A) > sum_frequency(best_left, best_right, A)) {
      best_left = left;
      best_right = right;
    }
  end

  return sum_frequency(best_left, best_right);
*/