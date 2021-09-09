#include <iostream>
using namespace std;
#define size 5 //as queue stores max of 5
//class for queue
class queue
{
    //data members in private
private:
    int rear = -1;
    int front = 0; // front need not to be updated after enqueing
    int c = 0;     //count useful for isemptyfn and isfullfn functions
    int array[size];
    //member functions in public
public:
    void enqueue(int); //int here because as value goes for enqueing
    int dequeue();     //returns to next job element
    int peek()         //returns to current front
    {
        //should return current job
        return array[front];
    }
    void display()
    {
        int i;
        if (c == 0)
        {
            cout << "currently No job in queue";
            return;
        }
        for (i = 0; i < c; i++)
        {
            cout << " " << array[(front + i) % 5];
        }
    }

    bool isfullfn()
    {
        // as maximum size is 5
        return c == 5;
    }
    bool isemptyfn()
    {
        // if there is no job to do count will be zero
        return c == 0;
    }
};
void queue::enqueue(int value) //using scope resolution operator
{
    if (isfullfn())
    {
        //checking whether queue has space or not for entering from rear end
        cout << "queue is full" << endl;
        return;
    }
    rear = (rear + 1) % 5;
    array[rear] = value; //enqueing from rear end
    c++;                 //count need to be updated
}
int queue::dequeue()
{
    if (isemptyfn())
    {
        return INT8_MIN; // after the flag equals this it will show empty
    }
    int element = array[front];
    front = ++front % 5;
    c--;
    return element;
}
