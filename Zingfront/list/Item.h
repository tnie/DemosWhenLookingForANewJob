#include <stdlib.h>
#include <vector>

#ifndef _CACHE_ITEM__
#define _CACHE_ITEM__

const int _AGE_LIMIT = 10; // 10
const int _COUNT_LIMIT = 100; // 100
const int _TIMES_LOOP = 200;  // 200

// 用于产生随机数，方案二
static std::vector<int> Zero2Count;

class Item
{
public:
  // 默认在单向链表的头部插入
  Item();
  // 选择位置插入
  Item(const int random , const int age=0); 
  ~Item(); 
public:
  // 返回值：通过判断 age > 10 淘汰掉的 item 的数目
  static int Scan();
  static void Print() ;
  static bool IsFull() { return m_count >= _COUNT_LIMIT;}
  static int GetCount() { return m_count;}
  
private:
  int m_id;
  int m_age;
  Item* m_next;
  bool AgeUp() { return ( ++m_age > _AGE_LIMIT); }
private:
  static int m_count; // 有效元素个数
  static int m_index; // 所有创建过的元素个数（包括销毁了的）
  static Item* m_head;
};

#endif
