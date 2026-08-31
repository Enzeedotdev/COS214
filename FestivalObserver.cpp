#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "FestivalObserver.h"

Notice::Notice(std::string& noticeType, std::string& noticeDescription) : type(noticeType), description(noticeDescription) {}

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

        for (size_t i = 0; i < observerList.size(); i++)
    {
        if (observerList[i] == observer)
        {
            std::cout << "Observer already registered." << std::endl;
            return;
        }
    
    this->observerList.push_back(observer);
}

void FestivalControl::detach(FestivalObserver* observer) {
    if(observer == nullptr) {
        return;
    }
    observerList.erase(
        std::remove(observerList.begin(), observerList.end(), observer), 
        observerList.end()
    );
}

void FestivalControl::notify() {
    for(FestivalObserver* observer: observerList) {
        if(observer != nullptr) {
            observer->update();
        }
    }
}
