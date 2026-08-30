#ifndef FESTIVALLEAVES_H
#define FESTIVALLEAVES_H

#include "FestivalUnit.h"

class MainStage : public FestivalUnit
{
private:
    std::string currentPerformer;

public:
    MainStage(const std::string& performer, int capacity);
    void reportStatus() const;
};

class BackStage : public FestivalUnit
{
private:
    int crewMembers;

public:
    BackStage(int crewMembers, int capacity);
    void reportStatus() const;
};

class DJStage : public FestivalUnit
{
private:
    std::string currentDJ;

public:
    DJStage(const std::string& dj, int capacity);
    void reportStatus() const;
};

class DanceFloor : public FestivalUnit
{
private:
    int attendeeCount;
    int maxOccupancy;

public:
    DanceFloor(int maxOccupancy);
    void reportStatus() const;
};

class BurgerVendor : public FestivalUnit
{
private:
    int stockLevel;

public:
    BurgerVendor(int stockLevel, int capacity);
    void reportStatus() const;
};

class BeverageVendor : public FestivalUnit
{
private:
    int drinkLevel;

public:
    BeverageVendor(int drinkLevel, int capacity);
    void reportStatus() const;
};

class SecurityPost : public FestivalUnit
{
private:
    int securityLevel;

public:
    SecurityPost(int level, int capacity);
    void reportStatus() const;
};

class FirstAidTent : public FestivalUnit
{
private:
    int medicalStaffCount;

public:
    FirstAidTent(int staff, int capacity);
    void reportStatus() const;
};

#endif