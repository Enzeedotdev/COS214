#ifndef FESTIVALOBSERVER_H
#define FESTIVALOBSERVER_H

#include <vector>
#include <string>
#include <iostream>

class Notice {
    private:
        std::string type;
        std::string description;

    public:
        enum NoticeType {
            OPEN, 
            CLOSE, 
            SCHEDULE_CHANGE, 
            CAPACITY_ALERT,
            WEATHER_ALERT,
            PAUSE,
            RESUME,
            EVACUATE
        };

        Notice(std::string, std::string);
        std::string getNotice();
};

class FestivalSubject {
    private:
        std::vector<FestivalObserver*> observerList;

    public:
        FestivalSubject();
        ~FestivalSubject();
        virtual void attach(FestivalObserver* observer) = 0;
        virtual void detach(FestivalObserver* observer) = 0;
        virtual void notify() = 0;
};

class FestivalControl : public FestivalSubject {
    private:
        Notice& currentNotice;

    public:
        FestivalControl();
        void issueNotice(Notice notice);
        void attach(FestivalObserver* observer);
        void detach(FestivalObserver* observer);
        void notify();
};

class FestivalObserver {
    public:
        virtual ~FestivalObserver() = default;
        virtual void update(const Notice& notice) = 0;
};

#endif //FESTIVALOBSERVER_H