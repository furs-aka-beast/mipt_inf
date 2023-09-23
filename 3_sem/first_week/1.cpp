#include <iostream>

template<typename T, size_t arr_size>
void print_array(T* arr){
    std::cout<< *arr;
    for (int i = 1; i < arr_size; i++){
        std::cout<<' '<<arr[i];
    }
    std::cout<<'\n';
};

int main() {
  int arr[12] = {1, 0, 2, -1, 3, -2, 4, -5, 6, -7, 8, -9};
  print_array<int, 12>(arr);
  return 0;
}