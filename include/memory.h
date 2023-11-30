#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <tools.h>

namespace mstd
{
using uint = unsigned int;

template<class T>
class shared_ptr
{

    T* _data;
    uint* _size;

public:

    shared_ptr<T>();

    shared_ptr<T>(T* data);

    shared_ptr<T>(const shared_ptr<T>& other);

    virtual ~shared_ptr();
    
    void reset();

    void reset(T* new_pointer) noexcept;

    void swap(mstd::shared_ptr<T>& other) noexcept;

    uint use_count() const noexcept;

    T& operator*() noexcept;

    T* operator->() noexcept;

    bool operator==(const shared_ptr<T>& other) const noexcept;

    bool operator!=(const shared_ptr<T>& other) const noexcept;

    bool operator<(const shared_ptr<T>& other) const noexcept;

    bool operator>(const shared_ptr<T>& other) const noexcept;

    bool operator<=(const shared_ptr<T>& other) const noexcept;

    bool operator>=(const shared_ptr<T>& other) const noexcept;

    shared_ptr<T>& operator=(const shared_ptr<T>& shared_pt);

    shared_ptr<T>& operator=(decltype(nullptr));

    operator bool() const;

};

}

//code


template<class T>
mstd::shared_ptr<T>::shared_ptr(): _data( nullptr ), _size( nullptr ) {}


template<class T>
mstd::shared_ptr<T>::shared_ptr(T* data): _data(data)
{
    {
        if ( _data )
            this->_size = new uint(1);
        else
            this->_size = nullptr;
    }

}


template <class T>
mstd::shared_ptr<T>::shared_ptr(const mstd::shared_ptr<T> &other) : _data(other._data), _size(other._size)
{
    if (other._data)
        ++*this->_size;
}


template <class T>
mstd::shared_ptr<T>::~shared_ptr()
{
    if (this->_data && *this->_size == 1)
    {
        delete this->_size;
        delete this->_data;
    }
    else if (this->_data && *this->_size > 1)
    {
        --*this->_size;
    }
    this->_data = nullptr;
    this->_size = nullptr;
}


template <class T>
void mstd::shared_ptr<T>::reset()
{
    this->~shared_ptr();
}


template <class T>
void mstd::shared_ptr<T>::reset(T *new_pointer) noexcept
{
    this->reset();
    this->_data = new_pointer;

    if (new_pointer)
        this->_size = new uint(1);
}

template<class T>
void mstd::shared_ptr<T>::swap(mstd::shared_ptr<T>& other) noexcept
{
    mstd::swap(this->_data, other._data);
    mstd::swap(this->_size, other._size);
}

template <class T>
mstd::uint mstd::shared_ptr<T>::use_count() const noexcept
{
    return *this->_size;
}


template <class T>
T &mstd::shared_ptr<T>::operator*() noexcept
{
    return *_data;
}


template <class T>
T *mstd::shared_ptr<T>::operator->() noexcept
{
    return _data;
}


template <class T>
bool mstd::shared_ptr<T>::operator==(const shared_ptr<T> &other) const noexcept
{
    return (this->_data == other._data);
}


template <class T>
bool mstd::shared_ptr<T>::operator!=(const mstd::shared_ptr<T> &other) const noexcept
{
    return (this->_data != other._data);
}

template <class T>
bool mstd::shared_ptr<T>::operator<(const shared_ptr<T> &other) const noexcept
{
    return (this->_data < other._data);
}

template <class T>
bool mstd::shared_ptr<T>::operator>(const shared_ptr<T> &other) const noexcept
{
    return (this->_data > other._data);
}


template <class T>
bool mstd::shared_ptr<T>::operator<=(const shared_ptr<T> &other) const noexcept
{
    return (this->_data <= other._data);
}

template <class T>
bool mstd::shared_ptr<T>::operator>=(const shared_ptr<T> &other) const noexcept
{
    return (this->_data >= other._data);
}

template <class T>
mstd::shared_ptr<T>& mstd::shared_ptr<T>::operator=(const mstd::shared_ptr<T> &shared_pt)
{
    if (this->_data)
        this->~shared_ptr();

    this->_data = shared_pt._data;
    this->_size = shared_pt._size;

    if (this->_data)
        ++*this->_size;

    return *this;
}


template<class T>
mstd::shared_ptr<T>& mstd::shared_ptr<T>::operator=(decltype(nullptr))
{
    this->~shared_ptr();

    return *this;
}


template <class T>
mstd::shared_ptr<T>::operator bool() const
{
    if (_data)
        return true;
    else
        return false;
}



#endif