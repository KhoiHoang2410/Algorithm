#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapify(vector<int>& heap, int index) {
    while (index < heap.size()) {
        int left = index * 2 + 1, right = index * 2 + 2, swap_inx = index;
        
        if (left < heap.size() && heap[swap_inx < heap[left]]) swap_inx = left;
        if (right < heap.size() && heap[swap_inx < heap[right]]) swap_inx = right;

        if (heap[index] < heap[swap_inx]) {
            swap(heap[index], heap[swap_inx]);
        } else {
            break;
        }

        index = swap_inx;
    }
}

void rebuild_heap(vector<int>& arr) {
    int last_parent = arr.size() / 2;

    for (int i = last_parent; i >= 0; --i) {
        heapify(arr, i);
    }
}

void heap_sort(vector<int>& heap) {

}

int main() {
    vector<int> heap{14,2,4,5,1,2,10,22,34,1};

    rebuild_heap(heap);

    for (auto i:heap) {
        cout << i << " ";
    }

    return 0;
}
