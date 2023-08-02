#ifndef __LIST_H__
#define __LIST_H__

namespace mstd
{
    typedef int type_s;

    template <typename T>
    class list
    {
    private:
        template <typename N>
        class node
        {
        public:
            node *_pNext;
            N _data;

            node(N data = N(), node *pNext = nullptr) : _data(data), _pNext(pNext) {}
        };

        node<T> *_head;
        type_s _size;

    public:
        list() : _head(nullptr), _size(0) {}
        ~list();

        void push_back(T data) noexcept;

        inline type_s size() const noexcept
        {
            return this->_size;
        }

        inline T &operator[](const type_s index) noexcept;

        void pop_front();

        void push_front(T data);

        void clear()
        {
            this->~list();
        }

        void insert(T data, type_s index);
        void removeAt(type_s index);
    };

    template <typename T>
    list<T>::~list()
    {
        while (this->_head != nullptr)
            this->pop_front();
    }

    template <typename T>
    void list<T>::push_back(T data) noexcept
    {
        if (this->_head == nullptr)
            this->_head = new node<T>(data);
        else
        {
            node<T> *current = this->_head;
            while (current->_pNext != nullptr)
                current = current->_pNext;
            current->_pNext = new node<T>(data);
        }
        ++this->_size;
    }

    template <typename T>
    inline T &list<T>::operator[](const type_s index) noexcept
    {
        if (index >= this->_size || index < 0)
        {
            throw "Bad index";
        }
        type_s count = 0;
        node<T> *current = this->_head;

        while (count != index)
        {
            current = current->_pNext;
            ++count;
        }
        return current->_data;
    }

    template <typename T>
    void list<T>::pop_front()
    {
        if (this->_head != nullptr)
        {
            node<T> *current = this->_head;
            this->_head = this->_head->_pNext;
            delete current;
            --this->_size;
        }
        else
        {
            throw "Size is 0, HEAD = nullptr";
        }
    }

    template <typename T>
    void list<T>::push_front(T data)
    {
        this->_head = new node<T>(data, this->_head);
        ++this->_size;
    }

    template <typename T>
    void list<T>::insert(T data, type_s index)
    {
        if (index == 0)
        {
            this->push_front(data);
        }
        else if (index > 0 && index <= this->_size)
        {
            node<T> *previous = this->_head;
            for (type_s i = 0; i < index - 1; ++i)
                previous = previous->_pNext;

            node<T> *newNode = new node<T>(data, previous->_pNext);
            previous->_pNext = newNode;
            ++this->_size;
        }
        else
        {
            throw "Fail index";
        }
    }

    template <typename T>
    void list<T>::removeAt(type_s index)
    {
        if (index == 0)
        {
            this->pop_front();
        }
        else if (index > 0 && index < this->_size)
        {
            node<T> *previous = this->_head;
            for (type_s i = 0; i < index - 1; ++i)
            {
                previous = previous->_pNext;
            }
            node<T> *to_Delete = previous->_pNext;

            previous->_pNext = to_Delete->_pNext;
            --this->_size;
            delete to_Delete;
        }
        else
        {
            throw "Fail index";
        }
    }

}
#endif