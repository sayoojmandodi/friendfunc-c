// Created by : Sayooj Mandodi
// MailID     : career.sayoojmandodi@gmail.com
// Facebook   : Sayooj Mandodi

// Particular : FriendFunc
// Indetail   : Friend func is a non member function which can access private and protected member
//                 of a class. It should be declared inside the class using the keyword friend.
//                 Since its is not a member function this friend function can be called without
//                 using object of the class.

#include <iostream>

class base //base class
{

protected:
     int y, z; // protected variable

public:
     int x;
     base() : x(1), y(2), z(3) // constructor variable initilization
     {
          std::cout << "The value of x is " << x << std::endl;
          std::cout << "The value of y is " << y << std::endl;
          std::cout << "The value of z is " << z << std::endl;
     };

     friend base accesMemberFunc(base &b); // Friend function definition declartion should be inside the class
     void show();                          // member function
};

base accesMemberFunc(base &b) // Friend fucntion definition outside the class
{
     b.y += b.y;
     b.z += b.z;
     return b;
}

void base::show()
{
     std::cout << " ------ After friend function is called -------- " << std::endl;
     std::cout << "The value of x is " << this->x << std::endl; // member function is accessed
     std::cout << "The value of y is " << this->y << std::endl; // using friend function
     std::cout << "The value of z is " << this->z << std::endl;
}

int main()
{
     base b;
     b = accesMemberFunc(b); //Friend function is called here
     b.show();
}
