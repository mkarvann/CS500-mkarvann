#pragma once
#include "event.h"
#include "user.h"
#include <vector>
#include <memory>

class NotificationSystem
{
    public:
        void addUser(std::shared_ptr<User> user); 
        void notifyUsers(const std::vector<std::shared_ptr<Event>> &events);

    private:
        std::vector<std::shared_ptr<User>> users;
        void sendNotification(const User &user, const Event &event);
};