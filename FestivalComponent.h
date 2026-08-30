#ifndef FESTIVALCOMPONENT_H
#define FESTIVALCOMPONENT_H

#include <string>

class FestivalComponent
{
protected:
    std::string name;
    int capacity;
    bool isOpen;

public:
    FestivalComponent(const std::string& name, int capacity);
    virtual ~FestivalComponent();

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;
};

#endif