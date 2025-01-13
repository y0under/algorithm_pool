#include "construct_heap.h"

struct Item {
  struct Compare {
    bool operator ()(const Item &lhs, const Item &rhs) {
      return std::tie(lhs.a, lhs.b, lhs.c) <
        std::tie(rhs.a, rhs.b, rhs.c);
    }
  };

  int a;
  int b;
  int c;
};

int main() {
  auto construct = [](std::multiset<Item, Item::Compare> &heap) {
    for (int i = 0; i < 10; ++i) {
      Item item;
      item.a = (10 - i) % 3;
      item.b = i;
      item.c = i % 3;
      heap.insert(item);
    }
  };

  std::multiset<Item, Item::Compare> heap;
  y0_algorightm_pool::construct_heap<Item, Item::Compare>(heap, construct);
  for (const auto &e: heap) {
    std::cout << e.a << ' ' << e.b << ' ' << e.c << std::endl;
  }
}
