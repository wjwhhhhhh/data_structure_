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
    template <class T>
    class ListPtr;
    template<class T>
    class ListNode
    {

    public:
        friend class DouList<T>;
        friend class ListPtr<T>;
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
    template <class T>
    class ListPtr
    {
        using Node = ListNode<T>;
        using UNode=std::unique_ptr<Node>;
        using Ptr=ListPtr<T>;
        public:
        ListPtr()
        {

        }
        ListPtr(Node *val):val_(val){
        }

        ~ListPtr()=default;
        Ptr & operator++()
        {
            val_=val_->next_;
            return *this;
        }
        Ptr operator++(int)
        {
            Ptr temp=*this;
            ++(*this);
            return temp;
        }
        Ptr &operator--()
        {
            val_=val_->front_;
            return *this;
        }
        Ptr operator--(int)
        {
            Ptr temp=*this;
            --(*this);
            return temp;
        }
        T& operator *()
        {
            return (*val_).data_;
        }
        Node*operator->()
        {
            return val_;
        }
        bool operator==(const Ptr&tem)
        {
            return this->val_ == tem.val_;
        }
        bool operator!=(const Ptr&tem)
        {
            return !(*this==tem);
        }
        Node *get()
        {
            return val_;
        }
    private:
        Node *val_;
    };
    template<class T>
    class DouList {
        public:
        using Node = ListNode<T>;
        using UNode=std::unique_ptr<Node>;
        using Ptr=ListPtr<T>;
        DouList(): begin_(new Node()), end_(new Node())
        {
            begin_->next_=end_.get();
            end_->front_=begin_.get();
        }
        ~DouList()
        {

            Ptr p1=begin(),p2;
            do {
                p2=p1->next_;
                delete p1.get();
                p1=p2;
            } while (p1!=end());
            delete end().get();
        }
        void push_front(const T&val)
        {
            insert_back(begin_, val);
        }
        void push_back(const T&val)
        {
            insert_front(end_,val);
        }
        void insert_front(Ptr ing,const T&val)
        {
            if(ing== nullptr)return ;
            auto tem=new Node(val);
            auto front=ing->front_;
            front->next_=tem;
            tem->next_=ing.get();
            ing->front_=tem;
            tem->front_=front;
        }
        void insert_back(Ptr ing,const T&val)
        {
            if(ing== nullptr)return ;
            auto tem=new Node(val);
            auto back=ing->next_;
            ing->next_=tem;
            tem->next_=back;
            back->front_=tem;
            tem->front_=ing.get();
        }
        Ptr find(const T&val)
        {
            auto tem=begin();
            while(tem!=end())
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
        void erase(Ptr tem)
        {
            auto front=tem->front_;
            auto next=tem->next_;
            front->next_=next;
            next->front_=front;
            delete tem.get();
        }
        Ptr begin()
        {
            auto tem=begin_;
            tem++;
            return tem;
        }
        Ptr end()
        {
            return end_;
        }
        void show()
        {
            auto tem=begin();
            while(tem!=end())
            {
                cout<<tem->data_<<endl;
                tem=tem->next_;
            }
            return ;
        }
        private:
        Ptr begin_;
        Ptr end_;
    };
}

#endif //ALLTREE_LIST_HPP

#endif //ALLTREE_DOUBLELIST_H
