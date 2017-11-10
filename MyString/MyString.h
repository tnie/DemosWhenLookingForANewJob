#include <string.h>
#include <iostream>
#include <iomanip>

class MyString
{
friend MyString operator+(const MyString& str1, const MyString& str2);
friend std::istream& operator>>(std::istream& in, MyString& str);

public:
  // TODO 默认构造怎么处理？是否更应该考虑所有字符串末尾保有 \0
  MyString();
  ~MyString();
  MyString(const char* pzStr);
  MyString(const char ch, const int count){}
  MyString(const MyString& mystr); // 拷贝构造

  char& operator[](int index) {}
  MyString& operator=(const MyString& mystr);
//  MyString& operator=(const char* cstr) {}
  // 隐式转换
  MyString& operator+=(const MyString& mystr);
//  MyString& operator+=(const char* cstr) {}
  MyString& Append(const MyString& mystr){}
  // 区分两个 const 的作用
  char* c_str() const { return m_str;}
  //const char* c_str() const { return m_str;}
  MyString operator+(const MyString& mystr) const;

private:
  char* m_str;  // 分配的存储空间不包括 \0
  int m_length; // 长度不包括 \0
};

MyString operator+(const MyString& str1, const MyString& str2);

std::istream& operator>>(std::istream& in, MyString& str)
{
  const int limit_string_size = 1024;
  str.m_str = new char[limit_string_size];
  in >> std::setw(limit_string_size) >> str.m_str;
  return in;
}

std::ostream& operator<<(std::ostream& out, const MyString& str)
{
  out << str.c_str();
  return out;
}
