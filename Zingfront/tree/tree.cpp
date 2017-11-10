#include "tree.h"
#include <iostream>
#include <sstream>
#include <assert.h>
#include <cstring>

using namespace std;

string Node::Find(const Node& node, vector<int>& path) const
{
  path.push_back(m_value);
  if (node == *this)
    return vec2string(path);
  else
  {
    list<Node>::const_iterator cit;
    //for(cit = child_list.cbegin(); cit != child_list.cend(); ++cit)
    for(cit = child_list.begin(); cit != child_list.end(); ++cit)
    {
      string result = cit->Find(node, path);
      if (!result.empty())
        return result;
    }
  }
  path.pop_back();
  return "";
}

string Node::vec2string(const vector<int>& path) const
{
  ostringstream oss;
  vector<int>::const_iterator cit;
  //for(cit = path.cbegin(); cit != path.cend(); ++cit)
  for(cit = path.begin(); cit != path.end(); ++cit)
    oss << char(*cit);
  return oss.str();
}

// 初始化多叉树
Node Init()
{
  Node A('A');
  Node B('B');
  Node D('D');
  Node F('F');
  Node H('H');
  Node N('N');
  N.push_back('R').push_back('S').push_back('T');
  H.push_back('O').push_back('P').push_back('Q');
  F.push_back('K').push_back('L').push_back('M').push_back(N);
  D.push_back(H).push_back('I').push_back('J');
  B.push_back('E').push_back(F).push_back('G');
  A.push_back(B).push_back('C').push_back(D);
  return A;
}

string x2y(const string& xp, const string& yp, const string& separator="->")
{
  string str;
  int xl = xp.length();
  int yl = yp.length();
  int father_index;
  for(int i=0; i< xl && i<yl; ++i)
    if(xp.at(i) == yp.at(i))
       father_index = i;
    else
      break;

  for(int i=xl-1; i>father_index; --i)
    str += xp.at(i);
  
  for(int i=father_index; i<yl; ++i)
    str += yp.at(i);

  ostringstream oss;
  int length = str.length();
  oss << length << ":";
  for(int i=0;i<length;++i)
    oss << str.at(i) << ((i+1 == length) ? "" : separator);
  return oss.str();
}

int main(int argc, char** argv)
{
  assert(argc == 3);
  if (argc > 1)
    assert(strlen(argv[1]) == 1);
  if (argc > 2)
    assert(strlen(argv[2]) == 1);

  // 初始化多叉树
  Node head = Init();
  char _x,_y;
  _x = argv[1][0];
  _y = argv[2][0];
  //assert(_x != _y);

  vector<int> path;
  string pathX = head.Find(_x, path);
  path.clear();
  string pathY = head.Find(_y, path);
  cout << pathX << endl << pathY << endl;
  if (pathX.empty() || pathY.empty())
  {
    cerr << "多叉树中不存在输入的某个节点" << endl;
    return 0;
  }
  // 截去两个字符串的公共部分
  cout << x2y(pathX, pathY) << endl;
  return 0;
}
