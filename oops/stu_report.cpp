//Menu driven program for student report card
#include <iostream>
//report header file is already created
#include "report"
using namespace std;
//declaring flag as global variable for creation
int flag = 0;
int main()
{
  int roll_no;
  int option;
  string name;
  //declaring all subjects assuming no negative total marks and decimal marks
  // five subjects are maths,physics,chemistry,biology and java
  int maths, physics, chemistry, biology, java;
  //students 1,2,3 initialized by default constructors
  report stu_1;
  report stu_2;
  report stu_3;
  cout << "---students 1,2,3 are initialized by default constructors,enter student 4 and 5 details--- " << endl;
  //students 4 and 5 initialized by parameterized constructors
  cout << " Enter student-4 name:- ";
  // as name is string
  getline(cin, name);
  cout << " Enter student-4 roll_number:- ";
  cin >> roll_no;
  report stu_4(name, roll_no);
  cout << " Enter student-5 name:- ";
  cin.ignore();
  getline(cin, name);
  cout << " Enter student-5 roll_number:- ";
  cin >> roll_no;
  report stu_5(name, roll_no);
  //student 4 and 5 are initialized
  while (option != 3)
  {
    cout << endl;
    cout << "-----select any option shown below-----" << endl;
    cout << "1-for  student datas entry and creation of report cards" << endl;
    cout << "2-for displaying  all students report cards" << endl;
    cout << "3-exit program" << endl;
    cout << " select you option:- ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
      // as only 5 students reports
      for (int i = 0; i < 5; i++)
      {
        cout << endl;
        cout << "student" << i + 1 << "report card: " << endl;
        cout << " Enter student name:- ";
        cin.ignore();
        getline(cin, name);
        cout << " Enter student roll_number:- ";
        cin >> roll_no;
        cout << " Enter subjectwise marks:- " << endl;
        cout << " maths - ";
        cin >> maths;
        cout << " physics - ";
        cin >> physics;
        cout << " chemistry - ";
        cin >> chemistry;
        cout << " biology - ";
        cin >> biology;
        cout << " java - ";
        cin >> java;
        switch (i + 1)
        {
          //for creation of report cards
        case 1:
          stu_1.create(name, roll_no, maths, physics, chemistry, biology, java);
          break;
        case 2:
          stu_2.create(name, roll_no, maths, physics, chemistry, biology, java);
          break;
        case 3:
          stu_3.create(name, roll_no, maths, physics, chemistry, biology, java);
          break;
        case 4:
          stu_4.create(name, roll_no, maths, physics, chemistry, biology, java);
          break;
        case 5:
          stu_5.create(name, roll_no, maths, physics, chemistry, biology, java);
          break;
        }
        cout << "student" << i + 1 << " report card created successfully" << endl;
      }
      flag = 1;
    }
    break;
    //for display
    case 2:
    {
      //if option is 2 display all students report cards
      stu_1.display(flag);
      stu_2.display(flag);
      stu_3.display(flag);
      stu_4.display(flag);
      stu_5.display(flag);
    }
    break;
    //for exit
    case 3:
      break;//to exit
    default:
      cout << "enter option available in above list" << endl;
      break;
    }
  }
  return 0;
}