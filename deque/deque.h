//
// Created by wjw on 2024/2/27.
//

#ifndef DEQUE_H
#define DEQUE_H
#include <vector>
#include <cstdlib>

namespace Eula
{
    namespace deque
    {
        using std::vector;
        using size_t=int;
        template<class T>
        class deque
        {
        public :
            deque()=default;
            ~deque()=default;
            void push_back(T &value);
            void push_front(T &value);
            void pop_front();
            void pop_back();
            const size_t size()const ;
            T&operator[](size_t index);
        private :
            vector<T> dequeFront;
            vector<T> dequeBack;
            size_t dequeSize=0;
        };

        template<class T>
        T &deque<T>::operator[](size_t index) {
            if(index>=dequeSize||index<0)
            {
                exit(110);
            }
            if(index<dequeFront.size())
            {
                return dequeFront[dequeFront.size()-1-index];
            }
            else return dequeBack[index-dequeFront.size()];
        }

        template<class T>
        const size_t deque<T>::size() const {
            return dequeSize;
        }

        template<class T>
        void deque<T>::push_back(T &value)
        {
            dequeBack.push_back(value);
            dequeSize++;
        }
        template<class T>
        void deque<T>::push_front(T &value)
        {
            dequeFront.push_back(value);
            dequeSize++;
        }
        template<class T>
        void deque<T>::pop_front()
        {
            if(dequeSize==0)return ;
            dequeSize--;
            if(dequeFront.size()!=0)dequeFront.pop_back();
            else dequeBack.pop_back();
            return ;
        }
        template<class T>
        void deque<T>::pop_back()
        {
            if(dequeSize==0)return ;
            dequeSize--;
            if(dequeBack.size()!=0)dequeBack.pop_back();
            else dequeFront.pop_back();
            return ;
        }
    }
}



#endif //DEQUE_H
