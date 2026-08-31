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

void FestivalControl::issueNotice(Notice notice) {
    currentNotice = &notice;
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
            observer->update(*currentNotice);
        }
    }
}
