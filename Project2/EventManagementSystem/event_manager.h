#pragma once
#include "event.h"
#include "search_strategy.h"
#include "user.h"
#include "notification_system.h"
#include <memory>
#include <vector>

class EventManager 
{
    public:
        void addEvent(std::shared_ptr<Event> event);
        std::vector<std::shared_ptr<Event>> searchEvents(const SearchStrategy& strategy, const std::string& criteria) const;
        std::vector<std::shared_ptr<Event>> getUpcomingEvents() const;
        void displayEventDetails(const std::string& eventName) const;
        void addUser(std::shared_ptr<User> user);
        void rsvpForEvent(const std::string& username, const std::string& eventName);
        void cancelRSVP(const std::string& username, const std::string& eventName);
        void sendNotifications();
        void displayAllEvents() const;
        void displayEventAttendees(const std::string& eventName) const;
        void displayUserRSVPs(const std::string& username) const;


    private:
        std::vector<std::shared_ptr<Event>> events;
        std::vector<std::shared_ptr<User>> users;
        NotificationSystem notificationSystem;
        std::shared_ptr<Event> findEvent(const std::string& eventName) const;
        std::shared_ptr<User> findUser(const std::string& username) const;
};
