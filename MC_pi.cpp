#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <cmath>   // For sqrt()
#include <ctime>   // For time()

double monteCarloPi(int numPoints) {
    int pointsInsideCircle = 0;

    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < numPoints; ++i) {
        // Generate random (x, y) in [0, 1] x [0, 1]
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;

        // Check if the point is inside the quarter-circle
        if (x * x + y * y <= 1.0) {
            ++pointsInsideCircle;
        }
    }

    // Estimate pi
    return 4.0 * pointsInsideCircle / numPoints;
}

int main() {
    int numPoints;
    std::cout << "Enter the number of points for the simulation: ";
    std::cin >> numPoints;

    double piEstimate = monteCarloPi(numPoints);
    std::cout << "Estimated value of pi: " << piEstimate << std::endl;

    return 0;
}