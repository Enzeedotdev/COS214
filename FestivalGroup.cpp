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

void FestivalGroup::remove(FestivalComponent* component)
{
    for (std::vector<FestivalComponent*>::iterator it = children.begin();
         it != children.end();
         ++it)
    {
        if (*it == component)
        {
            children.erase(it);
            break;
        }
    }
}

void FestivalGroup::open()
{
    std::cout << "\nOpening group: " << name << std::endl;

    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->open();
    }
}

void FestivalGroup::close()
{
    std::cout << "\nClosing group: " << name << std::endl;

    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->close();
    }
}

void FestivalGroup::reportStatus() const
{
    std::cout << "\n" << name << " " << std::endl;

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