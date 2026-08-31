#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "FestivalObserver.h"

/**
 * @brief Constructs a Notice object.
 * 
 * @param noticeType The type of the notice as a string.
 * @param noticeDescription Additional descriptive information.
 */
Notice::Notice(std::string noticeType, std::string noticeDescription) : type(noticeType), description(noticeDescription) {}

/**
 * @brief Retrieves the notice description.
 * 
 * @return The description of the notice.
 */
std::string Notice::getNotice() const {
    return description;
}

/**
 * @brief Gets the notice type as an enum value.
 * 
 * @return The NoticeType enum value.
 */
Notice::NoticeType Notice::getNoticeType() const {
    if (type == "OPEN") return OPEN;
    if (type == "CLOSE") return CLOSE;
    if (type == "SCHEDULE_CHANGE") return SCHEDULE_CHANGE;
    if (type == "CAPACITY_ALERT") return CAPACITY_ALERT;
    if (type == "WEATHER_ALERT") return WEATHER_ALERT;
    if (type == "PAUSE") return PAUSE;
    if (type == "RESUME") return RESUME;
    if (type == "EVACUATE") return EVACUATE;
    return OPEN; // default
}

/**
 * @brief Constructs a FestivalControl object.
 */
FestivalControl::FestivalControl() : currentNotice(nullptr) {}

/**
 * @brief Issues a notice to all registered observers.
 * 
 * The notice is stored as the current notice and broadcast
 * to all registered observers.
 * 
 * @param notice The notice to issue. Must not be nullptr.
 */
void FestivalControl::issueNotice(Notice* notice) {
    if (notice == nullptr) return;
    
    currentNotice = notice;
    notify();
}

/**
 * @brief Registers an observer with the control system.
 * 
 * @param observer Pointer to the observer to register.
 *                 Must not be nullptr.
 */
void FestivalControl::attach(FestivalObserver* observer) {
    if(observer == nullptr) {
        return;
    }

    // Prevent duplicate registration
    for (size_t i = 0; i < observerList.size(); i++) {
        if (observerList[i] == observer) {
            std::cout << "Observer already registered." << std::endl;
            return;
        }
    }
    
    observerList.push_back(observer);
    std::cout << "Observer attached." << std::endl;
}

/**
 * @brief Unregisters an observer from the control system.
 * 
 * @param observer Pointer to the observer to detach.
 */
void FestivalControl::detach(FestivalObserver* observer) {
    if(observer == nullptr) {
        return;
    }

    auto it = std::remove(observerList.begin(), observerList.end(), observer);
    if (it != observerList.end()) {
        observerList.erase(it, observerList.end());
        std::cout << "Observer detached." << std::endl;
    } else {
        std::cout << "Observer not found - nothing detached." << std::endl;
    }
}

/**
 * @brief Notifies all registered observers.
 * 
 * Broadcasts the current notice to all observers.
 */
void FestivalControl::notify() {
    if (currentNotice == nullptr) {
        std::cout << "No current notice to broadcast." << std::endl;
        return;
    }

    for(FestivalObserver* observer : observerList) {
        if(observer != nullptr) {
            observer->update(currentNotice);
        }
    }
}

