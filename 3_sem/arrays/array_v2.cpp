#include <iostream>

struct S{
    S()=delete;
    S(const S&)=default;
    S&operator=(const S&)=delete;
    S(int){}
};
template <typename T>
class Array
{
public: 
    // Список операций:
    //
    explicit Array(size_t size , const T& val){
        data = reinterpret_cast <T*>(new char[sizeof(S)*size]);
        m_size=size;
        for (int i = 0; i < size; i++){
            new(data+i) T(val);
        }
    }
    Array(const Array & a){
        m_size=a.size();
        data = reinterpret_cast <T*>(new char[sizeof(S)*m_size]);
        for (int i = 0; i < a.size(); i++){
            new(data+i) T(a[i]);
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
        for (int i = 0; i < m_size; i++){
            (data+i)->~T();
        }
        delete data;
    }
    //   деструктор, если он вам необходим.
    //
    Array& operator=(const Array & a){
        for (int i = 0; i <= a.size(); i++){
            new(data+i) T(a[i]);
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
    Array <S> a(3,3);
    Array <S> b(2,2);
    a=b;
}
