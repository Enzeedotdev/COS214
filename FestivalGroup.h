#ifndef FESTIVALGROUP_H
#define FESTIVALGROUP_H

#include "FestivalComponent.h"
#include <vector>

/**
 * @brief Represents a grouping area within the festival.
 *
 * FestivalGroup is the Composite participant of the
 * Composite pattern. It owns FestivalComponent children
 * and applies operations recursively across the subtree.
 */
class FestivalGroup : public FestivalComponent
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

#endif