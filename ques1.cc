#include <iostream>

template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T> void insertion_sort(T *arr, int size) {
  // int j;
  // for (int i = 0; i < size; i++) {
  //   j = i;
  //   while (j > 0 && arr[j - 1] > arr[j]) {
  //     swap(arr[j - 1], arr[j]);
  //     j--;
  //   }
  // }
  int j;
  for (int i = 0; i < size; i++) {
    T temp = arr[i];
    j = i - 1;
    while (j > 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

template <typename T> void bubble_sort(T *arr, int size) {
  // for (int i = 1; i <= size; i++) {
  //   if (arr[i] < arr[i - 1]) {
  //     swap(arr[i], arr[i - 1]);
  //   }
  //   bubble_sort(arr, size - 1);
  // }
  for (int i = 0; i < size; i++) {
    for (int j = 1; j < size - 1; j++) {
      if (arr[j - 1] > arr[j])
        swap(arr[j - 1], arr[j]);
    }
  }
}

template <typename T> void selection_sort(T *arr, int size) {
  int min_idx;
  for (int i = 0; i < size - 1; i++) {
    min_idx = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }
    if(min_idx != i){
      swap(arr[i],arr[min_idx]);
    }
  }
}

template <typename T> void sort_array_menu(T *arr, int size) {
  std::cout << "How you want to sort the array\n"
            << "1. Insertion Sort\n2. Bubble Sort\n3. Selection Sort: ";
  int n;
  std::cin >> n;
  switch (n) {
  case 1:
    insertion_sort(arr, size);
    break;
  case 2:
    bubble_sort(arr, size);
    break;
  case 3:
    selection_sort(arr, size);
    break;
  default:
    std::cout << "Please chose from the above options\n";
    break;
  }
}

int main(void) {
  int arr[]{4, 4, 8, 2, 5, 63, 65, 32, 132, 343};
  sort_array_menu(arr, 10);
  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
