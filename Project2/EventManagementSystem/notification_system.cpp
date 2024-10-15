#include "notification_system.h"
#include <iostream>
#include <iomanip>

void NotificationSystem::addUser(std::shared_ptr<User> user) 
{
    for (const auto& existingUser : users) 
    {
        if (existingUser->getUsername() == user->getUsername()) 
        {
            std::cout << "User " << user->getUsername() << " is already added." << std::endl;
            return;
        }
    }
    users.push_back(user);
    std::cout << "User " << user->getUsername() << " has been added." << std::endl;
}

void NotificationSystem::notifyUsers(const std::vector<std::shared_ptr<Event>>& events) 
{
    for (const auto& user : users) 
    {
        for (const auto& event : events) 
        {
            if (event->isUpcoming() && user->hasRSVP(event->getName())) 
            {
                sendNotification(*user, *event);
            }
        }
    }
}

void NotificationSystem::sendNotification(const User& user, const Event& event) 
{
    std::cout << "Notification for " << user.getUsername() << ": ";
    std::cout << "Upcoming event '" << event.getName() << "' on " << event.getDate() << std::endl;
}