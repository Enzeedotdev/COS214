#ifndef FESTIVALGROUP_H
#define FESTIVALGROUP_H

#include "FestivalComponent.h"
#include <vector>

class FestivalGroup : public FestivalComponent
{
private:
    std::vector<FestivalComponent*> children;

public:
    FestivalGroup(const std::string& name, int capacity = 0);
    virtual ~FestivalGroup() override;

    void add(FestivalComponent* component);
    FestivalComponent* remove(FestivalComponent* component);

    void open();
    void close();
    void reportStatus() const;
    int getCapacity() const;
};

#endif