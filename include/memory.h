#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <tools.h>

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

//moved point in shared_ptr, later point = nullptr
    shared_ptr(T*& pointer): _data(pointer)
    {
        if(pointer)
        {
            _count = new t_count(1);
            pointer = nullptr;
        }
        else
            _count = nullptr;
    }

    shared_ptr(const shared_ptr<T>& other): _data(other._data), _count(other._count)
    {
        ++*this->_count;
    }

    ~shared_ptr()
    {
        if(_data && *_count == 1)
        {
            delete _data;
            delete _count;
        }
        else if( _data && _count)
        {
            --*_count;
        }
    }

    shared_ptr<T>& operator=(const shared_ptr<T>& other) noexcept
    {
        this->~shared_ptr();
        this->_data = other._data;
        this->_count = other._count;
        ++*this->_count;
        return *this;
    }

    shared_ptr<T>& operator=(T*& other) noexcept
    {
        this->reset(other);
        return *this;
    }


    void reset() noexcept
    {
       this->~shared_ptr();
       this->_data = nullptr;
       this->_count = nullptr;
    }

//if you want use this point with new point use this method
    void reset(T*& new_point) noexcept
    {
       this->~shared_ptr();
       this->_data = new_point;
       if (new_point)
       {
            _count = new t_count(1);
            new_point = nullptr;
       }
       else
            _count = nullptr;
    }
  
    inline T& operator*() noexcept
    {
        return *this->_data;
    }

    inline T* operator->() noexcept
    {
        return this->_data;
    }

    inline t_count count() noexcept
    {
        if(this->_count == nullptr)
            return 0;
        return *this->_count;
    }
  
    void swap(shared_ptr<T> &other) noexcept
    {
        mstd::swap(this->_data, other._data);
        mstd::swap(this->_count, other._count);
    }

};

template<class T>
shared_ptr<T> make_shared(const T& Class)
{
    T* ptr = new T(Class);
    return mstd::shared_ptr(ptr);
}

}

#endif