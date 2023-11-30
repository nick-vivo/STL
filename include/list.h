#ifndef __LIST_H__
#define __LIST_H__

#include <memory.h>
#include <exception.h>
#include <tools.h>
#include <initializer_list>
#include <type_traits>

namespace mstd
{
    template <class T>
    class Node
    {
    public:
        T data;

        mstd::shared_ptr<Node<T>> next;
        mstd::shared_ptr<Node<T>> previous;

        Node() : data(T()), next(nullptr), previous(nullptr) {}

        Node(T data, mstd::shared_ptr<Node<T>> next = nullptr, mstd::shared_ptr<Node<T>> previous = nullptr) : data(data), next(next), previous(previous) {}
    };

//Все для итератора Начало

    template <class T>
    class Iterator
    {
        using ptr_n = mstd::shared_ptr<Node<T>>;
        mstd::shared_ptr<Node<T>> it;

    public:
        Iterator() : it(nullptr) {}

        Iterator(const ptr_n &new_it) : it(new_it) {}

        Iterator(const Iterator<T> &other) : it(other.it) {}

        bool operator==(const Iterator<T> &other)
        {
            return it == other.it;
        }

        bool operator!=(const Iterator<T> &other)
        {
            return it != other.it;
        }

        Iterator &operator=(const Iterator<T> &other)
        {
            it = other.it;
            return *this;
        }

        Iterator &operator++(void)
        {
            it = it->next;
            return *this;
        }

        Iterator operator++(int d)
        {
            ptr_n tmp = it;
            it = it->next;
            return tmp;
        }

        Iterator &operator--(void)
        {
            it = it->previous;
            return *this;
        }

        Iterator operator--(int d)
        {
            ptr_n tmp = it;
            it = it->previous;
            return tmp;
        }

        T& operator*()
        {
            if(it)  return it->data;
            else    throw mstd::exception("fail");

        }

        template <typename F>
        Iterator<T>& operator+=(F i)
        {
            static_assert(std::is_same<F, short>::value ||
                          std::is_same<F, unsigned short>::value ||
                          std::is_same<F, int>::value ||
                          std::is_same<F, unsigned int>::value ||
                          std::is_same<F, long int>::value ||
                          std::is_same<F, unsigned long int>::value);

            long int step = 0;

            if (i > 0)
            {
                while (step < i)
                {
                    this->operator++();
                    ++step;
                }
            }
            else
            {

                while (step > i)
                {
                    this->operator--();
                    --step;
                }
            }

            return *this;
        }

        template <typename F>
        Iterator<T>& operator-=(F i)
        {
            static_assert(std::is_same<F, short>::value ||
                          std::is_same<F, unsigned short>::value ||
                          std::is_same<F, int>::value ||
                          std::is_same<F, unsigned int>::value ||
                          std::is_same<F, long int>::value ||
                          std::is_same<F, unsigned long int>::value);

            long int step = 0;

            if (i > 0)
            {
                while (step < i)
                {
                    this->operator--();
                    ++step;
                }
            }
            else
            {

                while (step > i)
                {
                    this->operator++();
                    --step;
                }
            }

            return *this;
        }

        bool operator<(const Iterator& other) const
        {
            return it < other.it;
        }

        bool operator>(const Iterator& other) const
        {
            return it > other.it;
        }

        bool operator<=(const Iterator& other) const
        {
            return it <= other.it;
        }

        bool operator>=(const Iterator& other) const
        {
            return it >= other.it;
        }
    };
    

    template<class T, typename F>
    Iterator<T> operator+(F i, const Iterator<T>& it)
    {
        static_assert(std::is_same<F, short>::value ||
                  std::is_same<F, unsigned short>::value ||
                  std::is_same<F, int>::value ||
                  std::is_same<F, unsigned int>::value ||
                  std::is_same<F, long int>::value ||
                  std::is_same<F, unsigned long int>::value);

        Iterator<T> new_it = it;
        
        F step = 0;

        if (i > 0)
        {
            while(step < i)
            {
                ++new_it;
                ++step;
            }
        }
        else
        {

            while(step > i)
            {
                --new_it;
                --step;
            }
        }

        return new_it;
    }

    template<class T, typename F>
    Iterator<T> operator+(const Iterator<T>& it, F i)
    {
        static_assert(std::is_same<F, short>::value ||
                  std::is_same<F, unsigned short>::value ||
                  std::is_same<F, int>::value ||
                  std::is_same<F, unsigned int>::value ||
                  std::is_same<F, long int>::value ||
                  std::is_same<F, unsigned long int>::value);

        Iterator<T> new_it = it;
        
        F step = 0;

        if (i > 0)
        {
            while(step < i)
            {
                ++new_it;
                ++step;
            }
        }
        else
        {

            while(step > i)
            {
                --new_it;
                --step;
            }
        }

        return new_it;
    }

