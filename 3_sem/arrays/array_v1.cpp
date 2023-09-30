#include <iostream>

template <typename T>
class Array
{
public: 
    // Список операций:
    //
    explicit Array(size_t size , const T& val){
        data = new T[size];
        m_size=size;
        for (int i = 0; i < size; i++){
            data[i]=val;
        }
    }
    Array(const Array & a){
        m_size=a.size();
        data = new T[a.size()];
        for (int i = 0; i < a.size(); i++){
            data[i]=a[i];
        }
    }
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    //
    Array(const Array && a){
        std::swap(a.data, data);
        std::swap(a.m_size,m_size);
    }
    //   конструктор перемещения
    //
    ~Array(){
        delete data;
    }
    //   деструктор, если он вам необходим.
    //
    Array& operator=(const Array & a){
        for (int i = 0; i <= a.size(); i++){
            data[i]=a[i];
        }
        return *this;
    }
    //   оператор копирующего присваивания.
    //
    Array& operator=(Array && a){
        std::swap(a.data, data);
    }
    //   оператор перемещающего присваивания.
    //
    size_t size() const{
        return m_size;
    }
    //   возвращает размер массива (количество
    //                              элементов).
    //
    T& operator[](size_t idx){
        return data[idx];
    }
    const T& operator[](size_t idx) const{
        return data[idx];
    }
    //   две версии оператора доступа по индексу.
private:
    T* data = nullptr;
    size_t m_size;
};
int main(){
    Array <int> a(3,3);
    Array <int> c(4,2);
    std::cout<<a[2];
    Array <int> b = a;
    a=c;
    std::cout<<a[2];
}
