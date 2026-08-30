#ifndef FESTIVALUNIT_H
#define FESTIVALUNIT_H

#include "FestivalComponent.h"

class FestivalUnit : public FestivalComponent
{
protected:
    std::string status;

public:
    FestivalUnit(const std::string& name, int capacity);

    virtual void open();
    virtual void close();
    virtual void reportStatus() const;
    virtual int getCapacity() const;
};

#endif