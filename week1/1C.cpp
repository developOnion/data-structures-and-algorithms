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

  int index = n;

  // insert to the beginning
  auto t0 = clk::now();

  // shifting
  for (int i = n - 1; i >= index; i--) {
    arr[i + 1] =  arr[i];
  }
  arr[index] = 10; // insert 10 to the front
  n++;

  auto t1 = clk::now();
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() << "\n";
}
