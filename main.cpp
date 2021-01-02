/**
 *
 * game3d.cpp
 * Danielle Marshall
 * 9/17/20
 * calculate the distance between two points in different scenarios
 *
 */

#include <iostream>
#include "game3d.h"

int main()
{
    //////////////// Part 1 //////////////////////////
    double  p1 = 5.9, p2 = 4.5;
    std::cout << "\n********Part 1********" << std::endl;
    game3d::Distance(p1, p2);
    game3d::Distance(p1);

    std::cout << "Now calculate for " << game3d::kMaxPoints <<
                " points" << std::endl;
    std::array<double, game3d::kMaxPoints> locations_1d = {11,22,37,41,53,66,79,80,95,101};
    double  total_distance = game3d::TotalWalkingDistance(locations_1d);
    std::cout << "Total traveled distance between " << " = " << total_distance << std::endl;
    //////////////// Part 2 //////////////////////////
    std::cout << "\n********Part 2********\n";
    //test if safe to travel between two points
    p1= 8.5, p2 = 26.9;
    game3d::SafeToTravelMessage(game3d::SafeToTravel(p1,p2));

    p1 = 8.5, p2 = 10.9;
    game3d::SafeToTravelMessage(game3d::SafeToTravel(p1,p2));

    p1 = 10.5;
    game3d::SafeToTravelMessage(game3d::SafeToTravel(p1));

    std::cout << "\nCalculating safe traveled distance for " << game3d::kMaxPoints << " points "
              << std::endl;
    total_distance = game3d::TotalSafeWalkingDistance(locations_1d);
    std::cout << "\nTotal safe traveled distance = " << total_distance << std::endl;

    //////////////// Part 3 //////////////////////////
    std::cout << "\n********Part 3********\n";
    std::array<double, 3> enemy1_location = {2,6,1};
    std::array<double, 3> enemy2_location = {3,4,0};
    double  enemy_distance = game3d::Distance(enemy1_location,enemy2_location);
    std::cout << "Distance between 2 3D points: " << enemy_distance << std::endl;
    enemy_distance = game3d::Distance(enemy1_location);
    std::cout << "Distance between 1 3D point and the origin: " << enemy_distance << std::endl;

    std::cout << "Calculating 3D distance for " << game3d::kMaxPoints << " 3D points " << std::endl;
    std::array<std::array<double, game3d::kDimensions>, game3d::kMaxPoints>
    locations_3d{
        enemy1_location,
        {3,6,7},
        {2,3,3},
        {5,3,5},
        {8,3,0},
        {8,8,2},
        {2,1,2},
        {6,3,1},
        {5,2,0},
        enemy2_location};
    total_distance = game3d::TotalWalkingDistance(locations_3d);
    std::cout << "Total traveled distance between " << game3d::kMaxPoints << " 3D points "
              << " = " << total_distance << std::endl;

    return 0;
}