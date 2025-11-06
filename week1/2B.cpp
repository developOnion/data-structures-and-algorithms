#include <iostream>
#include <chrono>
using clk = std::chrono::high_resolution_clock;
volatile int sink_int = 0;

int main(void) {
  const int MAX_CAP = 100000;
  int n = MAX_CAP / 2;
  int arr[MAX_CAP];

  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }

  int idx = n;

  auto t0 = clk::now();

  arr[idx - 1] = 0;
  n--;

  auto t1 = clk::now();

  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() << "\n";
}
