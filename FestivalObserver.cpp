#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "FestivalObserver.h"
#include "FestivalComponent.h"

/**
 * @brief Constructs a Notice object.
 * 
 * @param noticeType The type of the notice as a string.
 * @param noticeDescription Additional descriptive information.
 */

Notice::Notice(std::string& noticeType, std::string& noticeDescription) : type(noticeType), description(noticeDescription) {}

/**
 * @brief Retrieves the notice type.
 * 
 * @return The type of the notice as a string.
 */

std::string Notice::getNotice() const{
    return description;
}

FestivalControl::FestivalControl() : currentNotice(nullptr) {}

void FestivalControl::issueNotice(Notice* notice) {
    if (notice == nullptr) return;
    currentNotice = notice;
    notify();
}

void FestivalControl::attach(FestivalObserver* observer) {
    if(observer == nullptr) {
        return;
    }

        for (size_t i = 0; i < observerList.size(); i++) {
            if (observerList[i] == observer)
            {
                std::cout << "Observer already registered." << std::endl;
                return;
            }
        }
    
    this->observerList.push_back(observer);
    std::cout << "Observer attached." << std::endl;
}

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

void FestivalControl::notify() {
    if (currentNotice == nullptr) {
        std::cout << "No current notice to broadcast." << std::endl;
        return;
    }

    for(FestivalObserver* observer: observerList) {
        if(observer != nullptr) {
            observer->update(currentNotice);
        }
    }
}

FestivalGroup::FestivalGroup(const std::string& name, int capacity) : FestivalComponent(name, capacity) {}

FestivalGroup::~FestivalGroup() {
    for (size_t i = 0; i < children.size(); i++)
    {
        delete children[i];
    }
}

void FestivalGroup::add(FestivalComponent* component) {
    if (component != nullptr) {
        children.push_back(component);
    }
}

FestivalComponent* FestivalGroup::remove(FestivalComponent* component) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == component) {
            FestivalComponent* removed = *it;
            children.erase(it);
            return removed;
        }
    }

    return nullptr;
}

void FestivalGroup::open() {
    std::cout << "\nOpening " << name << " ...\n" <<  std::endl;

    for (size_t i = 0; i < children.size(); i++) {
        children[i]->open();
    }
}

void FestivalGroup::close() {
    std::cout << "\nClosing " << name << " ...\n" << std::endl;

    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->close();
    }
}

void FestivalGroup::reportStatus() const {
    std::cout << "\nReporting status for " << name << " : " << std::endl;

    for (size_t i = 0; i < children.size(); i++) {
        children[i]->reportStatus();
    }
}

int FestivalGroup::getCapacity() const {
    int total = 0;

    for (size_t i = 0; i < children.size(); i++) {
        total += children[i]->getCapacity();
    }

    return total;
}

void FestivalGroup::update(Notice* notice) {
    if (notice == nullptr) return;
    std::cout << name << " received notice: " << notice->getNotice() << std::endl;
    notify();
}