#include "road.h"
#include "vehicle.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

//impacts default behavior for most states
int SPEED_LIMIT = 10;

//all traffic in lane (besides ego) follow these speeds
vector<int> LANE_SPEEDS = {6,7,8,9};

//Number of available "cells" which should have traffic
double TRAFFIC_DENSITY   = 0.15;

// At each timestep, ego can set acceleration to value between
// -MAX_ACCEL and MAX_ACCEL
int MAX_ACCEL = 2;

// s value and lane number of goal.
vector<int> GOAL = {300, 0};

// These affect the visualization
int FRAMES_PER_SECOND = 4;
int AMOUNT_OF_ROAD_VISIBLE = 40;

static void verify_cost_function() {
  int goal_lane = 0;

  //Test cases used for grading - do not change.
//  float cost;
//  cout << "Costs for (intended_lane, final_lane, goal_distance):" << endl;
//  cout << "----------------------------------------------------------" << endl;
//  cost = goal_distance_cost(goal_lane, 2, 2, 1.0);
//  cout << "The cost is " << cost << " for " << "(2, 2, 1.0)" << endl;
//  cost = goal_distance_cost(goal_lane, 2, 2, 10.0);
//  cout << "The cost is " << cost << " for " << "(2, 2, 10.0)" << endl;
//  cost = goal_distance_cost(goal_lane, 2, 2, 100.0);
//  cout << "The cost is " << cost << " for " << "(2, 2, 100.0)" << endl;
//  cost = goal_distance_cost(goal_lane, 1, 2, 100.0);
//  cout << "The cost is " << cost << " for " << "(1, 2, 100.0)" << endl;
//  cost = goal_distance_cost(goal_lane, 1, 1, 100.0);
//  cout << "The cost is " << cost << " for " << "(1, 1, 100.0)" << endl;
//  cost = goal_distance_cost(goal_lane, 0, 1, 100.0);
//  cout << "The cost is " << cost << " for " << "(0, 1, 100.0)" << endl;
//  cost = goal_distance_cost(goal_lane, 0, 0, 100.0);
//  cout << "The cost is " << cost << " for " << "(0, 0, 100.0)" << endl;

}

static void verify_second_cost_function() {
//  //Target speed of our vehicle
//  int target_speed = 10;
//
//  //Lane speeds for each lane
//  vector<int> lane_speeds = {6, 7, 8, 9};
//
//  //Test cases used for grading - do not change.
//  float cost;
//  cout << "Costs for (intended_lane, final_lane):" << endl;
//  cout << "----------------------------------------------------------" << endl;
//  cost = inefficiency_cost(target_speed, 3, 3, lane_speeds);
//  cout << "The cost is " << cost << " for " << "(2, 2)" << endl;
//  cost = inefficiency_cost(target_speed, 2, 3, lane_speeds);
//  cout << "The cost is " << cost << " for " << "(2, 2)" << endl;
//  cost = inefficiency_cost(target_speed, 2, 2, lane_speeds);
//  cout << "The cost is " << cost << " for " << "(2, 2)" << endl;
//  cost = inefficiency_cost(target_speed, 1, 2, lane_speeds);
//  cout << "The cost is " << cost << " for " << "(1, 2)" << endl;
//  cost = inefficiency_cost(target_speed, 1, 1, lane_speeds);
//  cout << "The cost is " << cost << " for " << "(1, 1)" << endl;
//  cost = inefficiency_cost(target_speed, 0, 1, lane_speeds);
//  cout << "The cost is " << cost << " for " << "(0, 1)" << endl;
//  cost = inefficiency_cost(target_speed, 0, 0, lane_speeds);
//  cout << "The cost is " << cost << " for " << "(0, 0)" << endl;
}

static void verify_behavior_planner() {
  Road road = Road(SPEED_LIMIT, TRAFFIC_DENSITY, LANE_SPEEDS);

  road.update_width = AMOUNT_OF_ROAD_VISIBLE;

  road.populate_traffic();

  int goal_s = GOAL[0];
  int goal_lane = GOAL[1];

  //configuration data: speed limit, num_lanes, goal_s, goal_lane, max_acceleration

  int num_lanes = LANE_SPEEDS.size();
  vector<int> ego_config = {SPEED_LIMIT,num_lanes,goal_s,goal_lane,MAX_ACCEL};

  road.add_ego(2,0, ego_config);
  int timestep = 0;

  while (road.get_ego().s <= GOAL[0]) {
    timestep++;
    if (timestep > 100) {
      break;
    }
    road.advance();
    road.display(timestep);
    //time.sleep(float(1.0) / FRAMES_PER_SECOND);
  }
  Vehicle ego = road.get_ego();
  if (ego.lane == GOAL[1])
  {
    cout << "You got to the goal in " << timestep << " seconds!" << endl;
    if(timestep > 35)
    {
      cout << "But it took too long to reach the goal. Go faster!" << endl;
    }
  }
  else
  {
    cout << "You missed the goal. You are in lane " << ego.lane << " instead of " << GOAL[1] << "." << endl;
  }
}

int main() {
  // verify_cost_function();
  // verify_second_cost_function();
  verify_behavior_planner();

  return 0;
}