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

LNode *GetPreviousLinkList(LinkList &L, int index)
{
  if (index < 1)
  {
    return NULL;
  }
  LNode *p = L;
  int j = 0;
  while (p != NULL && j < index - 1)
  {
    p = p->next;
    j++;
  }
  return p;
}

bool AddNextLinkList(LinkList p, ElemType data)
{
  if (p == NULL)
  {
    return false;
  }
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = data;
  s->next = p->next;
  p->next = s;
  return true;
}

bool ListInsert(LinkList &L, int index, ElemType data)
{
  LNode *p = GetPreviousLinkList(L, index);
  return AddNextLinkList(p, data);
}

ElemType ListGet(LinkList &L, int index)
{
  LNode *p = GetPreviousLinkList(L, index);
  if (p == NULL || p->next == NULL)
  {
    return NULL;
  }
  return p->next->data;
  // return true;
}

bool ListChange(LinkList &L, int index, ElemType data)
{
  LNode *p = GetPreviousLinkList(L, index);
  if (p == NULL)
  {
    return false;
  }
  LNode *q = p->next;
  q->data = data;
  return true;
}

bool ListDel(LinkList &L, int index)
{
  LNode *p = GetPreviousLinkList(L, index);
  if (p == NULL)
  {
    return false;
  }
  LNode *q = p->next;
  p->next = q->next;
  free(q);
  return false;
}

void showList(LinkList L)
{
  for (int i = 0; i < len_tot; i++)
  {
    std::cout << ListGet(L, i) << ", ";
  }
  std::cout << std::endl;
}

int main()
{
  printf("%d", 1);
  LinkList L = (LinkList)malloc(sizeof(LNode));

  std::cout << "list insert:" << std::endl;
  for (int i = 0; i < len_tot; i++)
  {
    ListInsert(L, i, i * i);
  }
  showList(L);

  std::cout << "list change:" << std::endl;
  for (int i = 0; i < len_tot; i++)
  {
    ListChange(L, i, i * i * i);
  }
  showList(L);

  std::cout << "list del:" << std::endl;
  for (int i = 0; i < len_tot; i++)
  {
    ListDel(L, 0);
  }
  showList(L);
}