#include <iostream>

template<class T, int size>
class Array {
private:
    bool empty;
    int size_of_array;
    T *m_array;
public:
    Array();

    ~Array();

    bool is_empty();

    void push(T element, int index);

    void print();

    void deleted(int index);

    T *get_array();

    int get_size();

};

template<class T, int size>
Array<T, size>::Array() {
    empty = true;
    size_of_array = size;
    m_array = new T[size_of_array];
}

template<class T, int size>
Array<T, size>::~Array() {
    if(m_array != nullptr){
        delete[] m_array;
    }
}

template<class T, int size>
bool Array<T, size>::is_empty() {
    return empty;
}

template<class T, int size>
void Array<T, size>::push(T element, int index) {
    if (index > size_of_array - 1) {
        std::cout << "\nThere is no such index\n";
    } else {
        m_array[index] = element;
        empty = false;
    }
}

template<class T, int size>
void Array<T, size>::print() {
    std::cout << std::endl;
    for (int i = 0; i < size_of_array; ++i) {
        std::cout << m_array[i] << std::endl;
    }
}

template<class T, int size>
void Array<T, size>::deleted(int index) {
    if (index > size_of_array - 1) {
        std::cout << "\nThere is no such index\n";
    } else {
        for(int i = index; i < size_of_array; ++i){
            m_array[i] = m_array[i+1];
        }
        m_array[size_of_array-1] = 0;
        size_of_array--;
        if( size_of_array == 0){
            empty = true;
            m_array[index] = 0;
        }
    
//         T *temp;
//         temp = new T[size_of_array - 1];
//         for (int i = 0, j = 0; i < size_of_array; ++i) {
//             if (i != index) {
//                 temp[j] = m_array[i];
//                 ++j;
//             }
//         }
//         delete[] m_array;
//         m_array = temp;
//         --size_of_array;
//         if (size_of_array == 0) empty = true;
    }
}

template<class T, int size>
T *Array<T, size>::get_array() {
    m_array;
}

template<class T, int size>
int Array<T, size>::get_size() {
    return size_of_array;
}

int main() {
    Array<int, 2> a;
    a.push(2, 0);
    a.print();
    a.push(28, 1);
    a.print();
    a.deleted(0);
    a.print();
    std::cout << a.is_empty();
    return 0;
}
