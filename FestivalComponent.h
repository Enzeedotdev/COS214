#ifndef FESTIVALCOMPONENT_H
#define FESTIVALCOMPONENT_H

#include <string>

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

#endif