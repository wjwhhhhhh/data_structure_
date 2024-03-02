//
// Created by wjw on 2024/2/29.
//

#ifndef ALLTREE_REDBLACKTREE_HPP
#define ALLTREE_REDBLACKTREE_HPP
#include <cassert>
#include <functional>
namespace Eula
{
    namespace RBTree
    {
        using std::endl;
        using std::cout;
        using std::cerr;
        template<typename K,typename V>
        struct RBNode
        {
            RBNode(K ke=K(),V val=V(),bool fl=true)
            {
                IsRed=fl;
                parent= nullptr;
                left= nullptr;
                right= nullptr;
                key=ke;
                value=val;
            }
            static void remove(RBNode * node)
            {
                if(node->parent!=nullptr)
                {
                    auto par=node->parent;
                    par->left==node?par->left== nullptr:par->right==nullptr;
                }
                delete(node);
                node= nullptr;
                return ;
            }

            RBNode* parent;
            RBNode* left,*right;
            bool IsRed;
            K key;
            V value;
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
            ~RBTree();
            template<class P>
            void insert(const P&& val);
            void insert(const K& key,const V& val);
            bool find(const K&key);
            void InorderTraversal();
            V&operator[] (const K& key);
        private:
            Node* GetSubsequent(Node* node);
            void EraseLeaf(Node* node);
            void erase(Node* node);
            RBNode<K,V>*root;
            Node*appear(const K& key);
            inline Node*GetUncle(Node*tem)
            {
                auto node=tem->parent;
                if(node->parent->left==node)return node->parent->right;
                else return node->parent->left;
            }
            inline Node*GetGrand(Node*tem)
            {
                return tem->parent->parent;
            }
            inline Node*GetBrother(Node*tem)
            {
                if(tem->parent== nullptr)return nullptr;
                if(tem->parent->left==tem)return tem->parent->right;
                else tem->parent->left;
            }
            void LeftRotate(Node*node);//左旋
            void rightRotate(Node*node);//右旋
            void insertFixup(Node *node);
        };

        template<typename K, typename V>
        void RBTree<K, V>::EraseLeaf(RBTree::Node *node) {
            if(root==node)
            {
                delete root;
                root= nullptr;
                return ;
            }
            auto par=node->parent;
            if(node!= nullptr&&node->IsRed)//为红色
            {
                Node::remove(node);
                return ;
            }
            if(GetBrother(node)== nullptr)
            {
                Node::remove(node);
                return ;
            }
            if(par->IsRed==true)
            {
                if(par->left==node)
                {

                }
                else
                {

                }
            }
            else //父亲为黑色
            {
                if(par->left==node)
                {
                    if(par->right!=nullptr&&par->right->IsRed==true)
                    {
                        par->right->IsRed=false;
                        if(par->right->left!=nullptr)par->right->left->IsRed=true;
                        LeftRotate(par);
                        Node::remove(node);
                    }
                    else
                    {
                        auto bro=GetBrother(node);
                        if(bro->left== nullptr&&bro->right== nullptr)
                        {
                            bro->IsRed=true;
                        }
                        else if(bro->left!= nullptr&&bro->right!= nullptr)
                        {

                        }
                        else if(bro->right!= nullptr)
                        {

                        }
                        else
                        {

                        }
                    }
                }
                else
                {
                    if(par->left!=nullptr&&par->left->IsRed==true)
                    {
                        par->left->IsRed=false;
                        if(par->left->right!=nullptr)par->left->right->IsRed=true;
                        RightRotate(par);
                        Node::remove(node);
                    }
                    else
                    {

                    }
                }
            }

        }

        template<typename K, typename V>
        typename::Eula::RBTree::RBTree<K,V>::Node * RBTree<K, V>::GetSubsequent(RBTree::Node *node) {
            auto ing=node->right;
            while(ing->left!=nullptr)
            {
                ing=ing->left;
            }
            return ing;
        }

        template<typename K, typename V>
        void RBTree<K, V>::erase(RBTree::Node *node) {
            if(node->left== nullptr&&node->right== nullptr)
            {
                EraseLeaf(node);
                return ;
            }
            if(node->left== nullptr)
            {
                std::swap(node->key, node->right->key);
                std::swap(node->value, node->right->value);
                erase(node->right);
            }
            else if(node->left== nullptr)
            {
                std::swap(node->key, node->left->key);
                std::swap(node->value, node->left->value);
                erase(node->left);
            }
            else
            {
                auto tem= GetSubsequent(node);
                std::swap(node->key, tem->key);
                std::swap(node->value, tem->value);
                erase(tem);
            }
            return ;
        }

