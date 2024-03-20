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

        }
        private:
        T data_;
        std::unique_ptr<ListNode<T>> next_;
    };
    template<class T>
    class List {
        using Node=ListNode<T>;
        using UNode=std::unique_ptr<Node>;
    public:
        List():head_(nullptr)
        {
            size_=0;
        }
        List(const List& val)
        {
            if(val.head_==nullptr)return ;
            size_=0;
            auto  temp=&(val.head_);
            MakeSpace(this->head_);
            this->head_->data_=(*temp)->data_;
            temp=&((*temp)->next_);
            auto temp1=&(this->head_->next_);
            while(*temp!=nullptr)
            {
                MakeSpace(*temp1);
                (*temp1)->data_=(*temp)->data_;
                temp=&((*temp)->next_);
                temp1=&((*temp1)->next_);
            }
        }
        void push_front(const T& val)
        {
            UNode temp;
            MakeSpace(temp);
            temp->data_=val;
            temp->next_.swap(head_);
            head_.swap(temp);
        }
        void erase(const T&val)
        {
            auto temp1=&head_;
            while(*temp1!=nullptr)
            {
               if((*temp1)->data_==val)
               {
                   swap((*temp1)->data_,head_->data_);
                   break;
               }
            }
            if(head_->data_!=val)return ;
            size_--;
            UNode tem;
            std::swap(tem,head_);
            std::swap(tem->next_,head_);
            free(tem);
        }
        void show()
        {
            auto temp1=&head_;
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
            free_.clear();
        }
        void MakeSpace(UNode& val)
        {
            if(free_.size()==0)
            {
                free_.resize(size_+1);
                for(auto &c:free_)c=std::move(std::make_unique<Node>());
            }
            val=std::move(free_.back());
            if(free_.back()!=nullptr)
            {
                cout<<"die"<<endl;
            }
            free_.pop_back();
            size_++;
            return ;
        }
        void free(UNode &val)
        {
            size_--;
            free_.emplace_back(val);
        }
        ~List()
        {
            clear();
        }
    private:
        std::vector<std::unique_ptr<ListNode<T>>>free_;
        size_t size_;
        std::unique_ptr<ListNode<T>>head_;
    };
}

#endif //ALLTREE_LIST_HPP
