#include "FestivalGroup.h"
#include <algorithm> 

/**
 * @brief Creates a festival group.
 *
 * @param name Name of the group.
 * @param capacity Initial capacity.
 */
FestivalGroup::FestivalGroup(const std::string& name, int capacity) : FestivalComponent(name, capacity), hasReceivedNotice(false) {}

/**
 * @brief Destroys the group and all owned children.
 */
FestivalGroup::~FestivalGroup() {
    // Delete all owned children
    for (size_t i = 0; i < children.size(); i++) {
        delete children[i];
    }
}

/**
 * @brief Adds a child component.
 *
 * Ownership of the component is transferred to the group.
 *
 * @param component Component to add.
 */
void FestivalGroup::add(FestivalComponent* component) {
    if (component != nullptr) {
        children.push_back(component);
    }
}

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
FestivalComponent* FestivalGroup::remove(FestivalComponent* component) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == component) {
            FestivalComponent* removed = *it;
            children.erase(it);
            
            // Also detach from observers if it was registered
            FestivalObserver* obs = dynamic_cast<FestivalObserver*>(component);
            if (obs != nullptr) {
                detach(obs);
            }
            
            return removed;
        }
    }

    return nullptr;
}

/**
 * @brief Called when a notice is received from a parent subject.
 * 
 * As an Observer, this method processes the notice and then
 * forwards it to all registered observers.
 * 
 * @param notice The notice received. Must not be nullptr.
 */
void FestivalGroup::update(Notice* notice) {
    if (notice == nullptr) return;
    
    std::cout << name << " received notice: " << notice->getNotice() << std::endl;
    
    // Store the notice for forwarding
    lastReceivedNotice = *notice;
    hasReceivedNotice = true;
}

/**
 * @brief Registers an observer with this group.
 * 
 * @param observer The observer to register. Must not be nullptr.
 */
void FestivalGroup::attach(FestivalObserver* observer) {
    if(observer == nullptr) return;

    // Prevent duplicate registration
    for (size_t i = 0; i < observerList.size(); i++) {
        if (observerList[i] == observer) {
            std::cout << "Observer already registered to " << name << "." << std::endl;
            return;
        }
    }
    
    observerList.push_back(observer);
    std::cout << "Observer attached to " << name << "." << std::endl;
}

/**
 * @brief Unregisters an observer from this group.
 * 
 * @param observer The observer to detach.
 */
void FestivalGroup::detach(FestivalObserver* observer) {
    if(observer == nullptr) return;
    
    auto it = std::remove(observerList.begin(), observerList.end(), observer);
    if (it != observerList.end()) {
        observerList.erase(it, observerList.end());
        std::cout << "Observer detached from " << name << "." << std::endl;
    } else {
        std::cout << "Observer not found in " << name << " - nothing detached." << std::endl;
    }
}

/**
 * @brief Notifies all registered observers with the last received notice.
 */
void FestivalGroup::notify() {
    if (!hasReceivedNotice) return;
    
    for (FestivalObserver* observer : observerList) {
        if (observer != nullptr) {
            observer->update(&lastReceivedNotice);
        }
    }
}

/**
 * @brief Opens this group and all children.
 */
void FestivalGroup::open() {
    std::cout << "\nOpening " << name << " ...\n" << std::endl;

    for (size_t i = 0; i < children.size(); i++) {
        children[i]->open();
    }
}

/**
 * @brief Closes this group and all children.
 */
void FestivalGroup::close() {
    std::cout << "\nClosing " << name << " ...\n" << std::endl;

    for (size_t i = 0; i < children.size(); i++) {
        children[i]->close();
    }
}

/**
 * @brief Reports the status of this group and its children.
 */
void FestivalGroup::reportStatus() const {
    std::cout << "\nReporting status for " << name << " : " << std::endl;

    for (size_t i = 0; i < children.size(); i++) {
        children[i]->reportStatus();
    }
}

/**
 * @brief Calculates the total capacity of the subtree.
 *
 * @return Total capacity.
 */
int FestivalGroup::getCapacity() const {
    int total = 0;

    for (size_t i = 0; i < children.size(); i++) {
        total += children[i]->getCapacity();
    }

    return total;
}