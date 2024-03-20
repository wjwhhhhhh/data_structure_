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
            front_= nullptr;
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
        using UNode=std::unique_ptr<Node>;
        DouList()
        {
            begin_= new Node;
            end_= new Node;
            begin_->next_=end_;
            end_->front_=begin_;
        }
        void push_front(const T&val)
        {
            insert_back(begin_, val);
        }
        void push_back(const T&val)
        {
            insert_front(end_,val);
        }
        void insert_front(Node * ing,const T&val)
        {
            if(ing== nullptr)return ;
            auto tem=new Node(val);
            auto front=ing->front_;
            front->next_=tem;
            tem->next_=ing;
            ing->front_=tem;
            tem->front_=front;
        }
        void insert_back(Node*ing,const T&val)
        {
            if(ing== nullptr)return ;
            auto tem=new Node(val);
            auto back=ing->next_;
            ing->next_=tem;
            tem->next_=back;
            back->front_=tem;
            tem->front_=ing;
        }
        Node* find(const T&val)
        {
            auto tem=begin_->next_;
            while(tem!=end_)
            {
                if(tem->data_==val)return tem;
                tem=tem->next_;
            }
            return nullptr;
        }
        void erase(const T&val)
        {
            auto tem=begin_->next_;
            while(tem!=end_)
            {
                tem=tem->next_;
                if(tem->front_->data_==val)
                {
                    erase(tem->front_);
                }
            }
            return ;
        }
        void erase(Node* tem)
        {
            auto front=tem->front_;
            auto next=tem->next_;
            front->next_=next;
            next->front_=front;
            delete tem;
        }
        void show()
        {
            auto tem=begin_->next_;
            while(tem!=end_)
            {
                cout<<tem->data_<<endl;
                tem=tem->next_;
            }
            return ;
        }
        private:
        Node* begin_;
        Node* end_;
    };
}

#endif //ALLTREE_LIST_HPP

#endif //ALLTREE_DOUBLELIST_H
