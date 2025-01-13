#ifndef Y0_ALGORITHM_POOL_SRC_CONSTRUCT_HEAP_H
#define Y0_ALGORITHM_POOL_SRC_CONSTRUCT_HEAP_H

#include <functional>
#include <iostream>
#include <set>

namespace y0_algorightm_pool {
  template<typename T, typename ORDER, typename FUNC>
  bool construct_heap(std::multiset<T, ORDER> &heap, FUNC construct) {
    try
    {
      construct(heap);
    }
    catch (...) {
      std::cerr << __LINE__ << ':' << "cought any exception." << std::endl;
      return false;
    }

    return true;
  }

} // namespace y0_algorightm_pool

#endif

