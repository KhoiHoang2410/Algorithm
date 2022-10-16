#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapify(vector<int>& heap, int index) {
    bool swappable = true;
    while (index != 0 && swappable) {
        int parent = (index - 1)/2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            swappable = false;
        }
    }
}

void heapify(vector<int>& heap) {
    bool swappable = true;
    int index = 0;
    while (swappable) {
        int left = index * 2 + 1, right = index * 2 + 2, swap_inx = index;
        
        if (left < heap.size() && heap[swap_inx < heap[left]]) swap_inx = left;
        if (right < heap.size() && heap[swap_inx < heap[right]]) swap_inx = right;

        if (heap[index] < heap[swap_inx]) {
            swap(heap[index], heap[swap_inx]);
            index = swap_inx;
        } else {
            swappable = false;
        }
    }
}

void insert_heap(vector<int>& heap, int value) {
    heap.push_back(value);
    heapify(heap, heap.size()-1);
}

void pop_heap(vector<int>& heap) {
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    heapify(heap);
}

int main() {
    // vector<int> heap{14,2,4,5,1,2,10,22,34,1};

    vector<int> heap{14,14,10};

    insert_heap(heap, 22);
    insert_heap(heap, 31);
    insert_heap(heap, 42);
    insert_heap(heap, 23);
    insert_heap(heap, 14);
    insert_heap(heap, 13);
    insert_heap(heap, 10);
    pop_heap(heap);

    for (auto i:heap) {
        cout << i << " ";
    }

    return 0;
}
