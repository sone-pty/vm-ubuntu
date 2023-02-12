#ifndef SONE_DS_H_
#define SONE_DS_H_

#include <iostream>
#include <vector>

template <typename T> struct Node {
    T _val;
    Node* _next;
    Node* _prev;
    size_t _freq;

    Node(T val) : _val(val), _next(NULL), _prev(NULL), _freq(0) {}
    Node() : _next(NULL), _prev(NULL), _freq(0) {}
};

// 构造单链表
template <typename T> Node<T>* BuildSlist(const std::vector<T>& args)
{
    Node<T>* h = new Node<T>(), *pNode = h;
    
    for (size_t i = 0; i < args.size(); ++i)
    {
        pNode->_next = new Node<T>(args[i]);
        pNode = pNode->_next;
    }

    pNode->_next = NULL;
    return h;
}

template <typename T> void Print(const Node<T>* h)
{
    const Node<T>* pNode = h;

    while (pNode)
    {
        std::cout << pNode->_val << " ";
        pNode = pNode->_next;
    }
}

class Algo_LinkedList {
public:
    Algo_LinkedList() = default;

    template <typename T> void ReverseOutput(Node<T>* L) // 传入非头节点
    {
        if(L == NULL)
        {
            return;
        }

        if(L->_next == NULL)
        {
            std::cout << L->_val;
        }
        else
        {
            ReverseOutput(L->_next);
            std::cout << L->_val;
        }
    }

    template <typename T> void DeleteMinNode(Node<T>* L)
    {
        if(L == NULL || L->_next == NULL) return;

        Node<T>* pMinNode = L->_next, *pNode = L->_next, *pPrev = L, *pMinPrev = L;

        while(pNode)
        {
            if(pNode->_val < pMinNode->_val)
            {
                pMinNode = pNode;
                pMinPrev = pPrev;
            }

            pPrev = pNode;
            pNode = pNode->_next;
        }

        pMinPrev->_next = pMinNode->_next;
        delete pMinNode;
    }

    template <typename T> void ReverseList(Node<T>* L)
    {
        if(L == NULL || L->_next == NULL) return;

        Node<T>* pNode = L->_next, *pNext1 = NULL, *pNext2 = NULL;
        L->_next = NULL;

        while(pNode)
        {
            pNext1 = L->_next;
            L->_next = pNode;
            pNext2 = pNode->_next;
            pNode->_next = pNext1;
            pNode = pNext2;
        }
    }

    template <typename T> Node<T>* MergeSort(Node<T>* L) // 传入非头节点，返回第一个数据节点
    {
        if(L == NULL) return NULL;
        if(L->_next == NULL) return L;

        Node<T>* pSlow = L, *pFast = L, *pPrev = NULL;

        while(pFast && pFast->_next)
        {
            pPrev = pSlow;
            pSlow = pSlow->_next;
            pFast = pFast->_next->_next;
        }

        // 断开链表
        pPrev->_next = NULL;

        // 排序
        Node<T>* ph1 = MergeSort(L);
        Node<T>* ph2 = MergeSort(pSlow);

        // 合并
        return Merge(ph1, ph2);
    }

    template <typename T> Node<T>* Merge(Node<T>* l1, Node<T>* l2)
    {
        Node<T>* pNode1 = l1, *pNode2 = l2;
        Node<T> head, *pNode = &head;

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        while(pNode1 && pNode2)
        {
            if(pNode1->_val < pNode2->_val)
            {
                pNode->_next = pNode1;
                pNode = pNode->_next;
                pNode1 = pNode1->_next;
            }
            else
            {
                pNode->_next = pNode2;
                pNode = pNode->_next;
                pNode2 = pNode2->_next;
            }
        }

        if(pNode1)
        {
            pNode->_next = pNode1;
        }

        if(pNode2)
        {
            pNode->_next = pNode2;
        }

        return head._next;
    }

    template <typename T> void Unique(Node<T>* l)
    {
        Node<T>* p = l->_next, *q = NULL;

        while(p != NULL)
        {
            q = p;

            while(q->_next && q->_next->_val == p->_val)
            {
                q = q->_next;
            }

            if(p != q)
            {
                p->_next = q->_next;
            }

            p = p->_next;
        }
    }
};

#endif