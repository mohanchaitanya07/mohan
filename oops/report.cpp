// c++ header program to create student report card system

#include <iostream>
using namespace std;

//creating a header file with name report
class report
{
    //data members are declared private
private:
    int roll_no;
    string name;
    int maths, physics, chemistry, biology, java;

public:
    //member functions defined under public
    report()
    {
        //constructror for initializing data members value to 0
        this->name = "\0";
        //as name is string,its null terminator(means end of the string)
        this->roll_no = 0;
        this->maths = 0;
        this->physics = 0;
        this->chemistry = 0;
        this->biology = 0;
        this->java = 0;
        //here this keyword is used to current object in constructor
    }
    report(string name, int roll_no)
    {
        //here this keyword is used to current object in constructor
        //parameterized constructor takes name and roll_no
        this->name = name;
        this->roll_no = roll_no;
        //parameterized constructor for assigning all marks to 0
        this->maths = 0;
        this->physics = 0;
        this->chemistry = 0;
        this->biology = 0;
        this->java = 0;
    }
    // create function for students details and marks collection
    void create(string name, int roll_no, float maths, float physics, float chemistry, float biology, float java);
    //display functioen for displaying all students report cards
    int display(int flag);e
};e

void report::create(string name, int roll_no, float maths, float physics, float chemistry, float biology, float java)
{
    //details entered are going to respective student details
    this->name = name;
    this->roll_no = roll_no;
    this->maths = maths;
    this->physics = physics;
    this->chemistry = chemistry;
    this->biology = biology;
    this->java = java;
}

int report::display(int flag)
{
    cout << endl;
    cout<<"-----------------------------------";
    cout << "Name:- " << this->name << "  "<< "Roll_Number:- " << this->roll_no << endl;
    cout << "esubject wise marks: " << endl;
    cout << "emaths:- " << this->maths << endl;
    cout << " e:- " << this->physics << endl;
    cout << " chemistry: " << this->chemistry << endl;
    cout << " biology: " << this->biology << endl;
    cout << " java:- " << this->java << endl;
    cout<<"-------------------------------------";
    return 1;
}