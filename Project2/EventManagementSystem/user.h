#pragma once
#include "event.h"
#include <string>
#include <vector>

enum class NotificationFrequency 
{
    Daily,
    Weekly
};

class User 
{
    public:
        User(const std::string &name, NotificationFrequency freq)
            : username(name), notificationPreference(freq) {}

        std::string getUsername() const;
        NotificationFrequency getNotificationPreference() const;
        void setNotificationPreference(NotificationFrequency freq);
        void addRSVP(const std::string &eventName);
        void removeRSVP(const std::string &eventName);
        bool hasRSVP(const std::string &eventName) const;
        const std::vector<std::string> &getRSVPEvents() const;

    private:
        std::string username;
        NotificationFrequency notificationPreference;
        std::vector<std::string> rsvpEvents;
};