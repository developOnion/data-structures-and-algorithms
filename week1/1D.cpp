#include <iostream>
#include <chrono>
using clk = std::chrono::high_resolution_clock;
volatile int sink_int = 0;

int main(void) {
  const int MAX_CAP = 100000;
  int n = MAX_CAP;
  int arr[MAX_CAP];

  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }

  auto t0 = clk::now();

  int *newArr = new int[n * 2];
  for (int i = 0; i < n; ++i) {
    *(newArr + i) = *(arr + 1);
  }
  *(newArr + n) = 10;
  n++;

  auto t1 = clk::now();

  delete []newArr;

  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() << "\n";
}
