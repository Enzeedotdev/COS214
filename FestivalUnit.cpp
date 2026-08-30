#include "FestivalUnit.h"
#include <iostream>

FestivalUnit::FestivalUnit(const std::string& name, int capacity)
    : FestivalComponent(name, capacity)
{
    status = "Closed";
}

void FestivalUnit::open()
{
    isOpen = true;
    status = "Open";
}

void FestivalUnit::close()
{
    isOpen = false;
    status = "Closed";
}

void FestivalUnit::reportStatus() const
{
    std::cout << name
              << " | Status: "
              << status
              << " | Capacity: "
              << capacity
              << std::endl;
}

int FestivalUnit::getCapacity() const
{
    return capacity;
}