        template<typename K, typename V>
        template<class P>
        void RBTree<K, V>::insert(const P &&val) {
            insert(val.first,val.second);
            return ;
        }

        template<typename K, typename V>
        V &RBTree<K, V>::operator[](const K &key) {
            if(find(key)==false)insert(key,V());
            return appear(key)->value;
        }

        template<typename K, typename V>
        void RBTree<K, V>::InorderTraversal() {
            std::function<void(RBTree::Node*)>dfs=[&](RBTree::Node *node)
            {
                using std::cout;
                using std::endl;
                if(node== nullptr)return ;
                dfs(node->left);
                cout<<"me"<<node<<" kl"<<node->key<<endl;
                cout<<"left"<<" kl"<<node->left<<endl;
                cout<<"right"<<" kl"<<node->right<<endl;
                dfs(node->right);

            };
            dfs(root);
        }

        template<typename K, typename V>
        typename::Eula::RBTree::RBTree<K,V>::Node * RBTree<K, V>::appear(const K &key) {

            decltype(root) ans= nullptr;
            auto ing=root;
            while(ing!= nullptr)
            {
                if((ing->key)==key) {
                    ans = ing;
                    break;
                }
                else if((ing->key)<key)
                {
                    ing=ing->right;
                }
                else ing=ing->left;
            }
            return ans;
        }

        template<typename K, typename V>
        bool RBTree<K, V>::find(const K &key) {
            if(appear(key)!= nullptr)return true;
            else return false;
        }

        template<typename K, typename V>
        void RBTree<K, V>::insertFixup(RBTree::Node *node) {
                if(node==root)//根为新节点
                {
                    node->IsRed=false;
                    return ;
                }
                if(node->parent->IsRed==false)//parent为黑
                {
                    return ;
                }
                if(GetUncle(node)!= nullptr&&GetUncle(node)->IsRed==true)//uncle为红
                {
                    GetUncle(node)->IsRed=node->parent->IsRed=false;
                    GetGrand(node)->IsRed=true;
                    insertFixup(GetGrand(node));
                    return ;
                }
                if(node->parent->left==node)
                {
                    if(GetGrand(node)->left==node->parent)//左左
                    {
                        rightRotate(GetGrand(node));
                        node->parent->IsRed= false;
                        node->parent->right->IsRed= true;
                    }
                    else//右左
                    {
                        rightRotate(node->parent);
                        node=node->right;
                        insertFixup(node);
                    }
                }
                else
                {
                    if(GetGrand(node)->right==node->parent)//右右
                    {
                        LeftRotate(GetGrand(node));
                        node->parent->IsRed= false;
                        node->parent->left->IsRed= true;
                    }
                    else //左右
                    {
                        LeftRotate(node->parent);
                        node=node->left;
                        insertFixup(node);
                    }
                }
                return ;
        }


        template<typename K, typename V>
        RBTree<K, V>::~RBTree() {
            std::function<void(RBTree::Node*)>dfs=[&](RBTree::Node* u)
            {
                if(u==nullptr)return;
                dfs(u->left);
                dfs(u->right);
                delete u;
                return ;
            };
        }

        template<typename K, typename V>
        void RBTree<K, V>::insert(const K &key, const V &val) {
            auto node=new RBTree::Node(key,val);
            if(root==nullptr)
            {
                root=node;
                node->IsRed=false;
            }
            else
            {
                decltype(node) ing=root,last;
                while(ing!= nullptr)
                {
                    if(ing->key>node->key)
                    {
                        last=ing;
                        ing=ing->left;
                    }
                    else
                    {
                        last=ing;
                        ing=ing->right;
                    }
                }
                node->parent=last;
                if(last->key>node->key)
                {
                    last->left=node;
                }
                else
                {
                    last->right=node;
                }
            }
            insertFixup(node);
            return ;
        }

        template<typename K, typename V>
        void RBTree<K, V>::rightRotate(RBTree::Node *node) {
            assert(node!= nullptr);
            auto y=node,x=node->left;
            y->left=x->right;
            if(x->right!= nullptr)x->right->parent=y;
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
            if(y->left!= nullptr)y->left->parent=x;
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
