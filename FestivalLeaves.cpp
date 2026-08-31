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

void MainStage::open()
{
    isOpen = true;
    std::cout << "The crowd has began gathering as the Main Stage prepares for today's performances."
              << std::endl;
}

void MainStage::close()
{
    isOpen = false;
    std::cout << "The final performance has finished and the Main Stage has shut down for the day."
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

void BackStage::open()
{
    isOpen = true;
    std::cout << "Backstage crew is preparing  the equipment and performers for the day."
              << std::endl;
}

void BackStage::close()
{
    isOpen = false;
    std::cout << "Backstage operations have ended and equipment is being secured."
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

void DJStage::open()
{
    isOpen = true;
    std::cout << "Music begins filling the venue as the DJ Stage opens."
              << std::endl;
}

void DJStage::close()
{
    isOpen = false;
    std::cout << "The DJ Stage has powered down after its final set."
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

void DanceFloor::open()
{
    isOpen = true;
    std::cout << "The Dance Floor is now welcoming the festival attendees."
              << std::endl;
}

void DanceFloor::close()
{
    isOpen = false;
    std::cout << "The Dance Floor has been cleared and closed."
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

void BurgerVendor::open()
{
    isOpen = true;
    std::cout << "The smells from the grill start polluting th aeir as we start the service."
              << std::endl;
}

void BurgerVendor::close()
{
    isOpen = false;
    std::cout << "Burger service has ended and the grills are cooling down."
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

void BeverageVendor::open()
{
    isOpen = true;
    std::cout << "Cold drinks are now available to festival attendees."
              << std::endl;
}

void BeverageVendor::close()
{
    isOpen = false;
    std::cout << "The Beverage Vendor has stopped serving for the day."
              << std::endl;
}

SecurityPost::SecurityPost(int level, int capacity)
    : FestivalUnit("Security Post", capacity),
      securityLevel(level)
{
}

void SecurityPost::open()
{
    isOpen = true;
    std::cout << "Security teams are now monitoring festival grounds."
              << std::endl;
}

void SecurityPost::close()
{
    isOpen = false;
    std::cout << "Security operations are transitioning to shutdown procedures."
              << std::endl;
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

void FirstAidTent::open()
{
    isOpen = true;
    std::cout << "Medical staff are ready to assist festival attendees."
              << std::endl;
}

void FirstAidTent::close()
{
    isOpen = false;
    std::cout << "The First Aid Tent has completed its services for the event."
              << std::endl;
}