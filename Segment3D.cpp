#include "Segment3D.h"
#include "Vector3D.h"
#include <algorithm>
#include <cmath>

Segment3D::Segment3D(const Point3D& start, const Point3D& end) noexcept
    : m_start(start), m_end(end) 
{
}

const Point3D& Segment3D::GetStart() const noexcept
{
    return m_start;
}

const Point3D& Segment3D::GetEnd() const noexcept
{
    return m_end;
}

double Segment3D::PointToSegmentDistance(const Point3D& point, const Segment3D& segment) noexcept
{
    // Vector from start to end of segment
    const Vector3D segmentVector(segment.GetStart(), segment.GetEnd());
    const double segmentLengthSquared = segmentVector.LengthSquared();
    
    // If segment is just a point, return distance to that point
    if (segmentLengthSquared == 0.0) 
    {
        return Vector3D(segment.GetStart(), point).Length();
    }
    
    // Vector from start of segment to point
    const Vector3D startToPoint(segment.GetStart(), point);
    
    // Project startToPoint onto segmentVector
    const double t = std::max(0.0, std::min(1.0, 
        startToPoint.Dot(segmentVector) / segmentLengthSquared));
    
    // Calculate the closest point on the segment
    const Point3D closestPoint(
        segment.GetStart().GetX() + t * segmentVector.GetX(),
        segment.GetStart().GetY() + t * segmentVector.GetY(),
        segment.GetStart().GetZ() + t * segmentVector.GetZ()
    );
    
    // Return distance from point to closest point on segment
    return Vector3D(point, closestPoint).Length();
}

double Segment3D::Distance(const Segment3D& seg1, const Segment3D& seg2) noexcept
{
    // Check all point-to-segment distances
    double minDist = PointToSegmentDistance(seg1.GetStart(), seg2);
    minDist = std::min(minDist, PointToSegmentDistance(seg1.GetEnd(), seg2));
    minDist = std::min(minDist, PointToSegmentDistance(seg2.GetStart(), seg1));
    minDist = std::min(minDist, PointToSegmentDistance(seg2.GetEnd(), seg1));
    
    // Check if segments are crossing
    const Vector3D v1(seg1.GetStart(), seg1.GetEnd());
    const Vector3D v2(seg2.GetStart(), seg2.GetEnd());
    const Vector3D v12(seg1.GetStart(), seg2.GetStart());
    
    const Vector3D cross1 = v1.Cross(v2);
    const double cross1Length = cross1.Length();
    
    if (cross1Length != 0) 
    {
        const Vector3D normalizedCross = cross1.Normalize();
        const double dist = std::abs(v12.Dot(normalizedCross));
        const double t1 = v12.Cross(v2).Dot(normalizedCross) / v1.Length();
        const double t2 = v12.Cross(v1).Dot(normalizedCross) / v2.Length();
        
        if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) 
        {
            minDist = std::min(minDist, dist);
        }
    }
    
    return minDist;
} 