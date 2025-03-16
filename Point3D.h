#ifndef POINT3D_H
#define POINT3D_H

class Point3D 
{
private:
    double m_x, m_y, m_z;

public:
    // Constructor with default values
    explicit Point3D(const double x = 0.0, const double y = 0.0, const double z = 0.0) noexcept;
    
    // Destructor
    virtual ~Point3D() = default;
    
    // Copy operations
    Point3D(const Point3D&) = default;
    Point3D& operator=(const Point3D&) = default;
    
    // Move operations
    Point3D(Point3D&&) noexcept = default;
    Point3D& operator=(Point3D&&) noexcept = default;
    
    // Getters by value for better efficiency with primitive types
    double GetX() const noexcept;
    double GetY() const noexcept;
    double GetZ() const noexcept;
    
    // Operators
    Point3D operator+(const Point3D& other) const noexcept;
    Point3D operator-(const Point3D& other) const noexcept;
    Point3D operator*(double scalar) const noexcept;
};

// Non-member operator for scalar * Point3D
Point3D operator*(double scalar, const Point3D& point) noexcept;

#endif // POINT3D_H 