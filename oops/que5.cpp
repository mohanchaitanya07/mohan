//c++ program to implement singly linked list using operator overloading
#include <iostream>
using namespace std;

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
  //initialising head as null
  node *head = NULL;
  //isEmpty function under private
  bool isEmpty()
  {
    //used for checking empty spaces
    if (this->flag == 0)
      return true;
    else
      return false;
  }

public:
  int flag;
  //member functions under public
  Llist operator+(Llist const &obj)
  {
    //operator overloading
    if (this->head == NULL)
    {
      this->head = obj.head;
      cout << "--------successfully merged----------" << endl;
      //returning to this pointer
      return *this;
    }
    else
    {
      node *travel = this->head;
      while (travel->ptr != NULL)
        travel = travel->ptr;
      travel->ptr = obj.head;
      this->mergefn();
      cout << "---------successfully merged---------" << endl;
      //returning to this pointer
      return *this;
    }
  }
  void insertfn(int num);
  //to display
  void displayfn();
  //to merge the two Llists
  void mergefn();
  void resetfn();
};

//insertfn function which insertfns a node based on its sorted position implicitly
void Llist::insertfn(int num)
{
  if (this->head == NULL)
  {
    //initially
    this->head = new node;
    //taking data
    this->head->num = num;
    this->head->ptr = NULL;
    this->flag++;
  }
  else
  {
    node *temp = this->head;
    node *current = new node;
    current->num = num;
    while (temp != NULL)
    {
      //if data < head-data
      if (num <= temp->num)
      {
        current->ptr = head;
        head = current;
        this->flag++;
        break;
      }
      else if (temp->ptr != NULL)
      {
        //nodes between head and tail
        if (num >= temp->num && num <= temp->ptr->num)
        {
          current->ptr = temp->ptr;
          temp->ptr = current;
          this->flag++;
          break;
        }
      }
      //after the tail
      else if (temp->ptr == NULL)
      {
        if (num >= temp->num)
        {
          current->ptr = NULL;
          temp->ptr = current;
          this->flag++;
          break;
        }
      }
      temp = temp->ptr;
    }
  }
  cout << "-------------------successfully inserted----------------------" << endl;
}

void Llist::displayfn()
{
  //checking if Llist is empty or not
  if (this->isEmpty())
    cout << "---No elements in list(empty)---" << endl;
  else
  {
    cout << "-------------------------list is ------------------------" << endl;
    node *temp = this->head;
    while (temp->ptr != NULL)
    {
      cout << temp->num << "->";
      temp = temp->ptr;
    }
    cout << temp->num << "  " << endl;
  }
}

//function to initialise the Llists
void createLlist(Llist *Llist)
{
  int option = 1, num;
  while (option != 2)
  {
    cout << " 1 -  To add number into list" << endl;
    cout << " 2  - To stop creating list" << endl;
    cout << "Enter the option:-  ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
      //taking user input of the num
      cout << "Enter the number you want to insert in list:- " << endl;
      cin >> num;
      Llist->insertfn(num);
    }
    break;
    case 2:
      cout << "---------------------------successsfully stopped list creation-----------------------" << endl;
      break;
    }
  }
}

void Llist::mergefn()
{
  for (node *temp1 = this->head; temp1->ptr != NULL; temp1 = temp1->ptr)
  {
    for (node *temp2 = temp1->ptr; temp2 != NULL; temp2 = temp2->ptr)
    {
      //checking if it is greater
      if (temp1->num > temp2->num)
      {
        int temp_var = temp1->num;
        temp1->num = temp2->num;
        temp2->num = temp_var;
      }
    }
  }
}
//inline function
inline void Llist::resetfn()
{
  this->head = NULL;
  this->flag = 0;
}

int main()
{
  int num, locn;
  //creating Llist1
  Llist Llist1;
  //creating Llist2
  Llist Llist2;
  int option = 1;
  cout << "Please Enter the data of two lists to perform required operation!" << endl;
  cout << endl;
  cout << " ------------------------------------list1 creation----------------------------------" << endl;
  createLlist(&Llist1);
  cout << endl;
  cout << " ------------------------------------list2 creation----------------------------------" << endl;
  createLlist(&Llist2);
  //options
  cout << endl;
  while (option != 4)
  {
    cout << "--------------------options--------------------- " << endl;
    cout << "  1 -  To insert" << endl;
    cout << "  2 -  To display required list" << endl;
    cout << "  3 -  To merge two lists" << endl;
    cout << "  4 - To exit the program" << endl;
    cout << "enter option you want to perform:-   ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
      //to insert an element
      cout << "1 - To insert in list-1 " << endl;
      cout << "2 - To insert in list-2 " << endl;
      cout << "Enter option:-  ";
      cin >> option;
      if (option != 1 && option != 2)
      {
        //checking user wrong input
        cout << "----------!Please select either list1 or list2!----------" << endl;
      }
      else
      {
        cout << "Enter number you want to insertfn:- ";
        cin >> num;
        //based on option
        option == 1 ? Llist1.insertfn(num) : Llist2.insertfn(num);
      }
    }
    break;
    case 2:
    {
      cout << "1 - To displayfn list-1 " << endl;
      cout << "2 - To displayfn list-2 " << endl;
      cout << "option: ";
      cin >> option;
      if (option != 1 && option != 2)
      {
        //checking user wrong input
        cout << "---Please select either list1 or list2---" << endl;
      }
      else
        option == 1 ? Llist1.displayfn() : Llist2.displayfn();
    }
    break;
    case 3:
    {
      cout << " 1 - to merge list-2 into list-1 " << endl;
      cout << " 2 - to merge list-1 into list-2" << endl;
      cout << "Enter option:-  ";
      cin >> option;
      //checking if user enters wrong input
      if (option != 1 && option != 2)
      {
        cout << "---please select either option 1 or 2---" << endl;
      }
      else
      {
        //using operator loading we are merging Llist
        if (option == 1)
        {
          Llist1 = Llist1 + Llist2;
          Llist2.resetfn();
        }
        else
        {
          Llist2 = Llist1 + Llist2;
          Llist1.resetfn();
        }
      }
    }
    break;
    case 4:
      cout << "-----Program exited successfully------" << endl;
      break;
    default:
      //checking user wrong input
      cout << "-----Please Enter option which is shown above-----" << endl;
      break;
    }
  }
  return 0;
}
