#include "logger.h"
using XXYY::Logger;

void Logger::LogAll() {
    log_manager.push_back(log_temp);
    log_temp.clear();
}

void Logger::LogOne(std::string record) {
    log_temp.push_back(record);
}

void Logger::TakeOff(uint64_t num) {
    LogOne("Plane number "+std::to_string(num)+" take off.");
}

void Logger::Land(uint64_t num, uint64_t time) {
    LogOne("Plane number "+std::to_string(num)+" landed after "+
        std::to_string(time)+" time units in the takeoff queue.");
}

void Logger::ReadyToTakeOff(uint64_t num) {
    LogOne("Plane number "+std::to_string(num)+" ready to take off.");
}

void Logger::ReadyToLand(uint64_t num) {
    LogOne("Plane number "+std::to_string(num)+" ready to land.");
}

void Logger::Reject(uint64_t num) {
    LogOne("Plane number "+std::to_string(num)+" is rejected");
}

void Logger::Print(uint64_t start, uint64_t end) {
    if (start < 0 || end < 0 || start > end || 
        end > log_manager.size()) {
        std::cout << "Error: Out of range" << std::endl;
        return;
    }
    for (uint64_t i = start; i <= end; i++) {
        std::cout << "Time " << i << std::endl;
        auto temp = log_manager[i];
        for (uint64_t j = 0; j < temp.size(); j++) {
            std::cout << temp[j] << std::endl;
        }
    }
}

