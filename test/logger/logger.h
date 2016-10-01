#ifndef XXYY_LOGGER_H_
#define XXYY_LOGGER_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace XXYY {

class Logger {
  public:
  	Logger() = default;

  	//  log all the current time unit's events into log_manager
  	void LogAll();

  	//  the basic function for logging one event in current time unit
  	void LogOne(std::string record);

  	//  log specific events
  	void TakeOff(uint64_t num);
  	void Land(uint64_t num, uint64_t time);
  	void ReadyToTakeOff(uint64_t num);
  	void ReadyToLand(uint64_t num);
  	void Reject(uint64_t num);

  	// print log function
  	void Print(uint64_t start, uint64_t end);

  	//  TODO:WriteToFile()
  private:
  	std::vector<std::vector<std::string> > log_manager;
  	std::vector<std::string> log_temp;
};

} // XXYY

#endif // XXYY_LOGGER_H_
