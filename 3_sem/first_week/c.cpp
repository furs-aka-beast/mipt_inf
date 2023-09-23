#include <iostream>

template <typename T, size_t const arr_size>
void read_array(T* arr){
    for (int i=0; i< arr_size; i++){
        std::cin>>arr[i];
    }
};

int main() {
  size_t const arr_size = 5;
  double* arr_d = new double[arr_size];
  read_array<double, arr_size>(arr_d);
  delete[] arr_d;
  return 0;
}