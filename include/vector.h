#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <tools.h>

namespace mstd
{
using t_size = long int;

#define __STEP_STANDART 5
template<typename T>
class vector
{
private:
    t_size _step;
    t_size _capacity;
    t_size _size;
    T* _data;
public:
    vector();
    vector(const vector<T> &other); 

    ~vector();

    T& operator=(const vector<T> &other) = delete;

    void swap(vector<T> &other) noexcept;

    inline t_size capacity() const noexcept;

    inline t_size size() const noexcept;

    void push_back(T const &value) noexcept;

    void insert(t_size index, T const& value);

    inline T& at(t_size index);

// //If size == 0 method do not throw except 
    void pop_back();

    inline void clear() noexcept;

};

//Реализация
template <typename T>
vector<T>::vector() : _step(__STEP_STANDART), _capacity(0), _size(0), _data(nullptr) {}

template <typename T>
vector<T>::vector(const vector<T> &other) : _step(other._step), _capacity(other._capacity), _size(other._size), _data(new T[this->_capacity])
{
    for (t_size i = 0; i < this->_size; ++i)
        this->_data[i] = other._data[i];
}

template <typename T>
vector<T>::~vector()
{
    if (this->_data != nullptr)
        delete[] this->_data;
}

template <typename T>
void vector<T>::swap(vector<T> &other) noexcept
{
    mstd::swap(this->_data, other._data);
    mstd::swap(this->_size, other._size);
    mstd::swap(this->_step, other._step);
    mstd::swap(this->_capacity, other._capacity);
}

template <typename T>
inline mstd::t_size mstd::vector<T>::capacity() const noexcept
{
    return this->_capacity;
}

template <typename T>
inline mstd::t_size mstd::vector<T>::size() const noexcept
{
    return this->_size;
}

template <typename T>
void mstd::vector<T>::push_back(T const &value) noexcept
{
    if (this->_size + 1 > this->_capacity)
    {
        while (this->_size + 1 > this->_capacity)
            this->_capacity += this->_step;
        vector<T> cp(*this);
        cp.swap(*this);
    }
    this->_data[this->_size] = value;
    ++this->_size;
}

template <typename T>
void vector<T>::insert(t_size index, T const &value)
{
    if (index > this->_size || index < 0)
    {
        throw "Index is bad value"; // TODO: позже приписать сюда свой runtime
    }
    this->push_back(value);
    for (t_size i = this->_size - 1; i != index; --i)
    {
        mstd::swap(this->_data[i], this->_data[i - 1]);
    }
}

template <typename T>
inline T& vector<T>::at(t_size index)
{
    if (index >= this->_size || index < 0)
    {
        throw "Index is bad value"; // TODO: позже приписать сюда свой runtime
    }
    return this->_data[index];
}

template <typename T>
void mstd::vector<T>::pop_back()
{
    if (this->_size - 1 > 0)
    {
        --this->_size;
        if (this->_capacity - this->_size > this->_step)
        {
            this->_capacity -= this->_step;
            vector<T> cp(*this);
            cp.swap(*this);
        }
    }
    else if (this->_size - 1 == 0)
        this->clear();
}

template <typename T>
inline void vector<T>::clear() noexcept
{
    if (_data != nullptr)
    {
        delete[] this->_data;
        this->_data = nullptr;
        this->_size = 0;
        this->_capacity = 0;
        this->_step = __STEP_STANDART;
    }
}

}

#endif