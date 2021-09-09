//c++ program to implement linked Llist using function overload
#include <iostream>
using namespace std;

//node data
class node
{
public:
  int num;
  node *ptr;
};

class Llist
{
  //data members under private
private:
  node *head;
  //is empty function checks whether there are any empty spaces left
  bool isEmpty()
  {
    if (this->flag == 0)
      return true;
    else
      return false;
  }

public:
  int flag;
  Llist()
  {
    this->head = NULL;
    this->flag = 0;
  }
  //member functions under public
  //two insert functions
  void insertfn(int num);
  void insertfn(int num, int posn);
  //two delete functions
  int delete_fn();
  int delete_fn(int posn);
  //to display data
  void display_fn();
};

//insert function
void Llist::insertfn(int num)
{
  node *temp = NULL;
  node *cur = new node;
  cur->num = num;
  cur->ptr = NULL;
  //adding at the start of the node
  if (this->isEmpty())
  {
    this->head = cur;
    this->flag++;
  }
  else
  {
    temp = this->head;
    while (temp->ptr != NULL)
      temp = temp->ptr;
    temp->ptr = cur;
    this->flag++;
  }
  cout << "--------------successfully inserted---------------------" << endl;
}

//function to insertfn at a specific locn
void Llist::insertfn(int num, int posn)
{
  node *temp = NULL;
  //cur - current position
  node *cur = new node;
  cur->num = num;
  cur->ptr = NULL;
  if (this->isEmpty())
  {
    this->head = cur;
    this->flag++;
  }
  else
  {
    temp = this->head;
    if (posn == 0)
    {
      cur->ptr = this->head;
      this->head = cur;
    }
    //after last node inserting
    else if (posn == this->flag)
    {
      while (temp->ptr != NULL)
        temp = temp->ptr;
      temp->ptr = cur;
    }
    else
    {
      //inserting inbetween
      int locn = 1;
      while (locn != posn && temp != NULL)
      {
        temp = temp->ptr;
        ++locn;
      }
      cur->ptr = temp->ptr;
      temp->ptr = cur;
    }
    this->flag++;
  }
  cout << "---------successfully inserted at required position------------" << endl;
}

//to delete at last
int Llist::delete_fn()
{
  node *temp;
  node *prev_var;
  //checking if list is empty
  if (this->isEmpty())
  {
    cout << "-----------!Empty List!-------------" << endl;
    return 0;
  }
  temp = this->head;
  prev_var = this->head;
  //iterating upto last node
  while (temp->ptr != NULL)
  {
    prev_var = temp;
    temp = temp->ptr;
  }
  prev_var->ptr = NULL;
  //deleting the node using delete keyword
  delete temp;
  this->flag--;
  cout << "-----------successfully deleted------------------" << endl;
  return 1;
}

//function to delete node at a speicific locn
int Llist::delete_fn(int posn)
{
  node *temp;
  node *prev_var;
  //deleting the head
  if (posn == 1)
  {
    temp = this->head;
    this->head = this->head->ptr;
    delete temp;
  }
  else if (posn == this->flag)
  {
    temp = this->head;
    prev_var = this->head;
    while (temp->ptr != NULL)
    {
      prev_var = temp;
      temp = temp->ptr;
    }
    prev_var->ptr = NULL;
    delete temp;
  }
  else
  {
    //in between nodes deletion
    int locn = 1;
    temp = this->head;
    prev_var = this->head;
    while (locn != posn && temp != NULL)
    {
      prev_var = temp;
      temp = temp->ptr;
      ++locn;
    }
    prev_var->ptr = temp->ptr;
    delete temp;
  }
  this->flag--;
  cout << "---------Successfully deleted at required position----------" << endl;
  return 1;
}

//function to display_fn nodes in the Llist
void Llist::display_fn()
{
  //checking if Llist is empty or not
  if (this->isEmpty())
    cout << "-----------The list is empty---------------" << endl;
  else
  {
    cout << "------------------list is ------------------" << endl;
    node *temp = this->head;
    while (temp->ptr != NULL)
    {
      cout << temp->num << "->";
      temp = temp->ptr;
    }
    cout << temp->num << endl;
  }
}

int main()
{
  int num, locn;
  int option = 1;
  Llist Llist;
  while (option != 6)
  {
    cout << "---------------------Options------------------" << endl;
    cout << " 1 - To insert" << endl;
    cout << " 2 - To insert  at required location" << endl;
    cout << " 3 - To Delete" << endl;
    cout << " 4 - To Delete at required location" << endl;
    cout << " 5 - To display" << endl;
    cout << " 6 - Exit the program" << endl;
    cout << "    Enter your option: ";
    cin >> option;
    //based on option operations are being performed
    switch (option)
    {
    case 1:
    {
      cout << "Enter number you want to insert:- ";
      cin >> num;
      Llist.insertfn(num);
    }
    break;
    case 2:
    {
      cout << "Enter number you want to insert:- ";
      cin >> num;
      while (1)
      {
        cout << "please enter location to insert a node from 0 to " << Llist.flag << " :-";
        cin >> locn;
        //checking the boundary condition
        if (locn >= 0 && locn <= Llist.flag)
          break;
        cout << "-----plese select the location in the above shown range-----" << endl;
      }
      Llist.insertfn(num, locn);
    }
    break;
    case 3:
      //to delete
      Llist.delete_fn();
      break;
    case 4:
    {
      while (1)
      {
        if (Llist.flag == 0)
        {
          //checking boundary condition
          cout << "-------The list is empty---------" << endl;
          break;
        }
        cout << "Enter node number you want delete from 1 to " << Llist.flag << " :- ";
        cin >> locn;
        if (locn > 0 && locn <= Llist.flag)
          break;
        cout << " -----please select the node number shown in above range----- " << Llist.flag << " ";
        cout << endl;
      }
      if (Llist.flag != 0)
        Llist.delete_fn(locn);
    }
    break;
    case 5:
      //to display
      Llist.display_fn();
      break;
    case 6:
      cout << "-----------------Program successfully exited-------------------" << endl;
      break;
    default:
      cout << "-----Please enter an option which is shown above-----" << endl;
      break;
    }
  }

  return 0;
}