#ifndef FESTIVALOBSERVER_H
#define FESTIVALOBSERVER_H

#include <vector>
#include <string>
#include <iostream>

class FestivalComponent;  // Forward declaration
class FestivalObserver;   // Forward declaration

class FestivalObserver;
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
        Notice() : type(""), description("") {}
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
        Notice(std::string noticeType, std::string noticeDescription);

        /**
         * @brief Retrieves the notice type.
         * 
         * @return The type of the notice as a string.
         */
        std::string getNotice() const;
        
        /**
         * @brief Gets the notice type as an enum value.
         * 
         * @return The NoticeType enum value.
         */
        NoticeType getNoticeType() const;
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
        Notice* currentNotice; ///< The most recently issued notice (non-owning).

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
         * @param notice The notice to issue. Must not be nullptr.
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
         * @param notice The notice being broadcast. Must not be nullptr.
         */
        virtual void update(Notice* notice) = 0;
};



#endif //FESTIVALOBSERVER_H