    template<class T, typename F>
    Iterator<T> operator-(const Iterator<T>& it, F i)
    {
        static_assert(std::is_same<F, short>::value ||
                  std::is_same<F, unsigned short>::value ||
                  std::is_same<F, int>::value ||
                  std::is_same<F, unsigned int>::value ||
                  std::is_same<F, long int>::value ||
                  std::is_same<F, unsigned long int>::value);

        Iterator<T> new_it = it;
        
        F step = 0;

        if (i > 0)
        {
            while(step < i)
            {
                --new_it;
                ++step;
            }
        }
        else
        {

            while(step > i)
            {
                ++new_it;
                --step;
            }
        }

        return new_it;
    }

//Все для итератора конец

    template <class T>
    class List
    {
    public:
        using t_size = int;

    private:
        using ptr_n = mstd::shared_ptr<Node<T>>;

        ptr_n _head;
        ptr_n _tail;
        t_size _count;

    public:
        List() : _head(), _tail(), _count(0) {}

        List(const List<T> &other) : List()
        {
            ptr_n tmp = other._head;

            do
            {
                this->push_back(tmp->data);
                tmp = tmp->next;

            } while (tmp != other._head);
        }

        List(List<T> &&other) : List()
        {
            this->swap(other);
        }

        List(std::initializer_list<T> values) : _head(), _tail(), _count(0)
        {
            for (T i : values)
            {
                this->push_back(i);
            }
        }

        List<T> &operator=(List<T> other)
        {
            this->swap(other);

            return *this;
        }

        List<T> &operator=(std::initializer_list<T> values)
        {
            this->clear();

            for (T i : values)
            {
                this->push_back(i);
            }

            return *this;
        }

        void push_back(T data)
        {
            ptr_n add(new Node(data));

            if (!_head)
            {
                _head = add;
                _tail = add;

                _head->previous = _tail;
                _head->next = _tail;

                _tail->previous = _head;
                _tail->next = _head;
            }
            else
            {
                _tail->next = add;
                add->previous = _tail;
                _tail = add;

                _tail->next = _head;
                _head->previous = _tail;
            }
            ++_count;
        }

        void push_front(T data)
        {
            ptr_n add(new Node(data));

            if (!_head)
            {
                _head = add;
                _tail = add;

                _head->previous = _tail;
                _head->next = _tail;

                _tail->previous = _tail;
                _tail->next = _head;
            }
            else
            {
                add->next = _head;
                _head->previous = add;
                _head = add;

                _head->previous = _tail;
                _tail->next = _head;
            }
            ++_count;
        }

        bool pop_back()
        {

            if (_count == 1)
            {
                _head = _tail = nullptr;
                --_count;
                return true;
            }

            if (_count == 0)
            {
                return false;
            }

            ptr_n node = _tail;
            node->previous->next = node->next;
            node->next->previous = node->previous;

            _tail = node->previous;
            --_count;
            return true;
        }

        bool pop_front()
        {
            if (_count == 1)
            {
                _head = _tail = nullptr;
                --_count;
                return true;
            }

            if (_count == 0)
            {
                return false;
            }

            ptr_n node = _head;
            node->previous->next = node->next;
            node->next->previous = node->previous;

            _head = node->next;
            --_count;
            return true;
        }

        void insert(t_size index, T data)
        {

            if (index > _count || index < -_count)
            {
                throw mstd::exception("Failed index");
            }

            if (index == 0 || index == -_count)
            {
                this->push_front(data);
                return;
            }
            if (index == _count || index == -1)
            {
                this->push_back(data);
                return;
            }

            ptr_n node = get_node__index(index);
            ;

            ptr_n add(new Node(data));

            add->previous = node->previous;
            node->previous->next = add;

            node->previous = add;
            add->next = node;

            ++_count;
        }

        void rm(t_size index)
        {
            if (index >= _count || index < -_count)
            {
                throw mstd::exception("Failed index");
            }

            if (index == 0 || index == -_count)
            {
                this->pop_front();
                return;
            }

            if (index == _count - 1 || index == -1)
            {
                this->pop_back();
                return;
            }

            ptr_n node = get_node__index(index);

            node->previous->next = node->next;
            node->next->previous = node->previous;

            --_count;
        }

        void clear()
        {
            while (_head)
            {
                this->pop_back();
            }
        }

        T &operator[](t_size index)
        {
            return get_node__index(index)->data;
        }

        T &at(t_size index)
        {
            if (index >= _count || index < -_count)
            {
                throw mstd::exception("Failed index");
            }

            return get_node__index(index)->data;
        }

        t_size size()
        {
            return _count;
        }

        void swap(List<T> &other)
        {
            _head.swap(other._head);
            _tail.swap(other._tail);
            mstd::swap(_count, other._count);
        }

    private:
        inline ptr_n get_node__index(t_size index) const noexcept
        {
            t_size tmp = 0;
            ptr_n node = _head;

            if (index > 0)
            {
                while (tmp != index)
                {
                    node = node->next;
                    ++tmp;
                }
            }
            else
            {
                while (tmp != index)
                {

                    node = node->previous;
                    --tmp;
                }
            }

            return node;
        }

    public:
        bool empty()
        {
            return !_head;
        }

        Iterator<T> begin()
        {
            Iterator<T> tmp(_head);
            return tmp;
        }

        Iterator<T> end()
        {
            Iterator<T> tmp(_tail);
            return tmp;
        }
    };

}

#endif