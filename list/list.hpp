//
// Created by wjw on 2024/3/13.
//

#ifndef ALLTREE_LIST_HPP
#define ALLTREE_LIST_HPP

#include <memory>
#include <iostream>
namespace Eula {
    using std::cout;
    using std::endl;
    template <class T>
    class List;
    template<class T>
    class ListNode
    {

        public:
        friend class List<T>;
        ListNode()
        {
            data_=T();
            next_= nullptr;
        }

        explicit  ListNode(const T& val)
        {
            data_=val;
            next_= nullptr;
        }
        ~ListNode()
        {
            cout<<"hhh"<<endl;
        }
        private:
        T data_;
        std::unique_ptr<ListNode<T>> next_;
    };
    template<class T>
    class List {
    public:
        List():head_(nullptr)
        {
        }
        List(const List& val)
        {
            if(val.head_==nullptr)return ;
            auto  temp=&(val.head_);
            this->head_=std::make_unique<ListNode<T>>((*temp)->data_);
            temp=&((*temp)->next_);
            auto temp1=&(this->head_->next_);
            while(*temp!=nullptr)
            {
                (*temp1)=std::move(std::make_unique<ListNode<T>>((*temp)->data_));
                temp=&((*temp)->next_);
                temp1=&((*temp1)->next_);
            }
        }
        void push_front(const T& val)
        {
            auto temp=std::make_unique<ListNode<T>>(val);
            temp->next_.swap(head_);

            head_.swap(temp);
        }
        void show()
        {
            auto temp1=&(head_);
            while(*temp1!=nullptr)
            {
                cout<<(*temp1)->data_<<" ";
                temp1=&((*temp1)->next_);
            }
            cout<<endl;
        }
        void clear()
        {
            head_.reset();
        }
        ~List()
        {
            clear();
        }
    private:
        size_t size_;
        std::unique_ptr<ListNode<T>>head_;
    };
}

#endif //ALLTREE_LIST_HPP
