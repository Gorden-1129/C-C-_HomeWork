// 链表练习
#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef int ElemType; // 用int当数据
int len_tot = 3;

typedef struct LNode
{
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

bool ListInsert(LinkList &L, int index, ElemType data)
{
  return false;
}

ElemType ListGet(LinkList &L, int index)
{
  return false;
}

bool ListChange(LinkList &L, int index, ElemType data)
{
  return false;
}

bool ListDel(LinkList &L, int index)
{
  return false;
}

void showList(LinkList L) {
    for(int i =0;i<len_tot;i++){
        std::cout<< ListGet(L,i) << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    auto L = (LinkList)malloc(sizeof(LNode));

    std::cout<< "list insert:"<<std::endl;
    for(int i =0;i<len_tot;i++){
        ListInsert(L,i,i*i);
    }
    showList(L);

    std::cout<< "list change:"<<std::endl;
    for(int i =0;i<len_tot;i++){
        ListChange(L,i,i*i*i);
    }
    showList(L);

    std::cout<< "list del:"<<std::endl;
    for(int i =0;i<len_tot;i++){
        ListDel(L,0);
    }
    showList(L);
}