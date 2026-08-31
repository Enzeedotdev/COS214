#ifndef FESTIVALCOMPONENT_H
#define FESTIVALCOMPONENT_H

#include <string>
#include <vector>
#include "FestivalObserver.h"

/**
* @brief Common component abstraction for all festival elements.
*
* FestivalComponent forms the Component participant of the
* Composite pattern. Both FestivalGroup and FestivalUnit
* inherit from this class and can be treated uniformly.
*/
class FestivalComponent
{
protected:
    std::string name;
    int capacity;
    bool isOpen;

public:
    /**
     * @brief Constructs a festival component.
     *
     * @param name Name of the component.
     * @param capacity Maximum capacity of the component.
     */
    FestivalComponent(const std::string& name, int capacity);

    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~FestivalComponent();

    /**
     * @brief Opens the component for operation.
     */
    virtual void open() = 0;

    /**
     * @brief Closes the component.
     */
    virtual void close() = 0;

    /**
     * @brief Displays the current state of the component.
     */
    virtual void reportStatus() const = 0;

    /**
     * @brief Retrieves the capacity of the component.
     *
     * @return Capacity of the component.
     */
    virtual int getCapacity() const = 0;
};




/**
 * @brief Represents an operational unit within the festival.
 *
 * FestivalUnit acts as the Leaf participant in the Composite
 * pattern. Unlike FestivalGroup, a FestivalUnit cannot contain
 * other FestivalComponents.
 */
class FestivalUnit : public FestivalComponent
{
protected:

    /**
     * @brief Current operational status of the unit.
     */
    std::string status;

public:

    /**
     * @brief Creates a festival unit.
     *
     * @param name Name of the unit.
     * @param capacity Maximum capacity of the unit.
     */
    FestivalUnit(const std::string& name, int capacity);

    /**
     * @brief Virtual destructor.
     */
    virtual ~FestivalUnit() = default;

    /**
     * @brief Opens the unit.
     */
    virtual void open() override;

    /**
     * @brief Closes the unit.
     */
    virtual void close() override;

    /**
     * @brief Reports the current status of the unit.
     */
    virtual void reportStatus() const override;

    /**
     * @brief Returns the capacity of the unit.
     *
     * @return Unit capacity.
     */
    virtual int getCapacity() const override;
};


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

#endif //FESTIVALCOMPONENT_H