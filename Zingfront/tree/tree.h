#include <list>
#include <string>
#include <vector>

#ifndef __NODE_TREE_
#define __NODE_TREE_
#define _DEBUG

struct Node
{
// 假定不会存在相同节点，代码未作限定
public:
  Node(const int value):m_value(value) {}
  ~Node() {}
  Node& push_back(const Node& node)
  {
    child_list.push_back(node);
    return *this;
  }
  bool operator==(const Node& node) const { return this->m_value == node.m_value; };
  // 找到输出路径，没找到输出空字符串
  std::string Find(const Node& node, std::vector<int>& path) const;

private:
  int m_value;
  std::list<Node> child_list;
  std::string vec2string(const std::vector<int>& path) const;
};

#endif
