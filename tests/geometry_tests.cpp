#include <gtest/gtest.h>
#include "Point3D.h"
#include "Vector3D.h"
#include "Segment3D.h"

/**
 * Test Suite for 3D Geometry Classes
 * This file contains unit tests for Point3D, Vector3D, and Segment3D classes
 * Each class has both positive and negative test cases to ensure correct behavior
 */

// Point3D Tests
/**
 * Tests Point3D initialization and getter methods with positive coordinates
 * Verifies that the point correctly stores and returns positive x, y, z values
 */
TEST(Point3DTest, PositiveCoordinates)
{
    Point3D p(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(p.GetX(), 1.0);
    EXPECT_DOUBLE_EQ(p.GetY(), 2.0);
    EXPECT_DOUBLE_EQ(p.GetZ(), 3.0);
}

/**
 * Tests Point3D initialization and getter methods with negative coordinates
 * Verifies that the point correctly handles and returns negative x, y, z values
 */
TEST(Point3DTest, NegativeCoordinates)
{
    Point3D p(-1.0, -2.0, -3.0);
    EXPECT_DOUBLE_EQ(p.GetX(), -1.0);
    EXPECT_DOUBLE_EQ(p.GetY(), -2.0);
    EXPECT_DOUBLE_EQ(p.GetZ(), -3.0);
}

/**
 * Tests Point3D operators for addition, subtraction, and scalar multiplication
 * Verifies that the operators correctly perform the expected operations
 */
TEST(Point3DTest, Operators)
{
    Point3D p1(1.0, 2.0, 3.0);
    Point3D p2(4.0, 5.0, 6.0);
    
    // Test addition
    Point3D sum = p1 + p2;
    EXPECT_DOUBLE_EQ(sum.GetX(), 5.0);
    EXPECT_DOUBLE_EQ(sum.GetY(), 7.0);
    EXPECT_DOUBLE_EQ(sum.GetZ(), 9.0);
    
    // Test subtraction
    Point3D diff = p2 - p1;
    EXPECT_DOUBLE_EQ(diff.GetX(), 3.0);
    EXPECT_DOUBLE_EQ(diff.GetY(), 3.0);
    EXPECT_DOUBLE_EQ(diff.GetZ(), 3.0);
    
    // Test scalar multiplication (point * scalar)
    Point3D scaled1 = p1 * 2.0;
    EXPECT_DOUBLE_EQ(scaled1.GetX(), 2.0);
    EXPECT_DOUBLE_EQ(scaled1.GetY(), 4.0);
    EXPECT_DOUBLE_EQ(scaled1.GetZ(), 6.0);
    
    // Test scalar multiplication (scalar * point)
    Point3D scaled2 = 3.0 * p1;
    EXPECT_DOUBLE_EQ(scaled2.GetX(), 3.0);
    EXPECT_DOUBLE_EQ(scaled2.GetY(), 6.0);
    EXPECT_DOUBLE_EQ(scaled2.GetZ(), 9.0);
}

// Vector3D Tests
/**
 * Tests Vector3D initialization and methods with positive components
 * Verifies:
 * 1. Correct storage and retrieval of positive x, y, z components
 * 2. Length calculation is positive for positive components
 */
TEST(Vector3DTest, PositiveComponents)
{
    Vector3D v(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(v.GetX(), 1.0);
    EXPECT_DOUBLE_EQ(v.GetY(), 2.0);
    EXPECT_DOUBLE_EQ(v.GetZ(), 3.0);
    EXPECT_GT(v.Length(), 0.0);
}

/**
 * Tests Vector3D initialization and methods with negative components
 * Verifies:
 * 1. Correct storage and retrieval of negative x, y, z components
 * 2. Length calculation remains positive even with negative components
 */
TEST(Vector3DTest, NegativeComponents)
{
    Vector3D v(-1.0, -2.0, -3.0);
    EXPECT_DOUBLE_EQ(v.GetX(), -1.0);
    EXPECT_DOUBLE_EQ(v.GetY(), -2.0);
    EXPECT_DOUBLE_EQ(v.GetZ(), -3.0);
    EXPECT_GT(v.Length(), 0.0); // Length should still be positive
}

/**
 * Tests dot product calculation for parallel vectors
 * Verifies that dot product is positive when vectors point in same direction
 * Expected result: 1*2 + 1*2 + 1*2 = 6.0
 */
TEST(Vector3DTest, PositiveDotProduct)
{
    Vector3D v1(1.0, 1.0, 1.0);
    Vector3D v2(2.0, 2.0, 2.0);
    EXPECT_DOUBLE_EQ(v1.Dot(v2), 6.0); // Parallel vectors, positive dot product
}

/**
 * Tests dot product calculation for opposite vectors
 * Verifies that dot product is negative when vectors point in opposite directions
 * Expected result: 1*(-1) + 1*(-1) + 1*(-1) = -3.0
 */
TEST(Vector3DTest, NegativeDotProduct)
{
    Vector3D v1(1.0, 1.0, 1.0);
    Vector3D v2(-1.0, -1.0, -1.0);
    EXPECT_DOUBLE_EQ(v1.Dot(v2), -3.0); // Opposite vectors, negative dot product
}

/**
 * Tests Vector3D construction from Point3D
 * Verifies that the Vector3D correctly uses Point3D for its implementation
 */
TEST(Vector3DTest, ConstructFromPoint)
{
    Point3D p(1.0, 2.0, 3.0);
    Vector3D v(p);
    
    EXPECT_DOUBLE_EQ(v.GetX(), 1.0);
    EXPECT_DOUBLE_EQ(v.GetY(), 2.0);
    EXPECT_DOUBLE_EQ(v.GetZ(), 3.0);
    
    // Test vector construction from two points
    Point3D start(1.0, 1.0, 1.0);
    Point3D end(4.0, 6.0, 8.0);
    Vector3D v2(start, end);
    
    EXPECT_DOUBLE_EQ(v2.GetX(), 3.0);
    EXPECT_DOUBLE_EQ(v2.GetY(), 5.0);
    EXPECT_DOUBLE_EQ(v2.GetZ(), 7.0);
}

// Segment3D Tests
/**
 * Tests distance calculation between non-intersecting segments
 * Verifies:
 * 1. Distance is positive for non-intersecting segments
 * 2. Distance matches expected value with specified precision
 * Test case uses segments in different planes to ensure 3D distance calculation
 */
TEST(Segment3DTest, PositiveDistance)
{
    Point3D p1(0, 0, 0);
    Point3D p2(2, 2, 0);
    Point3D p3(1, 0, 2);
    Point3D p4(3, 0, 2);
    
    Segment3D segment1(p1, p2);
    Segment3D segment2(p3, p4);
    
    double distance = Segment3D::Distance(segment1, segment2);
    EXPECT_GT(distance, 0.0);
    EXPECT_NEAR(distance, 2.12132, 1e-5);
}

/**
 * Tests distance calculation between identical segments
 * Verifies that distance is exactly zero when segments are the same
 * This is an edge case that confirms proper handling of coincident segments
 */
TEST(Segment3DTest, ZeroDistance)
{
    Point3D p1(0, 0, 0);
    Point3D p2(1, 1, 1);
    
    Segment3D segment1(p1, p2);
    Segment3D segment2(p1, p2); // Same segment
    
    EXPECT_DOUBLE_EQ(Segment3D::Distance(segment1, segment2), 0.0);
}

/**
 * Tests point-to-segment distance calculation for point above segment
 * Verifies correct perpendicular distance calculation
 * Test case uses point (1,1,0) above horizontal segment from (0,0,0) to (2,0,0)
 * Expected distance is 1.0 units (perpendicular height)
 */
TEST(Segment3DTest, PositivePointToSegmentDistance)
{
    Point3D start(0, 0, 0);
    Point3D end(2, 0, 0);
    Segment3D segment(start, end);
    Point3D point(1, 1, 0); // Point above the segment
    
    EXPECT_DOUBLE_EQ(Segment3D::PointToSegmentDistance(point, segment), 1.0);
}

/**
 * Tests point-to-segment distance calculation for point on segment
 * Verifies that distance is exactly zero when point lies on the segment
 * This is an edge case that confirms proper handling of points on the segment
 */
TEST(Segment3DTest, ZeroPointToSegmentDistance)
{
    Point3D start(0, 0, 0);
    Point3D end(2, 0, 0);
    Segment3D segment(start, end);
    Point3D point(1, 0, 0); // Point on the segment
    
    EXPECT_DOUBLE_EQ(Segment3D::PointToSegmentDistance(point, segment), 0.0);
} 