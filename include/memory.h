#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <tools.h>
#include <iostream>
namespace mstd
{
 
using t_count = unsigned int;

template<typename T>
class shared_ptr
{
private:
    T* _data;
    t_count* _count;
public:
    shared_ptr(): _data(nullptr), _count(nullptr) {}

    shared_ptr(T* pointer): _data(pointer)
    {
        if(pointer == nullptr)
            _count = nullptr;
        else
            _count = new t_count(1);
    }

    shared_ptr(const shared_ptr<T>& other): _data(other._data), _count(other._count)
    {
        ++*this->_count;
    }

    shared_ptr& operator=(const shared_ptr& other) 
    {
        this->~shared_ptr();
        this->_data = other._data;
        this->_count = other._count;
        ++*this->_count;
        return *this;
    }

    inline T& operator*()
    {
        return *this->_data;
    }

    inline T* operator->()
    {
        return this->_data;
    }

    inline t_count count()
    {
        return *this->_count;
    }

    void swap(shared_ptr<T> &other)
    {
        mstd::swap(this->_data, other._data);
        mstd::swap(this->_count, other._count);
    }

    ~shared_ptr()
    {
        if(_data && *_count == 1)
        {
            delete _data;
            delete _count;
            std::cout << "Вызвался декструктор, память очистилась";
        }
        else if( _data && _count)
        {
            --*_count;
            std::cout << "Вызвался деструткор -1";
        }
    }

};


}

#endif