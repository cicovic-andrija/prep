// #my-hard-2

#include "markers.h"
#include "vect.h"

#include <algorithm>
#include <tuple>

std::vector<int> extract_k_smallest(std::vector<std::vector<int>>&& arrays, int k);

int main()
{
    __BEGIN

    print_vec(extract_k_smallest({{ 1, 10, 100 }, { 2, 20, 200 }, { 3, 30, 300 }, { 4, 40, 400 }}, 6));

    __END
}

// Solution.

// 0 - value
// 1 - idx of array of origin
// 2 - idx of value in array of origin
using node = std::tuple<int, int, int>;

class MinHeap {
private:
    std::vector<node> heap;

    void heapify_up(int idx);
    void heapify_down(int idx);

public:
    void push(node nd) {
        heap.push_back(nd);
        heapify_up(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }

    node top() const {
        return heap.front();
    }

    bool empty() const {
        return heap.empty();
    }
};

void MinHeap::heapify_up(int idx)
{
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (std::get<0>(heap[idx]) < std::get<0>(heap[parent])) {
            std::swap(heap[idx], heap[parent]);
            idx = parent;
            continue;
        }
        break;
    }
}

void MinHeap::heapify_down(int idx)
{
    int n = heap.size();
    while (2 * idx + 1 < n) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int min = idx;
        if (left < n && std::get<0>(heap[left]) < std::get<0>(heap[min])) {
            min = left;
        }
        if (right < n && std::get<0>(heap[right]) < std::get<0>(heap[min])) {
            min = right;
        }
        if (min != idx) {
            std::swap(heap[idx], heap[min]);
            idx = min;
            continue;
        }
        break;
    }
}

std::vector<int> extract_k_smallest(std::vector<std::vector<int>>&& arrays, int k)
{
    int n = arrays.size();
    MinHeap min_heap;

    for (int i = 0; i < n; ++i) {
        if (!arrays[i].empty()) min_heap.push({ arrays[i][0], i, 0 });
    }

    std::vector<int> smallest;
    while (k-- && !min_heap.empty()) {
        node nd = min_heap.top();
        min_heap.pop();
        smallest.push_back(std::get<0>(nd));
        int array_idx = std::get<1>(nd);
        std::vector<int>::size_type next_val_idx = std::get<2>(nd) + 1;
        if (next_val_idx < arrays[array_idx].size()) {
            min_heap.push({ arrays[array_idx][next_val_idx], array_idx, next_val_idx });
        }
    }

    return smallest;
}
