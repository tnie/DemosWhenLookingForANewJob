#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "Item.h"

using namespace std;

int Item::m_count;
int Item::m_index;
Item* Item::m_head;

Item::Item():m_id(m_index++),m_age(0), m_next(m_head) 
{
  // TODO 构造中抛出异常？
  assert(m_count < _COUNT_LIMIT);
  m_head = this;
  ++m_count;
}

Item::Item(const int random , const int age):m_id(m_index++),m_age(age)
{
  assert(m_count < _COUNT_LIMIT);
  int pos = random % (m_count+1);
  if (m_count == 0 || pos == 0)
  {
    m_next = m_head;
    m_head = this;
  }
  else
  {
    Item* pre = NULL;
    Item* tmp = m_head;
    for (int i=0;i<pos;++i)
    {
      pre = tmp;
      tmp = tmp->m_next;
    }
    m_next = tmp;
    if (pre != NULL)
      pre->m_next = this;
  }

  ++m_count;
}

Item::~Item()
{
  if (m_head == this)
    m_head = this->m_next;
  else
  {
    Item* tmp, *pre;
    pre = tmp = m_head;
    while(tmp != this)
    {
      pre = tmp;
      tmp = tmp->m_next;
    }
    if (pre != NULL)
      pre->m_next = this->m_next;
  }
  --m_count;
}

void Item::Print()
{
  printf("[id(age)]: ");
  for (Item* tmp= m_head; tmp!=NULL; tmp = tmp->m_next)
    printf("%d(%d) ", tmp->m_id, tmp->m_age);
  printf("(live[%d], total[%d])\n", Item::m_count, Item::m_index);
}

int Item::Scan()
{
  int count = 0;
  Item* earliest;
  for (Item* tmp= m_head; tmp!=NULL; tmp = tmp->m_next)
  {
    earliest= tmp;
    if(tmp->AgeUp())
    {
      printf("age 到期，淘汰 item [id=%d] 。\n", tmp->m_id);
      delete tmp;
      ++count;
    }
  }
  // TODO > 至少淘汰一个 与之后的淘汰条件并不等价
  if(count == 0 && m_count >= _COUNT_LIMIT)
  {
    // TODO 第一个到底只收尾哪个？
    // earliest = m_head;
    printf("Cache 已满，淘汰第一个 item[id=%d] 。\n", earliest->m_id);
    delete earliest;
  }
  return count;
}

int randperm()
{
  random_shuffle(Zero2Count.begin(), Zero2Count.end());
  return Zero2Count.at(0);
}

int NewRandom()
{
  // 产生随机数方案一
  srand((unsigned)time(NULL));
  int random =  rand();
  //cout << "rand() returns: " << random << endl;
  for(int i=0;i<random%3 +1;++i)
    if (Item::IsFull() == false)
    {
      int value = randperm();
      new Item(value);
      int count = Item::GetCount();
      fprintf(stdout, "Cache [%d]位置新增 item 成功。\n", value % count);
    }
    else
      cerr << "Cache 已满，新增失败。" << endl;
}

int Init50(const int count=50)
{
  for(int i=0;i<count;++i)
    if (Item::IsFull() == false)
      new Item;
}

int main()
{
  for (int i = 0; i <= _COUNT_LIMIT; ++i)
    Zero2Count.push_back(i);
  // 已有 50 个 Item
  Init50();
  for(int i=0;i<_TIMES_LOOP;++i)
  {
    sleep(1);
    // 新增
    NewRandom();
    cout << "新增之后 && 淘汰之前:" << endl;
    Item::Print();
    Item::Scan();
    cout << "淘汰之后:" << endl;
    Item::Print();
    cout << "=================" << endl;
  }
  return 0;
}
