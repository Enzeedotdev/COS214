#include "FestivalGroup.h"
#include <iostream>

FestivalGroup::FestivalGroup(const std::string& name, int capacity)
    : FestivalComponent(name, capacity)
{
}

FestivalGroup::~FestivalGroup()
{
    for (size_t i = 0; i < children.size(); i++)
    {
        delete children[i];
    }
}

void FestivalGroup::add(FestivalComponent* component)
{
    if (component != nullptr)
    {
        children.push_back(component);
    }
}

FestivalComponent* FestivalGroup::remove(FestivalComponent* component)
{
    for (auto it = children.begin(); it != children.end(); ++it)
    {
        if (*it == component)
        {
            FestivalComponent* removed = *it;
            children.erase(it);
            return removed;
        }
    }

    return nullptr;
}

void FestivalGroup::open()
{
    std::cout << "\nOpening " << name << " ...\n" <<  std::endl;

    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->open();
    }
}

void FestivalGroup::close()
{
    std::cout << "\nClosing " << name << " ...\n" << std::endl;

    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->close();
    }
}

void FestivalGroup::reportStatus() const
{
    std::cout << "\nReporting status for " << name << " : " << std::endl;

    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->reportStatus();
    }
}

int FestivalGroup::getCapacity() const
{
    int total = 0;

    for (size_t i = 0; i < children.size(); i++)
    {
        total += children[i]->getCapacity();
    }

    return total;
}