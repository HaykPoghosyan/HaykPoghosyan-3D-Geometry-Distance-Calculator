# Geometry3D Library

A C++17 library for 3D geometry operations including points, vectors, and line segments.

## Features

- `Point3D`: 3D point representation with x, y, z coordinates
- `Vector3D`: 3D vector operations including dot product, cross product, and normalization
- `Segment3D`: Line segment operations including distance calculations

## Building the Project

### Prerequisites

- CMake 3.14 or higher
- C++17 compatible compiler

### Build Steps

1. Clone the repository
2. Create a build directory:
   ```
   mkdir build
   cd build
   ```
3. Configure with CMake:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   cmake --build .
   ```

## Running Unit Tests

The project includes Google Test-based unit tests. To build and run the tests:

1. Configure CMake with unit tests enabled (on by default):
   ```
   cmake -B build -DBUILD_UNIT_TESTS=ON
   ```

2. Build the tests:
   ```
   cmake --build build --target geometry_tests
   ```

3. Run the tests:
   ```
   .\build\bin\Debug\geometry_tests.exe
   ```

For more verbose output, use:
```
.\build\bin\Debug\geometry_tests.exe --gtest_color=yes
```

## Usage Example

```cpp
#include "Point3D.h"
#include "Vector3D.h"
#include "Segment3D.h"
#include <iostream>

int main() 
{
    // Create two line segments
    Point3D p1(0, 0, 0);
    Point3D p2(2, 2, 0);
    Point3D p3(1, 0, 2);
    Point3D p4(3, 0, 2);
    
    Segment3D segment1(p1, p2);
    Segment3D segment2(p3, p4);
    
    // Calculate distance between segments
    double distance = Segment3D::Distance(segment1, segment2);
    std::cout << "Distance between segments: " << distance << std::endl;
    
    return 0;
}
``` 