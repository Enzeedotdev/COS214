#ifndef FESTIVALOBSERVER_H
#define FESTIVALOBSERVER_H

#include <vector>
#include <string>
#include <iostream>
#include "FestivalComponent.h"

/**
 * @brief Represents a notice/order that can be broadcast to observers.
 *
 * The Notice class encapsulates the type of event and additional
 * descriptive information. It is used in the push model of the
 * Observer pattern to transfer state from subject to observer.
 */
class Notice {
    private:
        std::string type;        ///< The type of the notice as a string.
        std::string description; ///< Additional descriptive information.

    public:
        /**
         * @brief Enumeration of predefined notice types.
         */
        enum NoticeType {
            OPEN,              ///< Indicates an area/unit should open.
            CLOSE,             ///< Indicates an area/unit should close.
            SCHEDULE_CHANGE,   ///< Indicates a schedule change.
            CAPACITY_ALERT,    ///< Indicates a capacity limit has been reached.
            WEATHER_ALERT,     ///< Indicates severe weather conditions.
            PAUSE,             ///< Indicates operations should pause.
            RESUME,            ///< Indicates operations should resume.
            EVACUATE           ///< Indicates an evacuation is required.
        };

        /**
         * @brief Constructs a Notice object.
         * 
         * @param noticeType The type of the notice as a string.
         * @param noticeDescription Additional descriptive information.
         */
        Notice(std::string& noticeType, std::string& noticeDescription);

        /**
         * @brief Retrieves the notice type.
         * 
         * @return The type of the notice as a string.
         */
        std::string getNotice() const;
};

/**
 * @brief Abstract base class for all observable subjects.
 *
 * The FestivalSubject class defines the interface for objects that
 * can be observed. It maintains a list of registered observers and
 * provides methods to attach, detach, and notify them. Observers
 * are stored as non-owning pointers.
 */
class FestivalSubject {
    protected:
        /**
         * @brief List of registered observers (non-owning).
         */
        std::vector<FestivalObserver*> observerList;

    public:
        /**
         * @brief Default constructor.
         */
        FestivalSubject() = default;

        /**
         * @brief Virtual destructor for safe polymorphic deletion.
         */
        virtual ~FestivalSubject() = default;

        /**
         * @brief Registers an observer for notifications.
         * 
         * @param observer Pointer to the observer to register.
         *                 Must not be nullptr.
         */
        virtual void attach(FestivalObserver* observer) = 0;

        /**
         * @brief Unregisters an observer.
         * 
         * @param observer Pointer to the observer to detach.
         *                 If the observer is not registered, nothing happens.
         */
        virtual void detach(FestivalObserver* observer) = 0;

        /**
         * @brief Notifies all registered observers.
         */
        virtual void notify() = 0;
};

/**
 * @brief Centralised festival control system.
 *
 * FestivalControl acts as the concrete Subject in the Observer pattern.
 * It is responsible for issuing notices that cascade through the
 * festival hierarchy to all interested observers.
 */
class FestivalControl : public FestivalSubject {
    private:
        Notice* currentNotice; ///< The most recently issued notice.

    public:
        /**
         * @brief Constructs a FestivalControl object.
         */
        FestivalControl();

                /**
         * @brief Issues a notice to all registered observers.
         * 
         * The notice is stored as the current notice and broadcast
         * to all registered observers.
         * 
         * @param notice The notice to issue.
         */
        void issueNotice(Notice* notice);

        /**
         * @brief Registers an observer with the control system.
         * 
         * @param observer Pointer to the observer to register.
         *                 Must not be nullptr.
         */
        void attach(FestivalObserver* observer) override;

        /**
         * @brief Unregisters an observer from the control system.
         * 
         * @param observer Pointer to the observer to detach.
         */
        void detach(FestivalObserver* observer) override;

        /**
         * @brief Notifies all registered observers.
         * 
         * Broadcasts the current notice to all observers.
         */
        void notify() override;
};

/**
 * @brief Abstract base class for all observers.
 *
 * The FestivalObserver class defines the interface for objects
 * that receive notifications from subjects. Concrete observers
 * implement the update() method to react to notices.
 */
class FestivalObserver {
    public:
        /**
         * @brief Virtual destructor for safe polymorphic deletion.
         */
        virtual ~FestivalObserver() = default;

        /**
         * @brief Called by a subject when a notice is broadcast.
         * 
         * @param notice The notice being broadcast.
         */
        virtual void update(Notice* notice) = 0;
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
    Notice* lastReceivedNotice;

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
    void update(Notice* notice);
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

#endif //FESTIVALOBSERVER_H