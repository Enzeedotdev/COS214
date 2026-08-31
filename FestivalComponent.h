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
 * @brief Represents a grouping area within the festival.
 *
 * FestivalGroup is the Composite participant of the
 * Composite pattern. It owns FestivalComponent children
 * and applies operations recursively across the subtree.
 */
class FestivalGroup : public FestivalComponent, public FestivalObserver, public FestivalSubject
{
private:

    /**
     * @brief Owned child components.
     */
    std::vector<FestivalComponent*> children;

public:

    /**
     * @brief Creates a festival group.
     *
     * @param name Name of the group.
     * @param capacity Initial capacity.
     */
    FestivalGroup(const std::string& name, int capacity = 0);

    /**
     * @brief Destroys the group and all owned children.
     */
    virtual ~FestivalGroup() override;

    /**
     * @brief Adds a child component.
     *
     * Ownership of the component is transferred to the group.
     *
     * @param component Component to add.
     */
    void add(FestivalComponent* component);

    /**
     * @brief Removes a child component.
     *
     * The component is removed without being deleted.
     * Ownership is transferred to the caller.
     *
     * @param component Component to remove.
     * @return Pointer to the removed component.
     */
    FestivalComponent* remove(FestivalComponent* component);
    void update(Notice notice);
    void attach(FestivalObserver* observer);
    void detach(FestivalObserver* observer);
    void notify();

    /**
     * @brief Opens this group and all children.
     */
    void open();

    /**
     * @brief Closes this group and all children.
     */
    void close();

    /**
     * @brief Reports the status of this group and its children.
     */
    void reportStatus() const;

    /**
     * @brief Calculates the total capacity of the subtree.
     *
     * @return Total capacity.
     */
    int getCapacity() const;
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