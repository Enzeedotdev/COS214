#include "FestivalLeaves.h"
#include <iostream>

MainStage::MainStage(const std::string& performer, int capacity)
    : FestivalUnit("Main Stage", capacity),
      currentPerformer(performer)
{
}

void MainStage::reportStatus() const
{
    std::cout << "Main Stage | Performer: "
              << currentPerformer
              << std::endl;
}

BackStage::BackStage(int crewMembers, int capacity)
    : FestivalUnit("Back Stage", capacity),
      crewMembers(crewMembers)
{
}

void BackStage::reportStatus() const
{
    std::cout << "Back Stage | Crew Members: "
              << crewMembers
              << std::endl;
}

DJStage::DJStage(const std::string& dj, int capacity)
    : FestivalUnit("DJ Stage", capacity),
      currentDJ(dj)
{
}

void DJStage::reportStatus() const
{
    std::cout << "DJ Stage | DJ: "
              << currentDJ
              << std::endl;
}

DanceFloor::DanceFloor(int maxOccupancy)
    : FestivalUnit("Dance Floor", maxOccupancy),
      attendeeCount(0),
      maxOccupancy(maxOccupancy)
{
}

void DanceFloor::reportStatus() const
{
    std::cout << "Dance Floor | Attendees: "
              << attendeeCount
              << "/"
              << maxOccupancy
              << std::endl;
}

BurgerVendor::BurgerVendor(int stockLevel, int capacity)
    : FestivalUnit("Burger Vendor", capacity),
      stockLevel(stockLevel)
{
}

void BurgerVendor::reportStatus() const
{
    std::cout << "Burger Vendor | Stock: "
              << stockLevel
              << std::endl;
}

BeverageVendor::BeverageVendor(int drinkLevel, int capacity)
    : FestivalUnit("Beverage Vendor", capacity),
      drinkLevel(drinkLevel)
{
}

void BeverageVendor::reportStatus() const
{
    std::cout << "Beverage Vendor | Drinks: "
              << drinkLevel
              << std::endl;
}

SecurityPost::SecurityPost(int level, int capacity)
    : FestivalUnit("Security Post", capacity),
      securityLevel(level)
{
}

void SecurityPost::reportStatus() const
{
    std::cout << "Security Post | Security Level: "
              << securityLevel
              << std::endl;
}

FirstAidTent::FirstAidTent(int staff, int capacity)
    : FestivalUnit("First Aid Tent", capacity),
      medicalStaffCount(staff)
{
}

void FirstAidTent::reportStatus() const
{
    std::cout << "First Aid Tent | Medical Staff: "
              << medicalStaffCount
              << std::endl;
}