#ifndef __TOOLS_H__
#define __TOOLS_H__

namespace mstd
{

//Work with ctor copy and operator=;
template<class T>
void swap(T& first, T& second);

}


//code

template<class T>
void mstd::swap(T& first, T& second)
{
    T tmp = first;
    first = second;
    second = tmp;
}

#endif