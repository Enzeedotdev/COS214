#ifndef FESTIVALUNIT_H
#define FESTIVALUNIT_H

#include "FestivalComponent.h"

class FestivalUnit : public FestivalComponent
{
protected:
    std::string status;

public:
    FestivalUnit(const std::string& name, int capacity);
    virtual ~FestivalUnit() = default;

    virtual void open() override;
    virtual void close() override;
    virtual void reportStatus() const override;
    virtual int getCapacity() const override;
};

#endif