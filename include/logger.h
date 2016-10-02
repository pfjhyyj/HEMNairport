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
  	Logger() = default;

  	//  log all the current time unit's events into log_manager
  	void LogAll();

  	//  the basic function for logging one event in current time unit
  	void LogOne(std::string record);

  	//  log specific events
  	void TakeOff(BasicPlane plane, uint64_t time);
  	void Land(BasicPlane plane, uint64_t time);
  	void ReadyToTakeOff(BasicPlane plane);
  	void ReadyToLand(BasicPlane plane);
  	void Reject(BasicPlane plane);

  	// print log function
  	void Print(uint64_t start, uint64_t end);

  	//  TODO:WriteToFile()
  private:
  	std::vector<std::vector<std::string> > log_manager;
  	std::vector<std::string> log_temp;
};

} // XXYY

#endif // XXYY_LOGGER_H_
