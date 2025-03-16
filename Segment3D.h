#ifndef SEGMENT3D_H
#define SEGMENT3D_H

#include "Point3D.h"
#include <optional>

class Segment3D 
{
private:
    Point3D m_start, m_end;

public:
    // Constructor
    explicit Segment3D(const Point3D& start, const Point3D& end) noexcept;
    
    // Destructor
    virtual ~Segment3D() = default;
    
    // Copy operations
    Segment3D(const Segment3D&) = default;
    Segment3D& operator=(const Segment3D&) = default;
    
    // Move operations
    Segment3D(Segment3D&&) noexcept = default;
    Segment3D& operator=(Segment3D&&) noexcept = default;
    
    // Getters
    const Point3D& GetStart() const noexcept;
    const Point3D& GetEnd() const noexcept;
    
    // Static methods for distance calculations
    static double Distance(const Segment3D& seg1, const Segment3D& seg2) noexcept;
    static double PointToSegmentDistance(const Point3D& point, const Segment3D& segment) noexcept;
};

#endif // SEGMENT3D_H 