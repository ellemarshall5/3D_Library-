#include "game3d.h"  // my game library
#include <array>     // for array container
#include <cmath>     // for pow(), sqrt() function
#include <iomanip>   // for formatted output
#include <iostream>

/**
 * @brief calculates the distance between two points
 * @param point_a
 * @param point_b
 * @returns the distance calculated
 */
double game3d::Distance(double point_a, double point_b)
{
    double distance = 0; //initializes double variable
    distance = fabs(point_a - point_b); //calculates the distance between two points, stores abs. value
    std::cout << std::fixed << std::setprecision(2); //sets the double to two decimals
    std::cout << "Distance between " << point_a << " and " <<
                point_b << " = " << distance << std::endl; //output
    return distance; //returns the distance number when function is called
}

/**
 * @brief calculates the total walking distance between two points
 * @param locations
 * @returns total distance
 */
double game3d::TotalWalkingDistance(const std::array<double, kMaxPoints > &locations)
{
    double total = 0; //initializes double
    for(int x = 0; x < locations.size() - 1; ++x) //loop over all elements
    {
        total += game3d::Distance(locations[x], locations[x + 1]); //calls distance function
    }
    return total; //returns total distance walked
}

/**
 * @brief Print message if it is safe to move to another point
 *
 * @param status: true or false
 */
void game3d::SafeToTravelMessage(bool status)
{
    std::cout << "Should I move? " << std::endl;
    if (status)
    {
        std::cout << "\tYes, you are in the safe zone" << std::endl;
    }
    else
    {
        std::cout << "\tNo, stay put. You are in the danger zone" << std::endl;
    }
}

/**
 * @brief checks if safe to travel by comparing distance to const variable
 * @param point1
 * @param point2
 * @return boolean value
 */
bool game3d::SafeToTravel(double point1, double point2)
{
    bool safe = true; //initialize bool
    double distance = 0.0; //initialize double

    distance = game3d::Distance(point1, point2); //calls distance function

    if (distance >= game3d::kSafeRadius) //compares distance to const variable
    {
        safe;
    }
    else
    {
        safe = false;
    }

    return safe;
}

/**
 * @brief calculates walking distance and determines if it is safe
 * @param locations
 * @returns total walking distance
 */
double game3d::TotalSafeWalkingDistance(const std::array<double, kMaxPoints> &locations)
{
    double total = 0; //initializes double
    bool safe = true; //initializes bool

    for(int i = 0; i < locations.size()-1; ++i) //loops over all elements
    {
        safe = game3d::SafeToTravel(locations[i], locations[i+1]); //calls function and stores it in safe variable
        game3d::SafeToTravelMessage(safe); //calls safe to travel message
        if(safe) //compares safe variable and if safe totals distance
        {
            total += game3d::Distance(locations[i], locations[i+1]); //calls distance function
        }
    }
    return total;
}

/**
 * @brief calculates distance between points in two arrays
 * @param a
 * @param b
 * @returns total distance between two points
 */
double game3d::Distance(std::array<double, game3d::kDimensions> a,
                        std::array<double, game3d::kDimensions> b)
{
    double distance; //initializes double
    double x = (a[0]-b[0]); //initializes double and calculates distance
    double y = (a[1]-b[1]); //initializes double and calculates distance
    double z = (a[2]-b[2]); //initializes double and calculates distance


    distance = std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2)); //calculates distance

    std::cout << std::fixed << std::setprecision(2); //sets decimal to two places
    std::cout << "\tDistance between (" << a[0] << "," << a[1] << "," << a[2] << ") and (" <<
              b[0] << "," << b[1] << "," << b[2] << ") = " << distance << std::endl; //output

    return distance;
}

/**
 * @brief calculates total walking distance between points in two arrays
 * @param locations
 * @returns total walking distance
 */
double game3d::TotalWalkingDistance(
        const std::array<std::array<double, game3d::kDimensions>, game3d::kMaxPoints> &locations)
{
    float total = 0; //initializes float

    for(int x = 0; x < locations.size()-1; ++x) //loops over all elements
    {
            total += game3d::Distance(locations[x], locations[x+1]); //calculates distance and updates total
    }
    return total;
}

