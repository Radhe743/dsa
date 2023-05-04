#include <iostream>

#ifdef __unix__ // Check if OS is Unix (including macOS and Linux)
#include <unistd.h>
#elif defined(_WIN32) || defined(_WIN64) // Check if OS is Windows
#include <windows.h>
#endif

// Function to print an array in the desired format
void printArray(const int arr[], int size)
{
// Check if OS is Unix (including macOS and Linux)
#ifdef __unix__
  // std::cout << "\033[1;33m"; // Set text color to yellow
  std::cout << "\033[38;5;208m";
#endif

  std::cout << "[";

  for (int i = 0; i < size; ++i)
  {
    std::cout << arr[i];
    if (i != size - 1)
    {
      std::cout << ",";
    }
  }

  std::cout << "]";

// Check if OS is Unix (including macOS and Linux)
#ifdef __unix__
  std::cout << "\033[0m"; // Reset text color
#endif

  std::cout << std::endl;
}
