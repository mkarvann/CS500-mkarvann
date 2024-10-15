#include "event_manager.h"
#include <iostream>
#include <algorithm>

void EventManager::addEvent(std::shared_ptr<Event> event) 
{
    events.push_back(std::move(event));
}

void EventManager::addUser(std::shared_ptr<User> user) 
{
    users.push_back(user);
    notificationSystem.addUser(user);
}

void EventManager::rsvpForEvent(const std::string& username, const std::string& eventName) 
{
    auto user = findUser(username);
    auto event = findEvent(eventName);
    if (user && event) {
        user->addRSVP(eventName);
        event->addAttendee(username);
        std::cout << "RSVP successful for " << username << " to event " << eventName << std::endl;
    } else {
        std::cout << "User or event not found.\n";
    }
}

void EventManager::cancelRSVP(const std::string& username, const std::string& eventName) 
{
    auto user = findUser(username);
    auto event = findEvent(eventName);
    if (user && event) {
        user->removeRSVP(eventName);
        event->removeAttendee(username);
        std::cout << "RSVP canceled for " << username << " from event " << eventName << std::endl;
    } else {
        std::cout << "User or event not found.\n";
    }
}

void EventManager::sendNotifications() 
{
    auto upcomingEvents = getUpcomingEvents();
    notificationSystem.notifyUsers(upcomingEvents);
}

void EventManager::displayAllEvents() const 
{
    std::cout << "All Events:\n";
    for (const auto& event : events) {
        std::cout << event->getName() << " - " << event->getDate() << "\n";
    }
}

void EventManager::displayEventAttendees(const std::string& eventName) const
{
    auto event = findEvent(eventName);
    if (event) {
        std::cout << "Attendees for " << eventName << ":\n";
        for (const auto& attendee : event->getAttendees()) 
        {
            std::cout << attendee << "\n";
        }
    } 
    else 
    {
        std::cout << "Event not found.\n";
    }
}

void EventManager::displayUserRSVPs(const std::string& username) const 
{
    auto user = findUser(username);
    if (user) {
        std::cout << "Events " << username << " has RSVP'd to:\n";
        for (const auto& eventName : user->getRSVPEvents()) 
        {
            std::cout << eventName << "\n";
        }
    } 
    else 
    {
        std::cout << "User not found.\n";
    }
}

std::shared_ptr<Event> EventManager::findEvent(const std::string& eventName) const 
{
    for (const auto& event : events) 
    {
        if (event->getName() == eventName) 
        {
            return event;
        }
    }
    return nullptr;
}

std::shared_ptr<User> EventManager::findUser(const std::string& username) const 
{
    for (const auto& user : users) 
    {
        if (user->getUsername() == username) 
        {
            return user;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Event>> EventManager::searchEvents(
    const SearchStrategy& strategy, const std::string& criteria) const 
    {
    std::vector<std::shared_ptr<Event>> results;
    for (const auto& event : events) {
        if (strategy.match(event, criteria)) 
        {
            results.push_back(event);
        }
    }
    return results;
}

std::vector<std::shared_ptr<Event>> EventManager::getUpcomingEvents() const 
{
    std::vector<std::shared_ptr<Event>> upcomingEvents;
    for (const auto& event : events) {
        if (event->isUpcoming()) {
            upcomingEvents.push_back(event);
        }
    }
    return upcomingEvents;
}

void EventManager::displayEventDetails(const std::string& eventName) const 
{
    auto event = findEvent(eventName);
    if (event) {
        std::cout << event->getDetails() << std::endl;
    } else {
        std::cout << "Event not found.\n";
    }
}