#include <iostream>
using namespace std;
//queue adt header file implemented with name queue
#include "queue.cpp"
int main()
{
  queue pr_queue;
  //operation to select
  cout << "choose the operation you want to perform from this below list:" << endl;
  cout << "   1 - Add to Print Queue" << endl;
  cout << "   2 - Current Job" << endl;
  cout << "   3 - Execute a Job" << endl;
  cout << "   4 - Display Jobs" << endl;
  cout << "   5 - Exit" << endl;
  while (1)
  {
    int option;
    cout << " Enter the option you want to perform:- ";
    cin >> option;

    if (option == 1)
    {
      //job id need to be taken and enqueue to queue
      int jobID;
      cout << " Enter jobID (integer): ";
      cin >> jobID;
      pr_queue.enqueue(jobID); //enqueues here
    }
    else if (option == 2)
    {
      //shows current job to do
      if (pr_queue.isemptyfn())
      {
        //to know current job
        cout << "No job in queue" << endl;
        continue;
      }
      cout << "Current job is " << pr_queue.peek() << endl;
    }
    else if (option == 3)
    {
      //completing job in front
      int flag;
      flag = pr_queue.dequeue();
      if (flag == INT8_MIN)
      {
        // checking whether Queue was empty
        cout << "currently No jobs in queue" << endl;
        continue;
      }

      cout << "Job " << flag << "successfully executed" << endl;
    }
    else if (option == 4)
    {
      //to display all jobs to be done
      cout << "Job IDs are: ";
      pr_queue.display();
      cout << endl;
    }
    else if (option == 5)
    {
      //tp exit the program
      cout << "Exit program" << endl;
      break;
    }
    else
    {

      cout << " Please select the option which is shown in menu" << endl;
    }
  }

  return 0;
}