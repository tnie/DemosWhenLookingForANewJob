#include "MyString.h"
#include <iostream>
#include <assert.h>
using namespace std;

MyString::MyString() {}
MyString::~MyString() 
{
  if (m_str != NULL)
  {
    delete[] m_str;
    m_str = NULL;
  }
}

MyString::MyString(const char* pzStr)
{
  m_length = strlen(pzStr);
  m_str = new char[m_length];
  strncpy(m_str, pzStr, m_length);
}

MyString::MyString(const MyString& mystr)
{
  m_length = mystr.m_length;
  m_str = new char[m_length];
  strncpy(m_str, mystr.m_str, m_length);
}

// TODO 需要防止自我赋值
MyString& MyString::operator=(const MyString& mystr)
{
  if(m_str != NULL)
  {
    delete [] m_str;
    m_str = NULL;
  }
  m_length = mystr.m_length;
  m_str = new char[m_length];
  strncpy(m_str, mystr.m_str, m_length);
  return *this;  
}

MyString& MyString::operator+=(const MyString& mystr)
{
  int length = this->m_length + mystr.m_length;
  char* dest = new char[length];
  strncpy(dest, this->m_str, this->m_length);
  strncpy(dest+this->m_length, mystr.m_str, mystr.m_length);
  if (m_str != NULL)
  {
    delete []m_str;
    m_str = NULL;
  }
  m_str = dest;
  m_length = length;
  cout << "Debug(operator+=): " << string(dest, length) << endl;
  return *this;
}

MyString MyString::operator+(const MyString& str) const
{
  int length = this->m_length + str.m_length;
  char* dest = new char[length];
  strncpy(dest, this->m_str, this->m_length);
  strncpy(dest+this->m_length, str.m_str, str.m_length);
  strncpy(dest+this->m_length+str.m_length, "\0", 1);
  cout << "Debug(MyString::operator+): " << string(dest, length) << endl;
  return MyString(dest);
}

//TODO 运算符重载。两种形式的区别
MyString operator+(const MyString& str1, const MyString& str2)
{
  cout << "Debug(operator+).." << endl;
  return (str1.operator+(str2));
}

int main()
{
  MyString niel("niel");
  MyString liyw("liyw");
  (niel = "nielove") = "nielong";
  cout << niel << endl;
  (niel += liyw) += MyString(", hah");
  //MyString any = "why? " + niel + liyw ; // ambiguous
  MyString any = ("why? " + niel) + liyw ; // ambiguous too
  cout << any << endl;
  MyString tmp;
  cin >> tmp;
  cout << "tmp(cin) is: " << tmp << endl;
  return 0;
}
