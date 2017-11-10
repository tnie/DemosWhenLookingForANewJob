#include <string>
using std::string;

int PrintAllStudent();
class Student
{
//friend int PrintAllStudent();
public:
  ~Student();
  Student(const string& name);
private:
  string m_name;
  Student* next;
  Student* prev;
  static Student* m_head;
public:
  static int PrintAllStudent();
  static int m_count;
  static int GetCount() { return m_count;};
};

