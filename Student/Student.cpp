#include <iostream>
#include "Student.h"
#include <assert.h>
using namespace std;

Student* Student::m_head;
int Student::m_count;

Student::Student(const string& name): m_name(name)
{
  this->prev = m_head;
  this->next = NULL;
  if(m_head != NULL)
    m_head->next = this;
  m_head = this;
  ++m_count;
}

Student::~Student()
{
  if (this == m_head)
    m_head = this->prev;
  if (this->next != NULL)
    this->next->prev = this->prev;
  if (this->prev != NULL)
    this->prev->next = this->next;
  --m_count;
}

int Student::PrintAllStudent()
{
  int count = 0;
  const Student *pStu = m_head;
  while(pStu != NULL)
  {
    cout << (pStu->m_name) << "#"  << endl;
    pStu = pStu->prev; 
    ++count;
  }
  return count;
}

int PrintAllStudent()
{
  return Student::PrintAllStudent();
}

int main()
{
  Student("niel");
  Student("liy");
  Student("maoh");
  Student("zhouh");
  Student niel("niel");
  Student liy("liy");
  Student maoh("maoh");
  Student zhouh("zhouh");

  cout << "The count of students(by PrintAllStudent()) is: " << PrintAllStudent() << endl;
  cout << "The count of students is(by g_count): " << Student::GetCount() << endl;
  assert(PrintAllStudent() ==  Student::GetCount());
  return 0;
}
