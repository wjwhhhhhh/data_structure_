//
// Created by wjw on 2024/2/29.
//

#ifndef ALLTREE_REDBLACKTREE_HPP
#define ALLTREE_REDBLACKTREE_HPP
#include <cassert>
namespace Eula
{
    namespace RBTree
    {
        template<typename K,typename V>
        struct RBNode
        {
            RBNode(bool fl=true)
            {
                IsBack=fl;
                parent= nullptr;
                left= nullptr;
                right= nullptr;
            }
            RBNode* parent;
            RBNode* left,right;
            bool IsBack;
        };

        template<typename K,typename V>
        class RBTree
        {
            using Node = RBNode<K,V>;
            public:
            RBTree()
            {
                root=nullptr;
            }
            ~RBTree()=default;
            private:
            void LeftRotate(Node*node);
            void rightRotate(Node*node);
            RBNode<K,V>*root;
        };

        template<typename K, typename V>
        void RBTree<K, V>::rightRotate(RBTree::Node *node) {
            assert(node!= nullptr);
            auto y=node,x=node->left;
            y->left=x->right;
            x->right->parent=y;
            x->parent=y->parent;
            if(x->parent== nullptr)root=x;
            else if(x->parent->left==y)x->parent->left=x;
            else x->parent->left=y;
            y->parent=x;
            x->right=y;
            return ;
        }

        template<typename K, typename V>
        void RBTree<K, V>::LeftRotate(RBTree::Node *node) {
            assert(node!= nullptr);
            auto x=node,y=node->right;
            x->right=y->left;
            y->left->parent=x;
            y->parent=x->parent;
            if(y->parent==nullptr) root=y;
            else if(y->parent->left==x) y->parent->left=y;
            else y->parent->right=y;
            x->parent=y;
            y->left=x;
            return ;
        }

    }
}
#endif //ALLTREE_REDBLACKTREE_HPP
