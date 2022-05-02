#include "assignment/quick_sort.hpp"

#include <cassert>  // assert

#include "assignment/partitioning.hpp"  // partition, median_of_three

namespace assignment {

  void QuickSort::Sort(std::vector<int>& arr) const {
    quick_sort(arr, 0, static_cast<int>(arr.size()) - 1);
  }

  void QuickSort::quick_sort(std::vector<int>& arr, int start, int stop) const {
    assert(start >= 0);

    if (stop - start < 2) {
      return;
    }

    // вычисляем индекс опорного элемента ... median_of_three ...
    int pivot_index = median_of_three(arr, start, stop);
    quick_sort(arr, start, pivot_index);
    quick_sort(arr, pivot_index, stop);
    // производим разбиение относительно опорного элемента ...  partition ...
    // рекурсивно повторяем процедуру над левой и правой частью ...
  }

}  // namespace assignment