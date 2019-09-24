// Particular : Friendfucntion cannot be inherited
// In detail  : Friend function cannot be inherited Example has been given below

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

     friend base accesMemberFunc(derived &b); // Friend function definition declartion should be inside the class
     void show()
     {
          std::cout << "Show func in base is called " << std::endl;
     }
};

class derived : public base
{
protected:
     int k, l;

public:
     int j;
     derived() : j(1), k(2), l(3)
     {
          std::cout << "The value of x is " << x << std::endl;
          std::cout << "The value of y is " << y << std::endl;
          std::cout << "The value of z is " << z << std::endl;
     }
     void showDerivedMember(); // member function
};

base accesMemberFunc(derived &b) // Friend fucntion definition outside the class
{
     b.show();
     b.j += b.j; // NO Error: friend function can access public variable of derived class
     b.k += b.k; // Error: private member var of derived class cannot be accessed by  friend function
     // Reason : since friend function is not inherited.

     //         its obvious friend function cannot access th
     //        it cannot access the derived class member var
     return b;
}

void derived::showDerivedMember()
{
     std::cout << " ------ After friend function is called -------- " << std::endl;

     std::cout << "The value of x is " << this->l << std::endl;
     std::cout << "The value of y is " << this->j << std::endl;
     std::cout << "The value of z is " << this->j << std::endl;
}
int main()
{
     derived d;
     d.show();
     accesMemberFunc(d);
}