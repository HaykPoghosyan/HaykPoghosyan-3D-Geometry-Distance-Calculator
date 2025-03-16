#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"
#include "Segment3D.h"

int main() 
{
    Point3D p1(0, 0, 0);
    Point3D p2(2, 2, 0);
    Point3D p3(1, 0, 2);
    Point3D p4(3, 0, 2);
    
    Segment3D segment1(p1, p2);
    Segment3D segment2(p3, p4);
    
    double distance = Segment3D::Distance(segment1, segment2);
    std::cout << "S1(" << p1.GetX() << "," << p1.GetY() << "," << p1.GetZ() << "->" 
              << p2.GetX() << "," << p2.GetY() << "," << p2.GetZ() << ") ";
    std::cout << "S2(" << p3.GetX() << "," << p3.GetY() << "," << p3.GetZ() << "->" 
              << p4.GetX() << "," << p4.GetY() << "," << p4.GetZ() << ") ";
    std::cout << "d=" << distance << "\n";
    
    return 0;
} 