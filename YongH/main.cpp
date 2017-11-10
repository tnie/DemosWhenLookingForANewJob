#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include "assert.h"

using namespace std;

// 假定用户不会输入 前缀 0，比如 001 002010
const string ch[]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
const string e[] ={"拾","佰","仟","@"};
const string _switch[] = {"万", "亿"};

ostream& operator<<(ostream& ost, const list<string>& vec)
{
  list<string>::const_iterator citor = vec.begin();
  for(; citor != vec.end(); ++citor)
    ost << *citor;
  return ost;
}
  
list<string>& Small(list<string>& target, const int num)
{
  assert(num <= 9999);
  int tmp = num;
  int eIndex=0;
  while(tmp  >0 )
  {
    int index = tmp % 10;
    target.push_front(ch[index]);
    assert(eIndex < sizeof(e)/sizeof(string)); // 防止溢出
    target.push_front(e[eIndex]);
    ++eIndex;
    tmp /= 10;
  }
  target.pop_front();
  // TODO: clear
{
// 清理末尾零
list<string>::reverse_iterator it = target.rbegin();
while (it != target.rend() && *it == ch[0])
{
  ++it;
  cout <<"单位: " << *it << endl;
  if (it != target.rbegin())
  {
    ++it;
    cout <<"数值: " << *it << endl;
  }
}
// 从 cit+2 开始删
cout <<"?: " << *(it.base()) << endl;
list<string>::iterator it2 = (it.base());
++it2;
target.erase(it2, target.end());
}
  //cout << target.length() << endl;
  //reverse(target.begin(), target.end());
  return target;
}

list<string>& func(list<string>& target, const long num)
{
long tmp = num;
int _index = 0;
while(tmp > 0)
{
int itor = tmp % 10000;
Small(target, itor);
target.push_front(_switch[_index%2]);
_index += 1;
tmp /= 10000;
}
target.pop_front();
return target;
}

int main()
{
  list<string> target;
  cout << ch << endl;
  cout << sizeof(ch)/sizeof(string) << endl;
  const int tmp[] = {2121,
    1,
    10,
    11,
    100,
    101,
    110,
    111,
    1000,
    1001,
    1010,
    1011,
    1101
  };
//  const int size = sizeof(tmp)/sizeof(int);
//  for (int i=0; i< size; ++i)
//  {
//    target.clear();
//    cout << tmp[i] << ": " << Small(target, tmp[i]) << endl;
//  }
  target.clear();
  const int smp = 1000;
  cout << smp << ": " << Small(target, smp) << endl;
//  target.clear();
//  const long lmp = 212121212121;
//  cout << lmp << ": " << func(target, lmp) << endl;
}
