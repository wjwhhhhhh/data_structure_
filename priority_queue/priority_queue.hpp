//
// Created by wjw on 2024/2/29.
//

#ifndef ALLTREE_PRIORITY_QUEUE_HPP
#define ALLTREE_PRIORITY_QUEUE_HPP
#include<vector>
#include <cassert>
#include<functional>
namespace Eula
{
    namespace PriorityQueue {
        template <typename T>
        struct Myself
        {
            bool operator()(const T &x,const T&y)const
            {
                return x<y;
            }
        };
        using std::vector;
        template <typename T,class cmp=Myself<T> >
                class PriorityQueue
                {
                    public:
                    PriorityQueue()
                    {
                    }
                    ~PriorityQueue()=default;
                    T&top();
                    void pop();
                    void push(const T&value) ;
                    inline int left(int x)const
                    {
                        return ((x << 1) + 1);
                    }
                    inline int right(int x)const
                    {
                        return ((x << 1) + 2);
                    }
                    inline int father(int x)const
                    {
                        return x-1>>1;
                    }
                    void up(int u);
                    void down(int u);
                    size_t size()const;
                    bool empty()const;
                    vector<T>Tree;//树上每个节点的值
                private:
                };

        template<typename T, class cmp>
        bool PriorityQueue<T, cmp>::empty() const {
            return Tree.empty();
        }

        template<typename T, class cmp>
        void PriorityQueue<T, cmp>::down(int u) {
                int t=u;
                //std::cout<<u<<left(u)<<Tree[u]<<"pl"<<std::endl;
                if(left(u)<Tree.size()&&!cmp()(Tree[left(u)],Tree[t]))t=left(u);
                if(right(u)<Tree.size()&&!cmp()(Tree[right(u)],Tree[t]))t=right(u);
            //std::cout<<t<<"l"<<std::endl;
                if(t!=u)
                {
                    std::swap(Tree[t],Tree[u]);
                    down(t);
                }
                return ;
        }
        template<typename T, class cmp>
        void PriorityQueue<T, cmp>::up(int u) {
            assert(u>=0&&u<Tree.size());
           //std::cout<<u<<"ok"<<std::endl;
            while(u!=0)
            {
                int fath=father(u);
             //   std::cout<<fath<<"fath"<<std::endl;
                if(!cmp()(Tree[u],Tree[fath]))
                {
                    std::swap(Tree[u],Tree[fath]);
                    u=fath;
                }
                else break;
            }
            return ;
        }

        template<typename T, class cmp>
        size_t PriorityQueue<T, cmp>::size() const {
            return Tree.size();
        }

        template<typename T, class cmp>
        void PriorityQueue<T, cmp>::push(const T &value) {
            Tree.push_back(value);
            assert(Tree.size()>0);

            up(Tree.size()-1);
        }

        template<typename T, class cmp>
        void PriorityQueue<T, cmp>::pop() {
            std::swap(Tree.back(),Tree[0]);
            Tree.pop_back();
            down(0);
            return;
        }

        template<typename T, class cmp>
        T &PriorityQueue<T, cmp>::top() {
            assert(Tree.size()>0);
            return Tree[0];
        }
    }
}

#endif //ALLTREE_PRIORITY_QUEUE_HPP
