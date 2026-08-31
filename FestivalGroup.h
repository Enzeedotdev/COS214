#ifndef FESTIVALGROUP_H
#define FESTIVALGROUP_H

#include "FestivalComponent.h"
#include "FestivalObserver.h"

/**
 * @brief Represents a grouping area within the festival.
 *
 * FestivalGroup is the Composite participant of the
 * Composite pattern. It owns FestivalComponent children
 * and applies operations recursively across the subtree.
 * It also acts as both an Observer and Subject to cascade
 * notifications down the hierarchy.
 */
class FestivalGroup : public FestivalComponent, public FestivalObserver, public FestivalSubject
{
private:
    /**
     * @brief Owned child components.
     */
    std::vector<FestivalComponent*> children;
    
    /**
     * @brief Most recently received notice (non-owning).
     */
    Notice lastReceivedNotice;
    bool hasReceivedNotice;

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
     * If the component is also an Observer, it is detached.
     *
     * @param component Component to remove.
     * @return Pointer to the removed component.
     */
    FestivalComponent* remove(FestivalComponent* component);

    /**
     * @brief Called when a notice is received from a parent subject.
     * 
     * As an Observer, this method processes the notice and then
     * forwards it to all registered observers (its children if
     * they are registered).
     * 
     * @param notice The notice received. Must not be nullptr.
     */
    void update(Notice* notice) override;

    /**
     * @brief Registers an observer with this group.
     * 
     * @param observer The observer to register. Must not be nullptr.
     */
    void attach(FestivalObserver* observer) override;

    /**
     * @brief Unregisters an observer from this group.
     * 
     * @param observer The observer to detach.
     */
    void detach(FestivalObserver* observer) override;

    /**
     * @brief Notifies all registered observers with the last received notice.
     */
    void notify() override;

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