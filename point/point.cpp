#include <iostream>
using namespace std;
class point {
   public:
      point(double x=0.0, double y=0.0):x(x),y(y){}
      double const getx() { return x;}
      void setx(double v) { x = v;}
      double const gety() { return y;}
      void sety(double v) { y = v;}
   private:
      double x, y;
};
ostream& operator << (ostream& out, point& p) {
      out << "( " << p.getx() << ", " << p.gety() << " )";
      return out;
}
point operator+ (point& p1, point& p2) {  
      point sum = { p1.getx() + p2.getx(), p1.gety() + p2.gety() };
      return sum;
}
int main() 
{
   point p1 = {3.0, 4.0};
   point p2 = {9.0, 16.0};
   cout << "point p1 = " << p1 << endl;
   cout << "point p2 = " << p2 << endl;
   point p = p1 + p2;
   cout << "point p = p1 + p2 = " << p << endl;
}
