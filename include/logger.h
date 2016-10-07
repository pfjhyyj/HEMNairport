#ifndef XXYY_LOGGER_H_
#define XXYY_LOGGER_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "plane.h"

namespace XXYY {

class Logger {
  public:
  	Logger() :time(0), processed(0), q_land(0), q_takeoff(0), ac_land(0),
  	    ac_takeoff(0), re_land(0), re_takeoff(0), land(0), takeoff(0),
  	    l_land(0), l_takeoff(0), idle(0), l_time(0), t_time(0), empty(true) {}

  	//  log all the current time unit's events into log_manager
  	void LogAll();

  	//  the basic function for logging one event in current time unit
  	void LogOne(std::string record);

  	//  log specific events
  	void TakeOff(BasicPlane plane, uint64_t time);
  	void Land(BasicPlane plane, uint64_t time);
  	void ReadyToTakeOff(BasicPlane plane);
  	void ReadyToLand(BasicPlane plane);
  	void RejectCome(BasicPlane plane);
  	void RejectTakeOff(BasicPlane plane);

  	// print log function
  	void Print(uint64_t start, uint64_t end);
  	void PrintAll();

  	//  TODO:WriteToFile()
  private:
  	std::vector<std::vector<std::string> > log_manager;
  	std::vector<std::string> log_temp;
  	uint64_t time;
  	uint64_t processed;
  	uint64_t q_land;
  	uint64_t q_takeoff;
  	uint64_t ac_land;
  	uint64_t ac_takeoff;
  	uint64_t re_land;
  	uint64_t re_takeoff;
  	uint64_t land;
  	uint64_t takeoff;
  	uint64_t l_land;
  	uint64_t l_takeoff;
  	uint64_t idle;
  	uint64_t l_time;
  	uint64_t t_time;
  	bool empty;
};

} // XXYY

#endif // XXYY_LOGGER_H_
