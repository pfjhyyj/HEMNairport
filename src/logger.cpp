#include "logger.h"

using XXYY::Logger;

void Logger::LogAll() {
    if (!empty) {
        idle++;
    }
    log_manager.push_back(log_temp);
    log_temp.clear();
    time++;
    empty = true;
}

void Logger::LogOne(std::string record) {
    log_temp.push_back(record);
}

void Logger::TakeOff(BasicPlane plane, uint64_t time) {
    LogOne(
        "Plane number " + std::to_string(plane.id) + " take off after " +
        std::to_string(time - plane.arrive_time) +
        " time units in the takeoff queue.");
    l_takeoff--;
    takeoff++;
    t_time += time - plane.arrive_time;
    empty = false;
}

void Logger::Land(BasicPlane plane, uint64_t time) {
    LogOne(
        "Plane number " + std::to_string(plane.id) + " landed after " +
        std::to_string(time - plane.arrive_time) +
        " time units in the land queue.");
    l_land--;
    land++;
    l_time += time - plane.arrive_time;
    empty = false;
}

void Logger::ReadyToTakeOff(BasicPlane plane) {
    LogOne("Plane number " + std::to_string(plane.id) + " ready to take off.");
    processed++;
    ac_takeoff++;
    q_takeoff++;
    l_takeoff++;

}

void Logger::ReadyToLand(BasicPlane plane) {
    LogOne("Plane number " + std::to_string(plane.id) + " ready to land.");
    processed++;
    ac_land++;
    q_land++;
    l_land++;
}

void Logger::RejectTakeOff(BasicPlane plane) {
    LogOne("Plane number " + std::to_string(plane.id) + " is rejected");
    processed++;
    q_takeoff++;
    re_takeoff++;
}

void Logger::RejectCome(BasicPlane plane) {
    LogOne("Plane number " + std::to_string(plane.id) + " is rejected");
    processed++;
    q_land++;
    re_land++;
}

void Logger::Print(uint64_t start, uint64_t end) {
    if (start > end || end > log_manager.size()) {
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

void Logger::PrintAll() {
    std::cout << "Simulation has concluded after " << time << " time units\n"
              << "Total number of planes processed "<< processed << std::endl
              << "Total number of planes asking to land " << q_land << std::endl
              << "Total number of planes asking to takeoff " << q_takeoff << std::endl
              << "Total number of planes accepted for landing " << ac_land << std::endl
              << "Total number of planes accepted for takeoff " << ac_takeoff << std::endl
              << "Total number of planes refused for landing " << re_land << std::endl
              << "Total number of planes refused for takeoff " << re_takeoff << std::endl
              << "Total number of planes that landed " << land << std::endl
              << "Total number of planes that took off" << takeoff << std::endl
              << "Total number of planes left in landing queue " << l_land << std::endl
              << "Total number of planes left in takeoff queue " << l_takeoff << std::endl
              << "Percentage of time runway idle " << idle << std::endl
              << "Average wait time in landing queue " << l_time/(time-idle) << std::endl
              << "Average wait time in takeoff queue " << t_time/(time-idle) << std::endl
              << "Average observed rate of planes wanting to land " << q_land/time << std::endl
              << "Average observed rate of planes wanting to takeoff " << q_takeoff/time << std::endl
              << std::endl;
}