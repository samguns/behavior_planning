#include <functional>
#include <iostream>
#include "cost.h"
#include "cmath"


using namespace std;

float goal_distance_cost(int goal_lane, int intended_lane, int final_lane, float distance_to_goal) {
  /*
  The cost increases with both the distance of intended lane from the goal
  and the distance of the final lane from the goal. The cost of being out of the
  goal lane also becomes larger as vehicle approaches the goal.
  */

  int delta_d = abs(intended_lane - goal_lane) + abs(final_lane - goal_lane);
  float cost = 1 - (exp(-(delta_d / distance_to_goal)));

  return cost;
}