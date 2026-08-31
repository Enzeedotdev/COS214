#ifndef FESTIVALLEAVES_H
#define FESTIVALLEAVES_H

#include "FestivalUnit.h"
#include <string>

/**
* @brief Represents the main performance stage.
*
* Stores information about the performer currently on stage.
*/
class MainStage : public FestivalUnit
{
private:
    std::string currentPerformer;

public:
    /** 
    * @brief Creates a MainStage.
    *
    * @param performer Current performer.
    * @param capacity Stage capacity.
    */
    MainStage(const std::string& performer, int capacity);
    void reportStatus() const override;
    void open() override;
    void close() override;
};

/**
* @brief Represents a backstage preparation area.
*/
class BackStage : public FestivalUnit
{
private:
    int crewMembers;

public:
    BackStage(int crewMembers, int capacity);
    void reportStatus() const override;
    void open() override;
    void close() override;
};

/**
* @brief Represents an electronic music stage.
*/
class DJStage : public FestivalUnit
{
private:
    std::string currentDJ;

public:
    DJStage(const std::string& dj, int capacity);
    void reportStatus() const override;
    void open() override;
    void close() override;
};

/**
* @brief Represents the festiv*l dance floor area.
*/
class DanceFloor : public FestivalUnit
{
private:
    int attendeeCount;
    int maxOccupancy;

public:
    DanceFloor(int maxOccupancy);
    void reportStatus() const override;
    void open() override;
    void close() override;
};

/**
* @brief Represents a food vendor selling burgers.
*/
class BurgerVendor : public FestivalUnit
{
private:
    int stockLevel;

public:
    BurgerVendor(int stockLevel, int capacity);
    void reportStatus() const override;
    void open() override;
    void close() override;
};

/**
*@brief Represents the drinks vendor.
*/
class BeverageVendor : public FestivalUnit
{
private:
    int drinkLevel;

public:
    BeverageVendor(int drinkLevel, int capacity);
    void reportStatus() const override;
    void open() override;
    void close() override;
};

/**
* @brief Represents a security monitoring point.
*/
class SecurityPost : public FestivalUnit
{
private:
    int securityLevel;

public:
    SecurityPost(int level, int capacity);
    void reportStatus() const override;
    void open() override;
    void close() override;
};

/**
* @brief Represents a medical assistance station.
*/
class FirstAidTent : public FestivalUnit
{
private:
    int medicalStaffCount;

public:
    FirstAidTent(int staff, int capacity);
    void reportStatus() const override;
    void open() override;
    void close() override;
};

#endif