#include "user.h"
#include <chrono>
#include <ctime>
#include <iomanip>

std::string User::getUsername() const 
{
    return username;
}

void User::setNotificationPreference(NotificationFrequency freq) 
{
    notificationPreference = freq;
}

void User::addRSVP(const std::string &eventName) 
{
    if (!hasRSVP(eventName)) {
        rsvpEvents.push_back(eventName);
    }
}

void User::removeRSVP(const std::string &eventName) 
{
    std::vector<std::string> updatedRSVPs;

    for (const auto& rsvp : rsvpEvents) {
        if (rsvp != eventName) {
            updatedRSVPs.push_back(rsvp);
        }
    }

    rsvpEvents = std::move(updatedRSVPs);
}

bool User::hasRSVP(const std::string &eventName) const 
{
    for (const auto& rsvp : rsvpEvents) {
        if (rsvp == eventName) {
            return true; 
        }
    }
    return false; 
}

const std::vector<std::string>& User::getRSVPEvents() const 
{
    return rsvpEvents;
}

NotificationFrequency User::getNotificationPreference() const 
{
    return notificationPreference;
}
