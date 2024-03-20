//
// Created by wjw on 2024/3/20.
//

#ifndef ALLTREE_DOUBLELIST_H
#define ALLTREE_DOUBLELIST_H
//
// Created by wjw on 2024/3/13.
//

#ifndef ALLTREE_LIST_HPP
#define ALLTREE_LIST_HPP

#include <memory>
#include <iostream>
#include <vector>
namespace Eula {
    using std::cout;
    using std::endl;
    template <class T>
    class DouList;
    template<class T>
    class ListNode
    {

    public:
        friend class DouList<T>;
        ListNode()
        {
            data_=T();
            next_= nullptr;
        }

        explicit  ListNode(const T& val)
        {
            data_=val;
            next_= nullptr;
            front_= nullptr;
        }
        ~ListNode()
        {

        }
    private:
        T data_;
        ListNode<T>* next_;
        ListNode<T>*front_;
    };
    template<class T>
    class DouList {
        public:
        using Node = ListNode<T>;
        DouList()
        {

        }
        private:
    };
}

#endif //ALLTREE_LIST_HPP

#endif //ALLTREE_DOUBLELIST_H
