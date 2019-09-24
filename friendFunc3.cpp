// Particular : Friend class
// InDetail   : Friend class is a class whose member have access to private and protected member
//              of another class
//              Another property of friendships is that they are not transitive
//              Here first square is made as friend class of rectangle class . It means square can access
//              private and protected member of Rectangle class but that doesnot mean Rectangle class
//              can access private and protected member of Square class.

//              because of this reason i have explicitly mentioned friend in both the class.
//              so that both class can access the private and protected member of each class through
//              member function.

#include <iostream>

class Square;

class Rectangle
{
     int width, height;
     friend class Square;

public:
     int area()
     {
          return width * height;
     }
     void convert(Square &sqr);
};

class Square
{
     friend class Rectangle;
     int side;

public:
     Square(int side)
     {
          std::cout << "Square Constructor called" << std::endl;
          this->side = side;
     }

     int area(Rectangle &rec)
     {
          return rec.width * rec.height;
     }
};

void Rectangle::convert(Square &sqr)
{
     std::cout << "The address of Square object in convert is " << &sqr << std::endl;
     std::cout << "The address of the called object in convert is " << this << std::endl;

     this->width = sqr.side;
     this->height = sqr.side;
}

int main()
{
     // Rectangle rect;
     Square sqr(6);
     Rectangle rect;
     std::cout << "The address of Square object is " << &sqr << std::endl;
     rect.convert(sqr); // Here rectangle class is a friend of square so object of rect can acess private member of square class
     rect.area();
     sqr.area(rect); //Here Square class is a friend of Rectangle so square obj can access the private memeber of rectangle class
     std::cout << "Area of Rectangle is " << rect.area() << std::endl;
}