#ifndef __SET_H__
#define __SET_H__

#include <tools.h>
#include <memory.h>
#include <list.h>
#include <exception.h>

namespace mstd
{
    //Для работы класса должны быть перегружены оператор ==, <, >. Через компаратор не делал
    template<class T>
    class Set
    {
        using ptr = mstd::shared_ptr<T>;
        using t_size = unsigned int;

        struct Node
        {
            T data;
            mstd::shared_ptr<Node> left;
            mstd::shared_ptr<Node> right;

            Node(T data): data(data), left(nullptr), right(nullptr) {}

            Node(T data, mstd::shared_ptr<Node> left, mstd::shared_ptr<Node> right): data(data), left(left), right(right) {}

            T data_const() const
            {
                return this->data;
            }
        };

        using ptr_n = mstd::shared_ptr<Node>;

        ptr_n root;
        t_size _size;

    public:

        Set(): root(nullptr), _size(0) {}

        Set(const Set& other): Set()
        {
            List<T> ls = other.get_list();

            for(t_size i = 0; i < ls.size(); ++i)
            {
                this->insert( ls.at(i) );
            }
        }

        Set(std::initializer_list<T> values): Set()
        {        
            for (T i : values) 
            {
                this->insert(i);
            }
        }

        Set(Set&& other): Set()
        {
            this->swap(other);
        }
        
        void swap(Set& other)
        {
            mstd::swap(this->root, other.root);
            mstd::swap(this->_size, other._size);
        }

        void insert(T data)
        {
            ptr_n node = new Node(data); 

            if( !root )
            {
                root = node;
            }
            else
            {
                ptr_n find_parent = __findNode(root, data);
                
                if( !find_parent )
                {
                    return;
                }
                else if( find_parent->data > data )
                {
                    find_parent->right = node;
                }
                else if( find_parent->data < data)
                {
                    find_parent->left = node;
                }
            }
            ++_size;
        }

        void erase(T src)
        {
            mstd::List<T> ls = this->get_list();

            this->root = nullptr;

            for(t_size i = 0; i < ls.size(); ++i)
            {
                if( src == ls.at(i) )
                {
                    --_size;
                    continue;
                }
                this->insert( ls.at(i) );
            }
        }

        bool empty() const noexcept
        {
            return !root;
        }

        t_size size() const noexcept
        {
            return this->_size;
        }

    private:
    
    ptr_n __findNode(ptr_n src, T dst)
    {
        if ( src->data == dst )
        {
            return nullptr;
        }
        else if( src->data < dst )
        {
            if( !src->left )
                return src;
            src = src->left;
        }
        else if( src->data > dst )
        {
            if ( !src->right )
                return src;
            src = src->right;
        }

        src = __findNode(src, dst);
        
        return src;
    }

    public:

        List<T> get_list() const
        {
            List<T> ls;

            __get_list(ls, root);

            return ls;
        }

    private:
        void __get_list(List<T>& list, ptr_n node) const
        {
            if (node)
            {
                __get_list(list, node->right);
                list.push_back(node->data_const());
                __get_list(list, node->left);
            }
        }

    };

}

#endif