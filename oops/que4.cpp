#include <iostream>
using namespace std;
// area class
class area
{

private:
    //length-l, breadth-b,radius-r as private data members
    float l, b, r;

public:
    //Rectangle and Circle as public member functions
    //Here friend functions returns to area of selected shape
    friend float Rectangle(float l, float b);
    friend float Circle(float r);
};
//all members functions are inline functions and friend functions
inline float Rectangle(float l = 1.0, float b = 1.0)
{
    return l * b;
}
// as default of l,b,r are 1.0 it calculates area of respectice shape
inline float Circle(float r = 1.0)
{
    return 3.14 * r * r;
}

// volume class
class volume
{

private:
    //length-l, breadth-b,height-h,radius-r as private data members
    float l, b, h, r;

public:
    float Cuboid(float l, float b, float h);
    float Sphere(float r);
    //for comparing volumes of two cuboids/spheres
    void compare_cuboid();
    void compare_sphere();
};

inline float volume::Cuboid(float l = 1.0, float b = 1.0, float h = 1.0)
{
    return Rectangle(l, b) * h;
}
inline float volume::Sphere(float r = 1.0)
{
    return (4 * Circle(r) * r) / 3;
}

inline void volume::compare_cuboid()
{
    //this pointer used for comparing
    float compared_len, compared_breadth, compared_height;
    cout << "Enter length of first cubiod:- ";
    cin >> this->l;
    cout << "Enter breadth of first cubiod:- ";
    cin >> this->b;
    cout << "Enter height of first cubiod:- ";
    cin >> this->h;
    cout << "Enter length of second cubiod:- ";
    cin >> compared_len;
    cout << "Enter breadth of second cubiod:- ";
    cin >> compared_breadth;
    cout << "Enter the height of second cubiod:-  ";
    cin >> compared_height;
    //calculates first cuboid volume
    float first_vol = Rectangle(this->l, this->b) * this->h;
    //calculates second cuboid volume
    float second_vol = Rectangle(compared_len, compared_breadth) * compared_height;
    //after calculation comparing which has higher volume
    if (first_vol == second_vol)
    {
        cout << "-----Both the cuboids have same volume of " << first_vol << " -----" << endl;
    }
    else if (first_vol > second_vol)
    {
        cout << "first cuboid volume is:-  " << first_vol << endl;
        cout << "second cuboid volume is:-  " << second_vol << endl;
        cout << "-----First cubiods volume is greater than second Cuboid----- " << endl;
    }
    else
    {
        cout << "first cuboid volume is:-  " << first_vol << endl;
        cout << "second cuboid volume is:-  " << second_vol << endl;
        cout << "-----Second cubiod has greater volume than first Cuboid-----" << endl;
    }
}

inline void volume::compare_sphere()
{
    float compared_rad;
    cout << "Enter radius of first Sphere:- ";
    cin >> this->r;
    cout << "Enter radius of second Sphere:- ";
    cin >> compared_rad;
    //calculates first sphere volume
    float first_vol = (4 * Circle(this->r) * this->r) / 3;
    //calculates second sphere volume
    float second_vol = (4 * Circle(compared_rad) * compared_rad) / 3;
    //comparing volumes of two spheres
    if (first_vol == second_vol)
    {
        //if both have same volumes
        cout << "-----Both the Sphere have same volume------" << first_vol << endl;
    }
    else if (first_vol > second_vol)
    {
        cout << "first sphere volume is:-  " << first_vol << endl;
        cout << "second sphere volume is:-  " << second_vol << endl;
        cout << "-----First Sphere has greater volume than second Sphere----" << endl;
    }
    else
    {
        cout << "first sphere volume is:-  " << first_vol << endl;
        cout << "second sphere volume is:-  " << second_vol << endl;
        cout << "-----Second Sphere  has greater volume than first Sphere-----" << endl;
    }
}

int main()
{
    int option = 1;
    volume volume;
    float l, b, h, r;
    while (option != 11)
    {
        //options for required result
        cout << "   1- Area of Rectangle" << endl;
        cout << "   2- Area of Circle" << endl;
        cout << "   3- Default area of Rectangle" << endl;
        cout << "   4- Default area of Circle" << endl;
        cout << "   5- volume of Cubiod" << endl;
        cout << "   6- volume of Sphere" << endl;
        cout << "   7- Default volume of Cubiod" << endl;
        cout << "   8- Default volume of Sphere" << endl;
        cout << "   9- To Compare volume of two cubiods" << endl;
        cout << "   10- To Compare volume of two Spheres" << endl;
        cout << "   11- Exit the program" << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            cout << "Enter length of  Rectangle:- ";
            cin >> l;
            cout << "Enter breadth of Rectangle:- ";
            cin >> b;
            cout << "Area of Rectangle is :- " << Rectangle(l, b) << endl;
        }
        break;
        case 2:
        {
            cout << "Enter radius of the Circle:- ";
            cin >> r;
            cout << "Area of Circle is: " << Circle(r) << endl;
        }
        break;
        case 3:
        {
            cout << "default area of Rectangle :- " << Rectangle() << endl;
        }
        break;
        case 4:
        {
            cout << "default  area of Circle is:- " << Circle() << endl;
        }
        break;
        case 5:
        {
            cout << "Enter length of cubiod:- ";
            cin >> l;
            cout << "Enter breadth of the cubiod:- ";
            cin >> b;
            cout << "Enter height of the cubiod:- ";
            cin >> h;
            cout << "volume of cubiod is:- " << volume.Cuboid(l, b, h) << endl;
        }
        break;
        case 6:
        {
            cout << "Enter radius of Sphere:- ";
            cin >> r;
            cout << "volume of Sphere is :-  " << volume.Sphere(r) << endl;
        }
        break;
        case 7:
        {
            cout << "default volume of cubiod is:- " << volume.Cuboid() << endl;
        }
        break;
        case 8:
        {
            cout << "default  volume of Sphere is :-: " << volume.Sphere() << endl;
        }
        break;
        case 9:
            volume.compare_cuboid();
            break;
        case 10:
            volume.compare_sphere();
            break;
        case 11:
            cout << "---program exited successfully---" << endl;
            break;
        default:
            cout << "-----please Enter a valid option between 1-10------" << endl;
            break;
        }
    }
    return 0;
}
