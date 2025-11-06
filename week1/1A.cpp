#include <iostream>
#include <chrono>
using clk = std::chrono::high_resolution_clock;
volatile int sink_int = 0;

int main(void) {
  const int MAX_CAP = 100000;
  int n = 0;
  int arr[MAX_CAP];

  auto t0 = clk::now();

  arr[0] = 10;
  n++;

  auto t1 = clk::now();
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() << "\n";
}
