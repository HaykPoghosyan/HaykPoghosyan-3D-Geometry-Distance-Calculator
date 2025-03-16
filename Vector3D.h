#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3D.h"

class Vector3D 
{
private:
    double m_x, m_y, m_z;

public:
    // Constructors
    explicit Vector3D(const double x = 0.0, const double y = 0.0, const double z = 0.0) noexcept;
    Vector3D(const Point3D& start, const Point3D& end) noexcept;
    
    // Destructor
    virtual ~Vector3D() = default;
    
    // Copy operations
    Vector3D(const Vector3D&) = default;
    Vector3D& operator=(const Vector3D&) = default;
    
    // Move operations
    Vector3D(Vector3D&&) noexcept = default;
    Vector3D& operator=(Vector3D&&) noexcept = default;
    
    // Getters by value for better efficiency with primitive types
    double GetX() const noexcept;
    double GetY() const noexcept;
    double GetZ() const noexcept;
    
    // Operations
    double Length() const noexcept;
    double Dot(const Vector3D& other) const noexcept;
    Vector3D Cross(const Vector3D& other) const noexcept;
    Vector3D Normalize() const noexcept;
};

#endif // VECTOR3D_H 